/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:46:03 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/07 19:21:33 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "ClapTrap.hpp"

void	main_print_banner(std::string title);

int	main ( void )
{
	main_print_banner("A attack B");
	{
		ClapTrap a("A");
		ClapTrap b("B");
		std::cout << std::endl;
		a.attack("B");
		std::cout << std::endl;
	}
	main_print_banner("A attack itself");
	{
		ClapTrap a("A");
		std::cout << std::endl;
		a.attack("A");
		std::cout << std::endl;
	}
	main_print_banner("A attack and other namesake");
	{
		ClapTrap a("A");
		ClapTrap b("A");
		std::cout << std::endl;
		a.attack("A");
		std::cout << std::endl;
	}
	main_print_banner("A attack empty name");
	{
		ClapTrap a("A");
		ClapTrap b("");
		std::cout << std::endl;
		a.attack("");
		std::cout << std::endl;
	}
	main_print_banner("A take amount of damage greater than your health points and with zero health points try attack B");
	{
		ClapTrap a("A");
		ClapTrap b("B");

		std::cout << std::endl;
		a.takeDamage(50);
		a.attack("B");
		std::cout << std::endl;
	}
	main_print_banner("A try attack B 11 times. Last time should has not enough energy to attack");
	{
		ClapTrap a("A");
		ClapTrap b("B");

		std::cout << std::endl;
		for (int i = 0; i < 11; i++)
			a.attack("B");
		main_print_banner("After that, A try repair itself but should has not enough energy to repaired");
		a.beRepaired(50);
		std::cout << std::endl;
	}
	main_print_banner("A try repair more than max health");
	{
		ClapTrap a("A");
		ClapTrap b("B");

		std::cout << std::endl;
		a.beRepaired(50);
		std::cout << std::endl;
	}
	main_print_banner("This test check if possible to attack bot destroyed previously");
	{
		ClapTrap a("A");
	
		std::cout << std::endl;
		ClapTrap("B").attack("A");
		std::cout << std::endl;
		a.attack("B");
		std::cout << std::endl;
	}
	main_print_banner("Chek copy constructor");
	{
		ClapTrap a("A");
		ClapTrap b(a);
	
		std::cout << std::endl;
		a.attack("A");
		std::cout << std::endl;
	}
	main_print_banner("Chek copy operator");
	{
		ClapTrap a("A");
		ClapTrap b("B");

		std::cout << std::endl;
		a = b;
		std::cout << std::endl;
		a.attack("B");
		std::cout << std::endl;
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
