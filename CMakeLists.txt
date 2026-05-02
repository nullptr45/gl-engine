cmake_minimum_required(VERSION 3.16)
project(gl-engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE GL_ENGINE_SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_executable(gl-engine ${GL_ENGINE_SOURCES})

add_subdirectory(external/glad)
add_subdirectory(external/glfw)

target_include_directories(gl-engine PUBLIC src)
target_link_libraries(gl-engine glfw glad)
