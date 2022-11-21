cmake_minimum_required(VERSION 3.0...3.20 FATAL_ERROR)

project(LearOpenGL LANGUAGES CXX C)

find_package(OpenGL REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} )

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(3rdparty/glfw-3.3.8)
add_subdirectory(3rdparty/glm-0.9.9.8)

include_directories( 3rdparty/glad/include )
include_directories( 3rdparty/stb)
include_directories( 3rdparty/glm-0.9.9.8)

file(GLOB RES_FILES shader/*.fs shader/*.vs)

add_executable(learn_ogl
    ${RES_FILES}
    src/main.cpp
    src/glfw_callbacks.h
    src/glfw_callbacks.cpp
    src/gl_objects.h
    src/gl_objects.cpp
    src/logl_globals.h
    src/camera.h
    3rdparty/stb/stb_image.h
    3rdparty/glad/src/glad.c    
    src/shader_s.h)

if (WIN32)
    target_link_libraries(learn_ogl glfw ${OPENGL_LIBRARIES})
else() 
    target_link_libraries(learn_ogl glfw ${OPENGL_LIBRARIES} X11 pthread Xrandr Xi dl)
endif()


