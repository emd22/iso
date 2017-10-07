cmake_minimum_required(VERSION 3.5)

file (GLOB_RECURSE SOURCES "*.cpp")
file (GLOB_RECURSE HEADERS "../include/game/*.hpp")

SET(GCC_COVERAGE_COMPILE_FLAGS "-g -std=c++11")

find_library(opengl GL)
find_library(freeglut glut)
find_library(sdl_image SDL2_image)
find_library(libglew GLEW)
find_library(sdl SDL2)

foreach(f IN LISTS SOURCES)
  get_filename_component(b ${f} NAME)
  set_source_files_properties(${f} PROPERTIES
    COMPILE_DEFINITIONS "__FILENAME__=${b}")
endforeach()
foreach(f IN LISTS HEADERS)
  get_filename_component(b ${f} NAME)
  set_source_files_properties(${f} PROPERTIES
    COMPILE_DEFINITIONS "__FILENAME__=${b}")
endforeach()

include_directories(
  ${CMAKE_CURRENT_LIST_DIR}/../include/game
)
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

add_executable(game ${SOURCES} ${HEADERS})

target_link_libraries(game ${opengl} ${libglew} ${freeglut} ${sdl_image} ${sdl})

# execute_process(COMMAND glxosd ../build/game)