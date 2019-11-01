# LIBFT 42
## What is libft?

Libft is an individual project at 42 that requires us to re-create some standard C library functions including some additional ones that can be used later to build a library of useful functions for the rest of the program.

Disclaimer: Reinventing the wheel is bad, 42 makes us do this just so we can have a deeper understanding of data structures and basic algorithms. At 42 we're not allowed to use some standard libraries on our projects, so we have to keep growing this library with our own functions as we go farther in the program.

## List function
|string|print|memory|math|libft_list|is_methode|flags|divers|bytes_tools|stdio|regex|
|------|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|
|ft_tabdel|ft_putwchar_fd|ft_realloc|ft_sqrt|ft_lstnew|ft_toupper|init_flags|timestamp|ft_print_memory|ft_printf|ft_regex_exec|
|ft_strxfrm|ft_putwchar|ft_memset|ft_recursive_power|ft_lstmap|ft_tolower|print_usage|nlen_wchar|ft_option|ft_dprintf|ft_regex_free|
|ft_strupcase|ft_putstrw_fd|ft_memnew|ft_recursive_factorial|ft_lstiter|ft_isxdigit|init_usage|len_wchar_single|ft_create_bytes_tab|ft_sprintf|ft_regex_print|
|ft_strtrim|ft_putstrw|ft_memmove|ft_pow|ft_lstdelone|ft_isword|get_flags_av|len_wchar|ft_reverse_bytes||ft_regex_replace|
|ft_strtok|ft_putstr_fd|ft_memdel|ft_iterative_power|ft_lstdel|ft_isuppercase|remove_flags|get_next_line||||
|ft_strsub|ft_putstr|ft_memcpy|ft_iterative_factorial|ft_lstadd|ft_isspace|exist_flags|ft_tablen||||
|ft_strstr|ft_putpstr_fd|ft_memcmp|ft_is_prime||ft_isprint|add_flags|ft_swap||||
|ft_strsplit|ft_putpnstr_fd|ft_memchr|ft_intlen||ft_islowercase|add_flags_av|ft_sort_integer_table||||
|ft_strrev|ft_putpchar_fd|ft_memccpy|ft_intlen_base||ft_isgraph|error_line_e|ft_inttab_del||||
|ft_strpbrk|ft_putnstrw_fd|ft_memalloc|ft_find_next_prime||ft_isdigit|error_line_pos|ft_getchar||||
|ft_strnstr|ft_putnstrw|ft_bzero|||ft_iscntrl|error_line_e|ft_createtab||||
|ft_strnlen|ft_putnstr_fd||||ft_isblank|ft_error_argv|ft_countwchar||||
|ft_strnew|ft_putnstr||||ft_isascii|||||
|ft_strnequ|ft_putnbr_fd||||ft_isalpha||||||
|ft_strncpychr|ft_putnbr||||ft_isalnum||||||
|ft_strncpy|ft_putnbr_base_fd||||||||||
|ft_strncmp|ft_putnbr_base||||||||||
|ft_strncat|ft_putendl_fd||||||||||
|ft_strmapi|ft_putendl||||||||||
|ft_strmap|ft_putchar_fd||||||||||
|ft_strlowcase|ft_putchar||||||||||
|ft_strlen|ft_printtab_fd||||||||||
|ft_strlcpy|ft_printtab||||||||||
|ft_strlcat|||||||||||
|ft_strjoin|||||||||||
|ft_striteri|||||||||||
|ft_striter|||||||||||
|ft_str_is_uppercase|||||||||||
|ft_str_is_printable|||||||||||
|ft_str_is_numeric|||||||||||
|ft_str_is_lowercase|||||||||||
|ft_str_is_alpha|||||||||||
|ft_strerror|||||||||||
|ft_strequ|||||||||||
|ft_strdup|||||||||||
|ft_strdel|||||||||||
|ft_strcpychr|||||||||||
|ft_strcpy|||||||||||
|ft_strcmp|||||||||||
|ft_strclr|||||||||||
|ft_strchr|||||||||||
|ft_strcat|||||||||||
|ft_strcapitalize|||||||||||
|ft_spancharspace|||||||||||
|ft_spanchar|||||||||||
|ft_span|||||||||||
|ft_itoa|||||||||||
|ft_itoa_buffer|||||||||||
|ft_itoa_base|||||||||||
|ft_itoabase_buffer|||||||||||
|ft_base_string|||||||||||
|ft_atol|||||||||||
|ft_atol_base|||||||||||
|ft_atoi|||||||||||
|ft_atoi_base|||||||||||
|ft_atof|||||||||||
|ft_atof_base|||||||||||


# Arguments parser

## Prototype
### init_flags
> Parse arguments with pattern flag
```
int			init_flags(char **argv, char *flag, char *mflag, enum e_flags mod)
```

* argv si your argv programs
* flag for regex simple flags
* mflag for regex for multi-flags
* enum e_flag for yout mod
* return -1 for error in parsing

| mod | Description |
|-----|-------------|
| F_STOP|  stop get flag when he have other than '-'|

## Regex for argv parser
```
flag :
    alone_flag, alone_flag,  |  flag  ( type {min, max, \"regex_pattern\"} , ...) ; set_flag, set_flag, ... ; unset_flag, unset_flag, ... ;|

type :  
        char*	{min, max, regex_pattern}
        int     {min, max}
        char	{min, max, regex_pattern}
        file	{min, max, regex_pattern}


mflag :
    mflag ; set_flag | ... ect


ex :

l, r, f, u, | werror (int,); u, r,;;| Wextra_full (char*{5,9}, int(,9));;;|


--Werror need a int in params

./prog --Werror 55      --> OK
./prog --Werror 557     --> KO
./prog --Werror         --> KO

--Wextra_full a string and int in params
    the char* need to be lenght 5 to 9 character

    the int need to be maximun to 9
    
./prog --Werror 55                  --> KO
./prog --Werror yoyoy 557           --> KO
./prog --Werror yoyoy  5            --> OK
./prog --Werror yoyoy  -5           --> OK
./prog --Werror yoyoyllllll  5      --> KO

    
```

# Regular expression


## Prototype
### ft_regex_exec
> Compare s1 to reg's pattern
```
int	ft_regex_exec(t_regex *st, const char *s1, const char *reg)
```

*  return 0 if si not match
*  return positive integer for number that match
*  return -1 for error allocation memory
*  t_regex the struct with all information
*  s1 is your string
*  reg is your regex pattern


### ft_regex_replace
> Compare s1 to reg's pattern and replace all capturing string with rep's string

```
char	*ft_regex_replace(const char *s1, const char *reg, char *pat, enum e_regex_replace mod)
```
*  return NULL ptr if error in allocation memory
*  s1 is your string
*  reg is your regex pattern
*  pat is for replace string
*  enum is for mod 

| mod | Description |
|-----|-------------|
| REG_FIRST| Replace first pattern matching|
| REG_LAST| Replace last pattern matching|
|REG_ALL| Replace all pattern matching|

### ft_regex_print
> For printings results

```
void    ft_regex_print(t_regex *st)
```
* print t_regex struct

### ft_regex_free
> You need to be free the structure after matching

```
void	ft_regex_free(t_regex *st)
```
*  free t_regex struct

## REGEX

### Class

|   exemple     |      Description                                    |
|---------------|-----------------------------------------------------|
| [] 	        |   nothings                              |       
| [0] 	        |   The character "0"                                 |     
| [0-9] 	    |   Any number                                        |   
| [[:isdigit:]] |   Any number                                        |  
| [\d]          |   Any number                                        |  
| [^0-9] 	    |   Any character other than a number                 |       
| [^[:isdigit:]]|   Any character other than a number                 |   
| [^\d]|   Any character other than a number                 |   
| [-0-9] 	    |   Any number or a "-"                               |       
| [0-9-] 	    |   Any number or a "-"                               |       
| [^-0-9] 	    |   Any character except a number or a "-"            |                          
| []0-9] 	    |   Any number or a "]"                               |       
| [0-9]] 	    |   Any number followed by a "]"                      |                
| [0-9-z] 	    |   Any number, or any a "-", or "z". |                                     
| [0-9\\-a\\]]    |   Any number, or a "-", a "a", or a "]"             |            

#### Character class 


|POSIX       |    Non standard |   perl    |       Description                                  |
|------------|-----------------|-----------|----------------------------------------------------|
|            |    [:word:]     |   \w      |    Alphanumeric characters plus "_"                |
|            |                 |   \W      |    Non-word characters                             |    
|            |    [:ascii:]    |           |    ASCII characters                                |        
|[:alnum:]   |                 |           |    Alphanumeric characters                         |             
|[:alpha:]   |                 |           |    Alphabetic characters                           |           
|[:blank:]   |                 |           |    Space and tab                                   |   
|[:cntrl:]   |                 |           |    Control characters                              |       
|[:digit:]   |                 |   \d      |    Control characters                              |       
|            |                 |   \D      |    Non-digits                                      |
|[:graph:]   |                 |           |    Visible characters                              |        
|[:lower:]   |                 |           |    Lowercase letters                               |       
|[:print:]   |                 |           |    Visible characters and the space character      |                                
|[:punct:]   |                 |           |    Punctuation characters                          |            
|[:space:]   |                 |   \s      |    Whitespace characters                           |          
|            |                 |   \S      |    Non-whitespace characters                       |               
|[:upper:]   |                 |           |    Uppercase letters                               |       
|[:xdigit:]  |                 |           |    Uppercase letters                               |     

### Quantifier
>  By default , quantifier as ``Greedy`` means match longest possible string . The ``lazy`` mode of quantifiers is an opposite to the ``greedy`` mode. It means: “repeat minimal number of times”.
If you need ``lazy`` quantifier , add ``?`` at the end of quantifier

| quantifier | lazy |Description  |
|----------|-|--------------|
|  ?   |??    | Matches the preceding element zero or one time. For example, ab?c matches only "ac" or "abc".  |
|  +   |+?    | Matches the preceding element one or more times. For example, ab+c matches "abc", "abbc", "abbbc", and so on, but not "ac". |
|  \*   |\*?   | Matches the preceding element zero or more times. For example, ab*c matches "abc", "abbc", "ac"|
| {m,n}  |{m,n}?  |  Matches the preceding element at least m and not more than n times. For example, a{3,5} matches only "aaa", "aaaa", and "aaaaa". This is not found in a few older instances of regexes. BRE mode requires \{m,n\}. |
| {,n}   |{,n}?  |  Matches the preceding element zero or n time|
| {m,}    |{m,}? |  Matches the preceding element at least m time or more |
| {m;n}    |{m;n}?|  Matches the preceding element m time or n time |
| {m}      |-|  Matches the preceding element m time|


### Sepcial

| metachar |  Description  |
|----------|---------------|
| ^  | Matches the starting position within the string. In line-based tools, it matches the starting position of any line. |
| \|   |  The choice (also known as alternation or set union) operator matches either the expression before or the expression after the operator. For example, abc\|def matches "abc" or "def". |
| . | Matches any single character (many applications exclude newlines, and exactly which characters are considered newlines is flavor-, character-encoding-, and platform-specific, but it is safe to assume that the line feed character is included). Within POSIX bracket expressions, the dot character matches a literal dot. For example, a.c matches "abc", etc., but [a.c] matches only "a", ".", or "c". |
| $ | Matches the ending position of the string or the position just before a string-ending newline. In line-based tools, it matches the ending position of any line. |
| \n | newline|
| \t | tab |
| \r | return |
| \e | escape |
| \0x44 | hex ascii code|
| \0777 | octal ascii code |

### Enclose

| metachar |  Description  |
|----------|---------------|
| ( )     | Defines a marked subexpression. The string matched within the parentheses can be recalled later (see the next entry, \n). A marked subexpression is also called a block or capturing group. BRE mode requires \( \). |
| (?) | Add ? a start of enclose for capture everything on|
| (!) | Add ! a strart of enclose or after the ? for tell is not match enclose|
| (<your_name>) | Add <your_name> after ! or ? for naming capturing enclose |
