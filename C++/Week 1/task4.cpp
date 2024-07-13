                            /*       Check the letter is vowel or not        */

#include <iostream>

const char vowels[] = {'a', 'o', 'u', 'i', 'e'};

int main()
{
    char letter = 0;
    std::cout << "Enter the letter: ";
    std::cin >> letter;
    letter = tolower(letter);

    for (char i : vowels) 
    {
        if(i == letter) 
        {
            std::cout << "it is vowel" << std::endl;
            return 0;
        }
    }

    std::cout << "it is not vowel" << std::endl;
    return 0;
}
