#include <unordered_map>
#include <iostream>
#include <string>

class permutationString
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;
        std::unordered_map<char, int> s1Map;
        std::unordered_map<char, int> s2Map;
        for (char ch : s1)
        {
            if (s1Map.find(ch) == s1Map.end())
            {
                s1Map[ch] = 1;
            }
            else
            {
                s1Map[ch]++;
            }
        }

        for (int i = 0; i <= s2.length() - s1.length(); i++)
        {
            for (int j = 0; j < s1.length(); j++)
            {
                char aux = s2[i + j];
                if (s2Map.find(aux) == s2Map.end())
                {
                    s2Map[aux] = 1;
                }
                else
                {
                    s2Map[aux]++;
                }
            }
            if (mapMatches(s1Map, s2Map, s1))
            {
                return true;
            }

            s2Map.clear();
        }
        return false;
    }

    bool mapMatches(std::unordered_map<char, int> map1, std::unordered_map<char, int> map2, std::string s1)
    {
        for (char key : s1)
        {
            if (map2.find(key) == map2.end())
            {
                if (map1.at(key) - (-1) != 0)
                {
                    return false;
                }
            }
            else
            {
                if (map1.at(key) - map2.at(key) != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
