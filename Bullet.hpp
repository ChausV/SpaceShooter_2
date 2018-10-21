// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bullet.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <vchaus@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 17:52:04 by vchaus            #+#    #+#             //
//   Updated: 2018/10/06 17:52:04 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BULLET_HPP
# define BULLET_HPP

# include "SpaceObject.hpp"

class Bullet : public SpaceObject
{
public:
	Bullet();
	Bullet(int y, int x);
	Bullet(int y, int x, char c);
	Bullet(Bullet const & src);
	Bullet &	operator=(Bullet const & src);
	virtual ~Bullet();

protected:

private:

};

#endif
