/**
 * check - A function that checks the format
 * @format: A pointer to a string
 * Return: -1
 */
int check(const char *format)
{
	if (!format || (*format == '%' && !(format + 1)))
	{
		return (-1);
	}
	if (*format == '%' && *(format + 1) == ' ' && !(format + 2))
	{
		return (-1);
	}
	if (*format == '%')
	{
		format++;
		while (*format)
		{
			if (*format == ' ')
			{
				format++;
				continue;
			}
			return (0);
		}
		return (-1);
	}
	return (0);
}
