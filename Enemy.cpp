// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <vchaus@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 17:54:18 by vchaus            #+#    #+#             //
//   Updated: 2018/10/06 17:54:18 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Enemy.hpp"

Enemy::Enemy() : SpaceObject(1, 1, '0')
{}

Enemy::Enemy(int x) : SpaceObject(1, x, '0')
{}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
}

Enemy &	Enemy::operator=(Enemy const & src)
{

	if (this == &src)
		return *this;
	this->_body = src._body;
	this->_pos = src._pos;
	return *this;
}

Enemy::~Enemy()
{}

Bullet *	Enemy::fire() const
{
	if (_pos.getY() < (main_win_h / 2))
		return new Bullet(_pos.getY() + 1, _pos.getX());
	else
		return 0;
}
