#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int main( void )
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	{
		Animal *AnimalArray[10];
		for (int i = 0; i < 5; i++)
			AnimalArray[i] = new Dog("Dog");
		for (int i = 5; i < 10; i++)
			AnimalArray[i] = new Cat("Cat");
		AnimalArray[4]->makeSound();
		AnimalArray[5]->makeSound();
		for (int i = 0; i < 10; i++)
			delete AnimalArray[i];
	}
	{
		std::cout<<"----------------------\n";

		Dog *mDog = new Dog("Chihuahua");
		Cat *mCat = new Cat("Tabby");

		std::cout<<"----------------------\n";

		Animal *copyDog = mDog->clone_animal();
		Animal *copyCat = mCat->clone_animal();

		std::cout<<"----------------------\n";
		std::cout << "Animal type of Dog: " << mDog->Animal::getType() << std::endl;
		std::cout << "Animal type of Cat: " << mCat->Animal::getType() << std::endl;
		std::cout << "Animal type of copyDog: " << copyDog->Animal::getType() << std::endl;
		std::cout << "Animal type of copyCat: " << copyCat->Animal::getType() << std::endl;
		std::cout << "type of Dog: " << mDog->getType() << std::endl;
		std::cout << "type of Cat: " << mCat->getType() << std::endl;
		std::cout << "type of copyDog: " << copyDog->getType() << std::endl;
		std::cout << "type of copyCat: " << copyCat->getType() << std::endl;
		std::cout<<"----------------------\n";

		copyDog->Animal::setType("Cow");
		copyCat->Animal::setType("Horse");

		std::cout<<"----------------------\n";
		std::cout << "Animal type of Dog: " << mDog->Animal::getType() << std::endl;
		std::cout << "Animal type of Cat: " << mCat->Animal::getType() << std::endl;
		std::cout << "Animal type of copyDog: " << copyDog->Animal::getType() << std::endl;
		std::cout << "Animal type of copyCat: " << copyCat->Animal::getType() << std::endl;
		std::cout<<"----------------------\n";

		delete mDog;
		delete mCat;
		delete copyDog;
		delete copyCat;
	}
	{

		Dog mydog("puppy");
		Dog mydog2;
		Dog *mydog3 = mydog.clone_dog();

		mydog2 = mydog;

		std::cout << "Animal type of dog2: " << mydog2.Animal::getType() << std::endl;
		std::cout << "type of dog2: " << mydog2.getType() << std::endl;
		std::cout << "Animal type of dog3: " << mydog3->Animal::getType() << std::endl;
		std::cout << "type of dog3: " << mydog3->getType() << std::endl;
		mydog.setType("rottweiler");
		mydog.Animal::setType("Cow");
		mydog2.setType("chihuahua");
		mydog2.Animal::setType("Horse");
		std::cout << "Animal type of dog2: " << mydog2.Animal::getType() << std::endl;
		std::cout << "type of dog2: " << mydog2.getType() << std::endl;
		std::cout << "Animal type of dog2: " << mydog3->Animal::getType() << std::endl;
		std::cout << "type of dog2: " << mydog3->getType() << std::endl;
		std::cout << "Animal type of dog: " << mydog.Animal::getType() << std::endl;
		std::cout << "type of dog: " << mydog.getType() << std::endl;

		delete mydog3;
	}
	//system("leaks Zoo");
	return (0);
}
