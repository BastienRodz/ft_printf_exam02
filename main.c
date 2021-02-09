/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:05:47 by barodrig          #+#    #+#             */
/*   Updated: 2021/02/08 15:40:52 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int		main(void)
{
	char *str;
	str = "prout";

					printf("\n\n                               STRINGS TEST\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un prout\n"));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un prout\n"));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %s\n", str));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %s\n", str));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.5s\n", str));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.5s\n", str));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.2s\n", str));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.2s\n", str));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.0s\n", str));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.0s\n", str));

	printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10s\n", NULL));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10s\n", NULL));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.20s\n", str));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.20s\n", str));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %3s\n", str));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %3s\n", str));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");
					printf("\n\n                               INTEGERS TEST\n\n");
	int i;
	i = 123;

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %d\n", i));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %d\n", i));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.5d\n", i));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.5d\n", i));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.2d\n", i));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.2d\n", i));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.0d\n", i));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.0d\n", i));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.20d\n", i));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.20d\n", i));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %3d\n", i));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %3d\n", i));


		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	i = -12;

		printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %d\n", i));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %d\n", i));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.5d\n", i));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.5d\n", i));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.2d\n", i));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.2d\n", i));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.0d\n", i));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.0d\n", i));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.20d\n", i));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.20d\n", i));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %3d\n", i));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %3d\n", i));

			printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %3i\n", -2147483647));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %3d\n", -2147483647));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %3d\n", 2147483647));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %3d\n", 2147483647));

			printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %3d\n", 0));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %3d\n", 0));

			printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");
					printf("\n\n                               HEXADECIMALS TEST\n\n");
	unsigned int j;
	j = 28036591;

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %x\n", j));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %x\n", j));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.5x\n", j));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.5x\n", j));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.2x\n", j));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.2x\n", j));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.0x\n", j));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.0x\n", j));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.20x\n", j));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.20x\n", j));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %3x\n", j));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %3x\n", j));


		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	j = -28036591;

		printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %x\n", j));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %x\n", j));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.5x\n", j));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.5x\n", j));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.2x\n", j));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.2x\n", j));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.0x\n", j));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.0x\n", j));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %10.20x\n", j));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %10.20x\n", j));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %3x\n", j));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %3x\n", j));

			printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %3x\n", -2147483647));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %3x\n", -2147483647));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %3x\n", 2147483647));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %3x\n", 2147483647));

			printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %3x\n", 0));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %3x\n", 0));

		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n");

	printf("RETURN PRINTF = %d\n\n", printf("Ceci est un %3x\n", -4000000000));
	printf("RETURN FT_PRINTF = %d\n\n", ft_printf("Ceci est un %3x\n", -4000000000));


	return (0);
}
