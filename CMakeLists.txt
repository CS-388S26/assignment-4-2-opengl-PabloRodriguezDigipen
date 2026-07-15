cmake_minimum_required(VERSION 3.5)

project(OpenGLIntro LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

add_executable(OpenGLIntro main.cpp)

target_include_directories(OpenGLIntro PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/glew-2.3.1/include
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/glfw-3.4.bin.WIN64/include
)

target_link_libraries(OpenGLIntro PRIVATE
    OpenGL::GL
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/glew-2.3.1/lib/Release/x64/glew32.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/glfw-3.4.bin.WIN64/lib-vc2022/glfw3.lib
)