cmake_minimum_required(VERSION 3.12)

project(OpenGL)

set(CMAKE_CXX_STANDARD 17)


include_directories(
	SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/include
)
link_directories(
	SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/lib
)

#将文件夹纳入到编译系统
add_subdirectory(src)

add_executable(OpenGL "main.cpp" "glad.c")

# 将lib连接入softRender
target_link_libraries(OpenGL glfw3.lib source)
