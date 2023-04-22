#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: a character string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte)
*/
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	char c, *s;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
			c = (char) va_arg(args, int);
			write(1, &c, 1);
			count++;
			break;
			case 's':
			s = va_arg(args, char *);
			if (s == NULL)
				s = "(null)";
			while (*s)
			{
				write(1, s, 1);
				s++;
				count++;
			}
			break;
			case '%':
			write(1, "%", 1);
			count++;
			break;
			default:
			write(1, "%", 1);
			write(1, &(*format), 1);
			count += 2;
			break;
			}
		}
		else
		{
			write(1, &(*format), 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
