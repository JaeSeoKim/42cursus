# printf

> "This project is pretty straight forward. You will recode printf. Hopefully you will be able to reuse it in future project without the fear of being flagged as a cheater. You will mainly learn how to use variadic arguments."
>
> #### 📝 PDF
>
> - [**`FILE LINK`**](../pdf/en.subject-ft_printf.pdf)

## 🚀 Content

### 🚩 Mandatory part

| Program name     | libftprintf.a                                                |
| ---------------- | ------------------------------------------------------------ |
| Turn in files    | *.c, */*.c, *.h, */*.h, Makefile                             |
| Makefile         | all, clean, fclean, re, bonus                                |
| External functs. | malloc, free, write, va_start, va_arg, va_copy, va_end       |
| Libft authorized | yes                                                          |
| Description      | Write a library that contains ft_printf, a function that will mimic the real printf |

- The prototype of ft_printf should be `int ft_printf(const char *, ...);`
- You have to recode the libc’s printf function
- It must not do the buffer management like the real printf
- It will manage the following conversions: `c` `s` `p` `d` `i` `u` `x` `X`
- It will manage any combination of the following flags: ’-0.*’ and minimum field width with all conversions
- It will be compared with the real printf
- You must use the command ar to create your librairy, using the command libtool is forbidden.

> man 3 printf / man 3 stdarg

### 🚩 Bonus part

- If the Mandatory part is not perfect don’t even think about bonuses
- You don’t need to do all the bonuses
- Manage one or more of the following conversions: nfge
- Manage one or more of the following flags: l ll h hh
- Manage all the following flags: ’# +’ (yes, one of them is a space)

### ✅ ToDo List

- [ ] #### Format specifiers 정리!

  - [ ] **Mandatory part**
    - [ ] `%c`
    - [ ] `%s`
    - [ ] `%p`
    - [ ] `%d`
    - [ ] `%i`
    - [ ] `%u`
    - [ ] `%x`
    - [ ] `%X`
  - [ ] **Bonus part**
  - [ ] **Additional part**

- [ ] #### Format Parsing 방법 구상!

- [ ] #### ...

