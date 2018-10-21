// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SpaceObject.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <vchaus@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 17:50:24 by vchaus            #+#    #+#             //
//   Updated: 2018/10/06 17:50:24 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPACE_OBJECT_HPP
# define SPACE_OBJECT_HPP

# include "Coordinates.hpp"
# include <ncurses.h>

extern int const	main_win_h;
extern int const	main_win_w;
extern WINDOW * 	main_win;

class SpaceObject
{
public:
	SpaceObject();
	SpaceObject(int x, int y, char c);
	SpaceObject(SpaceObject const & src);
	SpaceObject &	operator=(SpaceObject const & src);
	virtual ~SpaceObject();

	Coordinates const &	getPos() const;
	char				getBody() const;
	bool				moveTo(int x, int y);
	bool				shift_one(int y, int x);

	void			show() const;

protected:
	Coordinates		_pos;

	char			_body;

private:

};

#endif
