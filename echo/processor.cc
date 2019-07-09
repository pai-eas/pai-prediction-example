#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string>

extern "C" {

class echo
{
	public:
		echo(): model_files(NULL) {}
		char *model_files;
};

void *initialize(const char *model_entry, const char *model_config, int *state)
{
	echo *model = new echo;

	struct stat path_stat;
	stat(model_entry, &path_stat);

	if (S_ISREG(path_stat.st_mode)) {
		model->model_files = strdup(model_entry);
	} else {
		DIR *dir = opendir(model_entry);
		if (!dir) {
			fprintf(stderr, "Fail to open model entry: %s\n", model_entry);
			*state = 400;
			return NULL;
		}

		std::string files = std::string(model_entry);

		struct dirent *ent;
		while ((ent = readdir(dir)) != NULL)
			files += "," + std::string(ent->d_name);

		model->model_files = strdup(files.c_str());
	}

	*state = 0;
	return model;
}

int process(void *model_buf, const void *input_data, int input_size,
						void **output_data, int *output_size)
{
	echo *model = (echo *)model_buf;

	if (input_size == 0) {
		const char *errmsg = "input data should not be empty";
		*output_data = strdup(errmsg);
		*output_size = strlen(errmsg);
		return 400;
	}

	std::string input = std::string((char *)input_data, input_size);

	char buf[BUFSIZ];
	snprintf(buf, BUFSIZ, "{\"modelfiles\": \"%s\", \"inputcontent\", \"%s\"}",
					 model->model_files, input.c_str());

	*output_data = strdup(buf);
	*output_size = strlen(buf);
	return 200;
}

}
