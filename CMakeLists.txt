cmake_minimum_required (VERSION 3.6)
project (PuzzleGame)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
	src/main.cpp
    src/Game.h
    src/Game.cpp
    src/core/Window.h
    src/core/StbImage.h
    src/core/Texture.h
    src/core/Texture.cpp
)

add_executable(PuzzleGame ${SOURCE_FILES})

# Third Party libraries
set(OpenGL_GL_PREFERENCE "GLVND") # preference to the new openGL

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIRS})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(PuzzleGame
    ${SDL2_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${OPENGL_gl_LIBRARY}
    ${GLUT_LIBRARY}
)

