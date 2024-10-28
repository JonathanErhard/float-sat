GET_PROPERTY(project_path GLOBAL PROPERTY project_path)

add_library(drivers
)

target_include_directories(drivers PUBLIC 
)

target_link_libraries(drivers PUBLIC rodos libcorfu-onboard common-generated)

add_subdirectory(common)
add_subdirectory(nodes/main-node)
