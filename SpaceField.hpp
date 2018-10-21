// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SpaceField.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <vchaus@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 23:45:58 by vchaus            #+#    #+#             //
//   Updated: 2018/10/06 23:45:58 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPACE_FIELD_HPP
# define SPACE_FIELD_HPP

# include "Ship.hpp"
# include "Enemy.hpp"
# include "Bullet.hpp"
# include <cstdlib>

# define EN_NUM 100
# define SH_BUL_NUM 100
# define EN_BUL_NUM 100
# define STARS_NUM 30

extern int const	main_win_h;
extern int const	main_win_w;
extern WINDOW *		main_win;

class SpaceField
{
public:
	SpaceField();
	SpaceField(SpaceField const & src);
	SpaceField &	operator=(SpaceField const & src);
	~SpaceField();

	Ship &	getShip();

	void	generateEnemies();
	void	moveEnemies();


	void	collisions();


	void	moveBullets();
	void	moveStars();

	void	showAll();

	void	setShipBullet(Bullet * bullet);
	void	setEnemyBullet(Bullet * bullet);
	void	enemyFire();

	void	showMoon() const;

protected:

private:
	Ship 		_ship;
	Enemy *		_enemies[EN_NUM];
	Bullet *	_sh_bullets[SH_BUL_NUM];
	Bullet *	_en_bullets[EN_BUL_NUM];
	Bullet *	_stars[STARS_NUM];

	static	char	moon[15][38];
};

#endif
