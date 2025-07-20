#include <iostream>

int main(){
    int x;
    int y;

    int add;
    int subtract;
    int multiply;
    double divide;
    int div;
    int mod;

    //Prompts the user for input and retrieves their input
    std::cout << "Please enter two positive integers, separated by a space: \n";
    std::cin>> x >> y;

    //establishing the arithemtic equations that each final calculation will produce. 
    add = x + y;
    subtract = x - y;
    multiply = x * y;
    divide = (double)x / double(y);
    div = x / y;
    mod = x % y;

    //outputs the calculations for each type of arithmetic equation
    std::cout << x << " + " << y << " = " << add <<std::endl;
    std::cout << x << " - " << y << " = " << subtract <<std::endl;
    std::cout << x << " * " << y << " = " << multiply <<std::endl;
    std::cout << x << " / " << y << " = " << divide <<std::endl;
    std::cout << x << " div " << y << " = " << div <<std::endl;
    std::cout << x << " mod " << y << " = " << mod <<std::endl;
    
    return 0;
}