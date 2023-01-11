#ifndef PHONEBOOK_HPP
#define  PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <string>

using	std::cin;
using	std::cout;
using	std::string;
using	std::endl;


class Phonebook
{
    private:
        Contect book[8];
        int		index;
    public:
        void	searching( int many),

		void get_contect(int i)
        {
            if (i > 8)
                return (NULL);
            return (book[i]);
        }
};
#endif