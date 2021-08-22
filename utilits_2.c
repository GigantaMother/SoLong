#include "so_long.h"

static void	error_continuation(int e);
static int	ft_size(int n);
static char	*ft_cpy(char *dst, const char *src, size_t dstsize);

void	error(int e)
{
	ft_putstr("Error\n");
	if (e == 1)
		ft_putstr("Неверное кол-во аргументов\n");
	else if (e == 2)
		ft_putstr("Файл с картой не открылся\n");
	else if (e == 3)
		ft_putstr("Имя карты слишком короткое\n");
	else if (e == 4)
		ft_putstr("Формат карты неверный\n");
	else if (e == 5)
		ft_putstr("Запрещённые символы на карте\n");
	else if (e == 6)
		ft_putstr("Строки карты разной длины\n");
	else if (e == 7)
		ft_putstr("Пустая строка\n");
	else if (e == 8)
		ft_putstr("Слишком много столбцов карты\n");
	else if (e == 9)
		ft_putstr("Слишком много строк карты\n");
	else if (e == 10)
		ft_putstr("Неверное кол-во игроков\n");
	else
		error_continuation(e);
	exit (0);
}

static void	error_continuation(int e)
{
	if (e == 11)
		ft_putstr("Неверное кол-во объектов\n");
	else if (e == 12)
		ft_putstr("Неверное кол-во выходов\n");
	else if (e == 13)
		ft_putstr("Ошибка малока\n");
	else if (e == 14)
		ft_putstr("Карта слишком маленькая\n");
	else if (e == 15)
		ft_putstr("Карта не окружена стенами\n");
	else if (e == 16)
		ft_putstr("mlx вернул NULL\n");
	else if (e == 17)
		ft_putstr("Зачем ты удалил текстуры? Вери\n");
	else
		ft_putstr("Неизвестная ошибка\n");
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		stop;

	stop = 0;
	size = ft_size(n);
	str = malloc(sizeof(*str) * (size + 1));
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_cpy(str, "-2147483648", 11));
	str[size--] = '\0';
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
		stop = 1;
	}
	while (size >= stop)
	{
		str[size] = n % 10 + '0';
		n /= 10;
		size--;
	}
	return (str);
}

static char	*ft_cpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int	ft_size(int n)
{
	int	len;

	if (n == -2147483648)
		return (11);
	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}
