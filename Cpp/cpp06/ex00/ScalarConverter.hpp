#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <stdexcept>
# include <sstream>


using std::string;
using std::cout;
using std::cerr;
using std::stoi;
using std::stof;
using std::endl;
using std::stod;

#define _INF 1
#define _CHAR 2
#define _FLOAT 3
#define _DOUBLE 4
#define _INT 5
#define INVALID 0


class ScalarConverter
{
	private:
				ScalarConverter();
				ScalarConverter(ScalarConverter const &copy);
				ScalarConverter &operator=(ScalarConverter const &other);
				static int check(const string&);
				static void putChar(const char& c);
				static void putChar(void);
				static void putInt(const int& i);
				static void putFloat(const float& f);
				static void putDouble(const double& d);
				static void typeChar(const string&);
				static void typeInt(const string&);
				static void typeFloat(const string&);
				static void typeDouble(const string&);
				static void notPossible(const string& str);
	public:
		~ScalarConverter();
		static bool convert(string&);
};

#endif
