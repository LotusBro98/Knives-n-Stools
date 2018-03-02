cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 17)



project(game)

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS})

include_directories(include)

set(RENDER_SOURCES
        src/render.cpp
)

set(GAME_SOURCES
        src/game.cpp
)

add_executable(game ${RENDER_SOURCES} ${GAME_SOURCES})

target_link_libraries(game ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} pthread)