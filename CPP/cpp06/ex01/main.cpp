#include "Serializer.hpp"

int main()
{
	Data *data = new Data;
	Data *data2;
	uintptr_t addr_num;

	data->value = 10;
	Serializer seri;
	addr_num = seri.serialize(data);
	std::cout << "addr -> num : " << addr_num << std::endl;
	std::cout << "addr : " << data << std::endl;
	data2 = seri.deserialize(addr_num); 
	std::cout << "data : " << data << " | value :" << data->value << std::endl;
	std::cout << "data2 : " << data2 << " | value :" << data2->value << std::endl;
	delete data;
	return (1);
}
