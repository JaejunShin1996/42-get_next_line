# Get Next Line - Reading a Line from a File Descriptor

## Project Overview

**Get Next Line** is a project aimed at developing a function that reads and returns a single line from a given file descriptor. The function is designed to be called repeatedly, allowing the reading of a file or input stream one line at a time. This project introduces the use of static variables in C programming, a crucial concept for managing persistent state across function calls.

The `get_next_line` function is efficient and versatile, handling files and standard input while adhering to performance constraints.

---

## Key Features

- **Function Prototype**: `char *get_next_line(int fd);`
- **Core Functionality**:
  - Reads a line from a file descriptor and returns it, including the newline character.
  - Handles repeated calls, allowing the reading of a file or input stream line by line.
  - Returns `NULL` when there is nothing left to read or an error occurs.

---

## Technical Details

- **Static Variables**: Utilized to maintain the state of the file reading process across multiple calls to `get_next_line()`.
- **Buffer Management**: A buffer size is defined at compile-time (modifiable via the `-D BUFFER_SIZE` flag) to control the amount of data read in each system call.
- **Error Handling**: The function gracefully handles file reading errors and end-of-file conditions.

### Supported Scenarios:
- **File Reading**: Works with any file descriptor, returning one line at a time until the end of the file is reached.
- **Standard Input**: Can be used to read from standard input in real-time (e.g., terminal input).
- **Line Termination**: Ensures that lines are properly terminated with a newline character, unless the file ends without one.

---

## Skills Demonstrated

- **Static Variables**: Gained a deep understanding of static variables and how they can be used to retain state across multiple function calls.
- **File I/O Management**: Developed efficient reading mechanisms that minimize unnecessary system calls while handling various file descriptor types.
- **Memory Management**: Ensured that all dynamically allocated memory was properly freed to avoid memory leaks.
- **Modular Programming**: Organized the code into separate files (`get_next_line.c`, `get_next_line_utils.c`) for better maintainability and clarity.

---

## Conclusion

The **Get Next Line** project provided hands-on experience in file I/O and memory management in C. The function I developed is a valuable addition to my collection of utility functions and can be used in various future projects where file or input stream reading is required.

