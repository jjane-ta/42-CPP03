/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:53:56 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/13 19:36:24 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CLAPTRAP_H__
# define __CLAPTRAP_H__

# include <string>
# include <iostream>

// ************************************************************************** //
//                              ClapTrap Class                                
// ************************************************************************** //

class ClapTrap {

public:

	virtual	~ClapTrap ( void );
	ClapTrap (const ClapTrap &claptrap);
	ClapTrap & operator = (const ClapTrap &claptrap);

	ClapTrap (const std::string & name );

	void	attack(const std::string & target);
	void	takeDamage(unsigned int amount);
	virtual void	beRepaired(unsigned int amount);
	
	static const unsigned int	hit_max = 10;
	static const unsigned int	energy_max = 10;
	static const unsigned int	damage_default = 0;	


protected:

	ClapTrap ( void );
	const std::string		_name;
	unsigned int	_hit_points;
	unsigned int	_energy_points;
	unsigned int	_attack_damage;

private: 

	static ClapTrap	*bot_list;
	ClapTrap	*get_ClapTrap_instanceByName(const std::string & name);
	ClapTrap	*_next;
	ClapTrap	*_prev;

};

#endif /* __CLAPTRAP_H__ */


