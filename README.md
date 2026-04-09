# libft--42

# 📚 Libft - 42 Project

## 🧠 Overview

Libft is the very first project in the 42 curriculum.
The goal is to recreate a custom C library by re-implementing standard functions from `<string.h>`, `<stdlib.h>`, and more.

This project helped me build a deep understanding of:

* Memory management
* String manipulation
* Linked lists
* Low-level programming in C

---

## 🚀 Features

### 🔹 Part 1 - Libc Functions

Re-implementation of standard C library functions :

* `ft_strlen`
* `ft_strchr`
* `ft_strrchr`
* `ft_strncmp`
* `ft_memset`
* `ft_bzero`
* `ft_memcpy`
* `ft_memmove`
* `ft_memchr`
* `ft_memcmp`
* `ft_strdup`
* `ft_atoi`
* `ft_calloc`

---

### 🔹 Part 2 - Additional Functions

* `ft_substr`
* `ft_strjoin`
* `ft_strtrim`
* `ft_split`
* `ft_itoa`
* `ft_strmapi`
* `ft_striteri`
* `ft_putchar_fd`
* `ft_putstr_fd`
* `ft_putendl_fd`
* `ft_putnbr_fd`

---
<!--
### 🔹 Bonus - Linked List Functions

* `ft_lstnew`
* `ft_lstadd_front`
* `ft_lstsize`
* `ft_lstlast`
* `ft_lstadd_back`
* `ft_lstdelone`
* `ft_lstclear`
* `ft_lstiter`
* `ft_lstmap`

---
-->

## 🛠️ Compilation

To compile the library:

```bash
make
```

This will generate:

```bash
libft.a
```

---

## 🧪 Usage

Include the header in your project:

```c
#include "libft.h"
```

Then compile with:

```bash
cc main.c libft.a
```

---

## 📁 Project Structure

```
.
├── Makefile
├── libft.h
├── ft_*.c
└── bonus/
```

---

## 📌 Notes

* All functions are written in pure C
* No use of standard library functions (unless allowed)
* Fully compliant with 42 Norm

---

## 💡 What I Learned

* How memory works in C
* Writing clean and reusable code
* Debugging segmentation faults
* Building a reusable library for future projects

---

## 🔗 Author

👤 Dracula Alhorany
💻 Software Engineering 

---

## 📘 Notes & Summary
You can find my detailed notes and explanations in this repository.
