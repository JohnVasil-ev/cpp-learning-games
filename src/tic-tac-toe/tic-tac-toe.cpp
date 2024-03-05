#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "learning/print-title.h"

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

void print_help();
char input_yes_no(std::string question);
int input_number(std::string question, int high, int low = 0);
char player_piece();
char opponent(char piece);
void display_board(const std::vector<char>& board);
char winner(const std::vector<char>& board);
bool is_legal(const std::vector<char>& board, int move);
int player_move(const std::vector<char>& board, char human);
int computer_move(std::vector<char> board, char computer);
void announce_winner(char winner, char computer, char human);

int main()
{
    system("clear");
    learning::print_title("Tic-Tac-Toe");
    print_help();

    int move;
    const int NUM_SQUARES = 9;
    std::vector<char> board(NUM_SQUARES, EMPTY);

    char player = player_piece();
    char computer = opponent(player);
    char turn = X;

    system("clear");
    display_board(board);

    while(winner(board) == NO_ONE)
    {
        if (turn == player)
        {
            move = player_move(board, player);
            board[move] = player;
        }
        else
        {
            move = computer_move(board, computer);
            board[move] = computer;
        }
        system("clear");
        display_board(board);
        turn = opponent(turn);
    }

    announce_winner(winner(board), computer, player);
}

void print_help()
{
    printf("Make your move known by entering a number, 0-8. The number\n");
    printf("corresponds to the desired board position, as illustrated:\n\n");

    printf("        0 | 1 | 2\n");
    printf("        3 | 4 | 5\n");
    printf("        6 | 7 | 8\n\n");
    
    printf("Prepare yourself, human. The battle is about to begin.\n\n");
}

char input_yes_no(std::string question)
{
    char response;
    do
    {
        printf("%s (y/n): ", question.c_str());
        std::cin >> response;
    } while (response != 'y' && response != 'n');

    return response;
}

int input_number(std::string question, int high, int low)
{
    int number;
    do
    {
        printf("%s (%d - %d): ", question.c_str(), low, high);
        std::cin >> number;
    } while (number > high || number < low);

    return number;
}

char player_piece()
{
    char go_first = input_yes_no("Do you require the first move?");
    if (go_first == 'y')
    {
        printf("\nThen take the first move. You will ned it.\n");
        return X;
    }
    else
    {
        printf("\nYour bravery will be your undoing... I will go first.\n");
        return O;
    }
}

char opponent(char piece)
{
    if (piece == X)
    {
        return O;
    }
    else
    {
        return X;
    }
}

void display_board(const std::vector<char>& board)
{
    printf("\n\t%c | %c | %c", board[0], board[1], board[2]);
    printf("\n\t---------");
    printf("\n\t%c | %c | %c", board[3], board[4], board[5]);
    printf("\n\t---------");
    printf("\n\t%c | %c | %c", board[6], board[7], board[8]);
    printf("\n");
}

char winner(const std::vector<char>& board)
{
    const int TOTAL_ROWS = 8;

    // all possible winning rows
    const int WINNING_ROWS[TOTAL_ROWS][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    // if any winning row has three values that are the same (and not EMPTY),
    // then we have a winner
    for (int row = 0; row < TOTAL_ROWS; ++row)
    {
        if ((board[WINNING_ROWS[row][0]] != EMPTY) &&
            (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
            (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]))
        {
            return board[WINNING_ROWS[row][0]];
        }
    }

    // since nobody has won, check for a tie (no empty squares left)
    if (count(board.begin(), board.end(), EMPTY) == 0)
        return TIE;

    // since nobody has won and it isn't a tie, the game isn't over
    return NO_ONE;
}

inline bool is_legal(int move, const std::vector<char>& board)
{
    return (board[move] == EMPTY);
}

int player_move(const std::vector<char>& board, char human)
{
    int move = input_number("Where will you move?", (board.size() - 1));
    while (!is_legal(move, board))
    {
        printf("\nThat square is already occupied, foolish human.\n");
        move = input_number("Where will you move?", (board.size() - 1));
    }
    printf("Fine...\n");

    return move;
}

int computer_move(std::vector<char> board, char computer)
{
    int move = 0;
    bool found = false;

    // if computer can win on next move, that's the move to make
    while (!found && move < board.size())
    {
        if (is_legal(move, board))
        {
            board[move] = computer;
            found = winner(board) == computer;
            board[move] = EMPTY;
        }

        if (!found)
        {
            ++move;
        }
    }

    // otherwise, if human can win on next move, that's the move to make
    if (!found)
    {
        move = 0;
        char human = opponent(computer);

        while (!found && move < board.size())
        {
            if (is_legal(move, board))
            {
                board[move] = human;
                found = winner(board) == human;
                board[move] = EMPTY;
            }

            if (!found)
            {
                ++move;
            }
        }
    }
    
    // otherwise, moving to the best open square is the move to make
    if (!found)
    {
        move = 0;
        int i = 0;

        const int BEST_MOVES[] = {0, 8, 2, 6, 1, 5, 3, 7, 4};
        // pick best open square
        while (!found && i < board.size())
        {
            move = BEST_MOVES[i];
            if (is_legal(move, board))
            {
                found = true;
            }

            ++i;
        }
    }

    return move;
}

void announce_winner(char winner, char computer, char human)
{
    if (winner == computer)
    {
        printf("%c's won!\n", winner);
        printf("As I predicted, human, I am triumphant once more -- proof\n");
        printf("that computers are superior to humans in all regards.\n");
    }
    else if (winner == human)
    {
        printf("%c's won!\n", winner);
        printf("No, no! It cannot be! Somehow you tricked me, human.\n");
        printf("But never again! I, the computer, so swear it!\n");
    }
    else
    {
        printf("It's a tie.\n");
        printf("You were most lucky, human, and somehow managed to tie me.\n");
        printf("Celebrate... for this is the best you will ever achieve.\n");
    }
}