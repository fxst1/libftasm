#ifndef LIST_H
# define LIST_H
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*last;
	struct s_list	*first;
}					t_list;

t_list				*ft_lstnew(const void* content, size_t content_size);
t_list				*ft_lstnew_noalloc(void* content, size_t content_size);
void				ft_lstpush(t_list **lst, t_list *add);
t_list				*ft_lstpop(t_list **lst);
t_list				*ft_lstadd_end(t_list **lst, t_list *add);
t_list				*ft_lstdel(t_list **lst);

# define			ft_lstadd ft_lstpush
#endif
