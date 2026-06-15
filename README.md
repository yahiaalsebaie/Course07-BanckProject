# Course07 Bank Project & C++ Utility Toolbox

## 💎 Core Features & Architecture

The application is structured into a modular design split between a state-driven Console UI engine and customized logical backends:

1. **Main Management Menu**: Full CRUD subsystem allowing real-time actions:
   * View full structured clients records table.
   * Securely add new account holders.
   * Account eviction/deletion by unique Account Number.
   * Dynamic account updates.
   * Search and view detailed client profile cards.
2. **Dedicated Transactions Menu Subsystem**:
   * **Safe Deposits**: Real-time balance augmentation with automated ledger persistence.
   * **Fail-Safe Withdrawals**: Business logic validation preventing overdrafts by comparing requested amounts against the existing `AccountBalance`.
   * **Total Balances Accounting**: Algorithmic lookup tracking and summing total net liquidity held inside the bank registry.
3. **Robust Backend Driver**: Driven by strongly-typed `Enums` mapping application routing state, utilizing references to optimized `std::vector<stClientData>` to maintain high in-memory performance before syncing commits back to `Clients.txt`.

## 🛠️ Project Structure & Custom Libraries Overview

* **Main Execution Engine**: `Course07BankManagementSystem.cpp` implements the centralized control loop (`ShowMainMenuScreen` and `ShowTransactionsMenuScreen`), processing options using custom input ranges.
* **Customized Library Stack**:
  * `MyBankDataLib.h`: Custom record parsing, standard layout alignment, and direct disk file synchronization.
  * `MyInputLib.h`: Custom numeric range validation (`ReadNumberInRange`) guarding input interfaces against invalid data entry or software crashes.
  * `MyStringLib.h`: Optimized string operations utilizing safe right/left parsing boundaries.
---

## 🚀 Getting Started & Compilation

### Prerequisites
Ensure you have a modern C++ compiler supporting at least **C++17** (e.g., GCC/MinGW, MSVC, Clang).

### Manual CLI Compilation
To build and run the executable using the Windows PowerShell environment with GCC, execute the following from the repository root directory:

```bash
# Compile the executable with C++17 standard enabled targeting the current directory include paths
g++ -std=c++17 Course07BankManagementSystem.cpp -I . -o Course07Bank.exe

# Run the compiled binary on Windows
.\Course07Bank.exe
