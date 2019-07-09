set(CMAKE_CXX_FLAGS "-O2")
file(GLOB echo_src processor.cc)
add_library(echo SHARED ${echo_src})

add_custom_command(
  OUTPUT make-tar-for-echo
  COMMAND cp ${CMAKE_SOURCE_DIR}/echo/service.json .
  COMMAND tar czf echo_processor_release.tar.gz libecho.so
)

add_custom_target(make-package-for-echo ALL DEPENDS make-tar-for-echo echo)
