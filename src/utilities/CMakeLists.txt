project(utilities)
aux_source_directory(. UTILITIES_SRC_FILES)
add_library(${PROJECT_NAME} SHARED ${UTILITIES_SRC_FILES})