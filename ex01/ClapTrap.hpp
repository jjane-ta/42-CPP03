/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:53:56 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/08 16:20:39 by jjane-ta         ###   ########.fr       */
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

	virtual ~ClapTrap ( void );
	ClapTrap (const ClapTrap &claptrap);
	ClapTrap & operator = (const ClapTrap &claptrap);

	ClapTrap (const std::string & name );

	void	attack(const std::string & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string	get_name( void ) const;	

private:

	ClapTrap ( void );
	
//	static const unsigned int	repair_cost = 1;
//	static const unsigned int	attack_cost = 1;
	
	static const unsigned int	hit_max = 10;
	static const unsigned int	energy_max = 10;
	static const unsigned int	damage_clap_trap = 0;	


	
	static ClapTrap	*bot_list;
	std::string	_name;
	unsigned int		_hit_points;
	unsigned int		_energy_points;
	unsigned int		_attack_damage;

	ClapTrap	*get_ClapTrap_instanceByName(const std::string & name);

	ClapTrap	*_next;
	ClapTrap	*_prev;

};

#endif /* __CLAPTRAP_H__ */


