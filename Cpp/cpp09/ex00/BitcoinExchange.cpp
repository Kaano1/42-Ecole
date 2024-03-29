#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    std::cout << "Default Constructor Call" << std::endl;
    openFile(csvFile);
}

BitcoinExchange::BitcoinExchange(std::string fileName)
{
    openFile(csvFile);
    openFile(inputFile, fileName);
    this->inputFileName = fileName;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &instance)
{
    std::cout << "Copy Constructor Call" << std::endl;
    *this = instance;
}

BitcoinExchange::~BitcoinExchange(void)
{
    if (this->csvFile.is_open())
        csvFile.close();
    if (this->inputFile.is_open())
        inputFile.close();
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    std::cout << "Operator Overload Call" << std::endl;
    if (this->csvFile.is_open())
        csvFile.close();
    if (this->inputFile.is_open())
        inputFile.close();
	openFile(this->csvFile);
    openFile(this->inputFile, rhs.inputFileName);
    this->mapCsv = rhs.mapCsv;
    return (*this);
}

void    BitcoinExchange::locateCsvInMap()
{
    std::string line;

    std::getline(this->csvFile, line);
    if (line != "date,exchange_rate")
        throw MyException("Invalid CSV file.");
    while (std::getline(this->csvFile, line))
    {
        std::istringstream ss(line);
        std::string date;
        std::string value;
        
        while (std::getline(ss, date, ',') && std::getline(ss, value, ','))
        {
            float tmp;
            try
            {
                tmp = std::stof(value);
            }catch(const std::exception& e)
            {
                throw MyException("Type Casting Error.");
            }
            this->mapCsv.insert(std::pair<std::string, float> (date, tmp));
        }
    }
}

std::map<std::string, float> &BitcoinExchange::getMap()
{
    return (this->mapCsv);
}

void	BitcoinExchange::start(void)
{
    std::string line;

    std::getline(this->inputFile, line);
    if (line != "date | value")
        throw MyException("Invalid Input file.");
    while (std::getline(this->inputFile, line))
    {
        std::stringstream ss(line);
        std::string dateStr;
        dateElements *inputInline;
        std::string valueStr;
        bool newLine = false;

        try{
            checkInputLine(line);
            
            while (std::getline(ss, dateStr, ' ') && std::getline(ss, valueStr, ' ') && std::getline(ss, valueStr, ' '))
            {
                inputInline = fillDateStruct(dateStr);
                try
                {
                    checkValue(valueStr);
                    inputInline->value = std::stof(valueStr);
                }
                catch(const std::exception& e)
                {
                    std::cout << e.what() << std::endl;
                    newLine = true;
                    delete inputInline;
                    break;
                }
            }
            if (newLine == true)
                continue;
            if (limitCheck(inputInline))
            {
                if (limitCheck(inputInline) == 3)
                    std::cout << "Error: too large a number." << std::endl;
                else if (limitCheck(inputInline) == 2)
                    std::cout << "Error: not a positive number." << std::endl;
                else
                    std::cout << "Error: bad input => " << inputInline->dateStr << std::endl;
                continue;
            }
        }
        catch(const std::exception &e)
        {
            std::cout << e.what() << line << std::endl;
            continue;
        }

        std::map<std::string, float>::iterator Cvits = mapCsv.begin();
        std::map<std::string, float>::iterator expected;
        while (Cvits != mapCsv.end())
        {
            if ((strToSum(dateStr) - strToSum(Cvits->first)) >= 0)
                expected = Cvits;
            else
                break;
            ++Cvits;
        }
        std::cout << dateStr << " => "<< inputInline->value << " = " << (inputInline->value * expected->second) << std::endl;
        delete inputInline;
    }
}