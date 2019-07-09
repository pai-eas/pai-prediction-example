#include "tensorflow_serving/apis/saved_model_loader.h"
#include "tensorflow_serving/apis/run_predict.h"
#include <opencv2/opencv.hpp>

#include <string.h>
#include <vector>
#include <sstream>
using namespace cv;

extern "C" {

void *initialize(const char *model_entry, const char *model_config, int *state)
{
	SavedModelLoader* loader = new SavedModelLoader;
	*state = loader->LoadModel(model_entry);
	return loader;
}

int process(void *model_buf, const void *input_data, int input_size,
						void **output_data, int *output_size)
{
	SavedModelLoader* loader = static_cast<SavedModelLoader*>(model_buf);
	if (input_size == 0) {
		const char* errmsg = "input data should not be empty";
		*output_data = strdup(errmsg);
		*output_size = strlen(errmsg);
		return 400;
	}
	RunRequest request;
	RunResponse response;
	std::string inputImage = std::string((const char*)input_data, input_size);
	std::vector<unsigned char> data(inputImage.begin(), inputImage.end());
	Mat image = imdecode(data, CV_LOAD_IMAGE_GRAYSCALE);
	std::cout << "channels: " << image.channels() << std::endl;
	std::cout << "row: " << image.rows << std::endl;
	std::cout << "col: " << image.cols << std::endl;
	std::vector<long long> shape;
	shape.push_back(1);
	shape.push_back(image.rows * image.cols);
	std::vector<float> content;
	content.reserve(image.rows * image.cols);
	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++)
			content.push_back(image.at<unsigned char>(i, j));
	}

	request.SetSignatureName("predict_images");
	request.AddFeed("images", shape, content);
	request.AddFetch("scores");
	int state = loader->Predict(request, &response);
	if (state < 0) {
		const char* errmsg = "Predict Process Failed";
		*output_data = strndup(errmsg, strlen(errmsg));
		*output_size = strlen(errmsg);
		return 500;
	}
	std::vector<float> result;
	std::ostringstream outputResult;
	response.GetData("scores", &result);
	outputResult << "{";
	outputResult << "\"result\": ";
	for (int i = 0; i < result.size(); i++) {
		outputResult << result[i] <<" ";
	}
	outputResult << "}";
	*output_data = strndup(outputResult.str().c_str(), outputResult.str().length());
	*output_size = outputResult.str().length();

	return 200;
}

}
