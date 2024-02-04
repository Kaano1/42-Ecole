#include "Serializer.hpp"

int main()
{
	Data* data = new Data;
	data->s = "Hello World!";
	data->c = "C style casting";
	
	uintptr_t raw = Serializer::serialize(data);
	cout << *(reinterpret_cast<string*>(raw) + 1) << endl;
	Data* data2 = Serializer::deserialize(raw);
	cout << "raw: " <<  raw << endl;
	cout << "data2->s: " << data2->s << endl;
	cout << "data2: " << data2 << endl;
	cout << "data: " << data << endl;
	delete data;
	return 0;
}