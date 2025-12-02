treevial/
├── CMakeLists.txt              # Główny plik konfiguracyjny CMake
├── clang-toolchain.cmake       # Twój plik toolchain (dla Clanga na Windows)
├── .gitignore                  # Ignorowanie build/, .vscode/, kluczy API
├── README.md                   # Opis projektu
│
├── external/                   # Zewnętrzne biblioteki (jeśli nie używasz FetchContent)
│   └── (opcjonalnie, np. json.hpp, CLI11.hpp)
│
├── src/                        # Kod źródłowy aplikacji
│   ├── main.cpp                # Punkt wejścia (tylko parsowanie CLI i uruchamianie logiki)
│   ├── CMakeLists.txt          # Konfiguracja dla plików źródłowych
│   │
│   ├── cli/                    # Obsługa wiersza poleceń
│   │   ├── CliParser.hpp       # Definicja argumentów (CLI11)
│   │   └── CliParser.cpp       # Logika walidacji argumentów
│   │
│   ├── core/                   # Główna logika biznesowa
│   │   ├── AppEngine.hpp       # "Mózg" programu, łączy moduły
│   │   └── AppEngine.cpp       # Implementacja przepływu (init -> analyze -> ask AI)
│   │
│   ├── analysis/               # Analiza kodu (libclang)
│   │   ├── CompilationDb.hpp   # Parsowanie compile_commands.json
│   │   ├── CompilationDb.cpp
│   │   ├── CodeAnalyzer.hpp    # Wrapper na libclang (diagnostyka, wizytator)
│   │   ├── CodeAnalyzer.cpp
│   │   ├── AstVisitor.hpp      # Twój wizytator (zbieranie zależności)
│   │   └── AstVisitor.cpp
│   │
│   ├── api/                    # Komunikacja z OpenAI
│   │   ├── OpenAiClient.hpp    # Klient HTTP (cpr/curl) i obsługa endpointów
│   │   ├── OpenAiClient.cpp
│   │   ├── PayloadBuilder.hpp  # Tworzenie JSON-a dla API (kontekst + prompt)
│   │   └── PayloadBuilder.cpp
│   │
│   └── utils/                  # Funkcje pomocnicze
│       ├── FileManager.hpp     # Odczyt plików, cache'owanie treści
│       ├── FileManager.cpp
│       ├── PathUtils.hpp       # Normalizacja ścieżek
│       └── StringUtils.hpp     # Pomocnicze operacje na stringach
│
└── tests/                      # Testy (tak jak omawialiśmy)
    ├── CMakeLists.txt
    ├── run_tests.py            # Twój skrypt testowy
    └── cases/                  # Pliki .cpp do testowania
        ├── basic_error.cpp
        └── basic_error.expected.txt
