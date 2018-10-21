// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bullet.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <vchaus@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 17:52:09 by vchaus            #+#    #+#             //
//   Updated: 2018/10/06 17:52:10 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bullet.hpp"

Bullet::Bullet() : SpaceObject(1, 1, '*')
{}

Bullet::Bullet(int y, int x) : SpaceObject(y, x, '*')
{}

Bullet::Bullet(int y, int x, char c) : SpaceObject(y, x, c)
{}

Bullet::Bullet(Bullet const & src)
{
	*this = src;
}

Bullet &	Bullet::operator=(Bullet const & src)
{

	if (this == &src)
		return *this;
	this->_body = src._body;
	this->_pos = src._pos;
	return *this;
}

Bullet::~Bullet()
{}
