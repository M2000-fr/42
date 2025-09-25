/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:41:24 by mechard           #+#    #+#             */
/*   Updated: 2025/03/17 21:41:24 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "----- Test Animal (Exercise 00) -----" << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;
    
    cat->makeSound();
    dog->makeSound();
    meta->makeSound();

    std::cout << "\n----- Test WrongAnimal -----" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();

    std::cout << "\n----- Test Array of Animals (Exercise 01) -----" << std::endl;
    const int numAnimals = 4;
    Animal* animals[numAnimals];

    for (int i = 0; i < numAnimals; i++)
	{
        if (i < numAnimals / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < numAnimals; i++)
	{
        animals[i]->makeSound();
    }

    for (int i = 0; i < numAnimals; i++)
	{
        delete animals[i];
    }

    delete meta;
    delete dog;
    delete cat;
    delete wrongMeta;
    delete wrongCat;
    
    return 0;
}
