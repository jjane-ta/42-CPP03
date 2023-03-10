/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:21:52 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/13 18:43:25 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FRAGTRAP_H__
# define __FRAGTRAP_H__

# include "ClapTrap.hpp"

// ************************************************************************** //
//                              FragTrap Class                                
// ************************************************************************** //

class FragTrap : virtual public ClapTrap
{

public:

	virtual ~FragTrap ( void );
	FragTrap (const FragTrap &fragtrap);
	FragTrap & operator = (const FragTrap &fragtrap);

	FragTrap (const std::string & name );

	void	attack(const std::string & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	
	static const std::string	fragtrap_color; 
	static const std::string	fragtrap_reset_color;

	void highFivesGuys(void);
	
	static const unsigned int	hit_max = 100;
	static const unsigned int	energy_max = 100;
	static const unsigned int	damage_default = 30;	

	void	print ( void );

protected:
	
	FragTrap ( void );

private:
//	bool	_isGuard;

	
};
#endif /* __FRAGTRAP_H__ */
