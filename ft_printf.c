/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:45:44 by barodrig          #+#    #+#             */
/*   Updated: 2021/02/05 17:17:40 by barodrig         ###   ########.fr       */
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
	if (c == 'd' || c == 'x' || c == 'd')
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
	while (width_after - width_after > 0)
	{
		if (zero == 1)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
		width--;
	}
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
	printf("FT_STRLEN STR = %i\n", ft_strlen(str));
	if (flags.point == 1 && flags.width == 0)
		return (count);
	if (flags.point == 0)
		flags.width_after = ft_strlen(str);
	count += ft_width_manager(flags.width, flags.width_after, 0);
	if (flags.point == 1)
	{
		count += ft_width_manager(flags.width_after, ft_strlen(str), 0);
		count += ft_putnstr(str, flags.width_after);
	}
	else
		count += ft_putnstr(str, ft_strlen(str));
	return(count);
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
				printf("\nPROUT\n");
				if (!ft_istype(content[i]) && !ft_isdigit(content[i]) && content[i] != '.')
					break ;
				if (content[i] == '.')
				{
					i++;
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
