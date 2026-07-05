cmake_minimum_required(VERSION 3.20.4 FATAL_ERROR)

set(TARGET_NAME ShapesEngine3)

project(${TARGET_NAME})

if(MSVC)
    add_compile_options(/utf-8)
endif()

file (GLOB_RECURSE SRC_FILES 
    ${PROJECT_SOURCE_DIR}/src/*.h
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/submodules/tinyxml2/tinyxml2.h
    ${PROJECT_SOURCE_DIR}/submodules/tinyxml2/tinyxml2.cpp
)

add_executable(${TARGET_NAME} ${SRC_FILES})

foreach(source IN LISTS SRC_FILES)
    get_filename_component(source_path "${source}" DIRECTORY)
    string(REPLACE ${PROJECT_SOURCE_DIR} "" source_path "${source_path}")
    source_group("${source_path}" FILES "${source}")
endforeach()

target_compile_features(${TARGET_NAME} PUBLIC cxx_std_20)

set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)

add_subdirectory(submodules/SDL)
target_link_libraries(${TARGET_NAME} SDL3-static)

#add_subdirectory(external/glad)
#target_link_libraries(${TARGET_NAME} glad)

add_subdirectory(submodules/glm)
target_link_libraries(${TARGET_NAME} glm)

include_directories(src)
include_directories(submodules/SDL/include)
include_directories(submodules/glm)
include_directories(submodules/tinyxml2)
include_directories(submodules/spdlog/include)

include_directories(external/glad/include)

add_compile_definitions(_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING)
