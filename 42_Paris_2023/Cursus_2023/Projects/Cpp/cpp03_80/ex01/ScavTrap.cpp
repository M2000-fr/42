/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:42:34 by mechard           #+#    #+#             */
/*   Updated: 2025/03/17 16:42:34 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name), _scavName(name),
    _scavHitPoints(100), _scavEnergyPoints(50), _scavAttackDamage(20)
{
    std::cout << "ScavTrap " << _scavName << " construit avec "
              << _scavHitPoints << " points de vie, " << _scavEnergyPoints
              << " points d'énergie et " << _scavAttackDamage << " points d'attaque." 
              << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other), _scavName(other._scavName),
    _scavHitPoints(other._scavHitPoints), _scavEnergyPoints(other._scavEnergyPoints),
    _scavAttackDamage(other._scavAttackDamage)
{
    std::cout << "ScavTrap " << _scavName << " copié." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
	{
        ClapTrap::operator=(other);
        _scavName = other._scavName;
        _scavHitPoints = other._scavHitPoints;
        _scavEnergyPoints = other._scavEnergyPoints;
        _scavAttackDamage = other._scavAttackDamage;
    }
    std::cout << "ScavTrap " << _scavName << " assigné." << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _scavName << " détruit." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (_scavHitPoints <= 0)
	{
        std::cout << "ScavTrap " << _scavName << " est mort et ne peut pas attaquer." << std::endl;
        return;
    }
    if (_scavEnergyPoints <= 0)
	{
        std::cout << "ScavTrap " << _scavName << " n'a plus d'énergie pour attaquer." << std::endl;
        return;
    }
    _scavEnergyPoints--;
    std::cout << "ScavTrap " << _scavName << " attaque férocement " << target
              << ", infligeant " << _scavAttackDamage << " points de dégâts !" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (_scavHitPoints <= 0)
	{
        std::cout << "ScavTrap " << _scavName << " est déjà mort." << std::endl;
        return;
    }
    _scavHitPoints -= amount;
    if (_scavHitPoints < 0)
        _scavHitPoints = 0;
    std::cout << "ScavTrap " << _scavName << " reçoit " << amount
              << " points de dégâts, points de vie restants : " << _scavHitPoints << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (_scavHitPoints <= 0)
	{
        std::cout << "ScavTrap " << _scavName << " est mort et ne peut être réparé." << std::endl;
        return;
    }
    if (_scavEnergyPoints <= 0)
	{
        std::cout << "ScavTrap " << _scavName << " n'a plus d'énergie pour se réparer." << std::endl;
        return;
    }
    _scavEnergyPoints--;
    _scavHitPoints += amount;
    std::cout << "ScavTrap " << _scavName << " se répare de " << amount
              << " points, nouveaux points de vie : " << _scavHitPoints << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _scavName << " est maintenant en mode Gate keeper." << std::endl;
}
