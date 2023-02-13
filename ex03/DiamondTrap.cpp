/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:32:13 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/13 16:37:45 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

const std::string DiamondTrap::diamondtrap_color = "\033[0;32m";
const std::string DiamondTrap::diamondtrap_reset_color = "\033[0m";

/*
DiamondTrap::DiamondTrap ( void ) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap basic private constructor should never caled!!" << std::endl;
}
*/
DiamondTrap::~DiamondTrap ( void )
{
	std::cout << diamondtrap_color;
	std::cout << "DiamondTrap " << this->_name << " destroyed!!" << std::endl;
	std::cout << diamondtrap_reset_color;
}

DiamondTrap::DiamondTrap (const DiamondTrap &diamondtrap) :
	ClapTrap(diamondtrap),
	ScavTrap(diamondtrap),
	FragTrap(diamondtrap),
	_name(diamondtrap._name)
{
	_hit_points = DiamondTrap::hit_max;
	_energy_points = DiamondTrap::energy_max;
	_attack_damage = DiamondTrap::damage_default;
		std::cout << diamondtrap_color;
	std::cout << "Copy DiamondTrap " << this->_name << " say hello!!" << std::endl;
	std::cout << diamondtrap_reset_color;
}

DiamondTrap & DiamondTrap::operator = (const DiamondTrap & diamondtrap)
{
	this->ScavTrap::operator = (diamondtrap);
	this->FragTrap::operator = (diamondtrap);
	std::cout << diamondtrap_color;
	std::cout << "DiamondTrap " << this->_name << " now is a copy of DiamondTrap " << diamondtrap._name << std::endl;
	std::cout << diamondtrap_reset_color;
	return (*this);
}

DiamondTrap::DiamondTrap (const std::string & name ) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name),
	_name(name)
{
	_hit_points = DiamondTrap::hit_max;
	_energy_points = DiamondTrap::energy_max;
	_attack_damage = DiamondTrap::damage_default;
	
	std::cout << diamondtrap_color;
	std::cout << "DiamondTrap " << this->_name << " say hello!!" << std::endl;
	std::cout << diamondtrap_reset_color;
}


void	DiamondTrap::attack(const std::string & target)
{
	std::cout << diamondtrap_color;
	std::cout << "DiamondTrap " << this->_name << " call ScavTrap.attack(" << target << ")" << std::endl;
	std::cout << diamondtrap_reset_color;
	ScavTrap::attack(target);	
}


void	DiamondTrap::takeDamage(unsigned int amount)
{
	std::cout << diamondtrap_color;

	std::cout << "DiamondTrap call ClapTrap.takeDamage(" << amount << ")" << std::endl;
	std::cout << diamondtrap_reset_color;
	ClapTrap::takeDamage(amount);
}

void	DiamondTrap::beRepaired(unsigned int amount)
{

	if (!this->_energy_points)
	{
		std::cout << diamondtrap_color;
		std::cout << "DiamondTrap " << this->_name << " can't repaired with zero energy points.\n";
		std::cout << diamondtrap_reset_color;
	}
	else
	{
		this->_energy_points--;
		if (amount > hit_max)
			this->_hit_points = DiamondTrap::hit_max;
		else
			this->_hit_points = amount;
		std::cout << diamondtrap_color;
		std::cout << "DiamondTrap " << this->_name << " repair " << amount << " points of health."\
			<< " Now has " << this->_hit_points << " of health." << std::endl;
		std::cout << diamondtrap_reset_color;

	}
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << diamondtrap_color;
	std::cout << "DiamondTrap " << this->_name << " say : My clap name is " << ClapTrap::_name << std::endl;
	std::cout << diamondtrap_reset_color;
}

void DiamondTrap::print ( void )
{
	ClapTrap::print();
	ScavTrap::print();
	FragTrap::print();
	std::cout << diamondtrap_color;
	std::cout << "DiamondTrap own values:\n _name = " << this->_name << std::endl;
	std::cout << diamondtrap_reset_color;
}
