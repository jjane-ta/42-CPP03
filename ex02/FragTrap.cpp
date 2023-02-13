/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:32:13 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/13 16:43:43 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

const std::string FragTrap::fragtrap_color = "\033[0;35m";
const std::string FragTrap::fragtrap_reset_color = "\033[0m";


FragTrap::FragTrap ( void ) : ClapTrap()
{
	std::cout << "FragTrap basic private constructor should never caled!!" << std::endl;
}

FragTrap::~FragTrap ( void )
{
	std::cout << fragtrap_color;
	std::cout << "FragTrap " << this->_name << " destroyed!!" << std::endl;
	std::cout << fragtrap_reset_color;
}

FragTrap::FragTrap (const FragTrap &fragtrap) : ClapTrap(fragtrap)
{
	_hit_points = FragTrap::hit_max;
	_energy_points = FragTrap::energy_max;
	_attack_damage = FragTrap::damage_default;

	std::cout << fragtrap_color;
	std::cout << "Copy FragTrap " << this->_name << " say hello!!" << std::endl;
	std::cout << fragtrap_reset_color;
}

FragTrap & FragTrap::operator = (const FragTrap &fragtrap)
{
	this->ClapTrap::operator = (fragtrap);
	std::cout << fragtrap_color;
	std::cout << "FragTrap " << this->_name << " now is a copy of FragTrap " << fragtrap._name << std::endl;
	std::cout << fragtrap_reset_color;
	return (*this);
}

FragTrap::FragTrap (const std::string & name ) : ClapTrap(name)
{
	_hit_points = FragTrap::hit_max;
	_energy_points = FragTrap::energy_max;
	_attack_damage = FragTrap::damage_default;
	
	std::cout << fragtrap_color;
	std::cout << "FragTrap " << this->_name << " say hello!!" << std::endl;
	std::cout << fragtrap_reset_color;

}

void	FragTrap::attack(const std::string & target)
{
	std::cout << fragtrap_color;
	std::cout << "FragTrap " << this->_name << " call ClapTrap.attack(" << target << ")" << std::endl;
	std::cout << fragtrap_reset_color;
	ClapTrap::attack(target);	
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout << fragtrap_color;

	std::cout << "FragTrap call ClapTrap.takeDamage(" << amount << ")" << std::endl;
	std::cout << fragtrap_reset_color;
	ClapTrap::takeDamage(amount);
}

void	FragTrap::beRepaired(unsigned int amount)
{

	if (!this->_energy_points)
	{
		std::cout << fragtrap_color;
		std::cout << "FragTrap " << this->_name << " can't repaired with zero energy points.\n";
		std::cout << fragtrap_reset_color;
	}
	else
	{
		this->_energy_points--;
		if (amount > hit_max)
			this->_hit_points = FragTrap::hit_max;
		else
			this->_hit_points = amount;
		std::cout << fragtrap_color;
		std::cout << "FragTrap " << this->_name << " repair " << amount << " points of health."\
			<< " Now has " << this->_hit_points << " of health." << std::endl;
		std::cout << fragtrap_reset_color;

	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << fragtrap_color;
	std::cout << "FragTrap " << this->_name << " say : Give me five guys!!" << std::endl;
	std::cout << fragtrap_reset_color;
}
