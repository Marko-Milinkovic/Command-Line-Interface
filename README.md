# Command Line Interface (CLI)

## Contents

1. [Introduction](#introduction)  
2. [Features](#features)  
3. [Command Reference](#command-reference)  
4. [Architecture](#architecture)  
5. [Concepts Overview](#concepts-overview)  
6. [Technical Overview](#technical-overview)  
7. [Build and Usage Instructions](#build-and-usage-instructions)  
   - [Build Requirements](#build-requirements)  
   - [Building the Project](#building-the-project)  
   - [Usage](#usage)  
8. [Roadmap](#roadmap)  
9. [Conclusion](#conclusion)

## Introduction

A fully functional Unix-like Command Line Interface implemented in C++ with a deep focus on object-oriented design principles and paradigm. 
Designed on a multi-layer architecture reflecting real-world compiler/interpreter design principles and leveraging proven design patterns to promote architectural clarity while keeping components reusable and loosely coupled. Built-in support for pipeline execution, I/O redirection, and batch mode enables seamless command chaining, flexible input/output management, and automated script processing. 
Implemented with robust error handling and validation subsystems with custom grammar, the CLI ensures reliability by detecting lexical, syntax, and semantic errors.

## Features

- **Layered architecture**   
  Built bottom-up through vertical layers of abstraction
  while employing a horizontal hierarchy that divides each layer into distinct,
  modular components to ensure clear separation of concerns and maintainability

- **10+ built-in commands**  
  Includes a diverse set of core utilities such as `echo`, `wc`, `tr`, `time`, `date`, `touch`, `truncate`, `rm`, `head`, and more.
  
- **Multi-stage command building and processing**  
  Commands go through lexical analysis, syntax parsing, semantic validation, building phase, and finally execution—mimicking compiler/interpreter pipelines

- **Support for I/O redirection (`<`, `>`, `>>`)**  
  Commands can read from and write to files via abstracted stream interfaces

- **Pipeline chaining (`|`)**  
  Enables Unix-style chaining of commands by linking dynamic stream buffers

- **Batch script execution**  
  Supports batch mode to process a list of commands from script files.

- **Robust error detection subsystems**  
  Full-stack detection with custom grammar and reporting of lexical, syntax and semantic errors ensures system reliability and user guidance
  
- **User-friendly error messages and interactive feedback**  
  Designed to help users quickly identify and correct input errors.

- **Design-first approach following fundamental principles of OOP**  
  Designed with strong emphasis on 4 core OOP principles, as well as separation of concerns, abstraction, algorithm and object decomposition, single-responsibility principles and other—ideal for scalability and future extension.

- **Use of design patterns**  
  Applies creational, structural and behavioral design patterns (e.g., Factory, Builder, Strategy, Bridge, Fascade) to promote loose coupling, flexibility and architectural clarity

## Command Reference

Below is a reference table listing all supported CLI commands, their descriptions, and usage examples.

| **Command**   | **Description**                                   | **Example**                         |
|---------------|---------------------------------------------------|-------------------------------------|
| `echo`        | Prints the given text to output                   | `echo Hello World`                  |
| `wc`          | Counts lines, words, or characters                | `wc -c < file.txt`                  |
| `tr`          | Translates or deletes characters in input         | `tr ":" "." < input.txt`           |
| `time`        | Displays current system time                      | `time`                              |
| `date`        | Displays current system date                      | `date`                              |
| `touch`       | Creates an empty file in current directory        | `touch file.txt`                   |
| `truncate`    | Clears contents of a file                         | `truncate file.txt`                |
| `rm`          | Removes (deletes) a file from current directory   | `rm file.txt`                      |
| `head`        | Displays the first N lines of a file              | `head -n 10 < file.txt`            |
| `prompt`      | Changes the CLI prompt text                       | `prompt MyShell>`                  |
| `batch`       | Executes commands from a batch file               | `batch script.txt`                 |
| `help`        | Displays help message or list of commands         | `help`                              |
| `clear`       | Clears the screen                                 | `clear`                             |
| `exit`        | Exits the CLI                                     | `exit`                              |

## Architecture

The CLI is designed with a clear, layered architecture that emphasizes modularity, separation of concerns, reusability and extensibility. It follows a bottom-up approach, starting from low-level lexical analysis and progressing through parsing, validation, command construction, and execution.

- **Vertical Layers of Abstraction:**  
  The system is organized into multiple layers, each responsible for a distinct phase of command processing:
  - **Tokenizing:** Converts raw input into tokens (lexems).
  - **Parsing:** Analyzes token sequences to form syntactic structures while searching for lexical errors.
  - **Validating:** Performs syntax and semantic checks based on custom CLI grammar to ensure command correctness.
  - **Command Building:** Constructs command objects based on validated input.
  - **Executing:** Executes commands and handles I/O and pipelines.

- **Horizontal Modularity:**  
  Within each layer, components are further divided into modules that encapsulate specific responsibilities, facilitating independent testing and easier maintenance.

## Concepts Overview

This project is grounded in core software engineering and design principles.

- **Object-Oriented Programming (OOP) Fundamentals**  
  Emphasizes the four pillars that form the backbone of the design:
  - **Encapsulation:** Bundling data and methods that operate on that data within classes, restricting direct access to some components.
  - **Abstraction:** Hiding complex implementation details behind simple interfaces to reduce complexity.
  - **Inheritance:** Establishing hierarchical relationships to promote code reuse and extend functionality.
  - **Polymorphism:** Enabling objects to be treated as instances of their parent class, allowing flexible and interchangeable behaviors.

- **Modularity and Encapsulation**  
  Components expose clear interfaces while hiding internal details, promoting modularity and reducing complexity.

- **Abstraction**
  - **Class as a realization of abstract type**
  - **Class as a realization of abstract data structure**
  - **Class as a realization of abstraction**
  - **Class as a realization of software (state) machine**
 
- **Substitution Principle**  
  Derived classes are designed to be substitutable for their base classes without altering the correctness of the program, ensuring that objects of subclasses can seamlessly replace objects of their parent 
  classes while maintaining expected behavior.

- **Separation of Concerns**  
  The system is decomposed both vertically (layered architecture) and horizontally (distinct responsibilities within layers), facilitating independent development and testing.

- **Single Responsibility Principle**  
  Each class or module has one clearly defined responsibility, enabling easier debugging, maintenance, and future expansion.

- **Design Patterns**  
  Strategic use of creational, structural, and behavioral design patterns to solve common design challenges, promote loose coupling, and improve code reuse:
  - **Creational Patterns:**  
    - *Singleton* for global command registry and static callback function registry  
    - *Builder* and *Abstract Factory* for CLI command creation
  - **Structural Patterns:**  
    - *Facade* to encapsulate the core engine complexity, providing a simple interface to users  
    - *Bridge* to connect CLI commands with their input/output handling strategies
  - **Behavioral Patterns:**  
    - *Command* pattern for representing and executing CLI commands  
    - *Visitor* pattern used for semantic validation of commands  
    - *Strategy* pattern for flexible IO handling of commands

- **Algorithm and Object Decomposition**  
  - Complex operations are divided into smaller, manageable algorithms to improve clarity and maintainability.  
  - System functionality is encapsulated within distinct objects, each responsible for specific tasks.

- **Robust Error Handling and Validation**  
  Incorporates multi-level error detection and handling to ensure system reliability and provide meaningful feedback to users.

This conceptual foundation supports the clean, scalable architecture and rich feature set of the CLI.


## Technical Overview

This project leverages modern C++ (C++11 and beyond) to deliver a clean, maintainable, and efficient codebase with strong performance characteristics. Key language features and paradigms used include:

- **Object-Oriented Programming (OOP)**  
  Encapsulation, inheritance, and polymorphism form the backbone of the architecture, enabling clear abstraction layers, reusable components, and extensibility.

- **Smart Pointers and RAII**  
  Usage of `std::unique_ptr` and `std::shared_ptr` ensures automatic and exception-safe resource management, preventing memory leaks and dangling pointers.

- **Standard Template Library (STL)**  
  Containers like `std::vector`, `std::string`, and `std::map` provide efficient, well-tested data structures for token storage, command lookup, and parsing operations.

- **Data Structures**  
  Implements linked lists, stacks, priority queues, and other classical data structures to support parsing, command queuing, and pipeline execution efficiently.

- **Static Members and Initialization**  
  Uses `static` variables and methods for centralized resource management, global state tracking, and initialization routines, ensuring controlled lifetime and thread safety where applicable.

- **Move semantics and rvalue references**  
  Utilized move semantics to optimize performance by eliminating unnecessary copies during object transfers.
  
- **Nested Structures and Classes**  
  Employs nested classes and structures to logically group related functionalities and improve encapsulation within complex components.

- **Exception Handling**  
  Robust error handling is implemented through C++ exceptions, facilitating clear separation between normal logic flow and error recovery.

- **Templates and Generic Programming**  
  Generic components improve code reuse and flexibility, especially in parsing utilities and command factory implementations.

- **Const-Correctness and References**  
  Careful use of `const` qualifiers and reference semantics enhance code safety, readability, and performance by avoiding unnecessary copies.

- **Lambda Expressions and Functional Constructs**  
  Used for concise callbacks, predicates, and algorithm customization, improving expressiveness and reducing boilerplate code.
  
- **Enum classes**
  Created scoped enums (enum class) for type-safe enumerations with limited scope.

## Build and Usage Instructions

### Build Requirements

To build the CLI application, ensure your system has the following installed:

- **C++11 or later** compliant compiler (e.g., `g++`, `clang++`)
- **CMake** (version 3.10 or higher recommended)
- **Make** (or Ninja, depending on your build preference)

## Building the Project

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/your-cli-project.git
   cd your-cli-project
   ```
2. **Create a build directory and generate build files:**
   ```bash
   mkdir build && cd build
   cmake .. 
   ```
3. **Compile the project:**
   ```bash
   make
   ```
4. **Run the executable:**
   ```bash
   ./cli
   ```
## Usage
Once launched, the CLI provides an interactive shell interface. You can begin entering commands directly.

### Examples

- Execute a simple command:
  ```bash
  echo "Hello, World!"
  ```
- View current date or time:
  ```bash
  date
  time
  ```
- Create and delete files:
  ```bash
  touch newfile.txt
  rm newfile.txt
  ```
- Input/Output Redirection
  ```bash
  wc -c < input.txt // read from a file
  echo Hello > output.txt // write to a file (overwrite)
  echo World >> output.txt // apend to a file
  ```
- Pipelining  
  Chain commands using the operator:
  ```bash
  time | tr ":" "." | wc -c
  ```
- Batchmode  
  Execute multiple commands from a file:
  ```bash
  batch script.txt
  ```
### Command formats

> **Note:** `[]` means optional. `argument` can be a string, a file, or—if not provided—will be read from the console.  
> **Special Note:** Redirection operators (`<`, `>`, `>>`) can only be placed at the **end** of the command line. 

| **Command** | **Format**                           |
|-------------|---------------------------------------|
| `echo`      | `echo [argument]`                         |
| `wc`        | `wc -opt [argument]`                |
| `tr`        | `tr [argument] what [what]`     |
| `time`      | `time`                                |
| `date`      | `date`                                |
| `touch`     | `touch filename`                        |
| `truncate`  | `truncate filename`                     |
| `rm`        | `rm filename`                           |
| `head`      | `head -ncount [argument]`                  |
| `prompt`    | `prompt argument`            |
| `batch`     | `batch [argument]`                 |
| `help`      | `help`                      |
| `clear`     | `clear`                               |
| `exit`      | `exit`                                |

## Roadmap

The following enhancements and features are planned for future releases:

- **Job Control & Background Execution**  
  - Support for running commands in the background using `&`, and job management commands (`jobs`, `fg`, `bg`).

- **Command Substitution & Shell Expansions**  
  - Allow expressions like ``echo $(date)`` and environment variable expansion (`$PATH`, `$HOME`).

- **Interactive Features**  
  - Command history with up/down arrow navigation.  
  - Tab-completion for commands, options, and file paths.

- **Advanced Scripting Support**  
  - Control structures (`if`, `while`, `for`) and function definitions in batch scripts.  
  - Variables and parameter expansion for more powerful automation.

- **Unit Testing & CI Integration**  
  - Comprehensive test suite (using Google Test or Catch2).  
  - Automated builds and tests via GitHub Actions or similar CI pipelines.

- **Performance & Resource Management**  
  - Benchmarking and profiling tools to identify and optimize hot paths.  
  - Improve memory footprint and execution throughput.

## Conclusion

This CLI project demonstrates a robust, extensible command-shell designed with industry-grade software engineering principles. With its layered architecture, comprehensive error handling, and support for pipelines, redirection, and batch scripting, it provides a solid foundation for real-world shell development. Future enhancements outlined in the roadmap will further expand its capabilities, making it an even more powerful and flexible tool. Contributions, feedback, and collaboration are welcome—please open issues or submit pull requests to help drive this project forward.  

