// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ship.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <vchaus@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 17:53:52 by vchaus            #+#    #+#             //
//   Updated: 2018/10/06 17:53:52 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SHIP_HPP
# define SHIP_HPP

# include "SpaceObject.hpp"
# include "Bullet.hpp"

class Ship : public SpaceObject
{
public:
	Ship();
	Ship(int h, int w);
	Ship(Ship const & src);
	Ship &	operator=(Ship const & src);
	virtual ~Ship();

	Bullet *	fire() const;

	int		getLives() const;
	void	setLives(int lives);
	void	decrLives();
	int		getScore() const;
	void	setScore(int score);
	void	incrScore();

protected:

private:
	int		_lives;
	int		_score;

};

#endif
