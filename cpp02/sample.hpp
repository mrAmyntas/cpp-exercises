#ifndef SAMPLE_H
#define SAMPLE_H

#include <iostream>

class Sample {

	public:

		Sample(void); 
		~Sample(void);
		Sample(Sample const & src);
		Sample  &operator=(Sample const & rhs);

		int getVal(void) const;

	private:

		int _Val;

};

#endif