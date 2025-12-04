#include <iostream>
#include <analysis/CompilerProbe.hpp>
#include <string>

int main() {
  CompilerProbe cp;
  std::vector<std::string> prot_res = cp.getSystemIncludes();

  for(size_t i = 0; i < prot_res.size(); ++i) {
    std::cout << prot_res.at(i) <<"\n";
  }

  std::cout << "\n";

  std::cout << cp.getResourceDir();
  
  return 0;
}
