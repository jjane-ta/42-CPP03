/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:21:52 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/09 19:59:49 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DIAMONDTRAP_H__
# define __DIAMONDTRAP_H__

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

// ************************************************************************** //
//                              DiamondTrap Class                                
// ************************************************************************** //

class DiamondTrap : public FragTrap, public ScavTrap
{

public:

	~DiamondTrap ( void );
	DiamondTrap (const DiamondTrap &diamondtrap);
	DiamondTrap & operator = (const DiamondTrap &diamondtrap);

	DiamondTrap (const std::string & name );

	void	attack(const std::string & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	
	static const std::string	diamondtrap_color; 
	static const std::string	diamondtrap_reset_color;

	void highFivesGuys(void);
	
	static const unsigned int	hit_max = 100;
	static const unsigned int	energy_max = 100;
	static const unsigned int	damage_default = 30;	

/*
	static Singleton*  Instance() {
	static Singleton *p;
		  if(!p) { p = new Singleton; }
	  return p;
	}
*/

 // #### MAKE ClapTrap virtual????
 // #### MAKE DiamondTrap static?????



private:
	
	DiamondTrap ( void );

	bool	_isGuard;

	
};
#endif /* __DIAMONDTRAP_H__ */
