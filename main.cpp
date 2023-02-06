/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:46:03 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/06 20:22:17 by jjane-ta         ###   ########.fr       */
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
	main_print_banner("A attack ");
	{
		ClapTrap a("A");
		ClapTrap b("");
		std::cout << std::endl;
		a.attack("");
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
