#ifndef COMPILER_PROBE_HPP
#define COMPILER_PROBE_HPP

#include <algorithm>
#include <array>
#include <core/Errors.hpp>
#include <cstdio>
#include <cstdio>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

class CompilerProbe {
  std::string compiler_cmd_;
public:
  explicit CompilerProbe(std::string compiler = "/usr/bin/clang");
  
  std::vector<std::string> getSystemIncludes();
  std::string getResourceDir();
private:
  /**
  * @brief Normalizes a string by removing all whitespace characters.
  *
  * This function modifies the input string in place to remove any whitespace
  * characters (such as spaces, tabs, newlines, etc.) as defined by std::isspace.
  * A copy of the modified string is then returned.
  *
  * @param s The string to be normalized. Passed by value to allow for
  * in-place modification and subsequent return.
  * @return std::string The normalized string without any whitespace.
  */
  void normalizeString(std::string& s);

  std::string exec(const std::string& cmd);
};

#endif
