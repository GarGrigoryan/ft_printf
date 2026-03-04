*This project has been created as part of the 42 curriculum by gargrigo.*

# ft_printf

## Description oooo

ft_printf is a custom implementation of the standard C printf() function from the C standard library.

The goal of this project is to recreate the behavior of printf() by handling formatted output and variable arguments using stdarg.h.

This project helps deepen understanding of:

- Variadic functions (va_list, va_start, va_arg, va_end)

- Format parsing

- String and number manipulation

- Low-level output using write()

## Instructions

To compile the library, run:

```bash
make
```

This will create a static library file named `libftprintf.a`.

### Usage

Include the header in your source code:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
cc your_program_name.c -L. -lftprintf
```

## Resources

### Documentation
- [The Open Group – printf Specification](https://pubs.opengroup.org/onlinepubs/9699919799/functions/printf.html)
- [GNU printf Documentation](https://www.gnu.org/software/libc/manual/html_node/Formatted-Output-Functions.html)
- [C stdarg.h Documentation](https://en.cppreference.com/w/c/variadic)

### References
- [C printf Reference (cppreference)](https://en.cppreference.com/w/c/io/fprintf)

### AI Usage

AI was used in the following parts of this project:

- **README.md creation**: AI assistance was used to structure and write the README.md file according to 42 School requirements, including formatting and section organization.

All code implementations were written manually by the student, with AI used only for creating README.md file and understanding requirements.
