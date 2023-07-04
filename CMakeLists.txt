cmake_minimum_required(VERSION 3.21)

project(BETweaker)

set(BDS_VERSION "default" CACHE STRING "A string option for custom build")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/x64/)
set(TARGET_DIR ${CMAKE_SOURCE_DIR}/x64/Release/)

if(NOT BDS_VERSION STREQUAL "default")
    add_definitions(-D${BDS_VERSION})
endif()

file(GLOB_RECURSE SRC_FILES_DIR
    ${PROJECT_SOURCE_DIR}/src/*.c
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/*.h
)

include_directories(
    ${CMAKE_SOURCE_DIR}/SDK/include
    ${CMAKE_SOURCE_DIR}/include
)

link_directories(
    ${CMAKE_SOURCE_DIR}/SDK/lib
)

add_definitions(
    -D"NDEBUG"
    -D"NOMINMAX"
    -D"TEMPLATE_EXPORTS"
    -D"UNICODE"
    -D"WIN32_LEAN_AND_MEAN"
    -D"_AMD64_"
    -D"_CRT_SECURE_NO_WARNINGS"
    -D"_UNICODE"
    -D"_USRDLL"
    -D"_WINDLL"
    -D"_WINDOWS"
)

add_compile_options(
    /diagnostics:column
    /EHsc
    /FC
    /GL
    /MD
    /nologo
    /permissive-
    /sdl
    /utf-8
    /Zc:inline
    /Zi
)

add_link_options(
    /DEBUG
    /DELAYLOAD:"bedrock_server.dll"
    /DLL
    /IGNORE:4199
    /INCREMENTAL:NO
    /LTCG:INCREMENTAL
    /MANIFESTUAC:NO
    /MACHINE:X64
    /NOLOGO
    /OPT:ICF
    /OPT:REF
    /SUBSYSTEM:CONSOLE
)

add_library(${CMAKE_PROJECT_NAME} SHARED ${SRC_FILES_DIR})

target_link_libraries(${CMAKE_PROJECT_NAME} 
	"${CMAKE_SOURCE_DIR}/SDK/lib/LiteLoader.lib"
	"${CMAKE_SOURCE_DIR}/SDK/lib/bedrock_server_api.lib"
	"${CMAKE_SOURCE_DIR}/SDK/lib/bedrock_server_var.lib"
	"${CMAKE_SOURCE_DIR}/SDK/lib/SymDBHelper.lib"
    "${CMAKE_SOURCE_DIR}/lib/plhook.lib"
)


