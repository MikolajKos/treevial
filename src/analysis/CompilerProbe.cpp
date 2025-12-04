#include <analysis/CompilerProbe.hpp>

CompilerProbe::CompilerProbe(std::string compiler) : compiler_cmd_(compiler) {}

void CompilerProbe::normalizeString(std::string& s) {
  s.erase(
     std::remove_if(s.begin(), s.end(), 
        [](unsigned char x){ return std::isspace(x); }
     ), 
     s.end()
  );
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

  if(!pipe) {
    throw treevial::errors::AnalysisError("Could not run compiler process: " + cmd);
  }

  while(fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
  }
  
  return result;
}

std::vector<std::string> CompilerProbe::getSystemIncludes() {
  std::vector<std::string> flags;
  std::array<char, 256> buffer;

  std::string cmd = compiler_cmd_ + " -E -x c++ - -v < /dev/null 2>&1";

  std::string output = exec(cmd);
  std::stringstream ss(output);
  std::string line;

  bool capture = false;
  while(std::getline(ss, line)) {
    // Remove whitespaces for data compatibility
    normalizeString(line);
    
    if (line == "#include<...>searchstartshere:") {
      capture = true;
      continue;
    }

    if(capture && line == "Endofsearchlist.") {
      capture = false;
      break;
    }
    
    if(capture) {
      std::string flag = "-I" + line;
      flags.push_back(flag);
    }
  }

  return flags;
}

std::string CompilerProbe::getResourceDir() {
  std::string cmd = compiler_cmd_ + " -print-resource-dir";
  std::string path = exec(cmd);

  normalizeString(path);
  return path;
}

