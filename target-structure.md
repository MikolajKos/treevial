```bash
treevial/
├── CMakeLists.txt              # Main CMake configuration file
├── clang-toolchain.cmake       # Toolchain file (Clang on Windows)
├── .gitignore                  # Ignore build/, .vscode/, API keys
├── README.md                   # Project description
│
├── external/                   # External libraries (if not using FetchContent)
│   └── (optional, e.g., json.hpp, CLI11.hpp)
│
├── src/                        # Application source code
│   ├── main.cpp                # Entry point (CLI parsing and running the logic)
│   ├── CMakeLists.txt          # Configuration for source files
│   │
│   ├── cli/                    # Command-line interface handling
│   │   ├── CliParser.hpp       # Argument definitions (CLI11)
│   │   └── CliParser.cpp       # Argument validation logic
│   │
│   ├── core/                   # Main business logic
│   │   ├── AppEngine.hpp       # Central module connecting subsystems
│   │   └── AppEngine.cpp       # Execution flow (init -> analyze -> ask AI)
│   │
│   ├── analysis/               # Code analysis (libclang)
│   │   ├── CompilationDb.hpp   # Parsing compile_commands.json
│   │   ├── CompilationDb.cpp
│   │   ├── CodeAnalyzer.hpp    # libclang wrapper (diagnostics, visitor)
│   │   ├── CodeAnalyzer.cpp
│   │   ├── AstVisitor.hpp      # AST visitor (dependency collection)
│   │   └── AstVisitor.cpp
│   │
│   ├── api/                    # Communication with OpenAI
│   │   ├── OpenAiClient.hpp    # HTTP client (cpr/curl) and endpoint handling
│   │   ├── OpenAiClient.cpp
│   │   ├── PayloadBuilder.hpp  # JSON construction for API requests
│   │   └── PayloadBuilder.cpp
│   │
│   └── utils/                  # Utility functions
│       ├── FileManager.hpp     # File reading and content caching
│       ├── FileManager.cpp
│       ├── PathUtils.hpp       # Path normalization
│       └── StringUtils.hpp     # String helper operations
│
└── tests/                      # Test suite
    ├── CMakeLists.txt
    ├── run_tests.py            # Test runner script
    └── cases/                  # .cpp files used for testing
        ├── basic_error.cpp
        └── basic_error.expected.txt
```
