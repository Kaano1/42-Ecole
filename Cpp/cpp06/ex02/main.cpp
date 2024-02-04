#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int i = rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		cout << "A" << endl;
	else if (dynamic_cast<B*>(p))
		cout << "B" << endl;
	else if (dynamic_cast<C*>(p))
		cout << "C" << endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		cout << "A" << endl;
	}
	catch(const exception& e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			cout << "B" << endl;
		}
		catch(const exception& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				cout << "C" << endl;
			}
			catch(const exception& e)
			{
				cerr << e.what() << '\n';
			}
		}
	}
}


int main()
{
	srand(time(NULL));
	Base *p = new A();
	p = generate();

	identify(p);
	identify(*p);
	delete p;
	system("leaks program");
	return 0;
}
