# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

project(mycc)

# compiler must be 11 or 14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)
# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)

find_package(Java)

include_directories(
        ${PROJECT_SOURCE_DIR}/grammar/gen
        ${PROJECT_SOURCE_DIR}/antlr/
        ${PROJECT_SOURCE_DIR}/antlr/antlr4-runtime/
        ${PROJECT_SOURCE_DIR}/src/utilities
        ${PROJECT_SOURCE_DIR}/src/Error
        ${PROJECT_SOURCE_DIR}/src/CodeGen
        ${PROJECT_SOURCE_DIR}/src/AST
        ${PROJECT_SOURCE_DIR}/src/
)

file(GLOB antlr4-cpp-src
    ${PROJECT_SOURCE_DIR}/antlr/antlr4-runtime/*.cpp
    ${PROJECT_SOURCE_DIR}/antlr/antlr4-runtime/atn/*.cpp
    ${PROJECT_SOURCE_DIR}/antlr/antlr4-runtime/dfa/*.cpp
    ${PROJECT_SOURCE_DIR}/antlr/antlr4-runtime/misc/*.cpp
    ${PROJECT_SOURCE_DIR}/antlr/antlr4-runtime/support/*.cpp
    ${PROJECT_SOURCE_DIR}/antlr/antlr4-runtime/tree/*.cpp
    ${PROJECT_SOURCE_DIR}/antlr/antlr4-runtime/tree/pattern/*.cpp
    ${PROJECT_SOURCE_DIR}/antlr/antlr4-runtime/tree/xpath/*.cpp
)
add_library(antlr4-cpp-runtime ${antlr4-cpp-src})

if (NOT ${PROJECT_SOURCE_DIR}/grammar/gen)
    file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/grammar/gen)
endif ()

set(ANTLR_EXECUTABLE ${CMAKE_SOURCE_DIR}/antlr/antlr-4.9.2-complete.jar)
execute_process(
        WORKING_DIRECTORY
        ${PROJECT_SOURCE_DIR}/grammar/
        # Note that this command runs in pure shell
        COMMAND
        java -jar ${ANTLR_EXECUTABLE} -Dlanguage=Cpp -no-listener -visitor -o gen C.g4
)

file(GLOB src_dir
        ${PROJECT_SOURCE_DIR}/grammar/gen/CLexer.cpp
        ${PROJECT_SOURCE_DIR}/grammar/gen/CParser.cpp
        ${PROJECT_SOURCE_DIR}/grammar/gen/CVisitor.cpp
        ${PROJECT_SOURCE_DIR}/grammar/gen/CBaseVisitor.cpp
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/src/AST/*.cpp
        ${PROJECT_SOURCE_DIR}/src/utilities/*.cpp
        ${PROJECT_SOURCE_DIR}/src/Error/*.cpp
        ${PROJECT_SOURCE_DIR}/src/CodeGen/*.cpp
        )

add_executable(${PROJECT_NAME} ${src_dir})
target_link_libraries(${PROJECT_NAME} antlr4-cpp-runtime)

# Add custom target update_antlr, use `make update_antlr` to update your lexer & grammar rules anytime
add_custom_target(update_antlr
        WORKING_DIRECTORY
        ${PROJECT_SOURCE_DIR}/grammar/
        COMMAND
        java -jar ${ANTLR_EXECUTABLE} -Dlanguage=Cpp -no-listener -visitor -o gen C.g4
        COMMENT
        "Auto updates for developing antlr grammar"
        )