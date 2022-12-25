
class Phonebook
{
    private:
        Contect book[8];
        int		index;
    public:
		Contect get_contect(int i)
        {
            return (book[i]);
        }
};
