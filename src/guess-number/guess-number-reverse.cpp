#include <iostream>
#include <cstdlib>
#include <set>

int main()
{
    std::srand(static_cast<unsigned int>(time(0)));
    printf("Hello to the \"Guess My Number\" game.\n");
    printf("I will try to guess what number you thinking.\n\n");

    printf("Enter your secret number: ");
    unsigned int guess_number;
    std::cin >> guess_number;

    unsigned int tries = 1;
    std::set<unsigned int> numbers;

    unsigned int low = 0;
    unsigned int high = guess_number;
    while(true)
    {
        int number = (std::rand() % guess_number + 1);
        while(true)
        {
            if (numbers.count(number) || number < low || number > high)
            {
                number = (std::rand() % guess_number + 1);
                continue;
            }

            numbers.insert(number);
            break;
        }

        printf("\nI guess your numer is %d\n", number);
        if (number < guess_number)
        {
            low = number;
            printf("But it's too low!\n");
        }
        else if (number > guess_number)
        {
            high = number;
            printf("But it's too high!\n");
        }
        else
        {
            printf("I am correct!\n");
            printf("Number of tries: %d\n", tries);
            break;
        }

        tries++;
    }
}
