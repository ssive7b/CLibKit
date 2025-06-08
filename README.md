# CLibKit

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))

A handy C library with all the essential functions you need for memory management, string handling, data structures, file operations, and more.

## What's This About?

CLibKit is a well-built C library that gives you a solid collection of utility functions for C programming. It's designed with clean code and reliability in mind, making it a great foundation for system programming, embedded projects, and everyday C applications.

## What You Get

### Main Features
- **Character Checks**: Functions to test if characters are letters, numbers, printable, etc.
- **Memory Tools**: Safe ways to allocate, copy, and work with memory
- **String Handling**: Everything you need to work with strings efficiently
- **Linked Lists**: Complete set of functions to create and manage linked lists
- **File Reading**: Read files line by line with configurable buffer sizes
- **Custom Printf**: Your own printf implementation with standard format support
- **Sorting**: Basic sorting functions for your data
- **Type Conversion**: Convert between different C data types

### Design Goals
- Works just like standard C library functions
- Memory-safe where possible
- No external dependencies needed
- Consistent error handling

## How to Install

```bash
# Get the code
git clone https://github.com/ssive7b/CLibKit.git

# Go into the folder
cd CLibKit

# Build the library
make

# You'll get libft.a ready to use
```

## How to Use It

### Adding to Your Project

1. **Include the headers:**
```c
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
```

2. **Compile with the library:**
```bash
gcc -o your_program source.c -L./CLibKit -lft
```

3. **Using Make:**
```makefile
LIBFT_PATH = ./CLibKit
CFLAGS += -I$(LIBFT_PATH)/include
LDFLAGS += -L$(LIBFT_PATH) -lft
```

### Quick Examples

#### Working with Strings
```c
#include "libft.h"

int main(void)
{
    // Clean up and split a string
    char *input = "  Hello, C World!  ";
    char *clean = ft_strtrim(input, " ");
    char **words = ft_split(clean, ' ');
    
    // Print each word
    for (int i = 0; words[i]; i++) {
        printf("Word %d: %s\n", i, words[i]);
        free(words[i]);
    }
    
    free(words);
    free(clean);
    return 0;
}
```

#### Using Linked Lists
```c
#include "libft.h"

typedef struct {
    int id;
    char *data;
} item_t;

void work_with_lists(void)
{
    t_list *list = NULL;
    
    // Add some items
    for (int i = 0; i < 5; i++) {
        item_t *item = malloc(sizeof(item_t));
        item->id = i;
        item->data = ft_itoa(i * 2);
        
        t_list *node = ft_lstnew(item);
        ft_lstadd_back(&list, node);
    }
    
    printf("List has %d items\n", ft_lstsize(list));
    
    // Clean up
    ft_lstclear(&list, free);
}
```

## Function Reference

### Character Functions
| Function | What it does | Returns |
|----------|-------------|---------|
| `ft_isalpha(int c)` | Checks if character is a letter | 1 if true, 0 if false |
| `ft_isdigit(int c)` | Checks if character is a digit | 1 if true, 0 if false |
| `ft_isalnum(int c)` | Checks if character is letter or digit | 1 if true, 0 if false |
| `ft_isascii(int c)` | Checks if character is ASCII | 1 if true, 0 if false |
| `ft_isprint(int c)` | Checks if character is printable | 1 if true, 0 if false |

### Memory Functions
| Function | What it does | Returns |
|----------|-------------|---------|
| `ft_memset(void *s, int c, size_t n)` | Fill memory with a value | Pointer to memory |
| `ft_bzero(void *s, size_t n)` | Fill memory with zeros | Nothing |
| `ft_memcpy(void *dst, const void *src, size_t n)` | Copy memory | Pointer to destination |
| `ft_memmove(void *dst, const void *src, size_t n)` | Copy memory safely | Pointer to destination |
| `ft_calloc(size_t count, size_t size)` | Allocate zeroed memory | Pointer to memory |

### String Functions
| Function | What it does | Returns |
|----------|-------------|---------|
| `ft_strlen(const char *s)` | Get string length | Length number |
| `ft_strchr(const char *s, int c)` | Find character in string | Pointer to char or NULL |
| `ft_strrchr(const char *s, int c)` | Find character from end | Pointer to char or NULL |
| `ft_strncmp(const char *s1, const char *s2, size_t n)` | Compare strings | Difference value |
| `ft_strlcpy(char *dst, const char *src, size_t size)` | Copy string safely | Source length |
| `ft_substr(char const *s, unsigned int start, size_t len)` | Get part of string | New string or NULL |
| `ft_strjoin(char const *s1, char const *s2)` | Join two strings | New string or NULL |
| `ft_split(char const *s, char c)` | Split string by character | Array of strings or NULL |

### List Functions
| Function | What it does | Returns |
|----------|-------------|---------|
| `ft_lstnew(void *content)` | Create new list node | New node or NULL |
| `ft_lstadd_front(t_list **lst, t_list *new)` | Add node to front | Nothing |
| `ft_lstadd_back(t_list **lst, t_list *new)` | Add node to back | Nothing |
| `ft_lstsize(t_list *lst)` | Count list items | Number of items |
| `ft_lstlast(t_list *lst)` | Get last item | Pointer to last item |
| `ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Apply function to all items | New list or NULL |

### File and Output Functions
| Function | What it does | Use for |
|----------|-------------|---------|
| `get_next_line(int fd)` | Read next line from file | Reading files line by line |
| `ft_printf(const char *format, ...)` | Print formatted text | Console output |
| `ft_dprintf(int fd, const char *format, ...)` | Print to file | File output, logging |

### Conversion Functions
| Function | What it does | Returns |
|----------|-------------|---------|
| `ft_atoi(const char *str)` | String to number | Integer value |
| `ft_itoa(int n)` | Number to string | New string or NULL |
| `ft_toupper(int c)` | Make uppercase | Uppercase character |
| `ft_tolower(int c)` | Make lowercase | Lowercase character |

## Want to Help?

Feel free to contribute! Just make sure to:
- Test your new code properly
- Add documentation for new functions
- Follow the existing code style

## License

This project uses the [MIT License](https://opensource.org/licenses/MIT) - check the [LICENSE](LICENSE) file for details.

## Technical Info

- **C Standard**: Works with C99
- **Platforms**: POSIX-compatible systems
- **Dependencies**: None needed
- **Build System**: Uses Make

---

**CLibKit** - Simple and reliable C utilities  
Last updated: June 8, 2025