project(rswidget)
cmake_minimum_required(VERSION 3.2.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets REQUIRED)

set(COMPILE_OPTIONS -std=c++17)

add_library(rswidget 
    rswidget.cpp   
)

#This tells the CMakeLists of the Loader to link this proj as well
#I haven't found a better way to do this, a simple target link doesn't seem to work as it breaks MOC
get_property(REQ_LIBS GLOBAL PROPERTY REQ_LIBS_property)
set(REQ_LIBS ${REQ_LIBS} rswidget)
set_property(GLOBAL PROPERTY REQ_LIBS_property "${REQ_LIBS}")

target_link_libraries(rswidget PRIVATE 
    Qt5::Widgets
    libcorfu-ground
)

target_compile_options(rswidget PRIVATE ${COMPILE_OPTIONS})