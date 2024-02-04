#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) { *this = copy; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {  }

bool ScalarConverter::convert(string& str)
{
	int type;

	type = check(str);
	switch (type)
	{
		case INVALID:
			return (INVALID);
		case _CHAR:
			typeChar(str);
			break;
		case _FLOAT:
			typeFloat(str);
			break;
		case _DOUBLE:
			typeDouble(str);
			break;
		case _INT:
			typeInt(str);
			break;
		case _INF:
			notPossible(str);
			break;
		default:
			break;
	}
	return (1);
}

void ScalarConverter::notPossible(const string& str)
{
	if (str.compare("nanf") || str.compare("nan"))
	{
		cout << "char: impossible" << endl;
		cout << "int: impossible" << endl;
		cout << "float: " << (str.find(".") == 1 ? str : str + ".0") << "f" << endl;
		cout << "double: " << (str.find(".") == 1 ? str : str + ".0") << endl;
	}

}

void ScalarConverter::typeChar(const string& str)
{
	char c = static_cast<char>(str[0]);

	putChar(c);
	putInt(static_cast<int>(c));
	putFloat(static_cast<float>(c));
	putDouble(static_cast<double>(c));
}

void ScalarConverter::typeInt(const string& str)
{
	std::istringstream iss(str);
	int i;

	iss >> i;

	if (!isprint(i))
		putChar();
	else
		putChar(static_cast<char>(i));
	putInt(i);
	putFloat(static_cast<float>(i));
	putDouble(static_cast<double>(i));
}

void ScalarConverter::typeFloat(const string& str)
{
	float f = std::strtof(str.c_str(), NULL);


	if (!isprint(static_cast<int>(f)))
		putChar();
	else
		putChar(static_cast<char>(f));
	putInt(static_cast<int>(f));
	putFloat(f);
	putDouble(static_cast<double>(f));
}

void ScalarConverter::typeDouble(const string& str)
{
	double d = std::strtod(str.c_str(), NULL);

	if (!isprint(static_cast<int>(d)))
		putChar();
	else
		putChar(static_cast<char>(d));
	putInt(static_cast<int>(d));
	putFloat(static_cast<float>(d));
	putDouble(d);
}

void ScalarConverter::putChar(void)
{
	cout << "char: '" << "Non displayable" << "'" << endl;
}

void ScalarConverter::putChar(const char& c)
{
	if (!isprint(c))
		putChar();
	else
		cout << "char: '" << c << "'" << endl;
}

void ScalarConverter::putInt(const int& i)
{
	cout << "int: " << i << endl;
}

void ScalarConverter::putFloat(const float& f)
{
	if (f != static_cast<int>(f))
		cout << "float: " << f << "f" << endl;
	else
		cout << "float: " << f << ".0f" << endl;
}

void ScalarConverter::putDouble(const double& d)
{
	if (d != static_cast<int>(d))
		cout << "double: " << d << endl;
	else
		cout << "double: " << d << ".0" << endl;
}


int ScalarConverter::check(const string& str)
{
	int dot;
	int f;

	dot = 0;
	f = 0;
	if (!(str.compare("+inf") && str.compare("+inff") &&
			str.compare("-inf") && str.compare("-inff") &&
			str.compare("nan") && str.compare("nanf")))
				return (_INF);
	else if (str.length() == 1)
	{
		if (isdigit(str[0]))
			return (_INT);
		return (_CHAR);
	}

	else if (str.length() > 1)
	{
		for(size_t i = 0; i < str.size(); i++)
		{
			if (str[i] == '.')
			{
				dot++;
				if (!isdigit(str[i + 1]))
					return (INVALID);
			}
			else if (str[i] == 'f')
				f++;
			else if(!isdigit(str[i]) &&
				!(str[i] == 'f' && i == str.length() - 1 && f == 1) &&
				!(str[i] == '-' && i == 0))
					return (INVALID);
		}
		if (f == 1)
		{
			if (dot == 0)
				return (INVALID);
			else
				return (_FLOAT);
		}
		else if (dot == 1)
			return (_DOUBLE);
		return (_INT);
	}
	return (INVALID);
}
