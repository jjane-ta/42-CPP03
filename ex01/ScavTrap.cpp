/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:32:13 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/08 16:19:31 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::~ScavTrap ( void )
{
	std::cout << "ScavTrap " << this->get_name() << " destroyed!!" << std::endl;
}

ScavTrap::ScavTrap (const ScavTrap &scavtrap) : ClapTrap(scavtrap)
{
	std::cout << "Copy ScavTrap " << this->get_name() << " say hello!!" << std::endl;
}

ScavTrap & ScavTrap::operator = (const ScavTrap &scavtrap)
{
	(ClapTrap)*this = (ClapTrap) scavtrap;
	std::cout << "ScavTrap " << this->get_name() << " now is a copy of ScavTrap " << scavtrap.get_name() << std::endl;
	return (*this);
}

ScavTrap::ScavTrap (const std::string & name ) : ClapTrap(name)
{
	std::cout << "ScavTrap " << this->get_name() << " say hello!!" << std::endl;
}

void	ScavTrap::attack(const std::string & target)
{
	std::cout << "ScavTrap call ClapTrap.attack() target name " << target << std::endl;
	((ClapTrap)*this).attack(target);	
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap call ClapTrap.takeDamage()" << std::endl;
	((ClapTrap)*this).takeDamage(amount);
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "ScavTrap call ClapTrap.beRepaired()" << std::endl;
	((ClapTrap)*this).beRepaired(amount);	
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
