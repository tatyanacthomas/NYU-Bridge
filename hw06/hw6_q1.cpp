#include <iostream>

int fib(int n);
//precondition: int n is retrieved from the user
//postcondition: summation calculation is done to retrieve the nth fibonacci value

int main(){
    int num;
    int fibVal;
    
    //retrieve user input
    std::cout << "Please enter a positive number: " << std::endl;
    std::cin>> num;
    
    //calculate fibonacci value
    fibVal = fib(num);
   
    //output value
    std::cout << fibVal << std::endl;
    
    return 0;
}

int fib(int n){
    int numA;
    int numB;
    int sum;
    
    numA = 0;
    numB = 1;
    sum = 0;
    
    if(n == 1){
        sum = 1;
        
    }else{
        for(int i = 1; i < n; i++){
            //add the numbers together and store the added number into a variable
            sum = numA + numB;
            //assigning numB value to the #1 position for the next summation
            numA = numB;
            //assigning the sum to #2 position for the next summation
            numB = sum;
        }
    }
    
    return sum;
}
