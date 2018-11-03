#################### Import the 'io_tools' library here ########################
find_library(TOOLS
			 NAMES io_tools
			 PATHS ${LIBRARY_OUTPUT_PATH})


#################### Create a library 'image' below this line ##################
include_directories(${PROJECT_SOURCE_DIR}/src/igg_image)

#add_library(image image.cpp)
#add_executable(main main.cpp)
#target_link_libraries(main image ${TOOLS})