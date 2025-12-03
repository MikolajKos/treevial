# --- 1. Creating static library for this module ---
add_library(analysis_lib STATIC
	CompilerProbe.cpp
)

# --- 2. Were headers can be found ---
target_include_directories(analysis_lib PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/.."
)

# --- 3. This module requires libclang ---
target_link_libraries(analysis_lib PRIVATE
	${LIBCLANG_LIBRARY}
)

# --- Add LLVM header catalogs (for clang-c/Index.h) ---
target_include_directories(analysis_lib PRIVATE ${LLVM_INCLUDE_DIRS})
