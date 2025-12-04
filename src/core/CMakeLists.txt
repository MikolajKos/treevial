# --- 1. Creating static library for this module ---
add_library(core_lib STATIC
	Errors.cpp
)

# --- 2. Were headers can be found ---
target_include_directories(core_lib PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/.."
)
