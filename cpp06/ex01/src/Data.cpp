#include "../inc/Data.hpp"

Data* deserialize(uintptr_t raw)
{
	Data	*ptr;

	ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}

uintptr_t serialize(Data* ptr)
{
	uintptr_t ret;

	ret = reinterpret_cast<uintptr_t>(ptr);
	return (ret);
}
