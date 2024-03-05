# Guess number
set(GUESS_NUMBER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/guess-number")
add_executable(guess-number "${GUESS_NUMBER_DIR}/guess-number.cpp")
add_executable(guess-number-reverse "${GUESS_NUMBER_DIR}/guess-number-reverse.cpp")

# Hangman
set(HANGMAN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/hangman")
add_executable(hangman "${HANGMAN_DIR}/hangman.cpp")

# Tic-Tac-Toe
set(TIC_TAC_TOE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tic-tac-toe")
add_executable(tic-tac-toe "${TIC_TAC_TOE_DIR}/tic-tac-toe.cpp")

# Test
set(TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/test")
add_executable(test "${TEST_DIR}/test.cpp")