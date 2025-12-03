#ifndef COMPILER_PROBE_HPP
#define COMPILER_PROBE_HPP

#include <vector>
#include <algorithm>
//TEMPORARY CHECK
#include <clang-c/Index.h>

class CompilerProbe {
public:
  std::vector<std::string> get_SystemHeaderFlags();
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
  std::string normalize_string(std::string s);
};

#endif
