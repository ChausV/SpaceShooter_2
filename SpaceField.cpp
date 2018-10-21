// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SpaceField.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <vchaus@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 23:46:04 by vchaus            #+#    #+#             //
//   Updated: 2018/10/06 23:46:04 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SpaceField.hpp"

SpaceField::SpaceField() : _ship(main_win_h, main_win_w)
{
	srand(time(NULL));
	for (int i = 0; i < EN_NUM; ++i)
		_enemies[i] = 0;
	for (int i = 0; i < SH_BUL_NUM; ++i)
		_sh_bullets[i] = 0;
	for (int i = 0; i < EN_BUL_NUM; ++i)
		_en_bullets[i] = 0;
	for (int i = 0; i < STARS_NUM; ++i)
		_stars[i] = new Bullet((rand() % (main_win_h - 3)) + 1, (rand() % (main_win_w - 3)) + 1, '.');
}

SpaceField::SpaceField(SpaceField const & src)
{
	*this = src;
}

SpaceField &	SpaceField::operator=(SpaceField const & src)
{
	if (this == &src)
		return *this;
	_ship = src._ship;

	for (int i = 0; i < EN_NUM; ++i)
	{
		if (src._enemies[i] == 0)
			_enemies[i] = 0;
		else
			_enemies[i] = new Enemy(*((src._enemies)[i]));
	}
	for (int i = 0; i < SH_BUL_NUM; ++i)
	{
		if (src._sh_bullets[i] == 0)
			_sh_bullets[i] = 0;
		else
			_sh_bullets[i] = new Bullet(*((src._sh_bullets)[i]));
	}
	for (int i = 0; i < EN_BUL_NUM; ++i)
	{
		if (src._en_bullets[i] == 0)
			_en_bullets[i] = 0;
		else
			_en_bullets[i] = new Bullet(*((src._en_bullets)[i]));
	}
	for (int i = 0; i < STARS_NUM; ++i)
	{
		if (src._stars[i] == 0)
			_stars[i] = 0;
		else
			_stars[i] = new Bullet(*((src._stars)[i]));
	}

	return *this;
}

SpaceField::~SpaceField()
{}

Ship &	SpaceField::getShip()
{
	return _ship;
}


void	SpaceField::generateEnemies()
{
	for(int i = 0; i < EN_NUM; ++i)
	{
		if (_enemies[i] == 0)
		{
			_enemies[i] = new Enemy((rand() % (main_win_w - 3)) + 1);
			return ;
		}
	}
}

void	SpaceField::moveEnemies()
{
	for(int i = 0; i < EN_NUM; ++i)
	{
		if (_enemies[i] != 0 && !_enemies[i]->shift_one(1, 0))
		{
			delete _enemies[i];
			_enemies[i] = 0;
		}
	}
}

void	SpaceField::moveStars()
{
	for(int i = 0; i < STARS_NUM; ++i)
	{
		if (!_stars[i]->shift_one(1, 0))
		{
			_stars[i]->moveTo(1, _stars[i]->getPos().getX());
		}
	}
}

void	SpaceField::collisions()
{
	// shipBullets and enemies
	for (int i = 0; i < SH_BUL_NUM; ++i)
	{
		if (_sh_bullets[i] != 0)
		{
			for(int j = 0; j < EN_NUM; ++j)
			{
				if (_enemies[j] != 0)
				{
					Coordinates tmp(_sh_bullets[i]->getPos());
					tmp--;
					if (_sh_bullets[i]->getPos() == _enemies[j]->getPos() || tmp == _enemies[j]->getPos())
					{
						delete _sh_bullets[i];
						delete _enemies[j];
						_sh_bullets[i] = 0;
						_enemies[j] = 0;
						_ship.incrScore();
						break;
					}
				}
			}
		}
	}
	// ship and enemies
	for(int i = 0; i < EN_NUM; ++i)
	{
		if (_enemies[i] != 0)
		{
			Coordinates tmp(_enemies[i]->getPos());
			tmp++;
			if (_enemies[i]->getPos() == _ship.getPos() || tmp == _ship.getPos())
			{
				delete _enemies[i];
				_enemies[i] = 0;
				beep();
				flash();
				_ship.decrLives();
				break;
			}
		}
	}
	// ship and enemyBullets
	for(int i = 0; i < EN_BUL_NUM; ++i)
	{
		if (_en_bullets[i] != 0)
		{
			Coordinates tmp(_en_bullets[i]->getPos());
			tmp++;
			if (_ship.getPos() == _en_bullets[i]->getPos() || _ship.getPos() == tmp)
			{
				delete _en_bullets[i];
				_en_bullets[i] = 0;
				beep();
				flash();
				_ship.decrLives();
				break;
			}
		}
	}
}

void	SpaceField::showAll()
{
	for (int i = 0; i < STARS_NUM; ++i)
		_stars[i]->show();
	for(int i = 0; i < SH_BUL_NUM; ++i)
	{
		if (_sh_bullets[i] != 0)
			_sh_bullets[i]->show();
	}
	for(int i = 0; i < EN_BUL_NUM; ++i)
	{
		if (_en_bullets[i] != 0)
			_en_bullets[i]->show();
	}
	for(int i = 0; i < EN_NUM; ++i)
	{
		if (_enemies[i] != 0)
			_enemies[i]->show();
	}
}

void	SpaceField::setShipBullet(Bullet * bullet)
{
	if (!bullet)
		return ;
	for (int i = 0; i < SH_BUL_NUM; ++i)
	{
		if (_sh_bullets[i] == 0)
		{
			_sh_bullets[i] = bullet;
			return ;
		}
	}
}

void	SpaceField::setEnemyBullet(Bullet * bullet)
{
	if (!bullet)
		return ;
	for (int i = 0; i < EN_BUL_NUM; ++i)
	{
		if (_en_bullets[i] == 0)
		{
			_en_bullets[i] = bullet;
			return ;
		}
	}
}

void	SpaceField::enemyFire()
{
	for (int i = 0; i < EN_NUM; ++i)
	{
		if ((rand() % 100) == 0 && _enemies[i])
		{
			// wprintw(main_win, "here");
			setEnemyBullet(_enemies[i]->fire());
		}
	}
}

void	SpaceField::moveBullets()
{
	for(int i = 0; i < SH_BUL_NUM; ++i)
	{
		if (_sh_bullets[i] != 0 && !_sh_bullets[i]->shift_one(-1, 0))
		{
			delete _sh_bullets[i];
			_sh_bullets[i] = 0;
		}
	}
	for(int i = 0; i < EN_BUL_NUM; ++i)
	{
		if (_en_bullets[i] != 0 && !_en_bullets[i]->shift_one(1, 0))
		{
			delete _en_bullets[i];
			_en_bullets[i] = 0;
		}
	}
}

void	SpaceField::showMoon() const
{
	int		x = 2;
	int		y = 3;
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	wattron(main_win, COLOR_PAIR(1));
	for (int i = 0; i < 15; ++i)
	{
		mvwprintw(main_win, y + i, x, "%s", SpaceField::moon[i]);
	}
	wattroff(main_win, COLOR_PAIR(1));
}

	char	SpaceField::moon[15][38] = {
"            ______-----____          ",
"         .--               ---.      ",
"      ./   ()      .-.         \\.   ",
"     /   o    .   (   )          \\  ",
"   / .             '-'            \\ ",
"  | ()    .  O              .      | ",
"|                                   |",
"|       o               ()          |",
"|         .--.                 O    |",
" | .     |    |                    | ",
"  \\     `.__.'        o     .     / ",
"   \\                             /  ",
"      `\\    o      ()         /'    ",
"        `--____      ______---'      ",
"                ----                 " };

