static char	*skip_white_space(char *str)
{
	while ((*str == ' ' || *str == '\n' || *str == '\t')
		|| (*str == '\v' || *str == '\r' || *str == '\f'))
		str++;
	return (str);
}

static int	lil_atoi(char *str)
{
	int	somme;

	somme = 0;
	while (*str >= '0' && *str <= '9')
	{
		somme = ((somme * 10) + (*str - '0'));
		str++;
	}
	return (somme);
}

int ft_atoi(const char *str)
{
	int	signe;

	signe = 1;
	str = skip_white_space((char *)str);
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -signe;
		str++;
	}
	return (signe * lil_atoi((char*)str));
}