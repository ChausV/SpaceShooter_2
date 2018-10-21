// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SpaceObject.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <vchaus@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 17:50:29 by vchaus            #+#    #+#             //
//   Updated: 2018/10/06 17:50:29 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SpaceObject.hpp"

SpaceObject::SpaceObject()
{
	_pos = Coordinates(0, 0);
	_body = ' ';
}

SpaceObject::SpaceObject(int y, int x, char c)
{
	_pos = Coordinates(x, y);
	_body = c;
}

SpaceObject::SpaceObject(SpaceObject const & src)
{
	*this = src;
}

SpaceObject &	SpaceObject::operator=(SpaceObject const & src)
{
	if (this == &src)
		return *this;
	_pos = src._pos;
	_body = src._body;
	return *this;
}

SpaceObject::~SpaceObject()
{}


Coordinates const &	SpaceObject::getPos() const
{
	return _pos;
}

char			SpaceObject::getBody() const
{
	return _body;
}

void			SpaceObject::show() const
{
	mvwprintw(main_win, _pos.getY(), _pos.getX(), "%c", _body);
	// wrefresh(win);
}

bool			SpaceObject::shift_one(int y, int x)
{
	if (y > 0)
	{
		if (_pos.getY() == (main_win_h - 2))
			return false;
		else
			_pos++;
	}
	if (y < 0)
	{
		if (_pos.getY() == 1)
			return false;
		else
			_pos--;
	}
	if (x > 0)
	{
		if (_pos.getX() == (main_win_w - 2))
			return false;
		else
			++_pos;
	}
	if (x < 0)
	{
		if (_pos.getX() == 1)
			return false;
		else
			--_pos;
	}
	return true;
}

bool			SpaceObject::moveTo(int y, int x)
{
	if (x > main_win_w - 2 || x < 1 || y > main_win_h - 2 || y < 1)
		return false;
	_pos.setXY(x, y);
	return true;
}

