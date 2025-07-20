#include <iostream>

double eApprox(int n);
//precondition: int n variable is provided where the greater n, the better the approximation of e
//postcondition: returns the nth "level of approximation" of the letter e, which employs the factorial function for calculation

double factorial(int n);
//precondition: int n variable is provided as the greatest multiplicand of a factorial equation
//postcondition: factorial value is outputted where factorial(n) is equivalent to n!

int main(){
    
    std::cout.precision(30);
    
    //this runs for a constant value therefore does not contribute to increasing runtime
    for (int n = 1; n <= 15; n++){
        std::cout<<"n = "<<n<<'\t'<<eApprox(n)<<std::endl;
    }
       
    return 0;
}

double eApprox(int n){

    //core variables, e is the output, and factorialN is the value returned from calling the factorial function
    double e;
    double factorialN;

    //temporary variables that will store an ever-changing value
    double tempSum;
    double tempFactorial;
    
    tempSum = 0.0;
    
    //since all factorial values can be derived from the uppermost factorial, instead of running factorial for every value n,
    //I run it once and derive the rest of the factorials from this value, ensuring I keep the runtime to theta(n)
    factorialN = factorial(n);

    //assigning a temporary variable with the factorialN so that it stays untouched 
    //and the denominator that contains the factorial can continue to decrement. 
    //tempFactorial is the decrementing denominator in the equation for e. 
    tempFactorial = factorialN;

    //decrementing loop so we start at n
    //we start by dividing factorialN by n, to get the (n-1)! value.
    //then for every i value that follows we divide i by the latest tempFactorial value which has been decrementing each loop
    //tempSum keeps track of all of the (1/n!) values that are being added up.
    for(double i = n; i > 0; i--){
        tempFactorial = (tempFactorial/i);
        tempSum += 1.0/tempFactorial;

    }
    
    //since we started the tempSum with the value for 1/(n-1)!, we need to add the 1/n! value to e here.
    e = tempSum + (1.0/factorialN);
    
    return e;

}

double factorial(int n){
    
    //must declare these values as double to prevent a bit limit.
    double factVal;
    double tempProduct;

    tempProduct = 1;
    
    //from 1 to the value of n, stores value of the multiplication in a temporary variable tempProduct
    //product is tempProduct * i, where tempProduct equals whatever product was evaluated in an earlier i value
    for(int i = 1; i <= n; ++i){
        tempProduct *= i;
    }
    
    //to better understand what is being returned, assigned final tempProduct to output variable "factVal"
    factVal = tempProduct;
    
    return factVal;
}


