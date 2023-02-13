/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:21:52 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/13 18:59:02 by jjane-ta         ###   ########.fr       */
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

class DiamondTrap : public ScavTrap , public FragTrap 
{

public:

	virtual ~DiamondTrap ( void );
	DiamondTrap (const std::string & name );
	DiamondTrap (const DiamondTrap &diamondtrap);
	DiamondTrap & operator = (const DiamondTrap &diamondtrap);


	void	attack(const std::string & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	
	static const std::string	diamondtrap_color; 
	static const std::string	diamondtrap_reset_color;

	static const unsigned int	hit_max = FragTrap::hit_max;
	static const unsigned int	energy_max = ScavTrap::energy_max;
	static const unsigned int	damage_default = FragTrap::damage_default;	

	void whoAmI ( void );	


	void print ( void );
private:
	const std::string		_name;

	
};
#endif /* __DIAMONDTRAP_H__ */
