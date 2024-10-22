#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void	write_char(int chr)
{
	write(1,&chr,1);
}

void	write_string(char *str)
{
	if(str == NULL)
		write(1,"(null)",6);
	else
	{
		while (str && *str)
		{
			write_char(*str++);
		}
	}
}


void	write_number(int n)
{
	int	count;
	char *nmbtostr;
	int ncpy;
	if(n == -2147483648){
		write_string("-2147483648");
	}
	else if (n < 0){
		write_char('-');
		write_number(n * -1);
	}
	else if (n >= 0 && n <= 9 ){
		write_char(n + '0');
	}
	else{
		count = 0;
		ncpy = n;
		while (n > 9)
		{
			n /= 10;
			count++;
		}
		nmbtostr = (char *)malloc(sizeof(char) * count + 1);
		nmbtostr[count] = '\0';
		while (ncpy > 9)
		{
			count--;
			nmbtostr[count] = ncpy % 10 + '0';
			ncpy /= 10;
			
		}
		write_char(ncpy % 10 + '0');
		write_string(nmbtostr);
		free(nmbtostr);
	}
}

void	write_unumber(unsigned int n)
{
	int				count;
	unsigned int	ncpy;
	char 			*nmbtostr;
	
	count = 0;
	ncpy = n;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	nmbtostr = (char *)malloc(sizeof(char) * count + 1);
	nmbtostr[count] = '\0';
	while (ncpy > 9)
	{
		count--;
		nmbtostr[count] = ncpy % 10 + '0';
		ncpy /= 10;
		
	}
	write_char(ncpy % 10 + '0');
	write_string(nmbtostr);
	free(nmbtostr);
}

void	write_hex(unsigned int n,char format)
{
	char *hex = "0123456789ABCDEF";
	char chr;
	if(n >= 16)
	{
		write_hex(n / 16,format);
	}
	if (n % 16 > 9 && n % 16 < 17)
	{
		if (format == 'x')
		{
			chr = hex[n % 16] + 32;
			write(1 ,&chr,1);
		}
		else
			write(1 ,&hex[n % 16],1);
	}
	else
		write(1 ,&hex[n % 16],1);
	
}
void	write_ptr(unsigned long long ptr)
{
	if(!ptr)
		write(1, "(nil)", 5);
	else{
		char *hex = "0123456789abcdef";
	
		if(ptr > 16)
			write_ptr(ptr / 16);
		else
			write(1,"0x",2);
		write(1,&hex[ptr % 16],1);
	}
}

void	ft_printf(char *format,...)
{
	va_list list;
	va_start(list,format);
	while (format && *format)
	{
		if(*format == '%')
		{
			format++;
			if (*format == 's')
			{
				write_string(va_arg(list,char *));
			}
			else if(*format == 'd' || *format == 'i')
			{
				write_number(va_arg(list,int));
			}
			else if(*format == 'u')
			{
				write_unumber(va_arg(list,unsigned int));
			}
			else if(*format == 'c')
			{
				write_char(va_arg(list,int));
			}
			else if(*format == 'x' || *format == 'X')
			{
				write_hex(va_arg(list,unsigned int),*format);
			}
			else if(*format == 'p')
			{
				write_ptr(va_arg(list,unsigned long long));
			}
			else
				write(1,format,1);
		}
		else
			write(1,format,1);
		format++;
	}
	
}
