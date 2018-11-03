add_subdirectory(igg_image)


include_directories(${PROJECT_SOURCE_DIR}/src/igg_image)

add_library(image image.cpp)
#add_executable(main main.cpp)
target_link_libraries(image ${TOOLS})