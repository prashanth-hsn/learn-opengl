cmake_minimum_required(VERSION 3.0...3.20 FATAL_ERROR)

project(LearOpenGL LANGUAGES CXX C)

find_package(OpenGL REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} )

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(3rdparty/glfw-3.3.8)

include_directories( 3rdparty/glad/include )

add_executable(learn_ogl
    src/main.cpp
    src/glfw_callbacks.h
    src/glfw_callbacks.cpp
    src/gl_objects.h
    src/gl_objects.cpp
    3rdparty/glad/src/glad.c)

target_link_libraries(learn_ogl glfw ${OPENGL_LIBRARIES} X11 pthread Xrandr Xi dl)

