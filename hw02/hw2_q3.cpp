#include <iostream>

//provides a const value to reduce having hard-coded values in formulas in the code
const int DAYS_TO_MINS = 1440;
const int HOURS_TO_MINS = 60;

int main(){
    int jDays;
    int jHours;
    int jMinutes;

    int bDays;
    int bHours;
    int bMinutes;

    int totalMinuteValue;

    int totalDays;
    int totalHours;
    int totalMinutes;

    //all of the following 3 cout/cin statements are to gather the inputs for John's working time
    std::cout<< "Please enter the number of days John has worked: \n";
    std::cin>> jDays;

    std::cout<< "Please enter the number of hours John has worked: \n";
    std::cin>> jHours;

    std::cout<< "Please enter the number of minutes John has worked: \n";
    std::cin>> jMinutes;

    //all of the following 3 cout/cin statements are to gather the inputs for Bill's working time
    std::cout<< "Please enter the number of days Bill has worked: \n";
    std::cin>> bDays;

    std::cout<< "Please enter the number of hours Bill has worked: \n";
    std::cin>> bHours;

    std::cout<< "Please enter the number of minutes Bill has worked: \n";
    std::cin>> bMinutes;

    //Calculates the total nubmer of minutes across the days, hours, and minutes across both Bill and John
    totalMinuteValue = ((jDays+bDays) * DAYS_TO_MINS + (jHours + bHours) * HOURS_TO_MINS + (jMinutes + bMinutes));

    //Divides out to identify the total number of days worked, and then subtracts it from the total minutes to establish the remainder number of minutes left to work
    totalDays = totalMinuteValue / DAYS_TO_MINS;
    totalMinuteValue = totalMinuteValue - (totalDays * DAYS_TO_MINS);

    //Divides out to identify the total number of hours worked that is remaining, and then subtracts it from the total minutes to establish the remainder number of minutes left to work
    totalHours = totalMinuteValue / HOURS_TO_MINS;
    totalMinuteValue =  totalMinuteValue - (totalHours * HOURS_TO_MINS);

    //assigns the number of minutes remaining to the final number of minutes 
    totalMinutes = totalMinuteValue;


    //outputs the final response
    std::cout << "The total time both of them worked together is: " <<totalDays<< " days, " <<totalHours<< " hours, and " <<totalMinutes<< " minutes. \n";
    
    return 0;

}