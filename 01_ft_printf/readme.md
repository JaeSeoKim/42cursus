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

###  ✅ ToDo List

#### Infomation

>  Printf 사용법  `%[flags][width][.precision][extend_type]type`

| flags                         | extend_type          | type             |
| ----------------------------- | -------------------- | ---------------- |
| `-`, `0`, `+`, `<SPACE>`, `#` | `h`, `hh`, `l`, `ll` | `cspdiuxXnfgeo%` |

위에서 설명한  `[flags][width][.precision][extend_type]` 은 순서가 섞여있을 때에도 작동을 해야 함.

- [x] `c`
- [x] `s`
- [x] `p`
- [x] `d`
- [x] `i`
- [x] `u`
- [x] `x`
- [x] `x`
- [x] `n`
- [ ] `f`
- [ ] `g`
- [ ] `e`
- [x] `o`
- [x] `%`

  [참고 링크](https://dojang.io/mod/page/view.php?id=736)

  - [ ] **Mandatory part**

    **Format Specifier**

      - `%c` : char - 하나의 문자
      - `%s` : *char - 문자열
      - `%p` : *void - pointer 주소
      - `%d` : int - 부호가 있는 10진수 정수
      - `%i` : int - 부호가 있는 10진수 정수
      - `%u` : unsinged int : 부호 없는 10진 정수
      - `%x` : hexadecimal(int) : 부호 없는 16진 정수 (소문자 사용)
      - `%X` : hexadecimal(int) : 부호 없는 16진 정수 (대문자 사용)

    **Flag**

    - `-` : 왼쪽 정렬
    - `0` : 공백 대신 0으로 padding처리
    - `.` : 정밀도 숫자 서식에 관여
    - `*` : 가변인자로 width, precision의 크기가 들어옴

  - [ ] **Bonus part**

    **Format Specifier**

      - `%n` : int * - 인자로 들어온 포인터에 현재 까지 출력한 문자 갯수 저장
      - `%f` : double - 1.200000: 실수를 소수점으로 표기(소문자)
      - `%g` : double - 1.200000e+00: 실수 지수 표기법 사용(소문자)
      - `%e` : double - 1.2: %f와 %e 중에서 짧은 것을 사용(소문자)

    | *length* | `d i`           | `u o x X`                | `f F e E g G a A` | `c`      | `s`        | `p`     | `n`              |
    | -------- | --------------- | ------------------------ | ----------------- | -------- | ---------- | ------- | ---------------- |
    | *(none)* | `int`           | `unsigned int`           | `double`          | `int`    | `char*`    | `void*` | `int*`           |
    | `hh`     | `signed char`   | `unsigned char`          |                   |          |            |         | `signed char*`   |
    | `h`      | `short int`     | `unsigned short int`     |                   |          |            |         | `short int*`     |
    | `l`      | `long int`      | `unsigned long int`      |                   | `wint_t` | `wchar_t*` |         | `long int*`      |
    | `ll`     | `long long int` | `unsigned long long int` |                   |          |            |         | `long long int*` |

    **flag**

    - `+` : 양수 일때에는 + 음수일때에는 - 기호 출력
    - `공백` :  양수일때에는 부호를 출력 하지 않고 음수일때에만 - 기호 출력
    - `#` : 진법에 맞게 숫자 앞에 0, 0x, 0X를 출력

  - [ ] **Additional part**

    **Format Specifier**

    | *length* | `d i`       | `u o x X`      | `f F e E g G a A` | `c`   | `s`     | `p`     | `n`          |
    | -------- | ----------- | -------------- | ----------------- | ----- | ------- | ------- | ------------ |
    | *(none)* | `int`       | `unsigned int` | `double`          | `int` | `char*` | `void*` | `int*`       |
    | `j`      | `intmax_t`  | `uintmax_t`    |                   |       |         |         | `intmax_t*`  |
    | `z`      | `size_t`    | `size_t`       |                   |       |         |         | `size_t*`    |
    | `t`      | `ptrdiff_t` | `ptrdiff_t`    |                   |       |         |         | `ptrdiff_t*` |
    | `L`      |             |                | `long double`     |       |         |         |              |

- [ ] Format Parsing 방법 구상!

  printf에서 return 값은 최종적으로 완성된 문자열의 크기!

  결론적으로 format으로 들어온 값을 출력 하되 `%` 를 만나면 flag를 해석하여 write후 문자열 갯수 리턴이 필요! 

