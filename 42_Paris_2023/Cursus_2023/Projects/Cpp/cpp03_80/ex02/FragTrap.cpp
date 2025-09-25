/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fragtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:04:44 by mechard           #+#    #+#             */
/*   Updated: 2025/03/17 17:04:44 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string &name) : ClapTrap(name), _fragName(name),
    _fragHitPoints(100), _fragEnergyPoints(100), _fragAttackDamage(30)
{
    std::cout << "FragTrap " << _fragName << " construit avec "
              << _fragHitPoints << " points de vie, " << _fragEnergyPoints
              << " points d'énergie et " << _fragAttackDamage << " points d'attaque."
              << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other),
    _fragName(other._fragName), _fragHitPoints(other._fragHitPoints),
    _fragEnergyPoints(other._fragEnergyPoints), _fragAttackDamage(other._fragAttackDamage)
{
    std::cout << "FragTrap " << _fragName << " copié." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
	{
        ClapTrap::operator=(other);
        _fragName = other._fragName;
        _fragHitPoints = other._fragHitPoints;
        _fragEnergyPoints = other._fragEnergyPoints;
        _fragAttackDamage = other._fragAttackDamage;
    }
    std::cout << "FragTrap " << _fragName << " assigné." << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _fragName << " détruit." << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (_fragHitPoints <= 0)
	{
        std::cout << "FragTrap " << _fragName << " est mort et ne peut pas attaquer." << std::endl;
        return;
    }
    if (_fragEnergyPoints <= 0)
	{
        std::cout << "FragTrap " << _fragName << " n'a plus d'énergie pour attaquer." << std::endl;
        return;
    }
    _fragEnergyPoints--;
    std::cout << "FragTrap " << _fragName << " attaque " << target
              << ", infligeant " << _fragAttackDamage << " points de dégâts !" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (_fragHitPoints <= 0)
	{
        std::cout << "FragTrap " << _fragName << " est déjà mort." << std::endl;
        return;
    }
    _fragHitPoints -= amount;
    if (_fragHitPoints < 0)
        _fragHitPoints = 0;
    std::cout << "FragTrap " << _fragName << " reçoit " << amount
              << " points de dégâts, points de vie restants : " << _fragHitPoints << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (_fragHitPoints <= 0)
	{
        std::cout << "FragTrap " << _fragName << " est mort et ne peut être réparé." << std::endl;
        return;
    }
    if (_fragEnergyPoints <= 0)
	{
        std::cout << "FragTrap " << _fragName << " n'a plus d'énergie pour se réparer." << std::endl;
        return;
    }
    _fragEnergyPoints--;
    _fragHitPoints += amount;
    std::cout << "FragTrap " << _fragName << " se répare de " << amount
              << " points, nouveaux points de vie : " << _fragHitPoints << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _fragName << " demande un HIGH FIVES positive !" << std::endl;
}
