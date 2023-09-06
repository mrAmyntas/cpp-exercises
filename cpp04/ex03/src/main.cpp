#include "../inc/Cure.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Character.hpp"
#include "../inc/MateriaSource.hpp"

int main( void )
{
	{
		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		std::cout << "-------------------------------" << std::endl;
		std::cout << "using 0, using 1, equipping the same materia and checking its use" << std::endl;
		std::cout << "-------------------------------" << std::endl;

		me->use(0, *bob);
		me->use(1, *bob);
		me->equip(tmp);
		me->use(2, *bob);
		std::cout << "-------------------------------" << std::endl;
		std::cout << "trying to create and equip non-existent materia" << std::endl;
		std::cout << "-------------------------------" << std::endl;

		tmp = src->createMateria("fice");
		if (tmp == 0)
			std::cout << "is null" << std::endl;
		me->equip(tmp);
		me->use(2, *bob);


		std::cout << "-------------------------------" << std::endl;
		std::cout << "equipping more ice, more than 4" << std::endl;
		std::cout << "-------------------------------" << std::endl;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);

		delete tmp;
		
		delete bob;
		delete me;

		std::cout << "-------------------------------" << std::endl;

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << "-------------------------------" << std::endl;

		delete src;
	}
	{
		std::cout << "-------------------------------" << std::endl;
		std::cout << "testing unequip" << std::endl;
		std::cout << "-------------------------------" << std::endl;

		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");

		AMateria* tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->use(0, *bob);
		me->unequip(0);
		me->use(0, *bob);
		delete src;
		delete bob;
		delete tmp;
		delete me;
	}
	return 0;
}
