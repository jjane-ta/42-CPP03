/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:25:07 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/13 19:05:06 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	ClapTrap::instances = 0;

ClapTrap *ClapTrap::bot_list = nullptr;

ClapTrap::ClapTrap ( void )
{
	instances++;
	std::cout << "ClapTrap basic private constructor should never caled!!" << std::endl;
} 

ClapTrap::~ClapTrap ( void )
{
	instances--;
	if (!this->_next && !this->_prev)
		bot_list = nullptr;
	else if (!this->_prev)
	{
		bot_list = this->_next;
		bot_list->_prev = nullptr;
	}
	else if (!this->_next)
		this->_prev->_next = nullptr;
	else
	{
		this->_prev->_next = this->_next;
		this->_next->_prev = this->_prev;
	}	
	
	std::cout << "ClapTrap " << this->_name << " destroyed!!" << std::endl;
}

ClapTrap::ClapTrap ( const std::string & name ) :
	_name(name),
	_hit_points(ClapTrap::hit_max),
	_energy_points(ClapTrap::energy_max),
	_attack_damage(ClapTrap::damage_default),
	_next(nullptr),
	_prev(nullptr)
{
	instances++;
	if (bot_list)
	{
		this->_next = bot_list;	
		if (this->_next)
			this->_next->_prev = this;
	}
	bot_list = this;
	std::cout << "ClapTrap " << this->_name << " say hello!!" << std::endl;

}

ClapTrap::ClapTrap (const ClapTrap &claptrap) :
	_name(claptrap._name),
	_hit_points(claptrap._hit_points),
	_energy_points(claptrap._energy_points),
	_attack_damage(claptrap._attack_damage),
	_next(nullptr),
	_prev(nullptr)

{
	instances++; 
	if (bot_list)
	{
		this->_next = bot_list;	
		if (this->_next)
			this->_next->_prev = this;
	}
	bot_list = this;
	std::cout << "Copy ClapTrap " << this->_name << " say hello!!" << std::endl;
}


ClapTrap & ClapTrap::operator = (const ClapTrap & claptrap) 
{
	std::cout << "ClapTrap " << this->_name << " now is a copy of ClapTrap " << claptrap._name << std::endl;
	_hit_points = claptrap._hit_points;
	_energy_points = claptrap._energy_points;
	_attack_damage = claptrap._attack_damage;
	
	return (*this);
}

void	ClapTrap::attack(const std::string & target)
{
	if (!this->_hit_points || !this->_energy_points)
	{
		if (!this->_hit_points)
			std::cout << "ClapTrap " << this->_name << " can't attack with zero health points.\n";
		else
			std::cout << "ClapTrap " << this->_name << " does not have enough energy to attack.\n";
	}
	else
	{
		ClapTrap *bot = this->get_ClapTrap_instanceByName(target);
		if (bot)
		{
			this->_energy_points--;
			if (this->_name.compare(target) == 0)
				std::cout << "ClapTrap " << this->_name << " attacks his namesake"\
					<< ", causing " << this->_attack_damage << " points of damage!" << std::endl;
			else
				std::cout << "ClapTrap " << this->_name << " attacks " << target\
					<< ", causing " << this->_attack_damage << " points of damage!" << std::endl;
			bot->takeDamage(this->_attack_damage);
		}
		else
		{
			if (this->_name.compare(target) == 0)
				std::cout << "ClapTrap " << this->_name << " prefers not to attack itself." << std::endl;
			else
				std::cout << "Are you kidding me? There are no one named " << target << '.' << std::endl;
		}
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points < amount)
		this->_hit_points = 0;
	else
		this->_hit_points -= amount;
	std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage."\
		<< " Now has " << this->_hit_points << " of health." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_energy_points)
		std::cout << "ClapTrap " << this->_name << " can't repaired with zero energy points.\n";
	else
	{
		this->_energy_points--;
		if (amount > hit_max)
			this->_hit_points = ClapTrap::hit_max;
		else
			this->_hit_points = amount;
		std::cout << "ClapTrap " << this->_name << " repair " << amount << " points of health."\
			<< " Now has " << this->_hit_points << " of health." << std::endl;

	}
}

ClapTrap	*ClapTrap::get_ClapTrap_instanceByName(const std::string & name)
{
	ClapTrap *bot = bot_list;

	while (bot)
	{
		if (this != bot && bot->_name.compare(name) == 0)
			break ;
		bot = bot->_next;
	}
	return (bot);
}

void	ClapTrap::print( void )
{
	std::cout << "ClapTrap info:"\
		<< "\n\tname		=> " << _name\
		<< "\n\tHit		=> " << _hit_points\
		<< "\n\tEnergy	=> " << _energy_points\
		<< "\n\tAttack	=> " << _attack_damage << std::endl;	
}
