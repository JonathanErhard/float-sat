cmake_minimum_required(VERSION 3.10)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../../../ui-layouts/custom-widgets/compiled)
PROJECT(widgetsplugin) 

# set the right include path first!
INCLUDE_DIRECTORIES(
  ../../corfu/dev-host/ground-tools/ground/src
 ../../corfu/build/ground-tools/ground/corfu-ground_autogen/include
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
)

#Must use this manual structure as QT5 CMake doesn't have the Macro to do this..
find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
QT5_WRAP_CPP(MOC_BUILT_SOURCES loader.h qcustomplot.h)

set(widgetsplugin_SOURCE_FILES 
  loader.cpp
  qcustomplot.cpp
  loader.h
  ${MOC_BUILT_SOURCES}) 

set(REQ_LIBS libcorfu-ground)
set_property(GLOBAL PROPERTY REQ_LIBS_property "${REQ_LIBS}")

#Add your custom widgets here, as well as in loader.cpp!!
add_subdirectory(widget1)
add_subdirectory(rswidget)


get_property(REQ_LIBS GLOBAL PROPERTY REQ_LIBS_property)
ADD_LIBRARY(custom-widgets SHARED ${widgetsplugin_SOURCE_FILES})

target_link_libraries(custom-widgets PRIVATE 
  ${REQ_LIBS}
  Qt5::Widgets
)
