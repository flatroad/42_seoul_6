#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_printf (const char *str, ...);
int	ft_arg (va_list list, char c, int count);

int	ft_c_printf (int num, int count);
int	ft_s_printf(char *str, int count);
int ft_p_printf (void *str, int count);
int	ft_di_printf(int num, int count);
int	ft_u_printf(unsigned int num, int count);
int	ft_xX_printf(unsigned int num, char c, int count);

int	ft_hex_printf(unsigned long num, char *hex, int count);

int main()
{
	char *str = "123";
	int num = 31;
	int num2 = 2147483647;
	int num3 = -2147483648;
	

	// printf("\ntest = %d d\n", ft_printf ("%c %s %p %x %X 123 %d %d %u %u %%", str, str, str, num, num, num2, num3, num2, num3));
	// printf("\ntest = %d\n", printf ("%c %s %p %x %X 123 %d %d %u %u %%", str, str, str, num, num, num2, num3, num2, num3));
	printf("%s\n","sivalsekki");
	ft_printf("%s\n","sivalsekki");
	while (1)
	{
		/* code */
	}
	
	return 0;
}

int	ft_c_printf(int num, int count)
{
	count = count + write(1, &num, 1);
	return (count);
}

int	ft_s_printf(char *str, int count)
{
	while (*str != 0)
	{
		count = count + write(1, str, 1);
		str++;
	}
	return (count);
}

int	ft_p_printf(void *str, int count)
{
	char			*hex;

	hex = "0123456789abcdef";
	count = count + write(1, "0x", 2);
	if (str == 0)
		count = count + write(1, "0", 1);
	else
		count = ft_hex_printf((unsigned long)str, hex, count);
	return (count);
}

int	ft_di_printf(int num, int count)
{
	if (num == -2147483648)
	{
		count = count + write(1, "-2147483648", 11);
		return (count);
	}
	if (num < 0)
	{
		count = count + write (1, "-", 1);
		num = -num;
	}
	if (num >= 10)
		count = ft_di_printf(num / 10, count);
	num = (num % 10) + '0';
	count = count + write (1, &num, 1);
	return (count);
}

int	ft_u_printf(unsigned int num, int count)
{
	if (num >= 10)
		count = ft_u_printf(num / 10, count);
	num = (num % 10) + '0';
	count = count + write (1, &num, 1);
	return (count);
}

int	ft_xX_printf(unsigned int num, char c, int count)
{
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	count = ft_hex_printf(num, hex, count);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		count;

	va_start(list, str);
	count = 0;
	while (*str != 0)
	{
		if (*str == '%')
		{
			str++;
			count = ft_arg (list, *str, count);
		}
		else
			count = count + write (1, str, 1);
		str++;
	}
	va_end(list);
	printf("\n count == %d\n", count);
	return (count);
}

int	ft_arg(va_list list, char c, int count)
{
	if (c == 'c')
		count = ft_c_printf (va_arg(list, int), count);
	else if (c == 's')
		count = ft_s_printf (va_arg(list, char *), count);
	else if (c == 'p')
		count = ft_p_printf (va_arg(list, void *), count);
	else if (c == 'd' || c == 'i')
		count = ft_di_printf (va_arg(list, int), count);
	else if (c == 'u')
		count = ft_u_printf (va_arg(list, unsigned int), count);
	else if (c == 'x' || c == 'X')
		count = ft_xX_printf (va_arg(list, unsigned int), c, count);
	else if (c == '%')
		count = count + write (1, "%", 1);
	return (count);
}

int	ft_hex_printf(unsigned long num, char *hex, int count)
{
	if (num >= 16)
		count = ft_hex_printf(num / 16, hex, count);
	num = num % 16;
	count = count + write(1, &(hex[num]), 1);
	return (count);
}
