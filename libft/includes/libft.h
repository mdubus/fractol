/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:36:56 by mdubus            #+#    #+#             */
/*   Updated: 2017/07/25 18:51:21 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 20

# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

/*
*********************************** LIBFT ***********************************
*/

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

/*
** -------------------------------- lists -------------------------------- **
*/

void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst, void (*del)(void *,
						size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstnew(void const *content, size_t content_size);
int						ft_lstsize(t_list *begin_list);

/*
** -------------------------------  memory ------------------------------- **
*/

void					ft_bzero(void *s, size_t n);
void					*ft_memalloc(size_t size);
void					*ft_memccpy(void *dst, const void *src, int c,
						size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					ft_memdel(void **ap);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memset(void *b, int c, size_t len);
void					ft_swap_adress(char	**a, char	**b);

/*
** --------------------------------- str --------------------------------- **
*/

void					ft_count_nb_occurence(char *str, char *search,
						int *nb_oc);
int						ft_countwords(char const *s, char c);
char					*ft_fill_with(size_t size, char c);
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_put_in_mask(char **mask3, char *temp2);
void					ft_putstr(char const *s);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putwstr(wchar_t	*str);
void					ft_putwchar(wchar_t c);
void					ft_replace_char_with_char_in_str(char **str,
						char search, char replace);
char					*search_and_replace_one(char *str, char *old,
						char *mew);
char					*search_and_replace_all(char *str, const char *old,
						const char *mew);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strchr(const char *s, int c);
int						ft_strclen(const char *s, char c);
void					ft_strclr(char *s);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strcpy(char *dest, const char *src);
void					ft_strdel(char **as);
char					*ft_strdup(const char *s1);
int						ft_strequ(char const *s1, char const *s2);
int						ft_strislower(char *str);
int						ft_strisupper(char *str);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strjoin(char const *s1, char const *s2);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlen(const char *s);
size_t					ft_strlen_secure(const char *s);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
						char));
char					*ft_strncat(char *s1, const char *s2, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strncpy(char *dst, const char *src, size_t len);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strnew(size_t size);
char					*ft_strnstr(const char *big,
						const char *little, size_t len);
char					*ft_strrchr(const char *s, int c);
char					**ft_strsplit(char const *s, char c);
char					*ft_strstr(const char *big, const char *little);
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
void					ft_strtoupper(char **str);
char					*ft_strtrim(char const *s);
int						ft_tolower(int c);
int						ft_toupper(int c);
void					ft_print_error_exit(void (*function)(const char *),
						const char *str);

/*
** ----------------------------- is something ----------------------------- **
*/

int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isblank(int c);
int						ft_isdigit(int c);
int						ft_islower(int c);
int						ft_isprint(int c);
int						ft_isupper(int c);

/*
** -------------------------------- numbers -------------------------------- **
*/

int						ft_atoi(const char *str);
int						ft_atoi_base(const char *str, int base);
char					*ft_itoa(int n);
char					*ft_itoa_base(int nb, unsigned int base);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
int						ft_nb_puissance_nb(int nb, int puissance);
int						ft_binary_to_decimal(char *str);
char					*ft_itoa_b_llint(long long int nb,
						unsigned int base);
char					*ft_itoa_b_ullint(unsigned long long int nb,
						unsigned int base);
char					*ft_itoa_llint(long long int n);
char					*ft_itoa_ullint(unsigned long long int n);
int						ft_absolute(int nb);
double					ft_absolute_double(double nb);

/*
******************************** GET_NEXT_LINE ********************************
*/

typedef struct			s_dlist
{
	int					fd;
	char				*reste;
	struct s_dlist		*next;
}						t_dlist;

typedef struct			s_gnl
{
	int					length;
	char				*buffer;
	t_dlist				*mew;
	int					ret;
}						t_gnl;

void					mew_lst(t_dlist **mew, int fd);
void					multi_fd_gnl(t_dlist **mew, t_dlist **mew2, int fd);
int						get_next_line(const int fd, char **line);
int						backslash_in_buffer(char *buffer, int length,
						t_dlist **mew, char **line);
int						backslash_in_rest(int fd, char **line, t_dlist **mew,
						char **buffer);

/*
********************************** FT_PRINTF  **********************************
*/

typedef struct			s_format
{
	char				*flag;
	char				*width;
	char				*precision;
	char				*modifier;
	char				*type;
	char				*argument;
	char				*result;
	struct s_format		*next;
}						t_format;

/*
** ------------------------------- call format -------------------------------**
*/

void					put_result(t_format **current, va_list ap);
void					free_current_list(t_format **current);
void					replace_args(char **str, t_format **current);

/*
** --------------------------------- colors ---------------------------------**
*/

char					*ft_text_colors(char *str);
char					*ft_bg_colors(char *str);
char					*ft_effects(char *str);
char					*ft_colors(char *str);

/*
** ------------------------------- count args -------------------------------**
*/

int						ft_count_args_printf(char *str, char c);
void					ft_count_args_printf2(char *str, int *i, int *nb);

/*
** ------------------------------- do parsing -------------------------------**
*/

int						do_parsing_flag(char *str, t_format **current, int i);
int						do_parsing_width(char *str, t_format **current, int i);
int						do_parsing_precision(char *str, t_format **current,
						int i, int j);
int						do_parsing_modifier(char *str, t_format **current,
						int i);
int						do_parsing_type(char *str, t_format **current, int i);

/*
** -------------------------------- getwchar --------------------------------**
*/

void					ft_getwchar_1(char *temp2, char **result2);
void					ft_getwchar_2(char *temp2, char **result2);
void					ft_getwchar_3(char *temp2, char **result2);
void					ft_getwchar_4(char *temp2, char **result2);
char					*ft_getwchar(int c);

/*
** ------------------------------- getwstring -------------------------------**
*/

char					*ft_getwstring(wchar_t *str);

/*
** ----------------------------------- is -----------------------------------**
*/

int						is_flag(char *str);
int						is_modifier(char *str);
int						is_type(char *str);

/*
** ---------------------------------  printf ---------------------------------**
*/

int						ft_printf(const char *format, ...);
void					ft_printf2(char **str, size_t *size,
						t_format **current, va_list ap);
size_t					ft_printf3(char **str, t_format **current, int *i,
						int *nb_arg);
void					ft_printf4(t_format **current, size_t *size);

/*
** ----------------------------------- cs -----------------------------------**
*/

void					ft_printf_c2(va_list ap, t_format **current, char *c,
						char *temp3);
void					ft_printf_c(t_format **current, va_list ap);
void					ft_printf_s(t_format **current, va_list ap);
void					ft_printf_s2(t_format **current, va_list ap,
						wchar_t *str, char *str2);

/*
** ---------------------------------- dioux ----------------------------------**
*/

void					ft_printf_di(t_format **current, va_list ap);
void					ft_printf_o(t_format **current, va_list ap);
void					ft_printf_u(t_format **current, va_list ap);
void					ft_printf_x(t_format **current, va_list ap);
void					ft_printf_x_upper(t_format **current, va_list ap);

/*
** ------------------------------ do flag hash ------------------------------**
*/

void					do_flag_hash(t_format **current);
void					do_flag_hash_with_o(t_format **current);
void					do_flag_hash_with_x(t_format **current);

/*
** ------------------------------ do flag zero ------------------------------**
*/

void					do_flag_zero(t_format **current);
void					do_flag_zero2(t_format **current, char **temp,
						int width_result, int i);
void					do_flag_zero3(t_format **current, int i, int j,
						char **temp);

/*
** -------------------------------- do flags --------------------------------**
*/

void					do_flag_plus(t_format **current);
void					do_flag_space(t_format **current);
void					do_flag_minus(t_format **current);

/*
** ---------------------------------- flags ----------------------------------**
*/

void					check_flags(t_format **current);
void					flag_minus(t_format **current);
void					flag_zero(t_format **current);
void					flag_zero2(t_format **current);
void					flag_hash(t_format **current);

/*
** ------------------------------- pourcent p -------------------------------**
*/

void					ft_printf_pourcent(t_format **current);
void					ft_printf_p(t_format **current, va_list ap);
void					ft_printf_p2(t_format **current,
						unsigned long int value);

/*
** ------------------------------- precision -------------------------------**
*/

void					preci21(char *temp, t_format **current, size_t i,
						size_t precision);
void					preci22(char *temp, t_format **current,
						size_t precision, size_t size);
void					preci2(t_format **current, size_t precision,
						size_t size, char *temp);
void					preci3(t_format **current, char *temp);

/*
** ----------------------------- precision width -----------------------------**
*/

void					check_precision(t_format **current);
void					check_width(t_format **current);
void					check_width2(t_format **current, size_t width);
void					check_width_sup_size(t_format **current, size_t size,
						size_t width);

/*
** --------------------------------- putstri ---------------------------------**
*/

size_t					ft_putstri(char *str);

/*
** -------------------------------- is colors --------------------------------**
*/

int						is_color(char *str);
int						is_bgcolor(char *str);
int						is_effect(char *str);

/*
** --------------------------------- parsing ---------------------------------**
*/

void					do_parsing(char *str, int nb_arg, t_format **current,
						va_list ap);
int						do_parsing2(char *str, t_format **current, int i);

/*
** ------------------------------- recup args -------------------------------**
*/

void					recup_argument2(t_format **current, int j, int i);
void					recup_argument(t_format **current);

#endif
