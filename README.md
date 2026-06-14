# Course07 Bank Project & C++ Utility Toolbox

A comprehensive, production-grade C++ banking management system and utility toolkit built as part of advanced foundational software architecture training. This repository features custom, header-only libraries optimizing algorithmic math operations, vector manipulations, safe text handling, data persistence, and secure console-based input/output operations.

---

## 🛠️ Project Structure & Architectural Overview

The repository is organized as a lightweight flat structure for header-only distribution, targeting rapid integration and test verification:

* **Core Application**: `ConsoleApplication3.cpp` serves as the main execution engine managing the Bank Management System console workflow.
* **Bank Subsystem**: `MyBankDataLib.h` handles account records parsing, data streaming, file persistence, and data schema logic utilizing `Clients.txt`.
* **Utility Stack**: A collection of decoupled, header-only helper modules targeting specialized domains:
  * `MyInputLib.h` / `myCpp5AllFuncLib.h`: Advanced, fail-safe console input validations and primitive operations.
  * `MyMathLib.h`: Highly-optimized arithmetic algorithms and mathematical computations.
  * `MyArrayLib.h` & `MyVectorLib.h`: Custom, memory-safe wrappers for arrays and dynamic arrays processing.
  * `MyStringLib.h` & `MyUtilityLib.h`: Optimized string sanitization, parsing, formatting, and general programmatic toolsets.

---

## 🚀 Getting Started & Compilation

### Prerequisites
Ensure you have a modern C++ compiler supporting at least **C++17** (e.g., GCC/MinGW, MSVC, Clang).

### Manual CLI Compilation
To build and run the executable using the Windows PowerShell environment with GCC, execute the following from the repository root directory:

```bash
# Compile the executable with C++17 standard enabled targeting the current directory include paths
g++ -std=c++17 ConsoleApplication3.cpp -I . -o Course07Bank.exe

# Run the compiled binary on Windows
.\Course07Bank.exe
