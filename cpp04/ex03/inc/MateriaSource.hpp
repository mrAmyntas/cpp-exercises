#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource {

	public:

		MateriaSource( );
		virtual ~MateriaSource( );
		MateriaSource( MateriaSource const & src );
		MateriaSource & operator=( MateriaSource const & rhs );

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

	private:
	
		AMateria** 	inv;

};

#endif // MATERIASOURCE_HPP