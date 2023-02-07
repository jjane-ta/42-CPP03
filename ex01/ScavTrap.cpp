/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:32:13 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/07 19:29:17 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::~ScavTrap ( void )
{
	std::cout << "ScavTrap basic private constructor should never caled!!" << std::endl;
}

ScavTrap::ScavTrap (const ScavTrap &scavtrap) : ClapTrap (scavtrap)
{
}

ScavTrap & ScavTrap::operator = (const ScavTrap &scavtrap)
{
	(ClapTrap) *this = (ClapTrap) scavtrap;
	std::cout << "ScavTrap " << this->_name << " now is a copy of ScavTrap " << scavtrap._name << std::endl;
	return ((ScavTrap) *this);
}

ScavTrap::ScavTrap (const std::string & name )
{

}
void	ScavTrap::attack(const std::string & target)
{
}

void	ScavTrap::takeDamage(unsigned int amount)
{

}

void	beRepaired(unsigned int amount)
{

}

void	ScavTrap::guardGate( void )
{

}


