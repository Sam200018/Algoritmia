#include <iostream>
#include <map>
#include <string>

bool checkPermutation(std::string first, std::string second)
{
    if (first.length() != second.length())
    {
        return false;
    }
    std::map<char, int> storage;
    std::pair<char, int> aux;
    for (int i = 0; i < first.length(); i++)
    {
        char position = first.at(i);
        storage[position]++;
    }

    for (auto j = 0; j < second.length(); j++)
    {
        char position = second.at(j);
        if (storage.find(position) == storage.end())
        {
            return false;
        }
        storage[position]--;
        if (storage[position] < 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::string str1 = "triangle", str2 = "integral";
    if (checkPermutation(str1, str2))
    {
        std::cout << "2 es permutacion de 1" << std::endl;
    }
    else
    {
        std::cout << "2 no es permutacion de 1" << std::endl;
    }
    return 0;
}
