*This project has been created as part of the 42 curriculum by ayouel-h.*

# Libft

## Description

Libft is a personal C library built from scratch for the 42 curriculum.
The goal of the project is to reimplement a set of standard libc functions
and add general-purpose utility functions (string, memory and linked-list
helpers) that will be reused in all future projects of the curriculum.

Everything is written in C, in accordance with the 42 school Norm (the
`:42` header style, 25-line functions, etc.), and compiled with
`-Wall -Wextra -Werror`.

## The library

### Part 1 — Libc functions

Reimplementations of libc functions with the `ft_` prefix, following their
man page behavior:

`ft_isalpha` `ft_isdigit` `ft_isalnum` `ft_isascii` `ft_isprint`
`ft_strlen` `ft_memset` `ft_bzero` `ft_memcpy` `ft_memmove` `ft_strlcpy`
`ft_strlcat` `ft_toupper` `ft_tolower` `ft_strchr` `ft_strrchr`
`ft_strncmp` `ft_memchr` `ft_memcmp` `ft_strnstr` `ft_atoi` `ft_calloc`
`ft_strdup`

### Part 2 — Additional functions

Utility functions that do not exist in the libc or behave differently:

- `ft_substr` — extracts a substring starting at `start` of max length `len`
- `ft_strjoin` — concatenates two strings into a new string
- `ft_strtrim` — trims characters of `set` from both ends of a string
- `ft_split` — splits a string on a delimiter into a NULL-terminated array
- `ft_itoa` — converts an integer to its string representation
- `ft_strmapi` — applies a function (with index) to each char, new string
- `ft_striteri` — applies a function (with index) to each char, in place
- `ft_putchar_fd` / `ft_putstr_fd` / `ft_putendl_fd` / `ft_putnbr_fd`
  — output a char, string, string + newline, or integer to a file descriptor

### Part 3 — Linked list

A simple singly linked list built on the `t_list` type declared in
`libft.h` (members: `content`, a `void *` to any data, and `next`):

`ft_lstnew` `ft_lstadd_front` `ft_lstsize` `ft_lstlast` `ft_lstadd_back`
`ft_lstdelone` `ft_lstclear` `ft_lstiter` `ft_lstmap`

## Instructions

Requirements: `cc`, `make` and `ar`.

```sh
make        # build libft.a at the root of the repository
make clean  # remove object files
make fclean # remove object files and libft.a
make re     # fclean + make
```

Usage example:

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -o program
```

```c
#include "libft.h"

int main(void)
{
	ft_putstr_fd("hello from libft\n", 1);
	return (0);
}
```

## Resources

- man pages of the reimplemented libc functions (`man 3 strlen`, etc.)
- [The Norm](https://www.intra.42.fr) — 42 school coding standard
- [openbsd strlcpy/strlcat paper](https://man.openbsd.org/strlcpy) —
  used as reference for the `ft_strlcpy` / `ft_strlcat` semantics
- [Tripouille/libftTester](https://github.com/Tripouille/libftTester) —
  tester used to validate the library

### How AI was used

AI tools were used as support, not to write the project: all functions
were implemented by the project author. AI was used to:

- check Norm compliance and fix formatting issues (`norminette` findings);
- clean up `libft.h` (remove an unused include, add missing prototypes);
- run student testers and an additional sanitizer-based edge-case test
  suite, and summarize the results in a test report;
- draft this README.
