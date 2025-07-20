#include <iostream>
#include <cstdlib>
#include <ctime>

const int GUESS_MAX = 5;

int main(){
    int secretNumber;
    int userGuess;
    int lowerBound;
    int upperBound;
    int guessesLeft;
    int guessesUsed;
    
    //explicitly cast this to int because I was getting the following warning: "Implicit conversion loses integer precision: 'time_t' (aka 'long') to 'unsigned int'"
    srand((int)time(0));
    secretNumber = (rand() % 100) + 1;
    
    std::cout<< "I thought of a number between 1 and 100! Try to guess it." <<std::endl;
    lowerBound = 1;
    upperBound = 100;
    guessesUsed = 0;
    

    //for loop decrementing from 5 guesses to 0
    for(int i = GUESS_MAX; i > 0; i--){
        
        //announces the current guessing range, and number of guesses left (which is == i)
        guessesLeft = i;
        std::cout << "Range: [" << lowerBound << ", " << upperBound << "], Number of guesses left: " << guessesLeft << std::endl;
        
        //retrieves user input
        std::cout << "Your guess: ";
        std::cin>> userGuess;
        
        //increments the number of guesses used right after input.
        guessesUsed++;
        
        //if statement for various outputs to the user. Adjusts the upper/lower bounds accordingly, which values will be stored, and then printed during the next iteration
        //if statement broken into two: if they guess it, breaks out right away, if they don't guess it, then has another inner if statement that will either tell them that they are out of guesses or give them another chance to make a guess
        if(userGuess == secretNumber){
            //If a user guesses in just 1 guess,  grammatically is best to say "1 guess" instead of "1 guesses".
            if(guessesUsed == 1){
                std::cout << "Congrats! You guessed my number in " << guessesUsed << " guess. " << std::endl;
            }else{
                std::cout << "Congrats! You guessed my number in " << guessesUsed << " guesses. " << std::endl;
            }
            break;
        }else{
            //if the GUESS_MAX has not been reached yet, they will get another chance to guess
            if(guessesUsed < GUESS_MAX){
                if(userGuess < secretNumber){
                    std::cout<< "Wrong! My number is bigger. " << std::endl;
                    lowerBound = userGuess + 1;
                }else{ //(userGuess > secretNumber){
                    std::cout << "Wrong! my number is smaller. " << std::endl;
                    upperBound = userGuess - 1;
                }
            }else{
                // since the GUESS_MAX has been reached, they have no more guesses, no need to break because the program will end from the for loop which ends when GUESS_MAX is reached
                std::cout<< "Out of guesses! My number is " << secretNumber << std::endl;
            }
        }
    }
    return 0;
}