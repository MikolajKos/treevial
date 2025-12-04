#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <stdexcept>
#include <string>

namespace treevial::errors {
  class AnalysisError : public std::runtime_error {
  public:
    explicit AnalysisError(const std::string& msg) : std::runtime_error("Analysis Error: " + msg) {}
  };
}

#endif
