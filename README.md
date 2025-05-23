# Command Line Interface (CLI)

A fully functional Unix-like Command Line Interface implemented in C++ with a deep focus on object-oriented design principles and paradigm, putting focus on decomposition, extensibility and clean architecture. 
Made with multi-layer architecture reflecting real-world compiler/interpreter design principles. 
Built-in support for pipeline execution, I/O redirection, and batch mode enables seamless command chaining, flexible input/output management and automated script processing.
Designed with robust error handling and validation subsystems and custom grammar, the CLI ensures reliability by detecting lexical, syntax, and semantic errors.

## Features

- **Layered architecture**   
  Built bottom-up through vertical layers of abstraction
  while employing a horizontal hierarchy that divides each layer into distinct,
  modular components to ensure clear separation of concerns and maintainability

- **15+ built-in commands**  
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

## Architecture

The CLI is designed with a clear, layered architecture that emphasizes modularity, separation of concerns, reusability and extensibility. It follows a bottom-up approach, starting from low-level lexical analysis and progressing through parsing, validation, command construction, and execution.

- **Vertical Layers of Abstraction:**  
  The system is organized into multiple layers, each responsible for a distinct phase of command processing:
  - **Tokenizing:** Converts raw input into tokens (lexems).
  - **Parsering:** Analyzes token sequences to form syntactic structures while searching for lexical errors.
  - **Validating:** Performs syntax and semantic checks based on custom CLI grammar to ensure command correctness.
  - **Command Building:** Constructs command objects based on validated input.
  - **Executing:** Executes commands and handles I/O and pipelines.

- **Horizontal Modularity:**  
  Within each layer, components are further divided into modules that encapsulate specific responsibilities, facilitating independent testing and easier maintenance.

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

