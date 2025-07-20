#include <iostream>

int main(){
    
    int userInput;
    int outputVal;
    
    //retrieve user input
    std::cout << "Please enter a positive integer: " << std::endl;
    std::cin>> userInput;
    
    //number of rows == to userInput value
    for(int i = 1; i <= userInput; i++){
        
        //number of columns == to userInput value
        for(int j = 1; j <= userInput; j++){
            
            //row count * column count = output value
            outputVal = i *  j;
            std::cout << outputVal<< "\t";
        }
        std::cout<<std::endl;
    }
    
    return 0;
}
