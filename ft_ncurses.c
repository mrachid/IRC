/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 10:14:10 by mrachid           #+#    #+#             */
/*   Updated: 2015/03/09 10:14:11 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_ncurse	*init_curses(void)
{
	t_ncurse		*curs;

	curs = (t_ncurse*)malloc(sizeof(t_ncurse));
	initscr();
	clear();
	curs_set(0);
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, curs->row, curs->col);
	curs->win_chat = newwin(curs->row * 9 / 10, curs->col * 8 / 10, 0, 0);
	curs->win_member = newwin(curs->row * 6 / 10, curs->col * 2 / 10, 0,
		curs->col * 8 / 10);
	curs->win_channel = newwin(curs->row * 3 / 10, curs->col * 2 / 10,
		curs->row * 6 / 10, curs->col * 8 / 10);
	curs->win_term = newwin(curs->row * 1 / 10, curs->col,
		curs->row * 9 / 10, 0);
	return (curs);
}

void		end_curses(t_ncurse *curs)
{
	nodelay(stdscr, TRUE);
	wrefresh(curs->win_term);
	wrefresh(curs->win_chat);
	clear();
	endwin();
}

void		draw_irc(t_ncurse *curs)
{
	wclear(curs->win_term);
	box(curs->win_term, 0, 0);
	box(curs->win_chat, 0, 0);
	box(curs->win_member, 0, 0);
	box(curs->win_channel, 0, 0);
	wrefresh(curs->win_chat);
	wrefresh(curs->win_member);
	wrefresh(curs->win_channel);
	mvwprintw(curs->win_term, 1, 3, "Enter your message => ");
	mvwprintw(curs->win_member, 1, 3, "List members :");
	mvwprintw(curs->win_channel, 1, 3, "List channels :");
	mvwprintw(curs->win_channel, 3, 3, "#B2C");
	mvwprintw(curs->win_channel, 4, 3, "#HEC");
	mvwprintw(curs->win_channel, 5, 3, "#PEDAGO");
	mvwprintw(curs->win_channel, 6, 3, "#STAFF");
	mvwprintw(curs->win_channel, 7, 3, "#PUBLIC");
	wrefresh(curs->win_term);
	wrefresh(curs->win_member);
	wrefresh(curs->win_channel);
}