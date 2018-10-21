// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <vchaus@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 16:28:18 by vchaus            #+#    #+#             //
//   Updated: 2018/10/06 16:28:18 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ncurses.h>
#include <iostream>
#include <ctime>
#include <signal.h>
#include "SpaceField.hpp"

int const	main_win_h = 50;
int const	main_win_w = 80;
WINDOW * 	main_win;

void scrResizeHandler(int)
{
	endwin();
	std::cerr << "Sorry Mario, resizing is forbidden. exit(1) now" << std::endl;
	exit(1);
}


int		main()
{
	int const	top_win_h = 8;
	int const	top_win_w = 80;
	SpaceField	space;

	// ncurses init
	initscr();
	keypad(stdscr, true);
	noecho();
	cbreak();
	curs_set(0);
	nodelay(stdscr, true);
	// start_color();
	refresh();

	//	finding out window position
	int term_h, term_w;
	getmaxyx(stdscr, term_h, term_w);
	if (term_w < main_win_w || term_h < (main_win_h + top_win_h))
	{
		endwin();
		std::cerr << "Terminal window is too small. Resize and try again." << std::endl;
		space.~SpaceField();
		exit(1);
	}
	int		top_win_pos_h = (term_h - (main_win_h + top_win_h)) / 2;
	int 	top_win_pos_w = (term_w - main_win_w) / 2;

	//	creating windows
	WINDOW * top_win = newwin(top_win_h, top_win_w, top_win_pos_h, top_win_pos_w);
	main_win = newwin(main_win_h, main_win_w, top_win_pos_h + top_win_h, top_win_pos_w);
	box(top_win, 0, 0);
	box(main_win, 0, 0);
	wrefresh(top_win);
	wrefresh(main_win);

	signal(SIGWINCH, scrResizeHandler);

	int     input;
	bool	loop_flag = true;
	clock_t	time = clock();
	clock_t	delay = 27000;
	unsigned frames = 0;
	while(loop_flag && space.getShip().getLives())
	{
		input = getch();
		switch (input)
		{
			case KEY_UP:
				space.getShip().shift_one(-1, 0);
				break;
			case KEY_DOWN:
				space.getShip().shift_one(1, 0);
				break;
			case KEY_LEFT:
				space.getShip().shift_one(0, -1);
				break;
			case KEY_RIGHT:
				space.getShip().shift_one(0, 1);
				break;
			case ' ':
				space.setShipBullet(space.getShip().fire());
				break;
			case 'q':
				loop_flag = false;
				break;
		}
		if (clock() > time)
		{
			time += delay;
			frames++;
			// werase(main_win);
			wclear(main_win);

			box(main_win, 0, 0);


			space.showMoon();
			if (frames % 20 == 0)
			{
				space.moveStars();
			}

			if (frames % 7 == 0)
			{
				space.moveEnemies();
				space.generateEnemies();

				space.enemyFire();
			}
			space.moveBullets();
			space.collisions();
			space.showAll();
			space.getShip().show();
			wrefresh(main_win);

			mvwprintw(top_win, 3, 10, "Lives: %d", space.getShip().getLives());
			mvwprintw(top_win, 3, 30, "Score: %d", space.getShip().getScore());
			mvwprintw(top_win, 3, 60, "Frames: %d", frames);
			wrefresh(top_win);
		}
	}
	wclear(top_win);
	wrefresh(top_win);
	wclear(main_win);
	wrefresh(main_win);
	mvwprintw(main_win, 15, 30, "GAME OVER");
	mvwprintw(main_win, 25, 28, "Your score: %d", space.getShip().getScore());
	mvwprintw(main_win, 30, 26, "Press 'q' to quit");
	wrefresh(main_win);
	nodelay(stdscr, false);
	while(true)
	{
		input = getch();
		if (input == 'q')
			break;
	}

	delwin(top_win);
	delwin(main_win);
	endwin();


	return 0;
}
