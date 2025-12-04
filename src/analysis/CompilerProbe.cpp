#include <analysis/CompilerProbe.hpp>

CompilerProbe::CompilerProbe(std::string compiler) : compiler_cmd_(compiler) {}

std::string CompilerProbe::normalizeString(std::string s) {
  s.erase(
     std::remove_if(s.begin(), s.end(), 
        [](unsigned char x){ return std::isspace(x); }
     ), 
     s.end()
  );
  return s;
}

std::string CompilerProbe::exec(const std::string& cmd) {
  std::array<char, 256> buffer;
  std::string result;

  // Lambda as a deleter
  auto pipe_closer = [](FILE* f) {
    if(f) pclose(f);
  };
  
  // Open pipe and assign deleter so pipe will be destructed automaticly
  std::unique_ptr<FILE, decltype(pipe_closer)> pipe(popen(cmd.c_str(), "r"), pipe_closer);

  return "temp value";
}

std::vector<std::string> CompilerProbe::getSystemIncludes() {
  std::vector<std::string> flags;
  char buff[512]; // Single line buffer

  FILE* pipe;
  const char* cmd = "clang -E -x c++ - -v < dev/null";
  
  // Create pipe between program and command

  return std::vector<std::string>();
}
