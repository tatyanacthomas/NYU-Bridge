#include <iostream>

//Constant values for readability. 1 is not needed because it is not in any calculation.
const int ONE_THOUSAND = 1000;
const int FIVE_HUNDRED = 500;
const int ONE_HUNDRED = 100;
const int FIFTY = 50;
const int TEN = 10;
const int FIVE = 5;

int main() {
    
    int userInput;
    
    int thousands;
    int fiveHundreds;
    int oneHundreds;
    int fifties;
    int tens;
    int fives;
    int ones;
    
    //decremental value as the program calculates
    int runningVal;
    
    //variable that will store the output
    std::string romanNumerals;
    
    //retrieve user input
    std::cout << "Enter decimal number: " << std::endl;
    std::cin>> userInput;
    
    //assigning variable to userInput so that the userInput is left unchanged
    runningVal = userInput;
    
    //calculating how many of each category of letter is needed, decrementing through the runningVal
    thousands = runningVal / ONE_THOUSAND;
    runningVal = runningVal - (thousands * ONE_THOUSAND);
    
    fiveHundreds = runningVal / FIVE_HUNDRED;
    runningVal = runningVal - (fiveHundreds * FIVE_HUNDRED);
    
    oneHundreds = runningVal / ONE_HUNDRED;
    runningVal = runningVal - (oneHundreds * ONE_HUNDRED);
    
    fifties = runningVal / FIFTY;
    runningVal = runningVal - (fifties * FIFTY);
    
    tens = runningVal / TEN;
    runningVal = runningVal - (tens * TEN);

    fives = runningVal / FIVE;
    runningVal = runningVal - (fives * FIVE);

    ones = runningVal;
    
    //initializing output as empty string
    romanNumerals = "";
    
    //looping through each letter type and printing the letters. Iteration count is equal to the number of thousands, 5 hundreds, etc etc that was established in the calculations above.
    for (int i  = 1 ; i <= ones ; i++){
        romanNumerals =  "I" + romanNumerals;
        
    }
    
    for (int i  = 1 ; i <= fives ; i++){
        romanNumerals =  "V" + romanNumerals;
        
    }
    
    for (int i  = 1 ; i <= tens ; i++){
        romanNumerals =  "X" + romanNumerals;
        
    }
    
    for (int i  = 1 ; i <= fifties ; i++){
        romanNumerals =  "L" + romanNumerals;
        
    }
    
    for (int i  = 1 ; i <= oneHundreds ; i++){
        romanNumerals =  "C" + romanNumerals;
        
    }
    
    for (int i  = 1 ; i <= fiveHundreds ; i++){
        romanNumerals =  "D" + romanNumerals;
        
    }
    
    for (int i  = 1 ; i <= thousands ; i++){
        romanNumerals =  "M" + romanNumerals;
        
    }
    
    //outputting the final roman numerals
    std::cout << "romanNumerals: " << romanNumerals << std::endl;
    
    return 0;
}
