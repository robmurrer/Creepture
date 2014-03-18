# Hello World examples
include_directories (${Box2D_SOURCE_DIR})
add_executable(hallo HelloWorld.cpp)
target_link_libraries (hallo Box2D)
