#include <iostream>

int main(){

    int inputNum;
    int decimalNum;
    int intBinaryString; //output value
    int incrementalOfPowerTen; //value to enable increment in the loop

    //retrieving user input
    std::cout<<"Enter decimal number: " << std::endl;;
    std::cin>>inputNum;
    
    //assigning input to variable to enable calculation while still retaining the original input
    decimalNum = inputNum;

    //initializing the output as 0    
    intBinaryString = 0;
    
    //incrementalofPowerTen will allow the program to move from one digit place (10s, 100s, 100s, etc) to the next at each loop
    incrementalOfPowerTen = 1;
    
    //while loop continues decrementing through the value of the input until it is zero.
    while(decimalNum > 0){
            //if the iteration is even, no changes are made to the output
            if(decimalNum % 2 == 0){
                intBinaryString = intBinaryString;
            //if the iteration is odd, the incremental value (10s, 100s, 1000s, etc) is added to the output value 
            }else{
                intBinaryString = incrementalOfPowerTen + intBinaryString;
                
            }
        //decrements the input value and increases the increment to enable the loop to continue down each digit
        decimalNum = decimalNum/2;
        incrementalOfPowerTen = incrementalOfPowerTen * 10;
        
    }
    //output final value 
    std::cout << "The binary representation of " << inputNum << " is " << (int)intBinaryString << std::endl;
    
    return 0;
}
