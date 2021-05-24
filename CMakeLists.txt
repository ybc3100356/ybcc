# CMakeLists.txt
cmake_minimum_required(VERSION 3.7)

project(mycc)
set(TEST_EXAMPLE tinycc)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# compiler must be 11 or 14
set(CMAKE_CXX_STANDARD 14)

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)
# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)
# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

set(ANTLR_EXECUTABLE ${CMAKE_SOURCE_DIR}/antlr/antlr-4.9.2-complete.jar)
# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR REQUIRED)

antlr_target(CParser ${CMAKE_SOURCE_DIR}/grammar/C.g4 LEXER PARSER
        PACKAGE c_grammar
        VISITOR)

antlr_target(TinyCParser ${CMAKE_SOURCE_DIR}/grammar/TinyC.g4 LEXER PARSER
        PACKAGE tinyc_grammar
        VISITOR)

# include generated files in project environment
include_directories(${ANTLR_CParser_OUTPUT_DIR})
include_directories(${ANTLR_TinyCParser_OUTPUT_DIR})

# add generated grammar to demo binary target
add_executable(${PROJECT_NAME} mycc.cpp
        ${ANTLR_CParser_CXX_OUTPUTS}
        )

add_executable(${TEST_EXAMPLE} tinycc.cpp
        ${ANTLR_TinyCParser_CXX_OUTPUTS}
        )

target_link_libraries(${PROJECT_NAME} antlr4_static)
target_link_libraries(${TEST_EXAMPLE} antlr4_static)
