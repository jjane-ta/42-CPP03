/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:21:52 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/07 19:01:45 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__

# include "ClapTrap.hpp"

// ************************************************************************** //
//                              ScavTrap Class                                
// ************************************************************************** //

class ScavTrap : public ClapTrap
{

public:

	~ScavTrap ( void );
	ScavTrap (const ScavTrap &scavtrap);
	ScavTrap & operator = (const ScavTrap &scavtrap);

	ScavTrap (const std::string & name );

	void	attack(const std::string & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	static const unsigned int	hit_max = 100;
	static const unsigned int	energy_max = 50;
	static const unsigned int	damage_clap_trap = 20;	

	void	guardGate( void );	

private:

	ScavTrap ( void );


};
#endif /* __SCAVTRAP_H__ */
