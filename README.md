# 🏦 Comprehensive Bank Management System & Extensions

A multi-phase **Bank Management System** developed as the capstone graduation projects within the C++ software engineering roadmap (Course 07: C++ Level 2 & Course 08: Algorithms & Data Structures Level 2) provided by **`ProgrammingAdvices`**.

The repository transitions seamlessly from a fundamental single-user transaction driver into an enterprise-grade console system integrated with strict user authentication, an immutable log system, and an algorithmic utility stack.

## 🌿 Repository Architecture & Branch Evolution

To inspect the development milestones, you can navigate across the following Git branches:

- **`main` / `Course07-Base`**: Contains the foundational financial ledger with client CRUD operations and core transaction handling.
    
- **`Bank-Extension-v1` (Current Branch)**: Implements advanced features from Course 08, adding employee management, user access control gates, and audit trails within the same core execution structure.

- **`Architecture:`** Built using **Procedural Programming**, focusing on functional decomposition with a strict separation between data and functions, and a direct process flow.

## 💎 Key Subsystems & Upgrades

### 1. Security & Identity Management (Course 08 Extension)

- **Granular Permissions Matrix**: Access controls calculated via a user permissions integer, blocking unauthorized employees from accessing management profiles or financial utilities.
    
- **System Audit Trail**: Fully automated logging system capturing every authorization event to `LoginRegister.txt` (Tracks: `Timestamp`, `Username`, `Password`, `Permissions Mask`).
    
- **Built-in Testing Credentials**:
    
    - **Username:** `Admin`
        
    - **Password:** `1234`
        

### 2. Core Ledger & Financial Subsystem (Course 07 Foundation)

- **Client Record Lifecycle**: Full CRUD operations parsing delimited database layouts directly into active memory vectors (`std::vector<stClientData>`).
    
- **Fail-Safe Transactions**: Multi-tier balance manipulation verifying ledger liquidity to strictly block illegal overdraft operations during dynamic withdrawals.
    

## 📂 Repository Structure & Toolbox Layout

The project features a flat architecture in its root directory, isolating logical subsystems into customized header toolboxes:

Plaintext

```
.
├── Course07BankManagementSystem.cpp  # Central Execution Engine & Routing System
├── Clients.txt                       # Flat-file database for simulated client records
├── Users.txt                         # Secure local user credentials and permissions data
├── MyBankDataLib.h                   # Specialized file I/O operations and parsing logic
├── MyInputLib.h                      # Input stream defense and numeric range boundary validation
├── MyStringLib.h                     # String tokenization and custom parsing logic
├── MyDateLib.h                       # Date management algorithms and calculations
├── MyArrayLib.h                      # Low-level array manipulation algorithms
├── MyMathLib.h                       # Math utility operations
├── MyUtilityLib.h                    # General-purpose program enhancement tools
├── MyVectorLib.h                     # Custom vector utility stack
└── Course07BanckProject.sln          # Central Visual Studio Solution File
```

## 🔒 Simulated Database & Security Compliance

- **Data Isolation**: Files like `Clients.txt` and `Users.txt` function strictly as local mock databases using custom field layout delimiters (`#//#`).
    
- No real financial credentials, actual banking numbers, or production-grade Personal Identifiable Information (PII) are processed or stored.
    

## 🚀 Build, Compilation & Execution

### Prerequisites

A compiler implementing the **C++17 standard** or later (GCC/MinGW, MSVC via Visual Studio).

### Native CLI Compilation

To build and compile the system manually using the standard GCC toolchain from your terminal, execute the following from the root directory:

Bash

```
# Compile using C++17 standard
g++ -std=c++17 Course07BankManagementSystem.cpp -I . -o Course07Bank.exe

# Launch the executable binary
.\Course07Bank.exe
```
