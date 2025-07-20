#include <iostream>

const float WEEKDAY_RATE = 0.40;
const float WEEKNIGHT_RATE = 0.25;
const float WEEKEND_RATE = 0.15;

int main(){
    //time variables
    int hr24;
    int min24;
    char colon;

    //other call input variables 
    std::string day;
    int callMinutes;

    //calculating cost variables
    float totalPrice;

    //Gather user input
    std::cout << "What day did you make the call? Please enter the day in 2-character notation: Mo, Tu, We, Th, Fr, Sa, Su \n";
    std::cin>> day;

    std::cout << "What time did the call start? Please use 24-hour notation. (Ex: 19:45) \n";
    std::cin>>hr24>>colon>>min24;

    std::cout <<"How many minutes long was the call? \n";
    std::cin>> callMinutes;

    //Calculate total if weekend
    if(day == "Sa" || day == "Su"){                         //Is Weekend
        totalPrice = callMinutes * WEEKEND_RATE;

    //calculate total if weekday (day and night rates)
    }else{                                                  //Is Weekday
        if (hr24 >= 8 && hr24 <= 18){                       //Weekday rate (call started between 8am - 6pm)
            totalPrice = callMinutes * WEEKDAY_RATE;


        }else{                                              //Weeknight rate (call started between 6:01 pm and 7:59 am)
            totalPrice = callMinutes * WEEKNIGHT_RATE;

        }
    }

    //Output
    std::cout<< "The cost of the call is $" << totalPrice << " USD." << std::endl;

    return 0;
}