*This project has been created as part of the 42 curriculum by spuschma.*

## Description
The goal of this project is to create a sort of *standard library* for future C projects. This is a purely educational exercise. Even the functions I tried to optimize are nowhere close to as optimized as any normal C standard library.

### Functions
All functions are declared in `libft.h`.

#### Part 1 - libc functions
Reimplementations of standard C library functions, with the same behavior as the originals.

**Character checks and conversion** (`ctype.h`)
| Function | Description |
|---|---|
| `ft_isalpha` | Checks if a character is a letter |
| `ft_isdigit` | Checks if a character is a digit (`0`-`9`) |
| `ft_isalnum` | Checks if a character is a letter or a digit |
| `ft_isascii` | Checks if a value is in the ASCII range (0-127) |
| `ft_isprint` | Checks if a character is printable, including space |
| `ft_toupper` | Converts a lowercase letter to uppercase |
| `ft_tolower` | Converts an uppercase letter to lowercase |

**Memory** (`string.h`, `strings.h`)
| Function | Description |
|---|---|
| `ft_memset` | Fills `n` bytes of memory with a byte value |
| `ft_bzero` | Sets `n` bytes of memory to zero |
| `ft_memcpy` | Copies `n` bytes from one memory area to another (areas must not overlap) |
| `ft_memmove` | Copies `n` bytes from one memory area to another, overlapping areas allowed |
| `ft_memchr` | Finds the first occurrence of a byte in `n` bytes of memory |
| `ft_memcmp` | Compares two memory areas byte by byte |

**Strings** (`string.h`)
| Function | Description |
|---|---|
| `ft_strlen` | Returns the length of a string |
| `ft_strlcpy` | Copies a string into a buffer of a given size, always null-terminating |
| `ft_strlcat` | Appends a string to a buffer of a given size, always null-terminating |
| `ft_strchr` | Finds the first occurrence of a character in a string |
| `ft_strrchr` | Finds the last occurrence of a character in a string |
| `ft_strncmp` | Compares up to `n` characters of two strings |
| `ft_strnstr` | Finds a substring within the first `len` characters of a string |

**Conversion and allocation** (`stdlib.h`, `string.h`)
| Function | Description |
|---|---|
| `ft_atoi` | Converts a string to an `int` |
| `ft_calloc` | Allocates memory for an array and sets it to zero |
| `ft_strdup` | Returns a newly allocated copy of a string |

#### Part 2 - Additional functions
Functions that are not part of libc, or differ from their libc counterparts. Functions that return a new string or array allocate it with `malloc`; the caller must free it.

| Function | Description |
|---|---|
| `ft_substr` | Returns a new string from `s`, starting at `start`, at most `len` characters long |
| `ft_strjoin` | Returns a new string made of `s1` followed by `s2` |
| `ft_strtrim` | Returns a copy of `s1` with the characters in `set` removed from both ends |
| `ft_split` | Splits a string by a delimiter character into a `NULL`-terminated array of strings |
| `ft_itoa` | Converts an `int` to a new string |
| `ft_strmapi` | Returns a new string made by applying `f` to each character (with its index) |
| `ft_striteri` | Applies `f` to each character of a string in place (with its index) |
| `ft_putchar_fd` | Writes a character to a file descriptor |
| `ft_putstr_fd` | Writes a string to a file descriptor |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor |
| `ft_putnbr_fd` | Writes an integer to a file descriptor |

#### Part 3 - Linked lists
Functions to build and manipulate singly linked lists. A list is made of `t_list` nodes, each holding a `void *content` and a `next` pointer to the following node, or `NULL` for the last one. Since the content is a `void *`, the list itself cannot know how to free it, so the functions that delete nodes take a `del` function that is applied to the content.

| Function | Description |
|---|---|
| `ft_lstnew` | Returns a new node holding `content`, with `next` set to `NULL` |
| `ft_lstadd_front` | Adds a node at the beginning of a list |
| `ft_lstsize` | Counts the nodes in a list |
| `ft_lstlast` | Returns the last node of a list |
| `ft_lstadd_back` | Adds a node at the end of a list |
| `ft_lstdelone` | Frees a single node and its content using `del`, leaving `next` untouched |
| `ft_lstclear` | Frees a node and all the nodes after it using `del`, then sets the list to `NULL` |
| `ft_lstiter` | Applies `f` to the content of every node of a list |
| `ft_lstmap` | Returns a new list made by applying `f` to the content of every node |

## Instructions
Building this library can be done using `make`. `make clean` removes old object files, `make fclean` removes object files and the library and `make re` cleans and then builds the library again.
To use the library `#include "libft.h` and compile with
```shell
cc main.c -I path/to/libft -L path/to/libft -lft
```

## Resources
- The libft subject PDF specifies some functions directly, for others it refers to man pages.

### AI Usage
All the code in this project is hand coded. **At no time did LLMs touch the code of this project!**
LLMs were occasionally used to speed up looking for information and for repetitive work like creating the list in this file.
At the final stage of the project a LLM was used to scan the codebase for bugs my tests didn't catch, but was instructed to just point them out, not fix them.
