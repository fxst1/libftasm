#ifndef LIBFT_H
# define LIBFT_H
# include <strings.h>

void		ft_bzero(void *buffer, size_t length);
char		*ft_strcat(char *dest, const char *src);
int			ft_isalpha(const int value);
int			ft_isdigit(const int value);
int			ft_isalnum(const int value);
int			ft_isascii(const int value);
int			ft_isprint(const int value);
size_t		ft_strlen(const char *s);
void		ft_cat(const int fd);

#endif
