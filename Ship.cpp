// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ship.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <vchaus@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 17:53:57 by vchaus            #+#    #+#             //
//   Updated: 2018/10/06 17:53:57 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Ship.hpp"

Ship::Ship() : SpaceObject(1, 1, 'X')
{
	_lives = 5;
	_score = 0;
}

Ship::Ship(int h, int w) : SpaceObject(h - 2, w / 2, 'X')
{
	_lives = 5;
	_score = 0;
}

Ship::Ship(Ship const & src) : SpaceObject(src)
{
	this->setLives(src.getLives());
	this->setScore(src.getScore());
}

Ship &	Ship::operator=(Ship const & src)
{
	if (this == &src)
		return *this;
	this->setLives(src.getLives());
	this->setScore(src.getScore());
	this->_pos = src._pos;
	this->_body = src._body;
	return *this;
}

Ship::~Ship()
{}


Bullet *	Ship::fire() const
{
	return new Bullet(_pos.getY() - 1, _pos.getX());
}


int		Ship::getLives() const
{
	return _lives;
}

void	Ship::setLives(int lives)
{
	if (lives >= 0)
		_lives = lives;
}

void	Ship::decrLives()
{
	if (_lives != 0)
		_lives--;
}

int		Ship::getScore() const
{
	return _score;
}

void	Ship::setScore(int score)
{
	_score = score;
}

void	Ship::incrScore()
{
	_score++;
}

