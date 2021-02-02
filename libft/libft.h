/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstannis <cstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 21:53:09 by cstannis          #+#    #+#             */
/*   Updated: 2021/02/02 05:51:11 by cstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

void		*ft_memset(void *dest, int c, size_t len);
void		ft_bzero(void *s, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t len);
void		*ft_memccpy(void *dst, const void *src, int c, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t len);
int			ft_memcmp(const void *s1, const void *s2, size_t len);
int			ft_atoi (const char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t len);
size_t		ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t len);
char		*ft_strnstr(const char *big, const char *small, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_ltoa_dec(long n);
int			ft_nblen(long nb, int base);
int			ft_cmpstr(char *s1, char *s2);
void		ft_toupper_str(char *str);
char		*ft_ultoa_hex(unsigned long long n);
int			ft_nblen(long nb, int base);
int			ft_cmpstr(char *s1, char *s2);
#endif
