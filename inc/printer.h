#ifndef PRINTER_H
# define PRINTER_H
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_PRINT(some) some ANSI_COLOR_RESET

typedef struct		s_printer
{
	int				fd;
	size_t			flushsize;
	uint8_t			*buf;
	uint8_t			*ptr;
	size_t			bufsize;
}					t_printer;

t_printer			*ft_printernew(const int fd, size_t bufsize);
void				ft_printerinit(t_printer *p, const int fd, size_t bufsize);
void				ft_printerclose(t_printer *p);
void				ft_printerflush(t_printer *p);

void				ft_printerwrite(t_printer *p, const void *buf, size_t len);
void				ft_printerwrite_int64(t_printer *p, const int64_t nbr);
void				ft_printerwrite_uint64(t_printer *p, const uint64_t nbr);

void				ft_printerread(t_printer *p, void *buf, size_t len);

void				ft_printf(const char *fmt, ...);
#endif
