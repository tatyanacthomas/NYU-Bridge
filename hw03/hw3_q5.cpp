#include <iostream>

const float KILOS_PER_LB = 0.453592;
const float METERS_PER_IN = 0.0254;

int main(){

    //variables
    int lbs;
    float kilos;
    int inches;
    float meters;
    float bmiVal;
    std::string weightStatus;

    //receive input
    std::cout<< "Please enter weight (in pounds): \n";
    std::cin>> lbs;

    std::cout<< "Please enter height (in inches): \n";
    std::cin>>inches;

    //lbs to kilos
    kilos = lbs * KILOS_PER_LB;

    //inches to meters
    meters = inches * METERS_PER_IN;

    //BMI calculation
    bmiVal = kilos/(meters*meters);

    //Weight status branching
    if(bmiVal < 18.5){
        weightStatus = "Underweight";
    }else if(bmiVal >= 18.5 && bmiVal < 25){
        weightStatus = "Normal";
    }else if(bmiVal >= 25 && bmiVal < 30){
        weightStatus = "Overweight";
    }else{ //BMI 30+
        weightStatus = "Obese";
    }

    //output weight status
    std::cout<< "The weight status is: " << weightStatus << std::endl;

    return 0;
}