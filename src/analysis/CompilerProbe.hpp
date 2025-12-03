#ifndef COMPILER_PROBE_HPP
#define COMPILER_PROBE_HPP

#include <vector>
#include <algorithm>

class CompilerProbe {
public:
  std::vector<std::string> get_SystemHeaderFlags();
private:
  std::string normalize_string(std::string s);
};

#endif
