# K&R C Programming - Exercises

My complete journey through "The C Programming Language" by Kernighan and Ritchie, with all exercises solved and documented.

## Who I Am

I am 14 years old and coming from a Python background. I decided to learn C the proper way - by working through K&R systematically - to understand how computers really work at the hardware level.

## Why K&R?

K&R is the definitive reference for learning C. It teaches you not just the syntax, but the philosophy behind the language. This is foundational knowledge that will serve me for any future work in systems programming.

## Development Environment

| Component | Details |
|-----------|---------|
| Hardware | Raspberry Pi 4B (ARM architecture) |
| Operating System | Linux |
| Compiler | GCC (GNU Compiler Collection) |
| Editor | Terminal + vim/nano |

This setup forces me to understand how C interacts directly with the OS and hardware, which is exactly what I want to learn.

## Progress Tracking

| Chapter | Topic | Status |
|---------|-------|--------|
| 1 | A Tutorial Introduction | Complete |
| 2 | Types, Operators, and Expressions | In Progress |
| 3 | Control Flow | Not Started |
| 4 | Functions and Program Structure | Not Started |
| 5 | Pointers and Arrays | Not Started |
| 6 | Structures | Not Started |
| 7 | Input and Output | Not Started |
| 8 | The UNIX System Interface | Not Started |

## How to Compile and Run

Each exercise is in its own file. To compile and run:

```bash
gcc chapter_01/exercise_1.c -o exercise_1
./exercise_1
```

## Code Organization

- Each chapter is in its own directory: `chapter_01/`, `chapter_02/`, etc.
- Each exercise is a separate `.c` file with a clear naming convention
- Every program includes:
  - Clear comments explaining the logic
  - Input/output examples in comments
  - Edge case handling where relevant
  - Personal notes on what I learned

## Exercise Documentation

### Exercise 2-5: Character Search Function

**File:** `exercise_2_05.c`

This exercise implements a function that searches for characters within strings.

**Macros:**
- `MAX` (200): Maximum buffer size for input lines

**Functions:**

- **`get_line(char s[])`** - Reads a line from standard input into the buffer
  - Reads characters until a newline character, EOF, or the buffer limit (MAX - 1) is reached
  - Ensures proper null-termination
  - Returns: The length of the string read (excluding the null terminator)

- **`any(char s1[], char s2[])`** - Finds the first location in string s1 where any character from s2 occurs
  - Mimics the standard C library function `strpbrk`, but returns an index instead of a pointer
  - Parameters:
    - `s1`: The main string to search through
    - `s2`: The string containing characters to look for
  - Returns: The index of the first match in s1, or -1 if no match is found

- **`main(void)`** - Main program entry point

## Key Concepts Being Learned

Coming from Python, these are the fundamental differences I'm working through:

1. **Manual Memory Management** - No garbage collection. I manage memory myself with malloc/free.
2. **Static Typing** - Every variable must be declared with a specific type before use.
3. **Pointers and References** - Understanding memory addresses and dereferencing operations.
4. **Low-Level Thinking** - How data is actually stored and accessed in memory.
5. **System Interaction** - How programs interact directly with the operating system.

## What Comes Next

This K&R foundation is the starting point. After completing all chapters, my focus will shift to:

1. **Embedded Systems** - Building real projects on Raspberry Pi with sensors and hardware control
2. **Data Structures and Algorithms** - Implementing fundamental CS concepts from scratch in C
3. **Compiler Design** - Understanding how programming languages are built and compiled

## Learning Philosophy

I believe that understanding foundations before abstractions is essential. That's why I'm investing the time to learn C systematically and deeply, rather than jumping to higher-level languages or frameworks.

## Feedback and Contributions

If you have suggestions for improvement or spot issues in the code, please open an issue. I'm focused on learning, not just getting the right answer.

## License

MIT License - See LICENSE file for details.
