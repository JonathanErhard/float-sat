cmake_minimum_required(VERSION 3.10)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../../ui-layouts/custom-widgets/compiled)
PROJECT(widgetsplugin) 

# set the right include path first!

get_property(CORFU_GROUND_INCLUDE GLOBAL PROPERTY CORFU_GROUND_INCLUDE_property)

INCLUDE_DIRECTORIES(
  ${CORFU_GROUND_INCLUDE}
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

#Add your custom widgets here, as well ast in loader.cpp!!
add_subdirectory(pointingWidget)
add_subdirectory(plottingWidget)


get_property(REQ_LIBS GLOBAL PROPERTY REQ_LIBS_property)
ADD_LIBRARY(custom-widgets SHARED ${widgetsplugin_SOURCE_FILES})

target_link_libraries(custom-widgets PRIVATE 
  ${REQ_LIBS}
  Qt5::Widgets
)
