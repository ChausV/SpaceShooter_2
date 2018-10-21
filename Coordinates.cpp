// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Coordinates.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <vchaus@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 18:04:07 by vchaus            #+#    #+#             //
//   Updated: 2018/10/06 18:04:08 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Coordinates.hpp"

Coordinates::Coordinates() : _x(0), _y(0)
{}

Coordinates::Coordinates(int x, int y) : _x(x), _y(y)
{}

Coordinates::Coordinates(Coordinates const & src)
{
	*this = src;
}

Coordinates &	Coordinates::operator=(Coordinates const & src)
{

	if (this == &src)
		return *this;
	_x = src._x;
	_y = src._y;
	return *this;
}

Coordinates::~Coordinates()
{}

Coordinates &	Coordinates::operator++()
{
	_x++;
	return *this;
}

Coordinates &	Coordinates::operator--()
{
	_x--;
	return *this;
}

Coordinates &	Coordinates::operator++(int)
{
	_y++;
	return *this;
}

Coordinates &	Coordinates::operator--(int)
{
	_y--;
	return *this;
}

bool	Coordinates::operator==(Coordinates const & src) const
{
	if (_x == src._x && _y == src._y)
		return true;
	else
		return false;
}

bool	Coordinates::operator!=(Coordinates const & src) const
{
	if (*this == src)
		return false;
	else
		return true;
}

int		Coordinates::getX() const
{
	return _x;
}

int		Coordinates::getY() const
{
	return _y;
}

void	Coordinates::setX(int x)
{
	_x = x;
}

void	Coordinates::setY(int y)
{
	_y = y;
}

void	Coordinates::setXY(int x, int y)
{
	_x = x;
	_y = y;
}

std::ostream &	operator<<(std::ostream & o, Coordinates const & src)
{
	o << "x: " << src.getX() << ", y: " << src.getY();
	return o;
}
