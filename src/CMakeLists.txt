# --- 1. Add subcatalogs and (run CMakeLists.txt for each one) ---
add_subdirectory(analysis)
add_subdirectory(core)

# --- 2. Create executable ---
add_executable(trev main.cpp)

# --- 3. Create connection between program and all its modules ---
target_link_libraries(trev PRIVATE
	analysis_lib
	core_lib
)

# --- 4. Setting headers access ---
target_include_directories(trev PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
