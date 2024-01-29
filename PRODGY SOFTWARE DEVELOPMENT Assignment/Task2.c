#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int secretNumber = rand() % 100 + 1;

    int userGuess;
    int attempts = 0;

    printf("Welcome to the Number Guessing Game!\n");

    do
    {
        printf("Enter your guess (between 1 and 100): ");
        scanf("%d", &userGuess);

        attempts++;

        if (userGuess > secretNumber)
        {
            printf("Too high! Try again.\n");
        }
        else if (userGuess < secretNumber)
        {
            printf("Too low! Try again.\n");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }

    } while (userGuess != secretNumber);

    return 0;
}