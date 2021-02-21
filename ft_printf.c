/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:45:44 by barodrig          #+#    #+#             */
/*   Updated: 2021/02/19 12:27:18 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

typedef	struct	s_pf
{
	int	width;
	int	width_after;
	int	point;
	int	zero;
}				t_pf;

int			ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int			ft_istype(char c)
{
	if (c == 's' || c == 'x' || c == 'd')
		return (1);
	else
		return (0);
}

t_pf		ft_init_flags(void)
{
	t_pf flags;

	flags.width = 0;
	flags.width_after = 0;
	flags.point = 0;
	flags.zero = 0;

	return (flags);
}

int			ft_strlen(const char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

const char	*ft_strdup(const char *str)
{
	int 	len;
	int 	i;
	char	*content;

	len = ft_strlen(str);
	if(!(content = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while(str[i])
	{
		content[i] = str[i];
		i++;
	}
	content[i] = '\0';
	return (content);
}

long int	ft_change_sign(long int nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

int			ft_sign(int n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
}

int			ft_len(long int nbr)
{
	int len;

	if (nbr <= 0)
		len = 1;
	else
		len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*str;

	sign = ft_sign(n);
	len = ft_len(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = '0' + ft_change_sign(n % 10);
		n = n / 10;
		len--;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

int			ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int			ft_putnstr(char *str, int n)
{
	int i;

	i = 0;
	if (!str)
		return (i);
	while (i < n)
		ft_putchar(str[i++]);
	return (i);
}

int		ft_width_manager(int width, int width_after, int zero)
{
	int count;

	count = 0;
	while (width - width_after > 0)
	{
		if (zero == 1)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
		width--;
	}
	return (count);
}

char	*ft_hextoa_base(unsigned long long nbr)
{
	char	*tab;
	char	*base;
	char	tmp;
	int		i;
	int		j;

	base = "0123456789abcdef";
	i = 0;
	tab = malloc(sizeof(char) * 25);
	if (nbr == 0)
		tab[i] = base[nbr % 16];
	while (nbr)
	{
		tab[i++] = base[nbr % 16];
		nbr /= 16;
	}
	j = 0;
	if (i == 0)
		i++;
	while (j < i / 2)
	{
		tmp = tab[j];
		tab[j] = tab[i - 1 - j];
		tab[i - 1 - j] = tmp;
		j++;
	}
	tab[i] = '\0';
	return (tab);
}

int		ft_hex_manager(t_pf flags, unsigned int nbr)
{
	int					count;
	char				*strnbr;

	count = 0;
	if (nbr == 0 && flags.width_after == 0 && flags.point == 1)
	{
		count += ft_width_manager(flags.width, 0, 0);
		return (count);
	}
	strnbr = ft_hextoa_base((unsigned long long)nbr);
	if (flags.width_after < ft_strlen(strnbr) && flags.point == 1)
		flags.width_after = ft_strlen(strnbr);
	if (flags.point == 1)
	{
		flags.width = flags.width - flags.width_after;
		count += ft_width_manager(flags.width, 0, 0);
	}
	else
		count += ft_width_manager(flags.width, ft_strlen(strnbr), flags.zero);
	if (flags.point == 1)
		count += ft_width_manager(flags.width_after - 1, ft_strlen(strnbr) - 1, 1);
	count += ft_putnstr(strnbr, ft_strlen(strnbr));
	free(strnbr);
	return (count);
}

int		ft_int_manager(t_pf flags, int nbr)
{
	int		count;
	int		temp_nbr;
	char	*strnbr;

	temp_nbr = nbr;
	count = 0;
	if (nbr == 0 && flags.width_after == 0 && flags.point == 1)
	{
		count += ft_width_manager(flags.width, 0, 0);
		return (count);
	}
	if (flags.point == 1 && nbr < 0)
	{
		nbr = -nbr;
		flags.zero = 1;
		flags.width--;
	}
	strnbr = ft_itoa(nbr);
	if (flags.width_after < ft_strlen(strnbr) && flags.point == 1)
		flags.width_after = ft_strlen(strnbr);
	if (flags.point == 1)
		count += ft_width_manager(flags.width, flags.width_after, 0);
	else
		count += ft_width_manager(flags.width, ft_strlen(strnbr), 0);
	if (flags.point == 1 && temp_nbr < 0)
		count += ft_putchar('-');
	if (flags.point == 1)
		count += ft_width_manager(flags.width_after, ft_strlen(strnbr), 1);
	count += ft_putnstr(strnbr, ft_strlen(strnbr));
	free(strnbr);
	return (count);
}

int			ft_string_manager(t_pf flags, char *str)
{
	int count;
	int i;

	i = 0;
	count = 0;
	if (str == NULL)
		str = "(null)";
	if (flags.point == 1 && flags.width_after > ft_strlen(str))
		flags.width_after = ft_strlen(str);
	if (flags.point == 0)
	{
		flags.width_after = ft_strlen(str);
		count += ft_width_manager(flags.width, flags.width_after, 0);
	}
	if (flags.point == 1)
	{
		count += ft_width_manager(flags.width, flags.width_after, 0);
		count += ft_putnstr(str, flags.width_after);
	}
	else
		count += ft_putnstr(str, ft_strlen(str));
	return (count);
}

int			content_manager(const char *content, va_list args)
{
	int		i;
	int		count;
	t_pf	flags;

	i = 0;
	count = 0;
	flags = ft_init_flags();
	while (content[i])
	{
		flags = ft_init_flags();
		if (content[i] == '%' && content[i + 1])
		{
			i++;
			while (content[i])
			{
				if (!ft_istype(content[i]) && !ft_isdigit(content[i]) && content[i] != '.')
					break ;
				if (content[i] == '.')
				{
					i++;
					flags.point = 1;
					while (ft_isdigit(content[i]))
					{
						flags.width_after = (flags.width_after * 10) + (content[i] - '0');
						i++;
					}
				}
				if (ft_istype(content[i]))
					break ;
				if (ft_isdigit(content[i]))
					flags.width = (flags.width * 10) + (content[i] - '0');
				i++;
			}
			if (ft_istype(content[i]))
			{
				if (content[i] == 's')
					count += ft_string_manager(flags, va_arg(args, char*));
				if (content[i] == 'd')
					count += ft_int_manager(flags, va_arg(args, int));
				if (content[i] == 'x')
					count += ft_hex_manager(flags, va_arg(args, unsigned int));
			}
			else if (content[i])
				count += ft_putchar(content[i]);
		}
		else if (content[i] != '%')
			count += ft_putchar(content[i]);
		i++;
	}
	return (count);
}

int			ft_printf(const char *input, ...)
{
	int				count;
	const char		*content;
	va_list			args;

	count = 0;
	content = ft_strdup(input);
	va_start(args, input);
	count = content_manager(content, args);
	va_end(args);
	free((char *)content);
	return (count);
}
