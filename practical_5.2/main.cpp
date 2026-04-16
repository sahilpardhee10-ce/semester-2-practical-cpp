#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main()
{
    fstream file("data.txt", ios::in);
    if (!file)
    {
        cout << "File not found!" << endl;
        return 1;
    }

    string line;
    int charCount = 0, wordCount = 0, lineCount = 0;

    // Read file line by line
    while (getline(file, line))
    {
        lineCount++; // count line
        bool inWord = false;

        for (int i = 0; i < line.length(); i++)
        {
            char c = line[i];
            charCount++; // count characters

            if (isspace(static_cast<unsigned char>(c)))
            {
                if (inWord)
                {
                    wordCount++;
                    inWord = false;
                }
            }
            else
            {
                inWord = true;
            }
        }

        // last word in line
        if (inWord)
            wordCount++;
    }

    cout << "Number of characters: " << charCount << endl;
    cout << "Number of words: " << wordCount << endl;
    cout << "Number of lines: " << lineCount << endl;

    file.close();
    return 0;
}