cmake_minimum_required(VERSION 3.20.4 FATAL_ERROR)

set(TARGET_NAME ShapesEngine3)

project(${TARGET_NAME})

file (GLOB_RECURSE SRC_FILES 
    ${PROJECT_SOURCE_DIR}/src/*.h
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/submodules/tinyxml2/tinyxml2.h
    ${PROJECT_SOURCE_DIR}/submodules/tinyxml2/tinyxml2.cpp
    ${PROJECT_SOURCE_DIR}/submodules/stb/stb_image.h
)

add_executable(${TARGET_NAME} ${SRC_FILES})

foreach(source IN LISTS SRC_FILES)
    get_filename_component(source_path "${source}" DIRECTORY)
    string(REPLACE ${PROJECT_SOURCE_DIR} "" source_path "${source_path}")
    source_group("${source_path}" FILES "${source}")
endforeach()

if(MSVC)
    target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX)
    target_compile_options(${TARGET_NAME} PRIVATE /wd4100)
    target_compile_definitions(${TARGET_NAME} PRIVATE _CRT_SECURE_NO_WARNINGS)
    target_compile_options(${TARGET_NAME} PRIVATE /utf-8)
else()
    target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
    target_compile_options(${TARGET_NAME} PRIVATE -Wno-unused-parameter)
endif()

target_compile_features(${TARGET_NAME} PUBLIC cxx_std_20)

set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_X11_XSCRNSAVER OFF CACHE BOOL "" FORCE)
set(SDL_X11_XTEST OFF CACHE BOOL "" FORCE)

set(SPDLOG_BUILD_SHARED OFF CACHE BOOL "" FORCE)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

add_subdirectory(submodules/SDL)
target_link_libraries(${TARGET_NAME} SDL3-static)

add_subdirectory(submodules/glm)
target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/submodules/glm)

add_subdirectory(submodules/assimp)
target_link_libraries(${TARGET_NAME} assimp)

add_subdirectory(submodules/spdlog)
target_link_libraries(${TARGET_NAME} spdlog)

include_directories(src)
include_directories(submodules/SDL/include)
include_directories(submodules/glm)
include_directories(submodules/tinyxml2)
include_directories(submodules/spdlog/include)
include_directories(submodules/stb)
include_directories(submodules/assimp/include)

include_directories(external/glad/include)

add_compile_definitions(_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING)

get_target_property(SPDLOG_TYPE spdlog::spdlog TYPE)
message(STATUS "spdlog type: ${SPDLOG_TYPE}")
