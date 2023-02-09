/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:46:03 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/09 19:53:58 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "DiamondTrap.hpp"

void	main_print_banner(std::string title);

int	main ( void )
{
	main_print_banner("A attack B");
	{
		DiamondTrap a("A");
		DiamondTrap b("B");
		std::cout << std::endl;
		a.attack("B");
		std::cout << std::endl;

	}
	main_print_banner("A attack itself");
	{
		DiamondTrap a("A");
		std::cout << std::endl;
		a.attack("A");
		std::cout << std::endl;
	}
	main_print_banner("A attack and other namesake");
	{
		DiamondTrap a("A");
		DiamondTrap b("A");
		std::cout << std::endl;
		a.attack("A");
		std::cout << std::endl;
	}
	main_print_banner("A attack empty name");
	{
		DiamondTrap a("A");
		DiamondTrap b("");
		std::cout << std::endl;
		a.attack("");
		std::cout << std::endl;
	}
	main_print_banner("A take amount of damage greater than your health points and with zero health points try attack B");
	{
		DiamondTrap a("A");
		DiamondTrap b("B");

		std::cout << std::endl;
		a.takeDamage(150);
		a.attack("B");
		std::cout << std::endl;
	}
	main_print_banner("A try attack B 11 times. Last time should has not enough energy to attack");
	{
		DiamondTrap a("A");
		DiamondTrap b("B");

		std::cout << std::endl;
		for (int i = 0; i < 101; i++)
			a.attack("B");
		main_print_banner("After that, A try repair itself but should has not enough energy to repaired");
		a.beRepaired(50);
		std::cout << std::endl;
	}
	main_print_banner("A try repair more than max health");
	{
		DiamondTrap a("A");
		DiamondTrap b("B");

		std::cout << std::endl;
		a.beRepaired(150);
		std::cout << std::endl;
	}
	main_print_banner("This test check if possible to attack bot destroyed previously");
	{
		DiamondTrap a("A");
	
		std::cout << std::endl;
		DiamondTrap("B").attack("A");
		std::cout << std::endl;
		a.attack("B");
		std::cout << std::endl;
	}
	main_print_banner("Chek copy constructor");
	{
		DiamondTrap a("A");
		DiamondTrap b(a);
	
		std::cout << std::endl;
		a.attack("A");
		std::cout << std::endl;
	}
	main_print_banner("Chek copy operator");
	{
		DiamondTrap a("A");
		DiamondTrap b  = a;
	
		std::cout << std::endl;
		a.attack("A");
		std::cout << std::endl;
	}
	main_print_banner("Test highFivesGuys()");
	{
		DiamondTrap a("A");
		std::cout << std::endl;
		a.highFivesGuys();
		std::cout << std::endl;
	}
	main_print_banner("Test virtual method berepaired");
	{
		ScavTrap *a = new DiamondTrap("A");

		FragTrap *c = new DiamondTrap("C");


		DiamondTrap b("B");
		std::cout << std::endl;
		a->beRepaired(150);
		std::cout << std::endl;
		b.attack("A");
		a->beRepaired(150);
		std::cout << std::endl;

		delete a;
		delete c;
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
