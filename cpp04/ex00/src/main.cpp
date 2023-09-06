#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

// int main( void )
// {
// 	{
// 		std::cout << "Construction of 3 animals and one wronganimal" << std::endl;
// 		std::cout << "-------------" << std::endl;
// 		const Animal* meta = new Animal();
// 		std::cout << "-------------" << std::endl;
// 		const Animal* j = new Dog();
// 		std::cout << "-------------" << std::endl;
// 		const Animal* i = new Cat();
// 		std::cout << "-------------" << std::endl;
// 		const WrongAnimal* k = new WrongCat();
// 		std::cout << "-------------" << std::endl;
	
// 		std::cout << "The animal types of the constructed animals" << std::endl;
// 		std::cout << "-------------" << std::endl;
// 		std::cout << meta->Animal::getType() << " " << std::endl;
// 		std::cout << j->Animal::getType() << " " << std::endl;
// 		std::cout << i->Animal::getType() << " " << std::endl;
// 		std::cout << k->WrongAnimal::getType() << " " << std::endl;

// 		std::cout << "The animal sounds of the constructed animals" << std::endl;
// 		std::cout << "-------------" << std::endl;
// 		meta->makeSound();
// 		j->makeSound();
// 		i->makeSound();
// 		k->makeSound();
// 		std::cout << "-------------" << std::endl;
// 		std::cout << "Destruction of the animals" << std::endl;
// 		std::cout << "-------------" << std::endl;
// 		delete meta;
// 		std::cout << "-------------" << std::endl;
// 		delete j;
// 		std::cout << "-------------" << std::endl;
// 		delete i;
// 		std::cout << "-------------" << std::endl;
// 		delete k;
// 	}
// 	{
// 		const Animal* meta = new Animal();
// 		const Animal* j = new Dog();
// 		const Animal* i = new Cat();
// 		std::cout << j->getType() << " " << std::endl;
// 		std::cout << i->getType() << " " << std::endl;
// 		i->makeSound(); //will output the cat sound!
// 		j->makeSound();
// 		meta->makeSound();
// 		delete meta;
// 		delete j;
// 		delete i;
// 	}
// 	{
// 		const WrongAnimal* meta = new WrongAnimal();
// 		const Animal* j = new Dog();
// 		const WrongAnimal* i = new WrongCat();
// 		std::cout << j->getType() << " " << std::endl;
// 		std::cout << i->getType() << " " << std::endl;
// 		i->makeSound(); //will output the cat sound!
// 		j->makeSound();
// 		meta->makeSound();
// 		delete meta;
// 		delete j;
// 		delete i;
// 	}
// 	return (0);
// }


int main()
{
	{
		Cat		resi;
		Dog		pluto;
		Animal	iets;
		// const Animal* meta = new Animal();
		// const Animal* i1 = new Cat();
		// const Cat* i2 = new Cat();
		// const WrongAnimal* k1 = new WrongCat();
		// const WrongCat* k2 = new WrongCat();

		// meta->makeSound(); //unknown animal
		// i1->makeSound(); //will output the cat sound!
		// i2->makeSound(); //will output the cat sound!

		// k1->makeSound(); //is a wrongcat
		// k2->makeSound(); //is a wrongcat
	}
	return 0;
}