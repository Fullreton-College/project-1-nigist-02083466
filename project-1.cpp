#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> words;
vector<string> uniqueWords;
vector<int> counts;

// clean word function
string cleanedword(string w)
{
    string clean = "";

    for (char c : w)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            clean += c;
        }
    }

    return clean;
}

// count words
void countWords()
{
    for (int i = 0; i < words.size(); i++)
    {
        bool found = false;

        for (int j = 0; j < uniqueWords.size(); j++)
        {
            if (words[i] == uniqueWords[j])
            {
                counts[j]++;
                found = true;
                break;
            }
        }

        if (!found && words[i] != "")
        {
            uniqueWords.push_back(words[i]);
            counts.push_back(1);
        }
    }
}

int main()
{
    ifstream file("homes.txt");

    if (!file.is_open())
    {
        cout << "File is not open" << endl;
        return 1;
    }

    string word;

    while (file >> word)
    {
        word = cleanedword(word);
        words.push_back(word);
    }

    countWords();

    for (int i = 0; i < uniqueWords.size(); i++)
    {
        cout << uniqueWords[i] << " : " << counts[i] << endl;
    }

    file.close();
}