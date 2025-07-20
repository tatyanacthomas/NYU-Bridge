#include <iostream>
#include <cmath>

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
//precondition:   int num is either passed in by the user or retrieved programatically, 
//                and precondition values of outCountDivs and outSumDivs are provided
//postcondition:  finds how many divisors a number has, minus the number itself and
//                adds up the sum of all of the divisors as well (not including the number itself)

bool isPerfect(int num);
//precondition:  int num is provided
//postcondition: calls analyzeDividors against int num for its outSumDivs value. 
//               Returns true if outSumDivs = num, returns false if outSumDivs != num

void perfectNumbers(int num);
//precondition:  int num is provided
//postcondition: calls isPerfect against all numbers in a range from 2 to num. 
//               Prints list of all perfect numbers in the given range, separated by a space

void amicableNumbers(int num);
//precondition:  int num is provided
//postcondition: Evaluates analyzeDividors against a range from 2 to num to find all instances where 
//               the sum of the divisors of amicableNum1 is the same as the value of amicableNum2, 
//               and  the sum of amicableNum2's divisors is equal the value of amicableNum1

int main(){
    int userInput;

    
    std::cout << "Please enter a positive integer >= 2: ";
    std::cin>> userInput;
    
    std::cout << std::endl;
    
    std::cout << "Perfect numbers from 1 to " << userInput << ": ";
    perfectNumbers(userInput); //this runs M times
    
    std::cout << std::endl<<std::endl;
    
    std::cout << "All amicable pairs from 1 to " << userInput << ": " <<std::endl;
    amicableNumbers(userInput); //this runs 2M times

    //Total analyzeDividors call count: 3 x M times, therefore calls the function Theta(M) times
    
    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs){
    int divCount;
    int divSum;

    divCount = 0;
    divSum = 0;
    
    //goes from 1 to sqrt(num) and increments the divCount when it finds a number that evenly divides with  num
    //and adds the divisor to the overall sum of divisors if it finds a number that evenly divides with num
    //this  will calculate the first 1/2 of the divisors associated with num
    for(int i = 1; i <= sqrt(num) ; ++i){
        if(num % i == 0){
            divCount++;
            divSum = i + divSum;
        }else{
            continue;
        }
    }
    //decrements from sqrt(num) to 1. Still increments the divCount, but adds num/i to the sumDivs value instead of just i. 
    //  num/i is i's complementary divisor from the prior loop 
    for(int i = sqrt(num); i > 0 ; --i){
        
        if(sqrt(num) - i == 0){ //this ensures that sqrt(num) values are not duplicated, skips over them
            i--;
        }
        //this makes sure that the value num is not included in the final eval 
        //since the complementary divisor of num is 1
        if(i == 1){ 
            continue;
        
        }else if(num % i == 0){
            divSum = (num/i) + divSum;
            divCount++;
        }else{
            continue;
        }
    }
    
    outCountDivs = divCount;
    outSumDivs = divSum;

}

bool isPerfect(int num){
    int countDivs;
    int sumDivs;
    bool isPerfect;
    
    countDivs = 0;
    sumDivs = 0;
    
    analyzeDividors(num, countDivs, sumDivs);

    //a perfect number is equal to the sum of its divisors 
    if(num == sumDivs){
        isPerfect = true;
    }else{
        isPerfect = false;
    }
    
    return isPerfect;
    
}

void perfectNumbers(int num){

    //runs through a range of numbers and identifies if the number is perfect. If so, prints it out. 
    for(int i = 2; i <= num; i++){
        if(isPerfect(i) == true){
            std::cout << i << " ";
        }else{
            continue;
        }
    }
    
}

void  amicableNumbers(int num){
    int am1CountDivs = 0, am1SumDivs = 0;
    int am2CountDivs = 0, am2SumDivs = 0;

    int callFuncCount = 0;

    int amPair1 = 0;
    int amPair2 = 0;
    
    for(int amPair1 = num; amPair1 > 2; amPair1--){
        //decrements from num to i, evaluating i and outputting am1countDivs and am1SumDivs
        analyzeDividors(amPair1,am1CountDivs,am1SumDivs);
        //callFuncCount++;
        //assigning the amicable pair 1's sum value to amicablePair2 value since that is going to be the other number that is evaluated
        amPair2 = am1SumDivs;
        //calculating the value of each i's sumDiv, which is stored in another variable called am2SumDivs
        //in otherwords, calculating sumDiv(sumDiv(i))
        analyzeDividors(amPair2, am2CountDivs, am2SumDivs);
        //callFuncCount++;

        //checking to see if i = sumDiv(sumDiv(i))
        //if so, outputs the two values that were evaluated in analyzeDivisors, i and am1SumDivs
        if (am2SumDivs == amPair1){
            if(amPair1 == am1SumDivs){ //doesn't print out perfect numbers
                continue;
            }
            if(am1SumDivs > num){ //doesn't print out any numbers that are greater than the given range
                continue;
            }
            std::cout << amPair1 << ", " << amPair2 << std::endl; 
            amPair1 = am1SumDivs; //once a pair is found, sets the newest value of i to the lower of the pair's values to prevent repeats
        }
    }
    //std::cout << "callFuncCount = " << callFuncCount << std::endl;
}