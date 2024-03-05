#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "learning/print-title.h"

int main()
{
    std::srand(static_cast<unsigned int>(time(0)));

    enum class FIELDS { TITLE, HINT, NUM_FIELDS };
    const int NUM_WORDS = 16;

    const std::string words[NUM_WORDS][static_cast<int>(FIELDS::NUM_FIELDS)] = {
        {"Hangman", "The name of the game ;)"},
        {"Puzzle", "A game or problem designed to test ingenuity or knowledge"},
        {"Adventure", "An exciting or unusual experience; a journey"},
        {"Chocolate", "A sweet, usually brown food made from roasted and ground cacao seeds"},
        {"Universe", "All existing matter and space considered as a whole; the cosmos"},
        {"Galaxy", "A system of millions or billions of stars, together with gas and dust, held together by gravitational attraction"},
        {"Jungle", "A dense forest typically found in a tropical region, filled with lush vegetation and various types of wildlife"},
        {"Exquisite", "Extremely beautiful and delicate; finely made or done"},
        {"Mystery", "Extremely beautiful and delicate; finely made or done"},
        {"Innovation", "The action or process of innovating; a new method, idea, product, etc"},
        {"Enchantment", "A feeling of great pleasure or delight; magic or sorcery"},
        {"Whisper", "To speak very softly using one's breath rather than one's throat, especially for the sake of privacy"},
        {"Harmony", "The combination of simultaneously sounded musical notes to produce chords and chord progressions having a pleasing effect"},
        {"Serenade", "A piece of music sung or played in the open air, typically by a man at night under the window of his beloved"},
        {"Majestic", "Having or showing impressive beauty or dignity"},
        {"Tantalizing", "Tormenting or teasing with the sight or promise of something that is unobtainable or forbidden"}
    };

    const int choice = std::rand() % NUM_WORDS;

    const std::string WORD = words[choice][static_cast<int>(FIELDS::TITLE)];
    const std::string HINT = words[choice][static_cast<int>(FIELDS::HINT)];

    const int MAX_WRONG = 5;
    int cur_wrong = 0;

    std::string cur_word(WORD.size(), '_');
    std::string used = "";

    while(cur_wrong < MAX_WRONG && cur_word != WORD)
    {
        system("clear");

        learning::print_title("Hangman");
        printf("\nYou have %d incorrect guesses left.\n", (MAX_WRONG - cur_wrong));
        printf("\nSo far, the word is: \"%s\".\n", cur_word.c_str());
        printf("The hint: \"%s\".\n\n", HINT.c_str());
        
        printf("You have used the following letters: ");
        for (const char& u : used)
            printf("%c ", u);
        printf(".\n\n");

        char guess;
        printf("Enter your guess: ");
        std::cin >> guess;
        guess = std::toupper(guess);

        if (used.find(guess) != std::string::npos)
        {
            printf("You have already guessed \"%c\"\n", guess);
            continue;
        }

        used += guess;
        bool found = false;

        for (const char& w : WORD)
        {
            if (std::toupper(w) == guess)
            {
                printf("\nThat's right! \"%c\" is in the word.\n", guess);
                found = true;
                for (size_t i = 0; i < WORD.size(); ++i)
                    if (std::toupper(WORD[i]) == guess)
                        cur_word[i] = w;
                break;
            }
        }

        if (!found)
        {
            cur_wrong++;
            printf("\nSorry. \"%c\" isn't in the word.\n", guess);
        }
    }

    if (cur_wrong >= MAX_WRONG)
    {
        printf("\nGame over!\n");
    }
    else
    {
        printf("\nCongratulations! You guessed!\n");
    }
    printf("The word was %s\n", WORD.c_str());
}