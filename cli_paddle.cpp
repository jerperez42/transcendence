/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_paddle.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:13:00 by jerperez          #+#    #+#             */
/*   Updated: 2024/11/12 18:09:58 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	_print_paddle_unicode(int index, char const **chars)
{
	std::cout << chars[index] << "\e[1B\e[1D"; //1D or 3D?
}

static void _print_paddle(int length, int at_top, char const **chars)
{
	if (!at_top)
	{
		_print_paddle_unicode(2, chars);
		length -= 1;
	}
	while (2 <= length)
	{
		_print_paddle_unicode(1, chars);
		length -= 2;
	}
	if (1 == length)
		_print_paddle_unicode(0, chars);
}

static void _print_left(int length, int at_top)
{
	const char *paddle[3] = {"▝", "▐", "▗"};

	_print_paddle(length, at_top, paddle);
}

static void _print_right(int length, int at_top)
{
	const char *paddle[3] = {"▘", "▌", "▖"};

	_print_paddle(length, at_top, paddle);
}

int	cli_paddle(int length_pix, int at_top, int is_left)
{
	if (is_left)
		_print_left(length_pix, at_top);
	else
		_print_right(length_pix, at_top);
	return 0;
}

// #include <cstdlib> 
// int main (int ac, char *av[])
// {
// 	if (4 != ac)
// 		return 2;
// 	const int ret = cli_paddle(std::atoi(av[1]), std::atoi(av[2]), std::atoi(av[3]));

// 	std::cout << std::endl;
// 	return ret;
// }
