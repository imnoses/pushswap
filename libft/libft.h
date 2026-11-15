/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   libft.h                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/13 15:37:09 by spuschma         #+#    #+#              */
/*   Updated: 2026/09/18 11:23:00 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/** Returns 1 if C is a digit, otherwise 0.  */
int					ft_isdigit(int c);

/** Returns 1 if C is an alphabetical character, otherwise 0.  */
int					ft_isalpha(int c);

/** Returns 1 if C is a digit or alphabetical character, otherwise 0.  */
int					ft_isalnum(int c);

/** Returns 1 if C is ascii, otherwise 0.  */
int					ft_isascii(int c);

/** Returns 1 if C is printable, otherwise 0.  */
int					ft_isprint(int c);

/** Return the length of S.  */
size_t				ft_strlen(const char *s);

/** Set N bytes of S to 0.  */
void				ft_bzero(void *s, size_t n);

/** Copy N bytes of SRC to DEST.  */
void				*ft_memcpy(void *dest, const void *src, size_t n);

/** Copy N bytes of SRC to DEST, guaranteeing
 *	correct behavior for overlapping strings.  */
void				*ft_memmove(void *dest, const void *src, size_t n);

/** Copy at most SIZE - 1 characters from SRC to DEST.  */
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

/** Append SRC to DEST, possibly with truncation to keep the total size
 *	below SIZE.  */
size_t				ft_strlcat(char *dst, const char *src, size_t size);

/** Return the lowercase version of C.  */
int					ft_tolower(int c);

/** Return the uppercase version of C.  */
int					ft_toupper(int c);

/** Find the first occurrence of C in S.  */
char				*ft_strchr(const char *s, int c);

/** Find the last occurrence of C in S.  */
char				*ft_strrchr(const char *s, int c);

/** Compare N characters of S1 and S2.  */
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/** Search N bytes of S for C.  */
void				*ft_memchr(const void *s, int c, size_t n);

/** Compare N bytes of S1 and S2.  */
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/** Locate the substring LITTLE in BIG.  */
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

/** Convert a string to an integer.  */
int					ft_atoi(const char *nptr);

/** Allocate N elements of SIZE bytes each, all initialized to 0.  */
void				*ft_calloc(size_t n, size_t size);

/** Duplicate S, returning an identical malloc'd string.  */
char				*ft_strdup(const char *s);

/** Returns a malloc'd substring from the string S,
 *	starting at START with length LEN.  */
char				*ft_substr(char const *s, unsigned int start, size_t len);

/** Returns a new malloc'd string,
 *	which is the result of concatenating S1 and S2.  */
char				*ft_strjoin(char const *s1, char const *s2);

/** Returns a malloc'd copy of S1 with characters
 *	from SET removed from the beginning and the end.  */
char				*ft_strtrim(char const *s1, char const *set);

/** Returns a malloc'd, NULL terminated array of malloc'd strings obtained
 *	by splitting S using the character C as a delimiter. */
char				**ft_split(char const *s, char c);

/** Returns a malloc'd string representing the integer N.  */
char				*ft_itoa(int n);

/** Returns a malloc'd string resulting form applying F to each char of S.  */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/** Applies F to each char of S given by address so it can be modified.  */
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/** Outputs the character C to the file descriptor FD.  */
void				ft_putchar_fd(char c, int fd);

/** Outputs the string S to the file descriptor FD.  */
void				ft_putstr_fd(char *s, int fd);

/** Outputs the string S followed by a new line to the file descriptor FD.  */
void				ft_putendl_fd(char *s, int fd);

/** Outputs the integer N to the file descriptor FD.  */
void				ft_putnbr_fd(int n, int fd);

/** Set N bytes of S to C.  */
void				*ft_memset(void *s, int c, size_t n);

/** Returns a malloc'd t_list node containing CONTENT.  */
t_list				*ft_lstnew(void *content);

/** Adds the node NEW at the beginning of the list LST.  */
void				ft_lstadd_front(t_list **lst, t_list *new);

/** Counts the number of nodes in the list LST.  */
unsigned int		ft_lstsize(t_list *lst);

/** Returns the last node of the list LST.  */
t_list				*ft_lstlast(t_list *lst);

/** Adds the node NEW at the end of the list LST.  */
void				ft_lstadd_back(t_list **lst, t_list *new);

/** Frees the content of LST using the function DEL,
 *	leaving the next node in tact.  */
void				ft_lstdelone(t_list *lst, void (*del)(void *));

/** Deletes and frees the given node and all its successors,
 *	using the function DEL. Finally, sets LST to NULL. */
void				ft_lstclear(t_list **lst, void (*del)(void *));

/** Iterates through the list LST and applies the
 *	function F to the content of each node.  */
void				ft_lstiter(t_list *lst, void (*f)(void *));

/** Returns a new t_list mirroring LST with the content of every node
 *	created by applyin F to the content of the original lists node.  */
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
