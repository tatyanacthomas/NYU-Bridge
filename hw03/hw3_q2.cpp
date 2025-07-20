#include <iostream>

int main(){

    //variables
    std::string userName;
    int gradYear;
    int currentYear;
    int classNumberValue;
    std::string studentStatus;

    //userInputName
    std::cout<< "Please enter your name: \n";
    std::cin>> userName;

    //userInputGradYear
    std::cout<< "Please enter your graduation year: \n";
    std::cin>> gradYear;

    //userInputCurrentYear
    std::cout<< "Please enter current year: \n";
    std::cin>> currentYear;

    //Calculate studentStatus
    if((gradYear - currentYear)> 0){ //student has not graduated yet
        classNumberValue = gradYear - currentYear;

        switch(classNumberValue){
            case 1: //1 year left
                studentStatus = "a Senior";
                break;
            case 2: //2 years left
                studentStatus = "a Junior";
                break;
            case 3:  //3 years left
                studentStatus = "a Sophomore";
                break;
            case 4: //4 years left
                studentStatus = "a Freshman";
                break;
            default: 
                studentStatus = "Not in college yet";
                break;
        }

    }else{ //student has graduated    //((gradYear - currentYear < 0))
            studentStatus = "Graduated";
    }

    //Output
    std::cout << userName << ", you are " << studentStatus << std::endl;

    return 0;

}