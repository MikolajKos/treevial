cmake_minimum_required(VERSION 3.20)
project(treevial)

set(CMAKE_CXX_STANDARD 20)

# ======================================================================
# LIBCLANG CONFIGURATION
# ======================================================================

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "LLVM Include Dir: ${LLVM_INCLUDE_DIRS}")

include_directories(${LLVM_INCLUDE_DIRS})

add_definitions(${LLVM_DEFINITIONS})

find_library(LIBCLANG_LIBRARY
	NAMES clang libclang
	HINTS ${LLVM_LIBRARY_DIRS})

if(NOT LIBCLANG_LIBRARY)
    message(FATAL_ERROR "libclang library not found!")
else()
    message(STATUS "Found libclang: ${LIBCLANG_LIBRARY}")
endif()

# ======================================================================
# DOXYGEN CONFIGURATION
# ======================================================================

find_package(Doxygen)

if (DOXYGEN_FOUND)
    message(STATUS "Doxygen executable found at: ${DOXYGEN_EXECUTABLE}")
    
    doxygen_add_docs(
        doc 
        "${CMAKE_SOURCE_DIR}/src" # Source directory to analyze
        
        COMMENT "Generating reference documentation for Treevial."
        
        # Internal Doxygen configuration settings
        Doxyfile_SET 
            PROJECT_NAME="Treevial Code Reference"
            RECURSIVE=YES                      # Scan subdirectories
            FILE_PATTERNS="*.cpp *.hpp"        # Files to include
            EXCLUDE_PATTERNS="*test*"          # Ignore test files
            OUTPUT_DIRECTORY="${CMAKE_BINARY_DIR}/docs" # Output location
    )

else (DOXYGEN_FOUND)
    message(WARNING "Doxygen not found. Documentation target 'doc' will not be generated.")
endif (DOXYGEN_FOUND)

# ======================================================================

# Executable declaration
add_executable(trev src/main.cpp)

find_package(nlohmann_json 3.2.0 REQUIRED)

target_link_libraries(trev PRIVATE ${LIBCLANG_LIBRARY} nlohmann_json::nlohmann_json)

# EOF

