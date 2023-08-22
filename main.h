#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#define INT_MAX   __INT_MAX__

int mary_print(const char *format, ...)
{
        int groupWork = 0;
        va_list list_of_args;

        if (format == NULL)
                return (-1);
        va_start(list_of_args, format);
        while (*format)
        {
        if (*format != '%')
        {
        write(1, format, 1);
                groupWork++;
        }
        else
        {
                format++;
                if (*format == '\0')
                        break;
                if (*format == '%')
                {
                        write(1, format, 1);
                        groupWork++;
                }
                else if (*format == 'c')
                {
                char c = va_arg(list_of_args, int);

                write(1, &c, 1);

                groupWork++;
                }
                else if (*format == 's')
                {
                char *str = va_arg(list_of_args, char*);
                int str_len = 0;

                while (str[str_len] != '\0')
                str_len++;
                write(1, str, str_len);
                groupWork += str_len;
                }
        }
        format++;
        }
        va_end(list_of_args);
        return (groupWork);
}

#endif /* MAIN_H */

