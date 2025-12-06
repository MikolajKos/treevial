#ifndef COMPILATION_DB_HPP
#define COMPILATION_DB_HPP

#include <filesystem>
#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>
#include <core/Errors.hpp>
#include <memory>

using json = nlohmann::json;
namespace fs = std::filesystem;

class CompilationDb {
  fs::path db_path_;
  json database_;
  bool loaded_;
public:
  CompilationDb(const fs::path& db_path);

  std::vector<std::string> getFlagsForFile() const;

private:
  void loadDatabase();
};

#endif
