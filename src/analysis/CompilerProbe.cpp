#include <analysis/CompilerProbe.hpp>

std::string CompilerProbe::normalize_string(std::string s) {
  s.erase(
     std::remove_if(s.begin(), s.end(), 
        [](unsigned char x){ return std::isspace(x); }
     ), 
     s.end()
  );
  return s;
}

std::vector<std::string> CompilerProbe::get_CompilerFlags() {
  std::vector<std::string> flags;
  char buff[512]; // Single line buffer

  FILE* pipe;
  const char* cmd = "clang -E -x c++ - -v < dev/null";
  
  // Create pipe between program and command
  
}
