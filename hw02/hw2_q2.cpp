#include <iostream>

//declares coin value constants for ease of reference
//PENNIES_VAL is not needed as it is not used in any calculation
const int QUARTERS_VAL = 25;
const int DIMES_VAL = 10;
const int NICKELS_VAL = 5;


int main(){
    
    int quarters;
    int dimes;
    int nickels;
    int pennies;

    int totalValue;

    int totalDollars;
    int totalCents;

    //prompts the user for dollars and cents total value
    std::cout << "Please enter your amount in the format of dollars and cents separated by a space \n";
    std::cin >> totalDollars >> totalCents;

    //adds up the total amount of cents across the dollars and cents and stores it in an int variable
    totalValue = ((totalDollars * 100) + totalCents);

    //total number of cents (totalValue) divided by "25" quarter value to get the quantity of quarters.
    //reassigns totalValue to prior totalValue minus coin value of all quarters (gets remainder of coins left to calculate) 
    quarters = (totalValue / QUARTERS_VAL);
    totalValue = totalValue - (quarters * QUARTERS_VAL);

    //total number of cents (totalValue) divided by "10" dimes value to get the quantity of dimes.
    //reassigns totalValue to prior totalValue minus coin value of all dimes (gets remainder of coins left to calculate)
    dimes = (totalValue / DIMES_VAL);
    totalValue = totalValue - (dimes * DIMES_VAL);

    //total number of cents (totalValue) divided by "5" nickels value to get the quantity of nickels.
    //reassigns totalValue to prior totalValue minus coin value of all nickels (gets remainder of coins left to calculate)
    nickels = (totalValue / NICKELS_VAL);
    totalValue  = totalValue - (nickels * NICKELS_VAL);

    //no calculation needed, simply assign the remaining coins left as the remainder of pennies
    pennies = totalValue;


    //outputs the final response
    std::cout<< totalDollars << " dollars and " <<  totalCents << " cents are: \n";
    std::cout<< quarters << " quarters, " << dimes << " dimes,  "<< nickels << " nickels, and " << pennies << " pennies.\n";
    
    return 0;

}