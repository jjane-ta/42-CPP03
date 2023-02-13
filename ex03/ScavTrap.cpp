/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:32:13 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/13 18:39:13 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

const std::string ScavTrap::scavtrap_color = "\033[0;31m";
const std::string ScavTrap::scavtrap_reset_color = "\033[0m";


ScavTrap::ScavTrap ( void ) : ClapTrap()
{
	std::cout << "ScavTrap basic private constructor should never caled!!" << std::endl;
}

ScavTrap::~ScavTrap ( void )
{
	std::cout << scavtrap_color;
	std::cout << "ScavTrap " << this->_name << " destroyed!!" << std::endl;
	std::cout << scavtrap_reset_color;
}

ScavTrap::ScavTrap (const ScavTrap &scavtrap) : ClapTrap(scavtrap)	
{
	_hit_points = ScavTrap::hit_max;
	_energy_points = ScavTrap::energy_max;
	_attack_damage = ScavTrap::damage_default;
	_isGuard = scavtrap._isGuard;

	std::cout << scavtrap_color;
	std::cout << "Copy ScavTrap " << this->_name << " say hello!!" << std::endl;
	std::cout << scavtrap_reset_color;
}

ScavTrap & ScavTrap::operator = (const ScavTrap &scavtrap)
{
	this->ClapTrap::operator = (scavtrap);
	_isGuard = scavtrap._isGuard;
	std::cout << scavtrap_color;
	std::cout << "ScavTrap " << this->_name << " now is a copy of ScavTrap " << scavtrap._name << std::endl;
	std::cout << scavtrap_reset_color;
	return (*this);
}

ScavTrap::ScavTrap (const std::string & name ) : ClapTrap(name)
{
	_hit_points = ScavTrap::hit_max;
	_energy_points = ScavTrap::energy_max;
	_attack_damage = ScavTrap::damage_default;
	_isGuard = false;

	std::cout << scavtrap_color;
	std::cout << "ScavTrap " << this->_name << " say hello!!" << std::endl;
	std::cout << scavtrap_reset_color;

}

void	ScavTrap::attack(const std::string & target)
{
	std::cout << scavtrap_color;
	std::cout << "ScavTrap " << this->_name << " call ClapTrap.attack(" << target << ")" << std::endl;
	std::cout << scavtrap_reset_color;
	ClapTrap::attack(target);	
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << scavtrap_color;

	std::cout << "ScavTrap call ClapTrap.takeDamage(" << amount << ")" << std::endl;
	std::cout << scavtrap_reset_color;
	ClapTrap::takeDamage(amount);
}

void	ScavTrap::beRepaired(unsigned int amount)
{

	if (!this->_energy_points)
	{
		std::cout << scavtrap_color;
		std::cout << "ScavTrap " << this->_name << " can't repaired with zero energy points.\n";
		std::cout << scavtrap_reset_color;
	}
	else
	{
		this->_energy_points--;
		if (amount > hit_max)
			this->_hit_points = ScavTrap::hit_max;
		else
			this->_hit_points = amount;
		std::cout << scavtrap_color;
		std::cout << "ScavTrap " << this->_name << " repair " << amount << " points of health."\
			<< " Now has " << this->_hit_points << " of health." << std::endl;
		std::cout << scavtrap_reset_color;

	}
}

void	ScavTrap::guardGate( void )
{
	this->_isGuard = true;	

	std::cout << scavtrap_color;
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
	std::cout << scavtrap_reset_color;
}

void	ScavTrap::print( void )
{
	ClapTrap::print();
	std::cout << scavtrap_color;
	std::cout << "ScavTrap info:\n"\
		<< "\tis_guard		=> " << std::boolalpha << _isGuard << std::endl; 
	std::cout << scavtrap_reset_color;
}
