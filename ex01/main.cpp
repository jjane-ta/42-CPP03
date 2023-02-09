/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:46:03 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/09 16:31:30 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "ScavTrap.hpp"

void	main_print_banner(std::string title);

int	main ( void )
{
	main_print_banner("A attack B");
	{
		ScavTrap a("A");
		ScavTrap b("B");
		std::cout << std::endl;
		a.attack("B");
		std::cout << std::endl;

	}
	main_print_banner("A attack itself");
	{
		ScavTrap a("A");
		std::cout << std::endl;
		a.attack("A");
		std::cout << std::endl;
	}
	main_print_banner("A attack and other namesake");
	{
		ScavTrap a("A");
		ScavTrap b("A");
		std::cout << std::endl;
		a.attack("A");
		std::cout << std::endl;
	}
	main_print_banner("A attack empty name");
	{
		ScavTrap a("A");
		ScavTrap b("");
		std::cout << std::endl;
		a.attack("");
		std::cout << std::endl;
	}
	main_print_banner("A take amount of damage greater than your health points and with zero health points try attack B");
	{
		ScavTrap a("A");
		ScavTrap b("B");

		std::cout << std::endl;
		a.takeDamage(150);
		a.attack("B");
		std::cout << std::endl;
	}
	main_print_banner("A try attack B 11 times. Last time should has not enough energy to attack");
	{
		ScavTrap a("A");
		ScavTrap b("B");

		std::cout << std::endl;
		for (int i = 0; i < 51; i++)
			a.attack("B");
		main_print_banner("After that, A try repair itself but should has not enough energy to repaired");
		a.beRepaired(50);
		std::cout << std::endl;
	}
	main_print_banner("A try repair more than max health");
	{
		ScavTrap a("A");
		ScavTrap b("B");

		std::cout << std::endl;
		a.beRepaired(150);
		std::cout << std::endl;
	}
	main_print_banner("This test check if possible to attack bot destroyed previously");
	{
		ScavTrap a("A");
	
		std::cout << std::endl;
		ScavTrap("B").attack("A");
		std::cout << std::endl;
		a.attack("B");
		std::cout << std::endl;
	}
	main_print_banner("Chek copy constructor");
	{
		ScavTrap a("A");
		ScavTrap b(a);
	
		std::cout << std::endl;
		a.attack("A");
		std::cout << std::endl;
	}
	main_print_banner("Chek copy operator");
	{
		ScavTrap a("A");
		ScavTrap b  = a;
	
		std::cout << std::endl;
		a.attack("A");
		std::cout << std::endl;
	}
	main_print_banner("Test virtual method berepaired");
	{
		ClapTrap *a = new ScavTrap("A");
		ScavTrap b("B");
		std::cout << std::endl;
		a->beRepaired(150);
		std::cout << std::endl;
		b.attack("A");
		a->beRepaired(150);
		std::cout << std::endl;

		delete a;
	}
}

void	main_print_banner(std::string title)
{	
	std::cout	<<	std::endl;
	std::cout	<<	std::setfill('*') << std::setw(title.size()) << "" << std::endl;
	std::cout	<<	title	<<	std::endl;
	std::cout	<<	std::setfill('*') << std::setw(title.size()) << "" << std::endl;
	std::cout	<<	std::endl;

}
