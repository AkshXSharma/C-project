
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int get_integer_from_user(const char *prompt) {
    int x;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &x) == 1) {
            clear_input_buffer();
            return x;
        } else {
            printf("Please enter a valid integer.\n");
            clear_input_buffer();
        }
    }
}

int main(void) {
    srand((unsigned) time(NULL));
    int secret, guess, attempts;
    char play_again = 'y';

    printf("=== Number Guessing Game ===\n\n");

    while (play_again == 'y' || play_again == 'Y') {
        secret = rand() % 100 + 1;  // choose between 1 and 100
        attempts = 0;

        printf("I have chosen a number between 1 and 100. Try to guess it!\n");

        do {
            guess = get_integer_from_user("Enter your guess: ");
            attempts++;

            if (guess < secret) {
                printf("Too low! Try a higher number.\n");
            } else if (guess > secret) {
                printf("Too high! Try a lower number.\n");
            } else {
                printf("🎉 Congratulations! You guessed it in %d attempts.\n", attempts);
            }
        } while (guess != secret);

        // Ask to play again
        printf("Do you want to play again? (y/n): ");
        play_again = getchar();
        clear_input_buffer();
        printf("\n");
    }

    printf("Thanks for playing! Goodbye.\n");
    return 0;
}
