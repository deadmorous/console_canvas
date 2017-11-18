cmake_minimum_required (VERSION 2.8.3) 
project (console_canvas) 

aux_source_directory(. SOURCE_FILES)
file (GLOB_RECURSE HEADER_FILES ../include/console_canvas/*.h)
add_library(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY
  COMPILE_DEFINITIONS $<$<CONFIG:Debug>:_DEBUG>
)
