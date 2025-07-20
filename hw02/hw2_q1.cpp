#include <iostream>

//declares coin value constants for ease of reference
const float QUARTERS_CENTS = 0.25;
const float DIMES_CENTS = 0.10;
const float NICKELS_CENTS = 0.05;
const float PENNIES_CENTS = 0.01;

int main(){
    
    float quarters;
    float dimes;
    float nickels;
    float pennies;

    float totalValue;

    int totalDollars; //intentionally declared as int as we are interested only in whole dollars
    float totalCents;

    std::cout << "Please enter number of coins: \n";

    //prompts the user for quarters and retrieves inputted value
    std::cout << "# of quarters: \n";
    std::cin >> quarters;
    quarters = quarters * QUARTERS_CENTS;

    //prompts the user for dimes and retrieves inputted value
    std::cout << "# of dimes: \n";
    std::cin>> dimes;
    dimes = dimes * DIMES_CENTS;

    //prompts the user for nickels and retrieves inputted value
    std::cout << "# of nickels: \n";
    std::cin>> nickels;
    nickels = nickels * NICKELS_CENTS;

    //prompts the user for pennies and retrieves inputted value
    std::cout << "# of pennies: \n";
    std::cin>> pennies;
    pennies = pennies * PENNIES_CENTS;
    
    //adds up the total value of the coins, in float format
    totalValue = (quarters + dimes + nickels + pennies);

    //multiplies totalValue by 100 to convert to total-#-of-cents, then divides 100 to get the coins' div value (expected to drop the cents value, as it is implicitly cast to int)
    totalDollars = (totalValue * 100)/100; 

    //takes the total number of cents (already in float format) 
    //and subtracts it from the totalDollars (converted to cent value, thus cast from int to float)
    totalCents = (totalValue * 100.0) - (totalDollars * 100.0);

    //outputs the final response
    std::cout<< "The total is " << totalDollars<< " dollars and " << totalCents << " cents \n";
    
    return 0;

}