# CSC450: Programming III — Critical Thinking 2

**Student Name:** Ryley Carlson
**Course:** CSC450 - Programming III (Module 2)
**Development Environment:** Visual Studio Code (C/C++ Extension Pack)
**Compiler Toolchain:** GCC / G++ Cross-Platform Environment

---

## Project Overview

This repository contains the complete deliverables for the Module 2 Critical Thinking assignment. The project focuses on safe text stream operations and advanced input data management:

1. **Apollo 11 Telemetry Application (`apollo11_string_app.cpp`):** A secure console application built to capture, sanitize, and concatenate Mission Control uplinks and spacecraft downlinks across three distinct phases of the 1969 lunar landing.
2. **Architectural Pseudocode (`apollo11_string_app_pseudocode.txt`):** A high-level logical system design blueprint tracking loop execution vectors and memory validation boundaries before running string updates.

---

## Hardware Optimization Note

While Eclipse IDE was originally recommended for this course, it utilizes a heavy GUI runtime framework that creates an overwhelming processing overhead on integrated graphics processing units (such as the legacy Intel HD 530 architecture). To mitigate UI thread blocking, asset delay bottlenecks, and local development system lag, this entire project environment was migrated to a highly optimized Visual Studio Code workspace configuration.

---

## Compilation and Execution Instructions

To compile and run the source file manually via your local native terminal framework, execute the following compiler commands:

### 1. Apollo 11 Telemetry Application
```bash
g++ -std=c++11 -Wall apollo11_string_app.cpp -o apollo11_string_app
./apollo11_string_app
```

---

## Identified Bug Fixes & Security Enhancements

### apollo11_string_app.cpp Features:
* **Mitigated Memory Buffer Overflows:** Replaced dangerous legacy C-style character arrays (`char buffer[N]`) and functions like `strcpy()` or `strcat()` with heap-managed `std::string` containers to block stack-smashing vectors (CWE-787).
* **Safe Stream Ingestion:** Swapped out primitive `std::cin >>` extractors for `std::getline()` to securely parse multi-word aerospace entries without breaking execution loops on empty whitespace characters.
* **Advanced Input Sanitization Engine:** Integrated a custom character validation pass utilizing runtime ASCII range boundary loops to actively strip out malicious non-printable control characters and escape sequences.
* **Resolved Terminal Buffer Traps:** Patched the initial `std::getline()` phase-one loop with a leading whitespace delimiter hook (`std::cin >> std::ws`) to safely drop lingering shell arguments and auto-pasted debugger file paths generated during VS Code startup routines.