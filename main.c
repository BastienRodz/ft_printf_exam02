/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:05:47 by barodrig          #+#    #+#             */
/*   Updated: 2021/02/05 16:20:15 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int		main(int argc, char **argv)
{
	(void)argc;
	printf("\nCeci est un prout\n");
	ft_printf("Ceci est un prout\n");

	printf("Ceci est un %s\n", argv[1]);
	ft_printf("Ceci est un %s\n", argv[1]);

	printf("\nCeci est un %10s\n", argv[1]);
	ft_printf("Ceci est un %10s\n", argv[1]);

	printf("\nCeci est un %10.0s\n", argv[1]);
	ft_printf("Ceci est un %10.0s\n", argv[1]);

	return (0);
}
