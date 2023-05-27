#include <stdio.h>
#include <string.h>

int main() {
    char words[10][20] = {"programming", "computer", "keyboard", "mouse", "google", "printer", "scanner", "software", "hardware", "internet"};
    int num_guesses = 0;
    int max_guesses = 10;
    int word_choice = 0;
    char guessed_letters[26];
    char guess[20];
    char word[20];
    int correct_guesses = 0;

    // Prompt user for word choice
    printf("Enter a number from 1 to 10 to choose a word: ");
    scanf("%d", &word_choice);
    word_choice--;  // Decrement by 1 to match array index

    // Set up word and guessed letters
    strcpy(word, words[word_choice]);
    memset(guessed_letters, 0, sizeof(guessed_letters));

    // Convert each letter in word to a dot
    for (int i = 0; i < strlen(word); i++) {
        guess[i] = '.';
    }

    // Main game loop
    while (correct_guesses < strlen(word) && num_guesses < max_guesses) {
        // Print current state of game
        printf("\nGuess the word: %s\n", guess);
        printf("Wrong guesses: ");
        for (int i = 0; i < 26; i++) {
            if (guessed_letters[i] != '\0') {
                printf("%c ", guessed_letters[i]);
            }
        }
        printf("\n");

        // Prompt user for guess
        char letter;
        printf("Guess a letter: ");
        scanf(" %c", &letter); // Note the space before %c to consume any whitespace

        // Check if letter has already been guessed
        int is_already_guessed = 0;
        for (int i = 0; i < 26; i++) {
            if (guessed_letters[i] == letter) {
                printf("You have already guessed that letter.\n");
                is_already_guessed = 1;
                break;
            }
        }

        if (!is_already_guessed) {
            // Add guess to guessed letters
            for (int i = 0; i < 26; i++) {
                if (guessed_letters[i] == '\0') {
                    guessed_letters[i] = letter;
                    break;
                }
            }

            // Check if letter is in word
            int is_in_word = 0;
            for (int i = 0; i < strlen(word); i++) {
                if (word[i] == letter) {
                    guess[i] = letter;
                    correct_guesses++;
                    is_in_word = 1;
                }
            }

            if (!is_in_word) {
                num_guesses++;
            }
        }
    }

    // Game over
    if (correct_guesses == strlen(word)) {
        printf("\nCongratulations! You guessed the word: %s\n", word);
    } else {
        printf("\nSorry, you ran out of guesses. The word was: %s\n", word);
    }

    return 0;
}
