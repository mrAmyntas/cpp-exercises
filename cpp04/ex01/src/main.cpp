#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int main( void )
{
	/*{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	{
		Animal *AnimalArray[10];
		for (int i = 0; i < 5; i++)
			AnimalArray[i] = new Dog();
		for (int i = 5; i < 10; i++)
			AnimalArray[i] = new Cat();
		AnimalArray[4]->makeSound();
		AnimalArray[5]->makeSound();
		for (int i = 0; i < 10; i++)
			delete AnimalArray[i];
	}*/
	// {
	// 	std::cout<<"----------------------\n";

	// 	Dog *mDog = new Dog();
	// 	Cat *mCat = new Cat();

	// 	std::cout<<"----------------------\n";

	// 	Dog copyDog(*mDog);
	// 	Cat copyCat = *mCat;
    
	// 	std::cout<<"----------------------\n";
	// 	std::cout << "Animal type of Dog: " << mDog->Animal::getType() << std::endl;
	// 	std::cout << "Animal type of Cat: " << mCat->Animal::getType() << std::endl;
	// 	std::cout << "Animal type of copyDog: " << copyDog.Animal::getType() << std::endl;
	// 	std::cout << "Animal type of copyCat: " << copyCat.Animal::getType() << std::endl;
	// 	std::cout<<"----------------------\n";
	// 	std::cout << "type of Dog: " << mDog->getType() << std::endl;
	// 	std::cout << "type of Cat: " << mCat->getType() << std::endl;
	// 	std::cout << "type of copyDog: " << copyDog.getType() << std::endl;
	// 	std::cout << "type of copyCat: " << copyCat.getType() << std::endl;
	// 	std::cout<<"----------------------\n";

	// 	copyDog.Animal::setType("Cow");
	// 	copyCat.Animal::setType("Horse");
	// 	mDog->setType("Pitbull");
	// 	mCat->setType("kitten");

	// 	std::cout<<"----------------------\n";
	// 	std::cout << "Animal type of Dog: " << mDog->Animal::getType() << std::endl;
	// 	std::cout << "Animal type of Cat: " << mCat->Animal::getType() << std::endl;
	// 	std::cout << "Animal type of copyDog: " << copyDog.Animal::getType() << std::endl;
	// 	std::cout << "Animal type of copyCat: " << copyCat.Animal::getType() << std::endl;
	// 	std::cout<<"----------------------\n";
	// 	std::cout << "type of Dog: " << mDog->getType() << std::endl;
	// 	std::cout << "type of Cat: " << mCat->getType() << std::endl;
	// 	std::cout << "type of copyDog: " << copyDog.getType() << std::endl;
	// 	std::cout << "type of copyCat: " << copyCat.getType() << std::endl;
	// 	std::cout<<"----------------------\n";

	// 	delete mDog;
	// 	delete mCat;

	// }
	{
		Dog mDog;
		Dog mDog2 = mDog;
		mDog = mDog2;
		system("leaks Zoo");
	}
	//system("leaks Zoo");
	//Animal check;*/
	return (0);
}
