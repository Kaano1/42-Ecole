#include "easyfind.hpp"

int main( void )
{
	try
	{
		std::vector<int> list;
		std::vector<int>::iterator itr;

		list.push_back(123);
		list.push_back(3);
		list.push_back(12);

		itr = easyfind( list, 3 );
		cout << *itr << endl;

		std::vector<int> list2;
		std::vector<int>::iterator itr2;

		list2.push_back(245);
		list2.push_back(655);
		list2.push_back(931);

		itr2 = easyfind( list2, 3 );
		cout << *itr2 << endl;
	}
	catch ( exception &e )
	{
		cerr << e.what() << endl;
	}
		

	return 0;
}