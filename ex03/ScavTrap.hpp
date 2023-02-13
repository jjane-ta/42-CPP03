/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:21:52 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/13 19:04:15 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__

# include "ClapTrap.hpp"

// ************************************************************************** //
//                              ScavTrap Class                                
// ************************************************************************** //



class ScavTrap : virtual public ClapTrap
{

public:

	virtual ~ScavTrap ( void );
	ScavTrap (const ScavTrap &scavtrap);
	ScavTrap & operator = (const ScavTrap &scavtrap);

	ScavTrap (const std::string & name );

	void	attack(const std::string & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	
	static const std::string	scavtrap_color; 
	static const std::string	scavtrap_reset_color;

	void	guardGate( void );	

	static const unsigned int	hit_max = 100;
	static const unsigned int	energy_max = 50;
	static const unsigned int	damage_default = 20;	

	void	print( void );
protected:
	
	ScavTrap ( void );

private:
	bool	_isGuard;

	
};
#endif /* __SCAVTRAP_H__ */
