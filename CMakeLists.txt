cmake_minimum_required(VERSION 3.21)
project(BETweaker)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release)

file(GLOB_RECURSE SRC_FILES_DIR
        ${PROJECT_SOURCE_DIR}/BETweaker/*.cpp
        ${PROJECT_SOURCE_DIR}/BETweaker/*.hpp
        ${PROJECT_SOURCE_DIR}/BETweaker/*.h
        ${PROJECT_SOURCE_DIR}/BETweaker/Kernel/*.cpp
        ${PROJECT_SOURCE_DIR}/BETweaker/Kernel/*.hpp
        ${PROJECT_SOURCE_DIR}/BETweaker/Kernel/*.h
        ${PROJECT_SOURCE_DIR}/BETweaker/Main/*.cpp
        ${PROJECT_SOURCE_DIR}/BETweaker/Main/*.hpp
        ${PROJECT_SOURCE_DIR}/BETweaker/Main/*.h
        )

include_directories(${CMAKE_SOURCE_DIR}/SDK/Header)
include_directories(${CMAKE_SOURCE_DIR}/SDK/Header/third-party)

link_directories(.)
link_directories(${CMAKE_SOURCE_DIR}/SDK/Lib)

add_definitions(-D"NDEBUG" -D"TEMPLATE_EXPORTS" -D"WIN32_LEAN_AND_MEAN" -D"_CRT_SECURE_NO_WARNINGS" -D"_WINDOWS"
        -D"_USRDLL" -D"_AMD64_" -D"NOMINMAX" -D"_WINDLL" -D"_UNICODE" -D"UNICODE")

add_compile_options(
        /permissive- /GS /GL /W3 /Gy /Zc:wchar_t /Zi /Gm- /sdl /Zc:inline /fp:precise /errorReport:prompt /WX-
        /Zc:forScope /Gd /Oi /MD /std:c++20 /FC /EHsc /nologo /diagnostics:column
)

add_link_options(
        /MANIFEST /LTCG:incremental /NXCOMPAT /DEBUG /DLL /MACHINE:X64 /OPT:REF /INCREMENTAL:NO /SUBSYSTEM:CONSOLE
        /MANIFESTUAC:NO /OPT:ICF /ERRORREPORT:PROMPT /NOLOGO /DELAYLOAD:"bedrock_server.dll" /TLBID:1
)

add_library(BETweaker SHARED ${SRC_FILES_DIR} BETweaker/Kernel/AutoCrafting.cpp)

# target_link_libraries(BETweaker LiteLoader.lib
#         bedrock_server_api.lib
#         bedrock_server_var.lib
#         SymDBHelper.lib)
