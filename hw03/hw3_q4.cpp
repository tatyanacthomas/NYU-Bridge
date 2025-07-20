#include <iostream>

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main(){

    //variables
    float userInput;
    int roundMethod;
    float remainder;
    float roundedOutput; 


    //user input
    std::cout<< "Please enter a Real number: \n";
    std::cin>> userInput;

    //request round method
    std::cout<< "Choose your rounding method: \n";
    std::cout<< "1. Floor round \n";
    std::cout<< "2. Ceiling round \n";
    std::cout<< "3. Round to the nearest whole number \n";

    std::cin>>roundMethod;

    //calculate round (using switch)

    remainder = userInput - (int)userInput;
    std::cout << "remainder = " << remainder << std::endl;

    if(remainder == 0.0){ //if it is already a round number; no decimal
        roundedOutput = userInput;
        

    }else{
        if (userInput > 0){ //rounding when the integer is positive
            switch (roundMethod){
                case FLOOR_ROUND: //round down to the nearest whole number
                    roundedOutput = userInput - remainder;
                    break;

                case CEILING_ROUND: //round up to the nearest whole number
                    roundedOutput = (userInput - remainder) + 1;
                    break;

                case ROUND: //round to the nearest whole number whether that is up or down, based on which is closest
                    if (remainder >= 0.5){
                        roundedOutput = (userInput - remainder) + 1;
                    }else{
                        roundedOutput = userInput - remainder;
                    }
                    break;
            }
        }else{ //rounding when the integer is negative
            switch (roundMethod){
                case FLOOR_ROUND: //round down to the nearest whole number
                    roundedOutput = (userInput - remainder ) - 1;
                    break;

                case CEILING_ROUND: //round up to the nearest whole number
                    roundedOutput = userInput - remainder;
                    break;

                case ROUND: //round to the nearest whole number whether that is up or down, based on which is closest
                    if (remainder >= -0.5){
                        roundedOutput = userInput - remainder;
                    }else{
                        roundedOutput = (userInput - remainder) -1;
                    }
                    break;
            }
        }
    }
    
    //output
    std::cout<< roundedOutput << std::endl;

    return 0;
}