/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_controller.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:13:45 by jerperez          #+#    #+#             */
/*   Updated: 2024/11/12 18:52:28 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <iostream>
#include <cstring>

static bool	_is_eof(ssize_t bread, char *buff)
{
	return (1 == bread && 4 == buff[0]);
}

static int _get_stdin(void)
{
	return fileno(stdin);
}

static int _tcsaveattr(struct termios old_termios)
{
	return tcgetattr(_get_stdin(), &old_termios );
}

static int _tcchangeattr(struct termios old_termios, struct termios new_termios)
{
	new_termios = old_termios;
	new_termios.c_lflag &= (~ICANON & ~ECHO);
	return tcsetattr(_get_stdin(), TCSANOW, &new_termios ); 
}

static int _tcloadattr(struct termios old_termios, struct termios new_termios)
{
	return tcsetattr(_get_stdin(), TCSANOW, &old_termios );
}

int main()
{
	struct termios	old_termios;
	struct termios	new_termios;
	char			buff[10];
	ssize_t			bread;

	_tcsaveattr(old_termios );
	_tcchangeattr(old_termios, new_termios);

	buff[0] = '\0';
	bread = 1;
	while (0 < bread && false == _is_eof(bread, buff))
	{
		printf( "Input available\n" );
		bread = read( fileno( stdin ), &buff, 10 );
		if (-1 != bread)
			buff[bread] = '\0';
		std::cout << (int)buff[0] << "|" << bread << std::endl;
	}

	tcsetattr( fileno( stdin ), TCSANOW, &old_termios );
	return 0;
}
