# Command Line Interface (CLI)

A fully functional Unix-like Command Line Interface implemented in C++ with a deep focus on object-oriented design principles and paradigm, putting focus on decomposition, extensibility and clean architecture. 
Made with multi-layer architecture reflecting real-world compiler/interpreter design principles. 
Built-in support for pipeline execution, I/O redirection, and batch mode enables seamless command chaining, flexible input/output management and automated script processing.
Designed with robust error handling and validation subsystems and custom grammar, the CLI ensures reliability by detecting lexical, syntax, and semantic errors.

---

### Features

- **Layered architecture**
  Built bottom-up through vertical layers of abstraction—from low-level,
  compiler-inspired parsing to fully realized CLI commands—while employing a horizontal hierarchy that divides each layer into distinct,
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

- **Design-first approach following fundamental principles of OOP**  
  Designed with strong emphasis on 4 core OOP principles, as well as separation of concerns, abstraction, algorithm and object decomposition, single-responsibility principles and other—ideal for scalability and future extension.

- **Use of design patterns**  
  Applies creational, structural and behavioral design patterns (e.g., Factory, Builder, Strategy, Bridge, Fascade) to promote loose coupling, flexibility and architectural clarity
