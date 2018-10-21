// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Coordinates.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <vchaus@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 18:04:02 by vchaus            #+#    #+#             //
//   Updated: 2018/10/06 18:04:02 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef COORDINATES_HPP
# define COORDINATES_HPP

# include <iostream>

class Coordinates
{
public:
	Coordinates();
	Coordinates(int x, int y);
	Coordinates(Coordinates const & src);
	Coordinates &	operator=(Coordinates const & src);
	~Coordinates();

	Coordinates &	operator++();
	Coordinates &	operator--();
	Coordinates &	operator++(int);
	Coordinates &	operator--(int);

	bool	operator==(Coordinates const & src) const;
	bool	operator!=(Coordinates const & src) const;

	int		getX() const;
	int		getY() const;
	void	setX(int x);
	void	setY(int y);
	void	setXY(int x, int y);

protected:

private:
	int		_x;
	int		_y;

};
std::ostream &	operator<<(std::ostream & o, const Coordinates & src);

#endif

