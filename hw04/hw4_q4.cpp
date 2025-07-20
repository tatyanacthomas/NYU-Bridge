#include <iostream>
#include <cmath>

int main() {

    int sequenceLen;
    int product;
    int userInput;
    double geoMean;
    
    //VERSION 1 

    //retrieving user input
    std::cout << "section a" << std::endl << std::endl;

    std::cout << "Please enter the length of the sequence: " << std::endl;
    std::cin>> sequenceLen;
    
    std::cout << "Please enter your sequence: " << std::endl;
    
    product = 1;
    
    //looping through each user input item and multiplies them with each other
    for(int i = 1; i <= sequenceLen ; i++){
        std::cin>> userInput;
        product = product * userInput;
    }
    
    //calculates the geometric mean
    geoMean = pow((double)product, (1/(double)sequenceLen));
    
    //outputs final value 
    std::cout.precision(4);
    std::cout<< "The geometric mean is: " << std::fixed << geoMean << std::endl<< std::endl;
    
    //VERSION 2
    std::cout << "section b" << std::endl << std::endl;
    std::cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:" << std::endl;
    
    //declaring a boolean flag that will tell the loop to end when a certain condition is met
    bool inputConcluded;
    
    //initializing the variables needed for the while loop
    int i = 1;
    product = 1;
    inputConcluded = false;
    
    //runs product-calculation loop until the input value entered is -1. Then raises the flag and ends the loop
    while(inputConcluded == false){
        std::cin>> userInput;
        if (userInput == -1){
            inputConcluded = true;
            
        }else{
            product = product * userInput;
            i++;
            
        }
    }
    
    //calculates the geometric mean
    geoMean = pow((double)product, (1/(double)sequenceLen));
    
    //outputs final value
    std::cout.precision(4);
    std::cout<< "The geometric mean is: " << std::fixed << geoMean << std::endl;
    
    
    return 0;
}
