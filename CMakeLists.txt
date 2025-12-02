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

# Executable declaration
add_executable(trev src/main.cpp)

find_package(nlohmann_json 3.2.0 REQUIRED)

target_link_libraries(trev PRIVATE ${LIBCLANG_LIBRARY} nlohmann_json::nlohmann_json)

# EOF

