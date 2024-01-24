# My_ft_printf

This is my second Hive project to develop my own printf function that imitates the original C library function, printf.

## Table of content

- [Description](#my_ft_printf)
- [Anatomy of ft_printf.c](#main-function-ft-printfc)
- [Helper functions](#helper-functions)

## Main function: ft-printf.c 

This is the primary function file for my *ft_printf*.

My *ft_printf.c* with a prototype *int	ft_printf(const char *format, ...)*
is	a variadic function, that is, it accepts a variable	number arguments 
that is denoted by the ellipses "..." in the protoype.
A struct 't_check' was declared in my header file, "ft_printf.h" in the 
format:
	
```C
typedef struct s_check
	{
	int	error;
	int	count;
	}				t_check;

```	
	
The code above provides the a means to 
1.	check for errors and return(ends the program).
2.	counts and logs each variable that is being written.
note: it is imperative this struct would be applied to all functions and 
processes of the *ft_printf* function.
	
My *ft_printf* is declared with a return type of 'int' to indicate the
number of characters succesfully written to the standard output/printed
as 'return(audit.count)'.
If an error occurs during printing, a negative value is returned.
This is done via the struct 't_check' that was earlier declared.

The variable 'char *format' reperesents the format flags (cspdiuxX%) that
tells the program what type of variable its writing to the standard output.

To begin, we would need the standard C library 'stdarg.h' which was included
in header file *ft_printf.h*. This would allow us to make use of the variardic
functions.

The following variardic functions (macros): va_start, va_arg, and va_end.
The va_start() macro must be called first and We would also need to declare
the argument pointer 'va_list' as a parameter to these macros. This is 
declared as 'arg_pnt'(argument pointer).
And this 'arg_pnt' is passed to va_arg() for each argument to be processed.
	
Struct 't_check' is declared as 'audit' and the variables, error and count
within are initalised to '0'.
Calling va_end within the same function is imperative as it signals the
end of the program.
	
We start the macros 'va_start' with the parameter declared via 'va_list' 
and using format: va_start(arg_pnt, format) which is utilised for 'va_arg'.
In the primary *ft_printf* function, the method used after all of the above
is done is to create a while loop that behavesin a way to check for the 
modulo '%' if not found then performs other required tasks. If the 
modulo is found, then the format flags are checked for.
To check for the format flags, a static helper function *ft_format_check*
is made.
*ft_format_check* directs the program to its expected helper function via
the conditional statements checking the format flags.
A special case for the helper function 'ft_put_hex', should have its 
va_arg parameter as unsigned int, for some reason unsigned long breaks.

 
### Helper functions:

**-ft_put_hex.c**

This is a helper function for my *ft_printf* function.
  
This function is intended to handle and wite out hexadecimals denoted
by the format 'x' and 'X'.
 
A singular helper function is used to handle both cases of 'x' and 'X'.
This was achieved by declaring an 'int' which is used as a switch.
 
This switch is influenced by the argument parameter, 'format' depending 
on the 'x'	and 'X' format it received. The switch is with a reference to 
an ascii value that is further utilised in the function.
 
The function is somewhat similar to *ft_putnbr* which is a base 10 in 
its recurssive approach but	this is in base 16.



**ft_put_ptr_hex.c**

This is a helper function for my *ft_printf* with the intent to write out 
a pointer address by format 'p'.
 
This helper function is also inttended to write out hexadecimals with a 
difference of always having '0x' as a prefix.
 
Another helper function *ft_putstr_fd* is utilised to always write out the 
prefix '0x' before any other thing.
 
If the pointer 'ptr' points to 0 or if its a null pointer, we use the 
another helper function *ft_putchar_fd* to write '0' after the prefix '0x'.
Else, we use the helper function, *ft_put_hex* to write the hexadecimals 
after the prefix.
 
There you go, we have our pointer address addressed. 



**ft_putnbr_fd**

This is a helper function for my *ft_printf* function that handles and 
writes strings representation of the input integer.

This function receives an integer and the struct t_check audit as arguments.

Since strings are to be written from integers, we need to handle the 
extreme cases of INT MIN. This is done explicitly by looking out for 
**-2147483648** and using our helper function *ft_putstr_fd* to write 
that out.

If the string is greater than INT MIN; first we write out the 
negative sign '-' with helper function *ft_putchar_fd*, then we proceed to 
convert the integer to positive, then followed by checking if the integer
is less than 10. We use helper function *ft_putchar_fd* to perform this 
while passing 'nb' added to ascii value for conversion into a string.

If not less, it performs the recurssion to split the integer into its
individual digits and write each value as string characters to the 
standard output.



**ft_putstr_fd**

This a helper function for my *ft_printf* with the intention of writing
out a string of characters to the standard output.

This function receives a string and struct t_check audit as arguments.

Edge cases of an empty string is first checked to which a "(null)" is passed
as a new parameter to be written should this be the case.
	
As an alternative to recursively calling the *ft_putstr_fd*, the following 
code/snipet is a method can be substituted for similar outcome.
	
``` C
if (write(1, "(null)", 6) == -1)
			audit->error = -1;
		else
			audit->count += 6;
		return ;
```
		
	
Otherwise, each character of the string is written in the normal way with
the help of *ft_putchar*.



**ft_putchar_fd**

This a helper function for my *ft_printf* with the intention of writing
out a character to the standard output.
	
This function receives a character and struct t_check audit as arguments.
	
In this function, *t_check audit* is utilised for every process, while
keeping an account of the count.
	
```C
		if (audit->error == -1)
		return ;
```
		
This snipet of code was added as a protection if ever an error value 
of '-1' makes its way to this function.



**ft_put_unsign_fd**

This is a helper function for my *ft_printf* function that handles and 
writes strings representation of the input integer.
	
The difference between this function and ft_putnbr_fd is that this only 
accepts positive integer argument by virtue of its unsigned int parameter.
	
If the integer is less than 10. We use helper function *ft_putchar_fd* to 
perform this while passing 'nb' added to ascii value '0' for conversion 
into a string.

If not less, it performs the recurssion to split the integer into its
individual digits and write each value as string characters to the 
standard output.

