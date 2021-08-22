#include "so_long.h"

static void	ft_putnbr_rek(long n);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(long n)
{
	if (n < 0)
	{
		write(1, "1", 1);
		n = -n;
	}
	else if (n == 0)
		write(1, "0", 1);
	else
		ft_putnbr_rek(n);
}

static void	ft_putnbr_rek(long n)
{
	int	num;

	if (n == 0)
		return ;
	ft_putnbr_rek(n / 10);
	num = (n % 10) + 48;
	write(1, &num, 1);
}

void	line_transfer(char *original, char *copy)
{
	int	i;

	i = 0;
	while (original[i])
	{	
		copy[i] = original[i];
		i++;
	}
}
