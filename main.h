#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h> 
#include <wchar.h> 

#define INT_MAX   __INT_MAX__

int percentage(char c)
{
    return (write(1, &c, 1));
}

int charac(va_list list_of_args)
{
    char c = (char) va_arg(list_of_args, int);
    return (percentage(c));
}

int print_string(va_list list_of_args)
{
    char *str = va_arg(list_of_args, char *);
    int count = 0;

    if (str == NULL)
    {
        str = "(null)";
    }
    while(*str)
    {
        count += percentage(*str++);
    }
    return (count);
}

int mary_print(const char *format, ...)
{
    va_list list_of_args;
    int count = 0;

    if (format == NULL)
    return (-1);
    va_start(list_of_args, format);
    while (*format)
    {
        if(*format != '%')
        {
            count += percentage(*format++);
            continue;
        }
        format++;
        if(*format == '%')
        {
            count += percentage('%');
        }
        else if (*format == 'c')
        {
            count += charac(list_of_args);
        }
        else if (*format == 's')
        {
            count += print_string(list_of_args);
        }
        else
        {
            count += percentage('%') + percentage(*format);
        }format++;
    }
    va_end(list_of_args);
    return (count);
}


#endif /* MAIN_H */
