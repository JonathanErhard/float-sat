add_library(common-generated INTERFACE)
target_include_directories(common-generated INTERFACE include)
target_link_libraries(common-generated INTERFACE libcorfu-tele)
