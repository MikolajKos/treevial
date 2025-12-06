#include <analysis/CompilationDb.hpp>

CompilationDb::CompilationDb(const fs::path& db_path) : db_path_(db_path) {}

std::vector<std::string> CompilationDb::getFlagsForFile() const {
  return std::vector<std::string>();
}

void CompilationDb::loadDatabase() {
  std::ifstream db_file(db_path_);
  if(!db_file) {
    throw treevial::errors::AnalysisError("Could not create JSON database file");
  }

  try {
    database_ = json::parse(db_file);
  }
  catch (const json::parse_error& e) {
    db_file.close();
    throw treevial::errors::AnalysisError("Could not parse JSON file");
  }
}

