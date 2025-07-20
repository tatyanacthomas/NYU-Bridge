#include <iostream>
#include <cmath>

void printDivisors(int num);
//precondition: int num is retrieved from userInput
//postcondition: num is iterated 2*sqrt(num)-1 times to identify divisor and complements of num

int main(){
    int userInput;
    
    std::cout << "Please enter a positive integer >= 2: ";
    std::cin>> userInput;
    
    printDivisors(userInput);
    
    return 0;
}

void printDivisors(int num){ 
    //since all divisors can be found within the first sqrt(num) range instead of  searching 
    //all values from 1 to num, I set the range to 1 to sqrt(num). 
    //Prints all i values equally divisible by num
    for(int i = 1; i <= sqrt(num) ; ++i){
        if(num % i == 0){
            std::cout<< i << " ";
        }
    }
    
    //iterates again through the same i-value range again, but in reverse (starts at sqrt(num)-1 because 
    //the last value that was evaluated in the previous loop was sqrt(num))
    //Prints i's complementary divisor 
    for(int i = sqrt(num)-1; i > 0 ; --i){
        if(num % i == 0){
            std::cout<< num/i << " ";
        }
    }
}
