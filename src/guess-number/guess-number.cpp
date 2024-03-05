#include <iostream>
#include <cstdlib>

int main()
{
    std::srand(static_cast<unsigned int>(time(0)));
    printf("Hello to the \"Guess My Number\" game.\n");
    printf("Try to guess what number I thinking.\n\n");

    int guess_number = (std::rand() % 10) + 1;
    int tries = 1;
    while(true)
    {
        printf("Enter your number: ");
        int number;
        std::cin >> number;
        if (number < guess_number)
        {
            printf("Too low!\n");
        }
        else if (number > guess_number)
        {
            printf("Too high!\n");
        }
        else
        {
            printf("You are correct!\n");
            printf("Number of tries: %d\n", tries);
            break;
        }

        tries++;
        printf("\n");
    }
}
