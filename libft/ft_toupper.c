int ft_toupper(int c)
{
	if (c < 123 && c > 96)
		c -= 32;
	return c;
}