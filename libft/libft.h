#ifndef LIBFT_H

# define libft_h

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef FD_SIZE
#  define FD_SIZE 65535
# endif

# define NULL  __DARWIN_NULL
# define __DARWIN_NULL ((void *)0)

int extend_stach(char **stash, char *buf);
void stock(char **stash, char *buf, int red);
void read_n_stock(int fd, char **stash);
char *get_next_line(int fd);
int found_new_line(char *str);
int char_until_end(char *str);
void clean_stash(char **stash);
void extract_line(char **stash, char **line);
void ft_strlcpy2(char **dst, char *src);

int		ft_formats(va_list *args, const char format);
int		ft_printf(const char *str, ...);
int		ft_print_char(char c);
int		ft_print_str(char *str);
void	ft_putstr(char *str);
int		ft_print_percent(void);
void	ft_putchar(char c);
void	ft_conv_hex(unsigned int nb, char *str);
int		ft_hex_len(unsigned int num);
int		ft_print_hex(unsigned int num, char format);
void	ft_put_nbr(int n);
int		ft_print_nbr(int num);
void	ft_put_unsigned(unsigned int n);
int		ft_unsigned_len(unsigned int n);
int		ft_print_unsigned(unsigned int n);
void	ft_put_ptr(size_t nb, char *str);
int		ft_ptr_len(size_t num);
int		ft_print_ptr(size_t ptr);

char	**ft_split(char const *s, char c);
char	**writetab(char **tab, char *str, char c);
int	c_count(char *s, char c);
void freetab(char **tab);
int	w_count(char *s, char c);

int ft_atoi(const char *str);
void ft_bzero(void *s, size_t n);
int	ft_isalpha(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_isdigit(int c);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memset(void *s, int c, size_t n);
const char *ft_strchr(const char *s, int c);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strnstr(const char	*big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
int ft_tolower(int c);
int ft_toupper(int c);
void *ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *src);


#endif