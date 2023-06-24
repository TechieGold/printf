# Printf.
```` c
int printf ( const char * format, ... );
````

This is our first group project at ALX, focused on replicating the **[printf (3)](http://man7.org/linux/man-pages/man3/printf.3.html)** function of language c, function of the C language. We have named our version  **_printf.**) 

The printf function is a vital part of the standard library and requires the inclusion of the <stdio.h> header file for usage.

Its main purpose is to write the text specified by the 'format' parameter to the standard output (stdout). If the 'format' string contains format specifiers (sequences beginning with %), additional arguments provided after the 'format'
parameter will be formatted and inserted into the resulting string, replacing their respective specifiers.

The 'format' parameter represents a C string containing the text to be written to stdout.

The specifier character at the end of each format specifier is the most significant component
as it defines the type and interpretation of the corresponding argument to be included in the formatted string.

### Parameters
> **format** -> C string that contains the text to be written to stdout.

Where the specifier character at the end is the most significant component, since it defines the type and the interpretation of its corresponding argument:
Specifier | Output | Example
------------ | ------------ | ------------
c | Character | A
s | String of characters | ALX
% | A % followed by another % character will write a single % to the stream| %
i and d | Signed decimal integer | 98
b | Unsigned binary | 10101
u | Unsigned decimal integer | 98
o | Unsigned octal | 5523
x | Unsigned hexadecimal integer (lowercase) | 36264eb
X | Unsigned hexadecimal integer (uppercase) | 36264EB
r | Reversed string | gnirts |
R | Rot13 string | cevags
##### Return Value.
On **success**, the **total number** of characters written is returned.
