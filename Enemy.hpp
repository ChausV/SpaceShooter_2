// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <vchaus@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 17:54:13 by vchaus            #+#    #+#             //
//   Updated: 2018/10/06 17:54:13 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "SpaceObject.hpp"
# include "Bullet.hpp"

class Enemy : public SpaceObject
{
public:
	Enemy();
	Enemy(int x);
	Enemy(Enemy const & src);
	Enemy &	operator=(Enemy const & src);
	virtual ~Enemy();

	Bullet *	fire() const;

protected:

private:

};

#endif
