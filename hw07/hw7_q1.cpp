#include <iostream>

const int JANUARY = 1;
const int FEBRUARY = 2;
const int MARCH = 3;
const int APRIL = 4;
const int MAY = 5;
const int JUNE = 6;
const int JULY = 7;
const int AUGUST = 8;
const int SEPTEMBER = 9;
const int OCTOBER = 10;
const int NOVEMBER = 11;
const int DECEMBER = 12;

int printMonthCalendar(int numOfDays, int startingDay);
//precondition:   function is called with variable int numOfDays and int startingDay (M-F num val)
//                relative to the month in question
//postcondition:  prints month's calendar view and returns the lastDay of the month (M-F num val)

void printYearCalendar(int year, int startingDay);
//precondition:   int year and int startingDay (M-F num val) is retrieved from user
//postcondition:  prints full year's collection of printMonthCalendars
//                accounting for leap year status if needed

bool isLeapYear(int year);
//precondition:   int year is evaluated
//postcondition:  returns whether the year is a leap year (true) or not (false)

int main(){
    
    int userYear;
    int userStartingDay;
    
    //retrive year and numerical value of starting day from the user, and feed it into the year print function
    std::cout <<  "Enter the year you would like a calendar for: " << std::endl;
    std::cin>> userYear;
    
    std::cout <<  "What day does Jan 1 start on that year? " << std::endl;
    std::cin>> userStartingDay;
    
    printYearCalendar(userYear, userStartingDay);
    
    return 0;
}

int printMonthCalendar(int numOfDays, int startingDay){
    int lastDay;
    int printedDayOfWeekNum;
    
    //day of week header
    std::cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << std::endl;

    //for the months where the prior month ended on the last day of the week, this restarts the week
    if(startingDay > 7){
        startingDay = 1;
    }
    //generates the spaces on the calendar before the first day is printed
    for (int i = 1; i < startingDay; i++){
        std::cout<< "\t";
    }
    
    //assigning startingDay to a temp variable that can be adjusted as needed
    printedDayOfWeekNum = startingDay;
    
    for(int i = 1; i <= numOfDays; i++){
        //if printedDayOfWeekNum has incremented past the 7-day week
        //start a new line and restart the printedDayOfWeek count
        if(printedDayOfWeekNum == 8){
            std::cout << std::endl;
            printedDayOfWeekNum = 1;
        }
        //increment the printedDayOfWeekNum only if we have not reached the end of the month
        if(i < numOfDays){
            printedDayOfWeekNum++;
        }
        
        //prints the day of month onto the calendar
        std::cout << i << "\t";
    }
    
    std::cout << std::endl << std::endl;


    //lastDay is whatever the last recorded printedDayOfWeekNum was
    lastDay = printedDayOfWeekNum;
    
    return lastDay;
}


bool isLeapYear(int year){
    bool leapYear;
    //leap year is each year that is a multiple of 4
    //except for years evenly divisible by 100 but not by 400
    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0){
                leapYear = true; //divisible by 4, 100, and 400
            }else{
                leapYear = false; //divisible by 4 and 100, but not 400
            }
        }else{
            leapYear = true; //divisible by 4 but not 100
        }
    }else{
        leapYear = false; //not divisible by 4
    }
    
    return leapYear;
}

void printYearCalendar(int year, int startingDay){
    int daysInMonth;
    
    for(int i = 1; i <= 12; i++){
        
        if(i % 2 == 0){ //if the month is even,  then the below
            if(i == 2){ //February only
                if(isLeapYear(year)== true){
                    daysInMonth = 29;
                }else{
                    daysInMonth = 28;
                }
            }else if(i < 7){ //all (other) even months Jan - Jul
                daysInMonth = 30;
            }else{ //even months Aug - Dec
                daysInMonth = 31;
            }
        }else{ //if month is  odd, then the below
            if(i <= 7){ //all odd months Jan - Jul
                daysInMonth = 31;
            }else{ // all odd months Aug - Dec
                daysInMonth = 30;
            }
        }
        //provides the month's header
        switch(i){
            case JANUARY:
                std::cout << "January " << year << std::endl;
                break;
            case FEBRUARY:
                std::cout << "February " << year << std::endl;
                break;
            case MARCH:
                std::cout << "March " << year << std::endl;
                break;
            case APRIL:
                std::cout << "April " << year << std::endl;
                break;
            case MAY:
                std::cout << "May " << year << std::endl;
                break;
            case JUNE:
                std::cout << "June " << year << std::endl;
                break;
            case JULY:
                std::cout << "July " << year << std::endl;
                break;
            case AUGUST:
                std::cout << "August " << year << std::endl;
                break;
            case SEPTEMBER:
                std::cout << "September " << year << std::endl;
                break;
            case OCTOBER:
                std::cout << "October " << year << std::endl;
                break;
            case NOVEMBER:
                std::cout << "November " << year << std::endl;
                break;
            case DECEMBER:
                std::cout << "December " << year << std::endl;
                break;
                   
        }
        //calls printMonthCal with:
        //  daysInMonth (calculated above) and
        //  startingDay (fed in from printYearCal call)
        //printMonthCal prints the month and returns a "lastDay" value
        //  "lastDay + 1" is assigned as the new startingDay
        //  instead of the value that was fed in from printYearCal
        startingDay = printMonthCalendar(daysInMonth,startingDay) + 1;
    }
}
