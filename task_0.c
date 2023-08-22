#include "main.h"

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
int main(void)
{
	mary_print("%c\n", 'g');
	mary_print("%s\n", "this is a group work");
	mary_print("%%\n");
	return (0);
}


