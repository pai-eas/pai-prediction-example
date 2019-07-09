# download tensorflow sdk
if (NOT EXISTS ${CMAKE_SOURCE_DIR}/sdk)
  execute_process(COMMAND wget http://eas-data.oss-cn-shanghai.aliyuncs.com/sdk/tensorflow_sdk_cpu_1.12.0.tar.gz -O ${CMAKE_SOURCE_DIR}/tensorflow_runtime_sdk_cpu.tar.gz)
  execute_process(COMMAND tar xzf ${CMAKE_SOURCE_DIR}/tensorflow_runtime_sdk_cpu.tar.gz -C ${CMAKE_SOURCE_DIR})
  execute_process(COMMAND rm -f ${CMAKE_SOURCE_DIR}/tensorflow_runtime_sdk_cpu.tar.gz)
endif()

# download opencv
if (NOT EXISTS ${CMAKE_SOURCE_DIR}/opencv)
  execute_process(COMMAND wget http://eas-data.oss-cn-shanghai.aliyuncs.com/sdk/opencv_static_library.tar.gz -O ${CMAKE_SOURCE_DIR}/opencv_static_library.tar.gz)
  execute_process(COMMAND tar xzf ${CMAKE_SOURCE_DIR}/opencv_static_library.tar.gz -C ${CMAKE_SOURCE_DIR})
  execute_process(COMMAND rm -f ${CMAKE_SOURCE_DIR}/opencv_static_library.tar.gz)
endif()

# opencv static libraries
set(opencv_static_libs
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_contrib.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_stitching.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_nonfree.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_superres.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_ocl.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_ts.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_videostab.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_gpu.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_photo.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_objdetect.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_legacy.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_video.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_ml.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_calib3d.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_features2d.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_highgui.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libIlmImf.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/liblibjasper.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/liblibtiff.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/liblibpng.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/liblibjpeg.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_imgproc.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_flann.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libopencv_core.a
  ${CMAKE_SOURCE_DIR}/opencv/lib/libzlib.a)

set(CMAKE_CXX_FLAGS "-O2 -fPIC")
include_directories(${CMAKE_SOURCE_DIR}/sdk/include)
include_directories(${CMAKE_SOURCE_DIR}/opencv/include)
link_directories(${CMAKE_SOURCE_DIR}/sdk/)

file(GLOB image_classification_src tf_image_processor.cc)

add_library(image_classification SHARED ${image_classification_src})
target_link_libraries(image_classification ${opencv_static_libs} tensorflow_cc tensorflow_framework tf_loader rt pthread m dl stdc++)

# files to package
set(package_files
    libimage_classification.so
    libtensorflow_framework.so
    libtf_loader.so
    libtensorflow_cc.so)

add_custom_command(
  OUTPUT make-tar-for-image-classification
  COMMAND cp ${CMAKE_SOURCE_DIR}/image_classification/service.json .
  COMMAND cp ${CMAKE_SOURCE_DIR}/sdk/libtensorflow_framework.so .
  COMMAND cp ${CMAKE_SOURCE_DIR}/sdk/libtensorflow_cc.so .
  COMMAND cp ${CMAKE_SOURCE_DIR}/sdk/libtf_loader.so .
  COMMAND tar czf image_classification_processor_release.tar.gz ${package_files}
)

add_custom_target(make-package-for-image-classification ALL DEPENDS image_classification make-tar-for-image-classification)
