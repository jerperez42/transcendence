/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_score_put09.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:13:00 by jerperez          #+#    #+#             */
/*   Updated: 2024/11/12 18:06:19 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

typedef void (*_t_print_num)(void);

static void _print_num(\
	char const *top, \
	char const *tmd, \
	char const *bmd, \
	char const *bot)
{
	std::cout	<< top << "\e[1B\e[3D" \
				<< tmd << "\e[1B\e[3D" \
				<< bmd << "\e[1B\e[3D" \
				<< bot;
}

static void _print_0(void)
{
	_print_num( \
				"▛▀▜", \
				"▌ ▐", \
				"▌ ▐", \
				"▙▄▟"  \
				);
}

static void _print_1(void)
{
	_print_num( \
				"  ▐", \
				"  ▐", \
				"  ▐", \
				"  ▐"  \
				);
}

static void _print_2(void)
{
	_print_num( \
				"▀▀▜", \
				"▄▄▟", \
				"▌  ",  \
				"▙▄▄"  \
				);
}

static void _print_3(void)
{
	_print_num( \
				"▀▀▜", \
				"▄▄▟", \
				"  ▐",  \
				"▄▄▟"  \
				);
}

static void _print_4(void)
{
	_print_num( \
				"▌ ▐", \
				"▙▄▟", \
				"  ▐",  \
				"  ▐"  \
				);
}

static void _print_5(void)
{
	_print_num( \
				"▛▀▀", \
				"▙▄▄", \
				"  ▐",  \
				"▄▄▟"  \
				);
}

static void _print_6(void)
{
	_print_num( \
				"▛▀▀", \
				"▙▄▄", \
				"▌ ▐",  \
				"▙▄▟"  \
				);
}

static void _print_7(void)
{
	_print_num( \
				"▀▀▜", \
				"  ▐", \
				"  ▐",  \
				"  ▐"  \
				);
}

static void _print_8(void)
{
	_print_num( \
				"▛▀▜", \
				"▙▄▟", \
				"▌ ▐",  \
				"▙▄▟"  \
				);
}


static void _print_9(void)
{
	_print_num( \
				"▛▀▜", \
				"▙▄▟", \
				"  ▐",  \
				"▄▄▟"  \
				);
}

int cli_score_put09(int num)
{
	if (0 > num || 9 < num)
		return 1;
	const _t_print_num fun[10] = {&_print_0, &_print_1, &_print_2, \
									&_print_3, &_print_4, &_print_5, \
									&_print_6, &_print_7, &_print_8, \
									&_print_9};
	(fun[num])();
	return 0;
}

// int main (int ac, char *av[])
// {
// 	if (2 != ac || '\0' == av[1][0])
// 		return 2;
// 	int const ret = cli_score_put09(av[1][0] - '0');

// 	std::cout << std::endl;
// 	return ret;
// }
