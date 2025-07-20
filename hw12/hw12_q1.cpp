#include <iostream>
#include <cstdlib>
#include <cctype>

//---------------------------------------------------------------------------------------------
//MONEY CLASS DECLARATION
class Money{
public:
    friend std::istream& operator >>(std::istream& ins, Money& amount);
    friend std::ostream& operator <<(std::ostream& outs, const Money& amount);
    friend Money operator+ (const Money& amount1, const Money& amount2);
    friend Money operator- (const Money& amount1, const Money& amount2);
    friend Money operator- (const Money& amount);
    friend bool operator== (const Money& amount1, const Money& amount2);
    friend bool operator< (const Money& amount1, const Money& amount2);
    friend bool operator> (const Money& amount1, const Money& amount2);
    friend Money operator/(const Money& amount1, const Money& amount2);
    Money(long dollars, int cents);
    Money(long dollars);
    Money( );
    double get_value( ) const;
private:
    long all_cents;
};

//---------------------------------------------------------------------------------------------
//CHECK CLASS DECLARATION
class Check{
    public:
        Check(); 
        //default constructor
  
        //setters
        void setCheckAmount(Money amount){checkAmount = amount.get_value() * 100;}
        void setCashedVal(bool cashed){checkCashed = cashed;}
        void setCheckNumber(int checkNo){checkNumber = checkNo;}

        //getters
        Money getCheckAmount() const {return checkAmount;}
        bool getCashedVal() const {return checkCashed;}
        int getCheckNumber() const{return checkNumber;}

        //other check functions
        bool convertCashedVal(char cashed);   
        //allows user to enter Y/N or y/n for cashed value

        std::string generateCheckNumber(int checkNo);    
        //auto-generates checkNumber into a 4-digit number with leading zeros
        //sets any deposits to have a check number 'DEPOSIT'
        
        Money getBankBalance(Money bankBalance, Check check) {return bankBalance + check.checkAmount/1;}
        //calculates the bank balance (balance of only the cashed checks and/or deposits)

        Money getActualBalance(Money actualBalance, Check check) {return actualBalance + check.checkAmount/1;}
        //calculates the actual balance (bank balance minus the uncashed checks)

    private:
        Money checkAmount;
        bool checkCashed;
        int checkNumber; 

};

//---------------------------------------------------------------------------------------------
//MAIN FUNCTION DECLARATIONS

void sortByCheckNumber(Check arr[], int arrSize);
//sorts the array that stores the checks from smallest to largest by check number

void printBankBalance(Check depositArr[], int depositSize, Check checkArr[], int checkSize,  Money& bankBalance);
//prints all the cashed checks and the balance according to the bank (since a bank only accounts for cashed values)

void printActualBalance(Check arr[], int arrSize, Money& actualBalance);
//prints all the uncashed checks and the real balance once all checks are cashed

void printBalanceDifferences(Money actualBalance, Money bankBalance);
//prints a summary of the differences between the actual and the bank balance


//---------------------------------------------------------------------------------------------
//MAIN

int main(){
    
    int depositsSize;
    int checksSize;

    Money currentBalance;
    std::cout << "Hello and welcome! Let's begin. " << std::endl;
    std::cout << "Please enter your current bank balance: " << std::endl;
    std::cin >> currentBalance; 

    Money bankBalance = currentBalance;
    Money actualBalance = 0;

    std::cout << std::endl;
    std::cout << "Let's start with deposits! We will be entering " << std::endl;
    std::cout << "all of the deposits that have been made since you " << std::endl;
    std::cout << "last balanced your checkbook. " << std::endl;

    std::cout << "To begin, how many deposits did you make?" << std::endl;
    std::cout << "Enter here: ";
    std::cin>> depositsSize;

    Check * deposit = new Check [depositsSize];

    std::cout << "Please enter the amount of each deposit, " <<std::endl;
    std::cout << "written in $X.XX format." << std::endl;

    int depositCount = 0;
    while(depositCount < depositsSize){
        Money depositAmount;
        std::cout << "Deposit #" << (depositCount + 1) << ": ";
        std::cin >> depositAmount;
        deposit[depositCount].setCheckAmount(depositAmount);
        deposit[depositCount].setCashedVal(true); //all deposits are automatically cashed
        //no check number needed, will remain 0 as per the default constructor

        //adds each deposit amount to the original bank balance
        bankBalance = deposit[depositCount].getBankBalance(bankBalance, deposit[depositCount]);
        depositCount++;
    }

    std::cout << std::endl;
    std::cout << "Great, let's move on to checks!" <<std::endl;
    std::cout << "How many checks would you like to submit? " << std::endl;
    std::cout << "Enter here: ";
    std::cin>> checksSize;

    Check * check = new  Check [checksSize];

    std::cout << "Please enter the transaction information." << std::endl;
    std::cout << "We will need each of the following:" << std::endl;
    std::cout << "\t 1. The transaction amount written in $X.XX format" << std::endl;
    std::cout << "\t 2. If the withdrawal checks have been cashed yet[Y/N]" << std::endl;
    std::cout << "\t 3. The check number. This is the 4-digit number " << std::endl;
    std::cout << "\t    on the check. Leading zeros are optional." << std::endl;
   
    int checkCount = 0;

     while(checkCount < checksSize){
        Money inputCheckAmount;
        char inputCheckCashed;
        int inputCheckNumber;
        std::cout << "Check #" << (checkCount + 1) << ": ";
        std::cout << std::endl << "\t";
        std::cout << "Amount: -";
        std::cin>>inputCheckAmount;
        std::cout << "\tCashed or Not [Y/N]: ";
        std::cin>>inputCheckCashed;
        std::cout << "\tCheck Number: ";
        std::cin>>inputCheckNumber;
        check[checkCount].setCheckAmount(-inputCheckAmount);

        //converts cashedVal from Y/N to 0/1 and then assigns said value to checkCashed
        check[checkCount].setCashedVal(check[checkCount].convertCashedVal(inputCheckCashed)); 

        check[checkCount].setCheckNumber(inputCheckNumber);
        
        if(check[checkCount].getCashedVal() == true){
            bankBalance = check[checkCount].getBankBalance(bankBalance, check[checkCount]);
            
        }else{
            //here the "actual balance" is just the total of uncashed checks
            //the real actual balance will be calculated after the loop is done
            actualBalance = check[checkCount].getActualBalance(actualBalance, check[checkCount]);
        }
        checkCount++;
    }

    actualBalance = bankBalance + actualBalance;
    std::cout << std::endl;

    //sort the checks array first before printing out all the results
    sortByCheckNumber(check, checkCount);

    std::cout << " ==============================" << std::endl;
    std::cout << "Thanks for entering your transaction details. " << std::endl;
    std::cout << "Here is a summary of your transaction and account details: " << std::endl;
    printBankBalance(deposit, depositCount, check, checkCount, bankBalance);
    printActualBalance(check, checkCount, actualBalance);

    printBalanceDifferences(actualBalance, bankBalance);

    delete[] deposit;
    deposit = NULL;

    delete [] check;
    check = NULL;

    return 0;
}


//---------------------------------------------------------------------------------------------
//MONEY CLASS MEMBER FUNCTION DEFINITIONS

int digit_to_int(char c);

std::istream& operator >>(std::istream& ins, Money& amount){
    char one_char;
    char decimal_point;
    char digit1; //digit for first digit in cents
    char digit2; //digits for second digit in cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.

    ins >> one_char;
    if (one_char == '-'){
        negative = true;
        ins >> one_char; //read '$'
    }else{
        negative = false;
        //if input is legal, then one_char == '$'
    }
    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)){
        std::cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1)*10 + digit_to_int(digit2);

    amount.all_cents = dollars*100 + cents;
    if (negative){
        amount.all_cents = -amount.all_cents;
    }


    return ins; 
}

std::ostream& operator <<(std::ostream& outs, const Money& amount){
    long positive_cents;
    long dollars;
    long cents;

    positive_cents = labs(amount.all_cents);
    dollars = positive_cents/100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0){
        outs << "-$" << dollars << '.';
    }else{
        outs << "$" << dollars << '.';
    }

    if (cents < 10){
        outs << '0';
    }

    outs << cents;

    return outs;
}

Money operator+ (const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

Money operator/(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents / amount2.all_cents;
    return temp;
}

Money operator- (const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator- (const Money& amount){
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

bool operator== (const Money& amount1, const Money& amount2){
    return (amount1.all_cents == amount2.all_cents);
}

bool operator< (const Money& amount1, const Money& amount2){
    return (amount1.all_cents < amount2.all_cents);
}

bool operator> (const Money& amount1, const Money& amount2){
    return (amount1.all_cents < amount2.all_cents);
}

Money::Money(long dollars, int cents){
    if(dollars*cents < 0){ //If one is negative and one is positive
        std::cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars*100 + cents;
}

Money::Money(long dollars) : all_cents(dollars*100){
    //Body intentionally blank.
}

Money::Money() : all_cents(0){
    //Body intentionally blank.
}

double Money::get_value() const{
    return (all_cents * 0.01);
}

int digit_to_int(char c){
    return (static_cast<int>(c) - static_cast<int>('0') );
}

//---------------------------------------------------------------------------------------------
//CHECK CLASS MEMBER FUNCTION DEFINITIONS

Check::Check(): checkAmount(0), checkCashed(false), checkNumber(0){
    //Body intentionally left blank
    //constructor sets all to 0
}

bool Check::convertCashedVal(char cashed){
    if(cashed == 'Y' || cashed == 'y'){
        return true;
    }else if(cashed == 'N' || cashed == 'n'){
        return false;
    }else{
        std::cout << "Invalid cashed check value. Aborting program." << std::endl;
        exit(1);
    }
}

std::string Check::generateCheckNumber(int checkNo){
    int checkNumberDigitCount = 4; //4 digits is standard 

    if(checkAmount < 0){ //check type is withdrawal

        //casting int checkNo to string
        std::string checkNumberStr = std::to_string(checkNo);

        //counting number of leading zeros needed and adding them to the front
        int leadingZeroCount = checkNumberDigitCount - checkNumberStr.length();

        for(int i = 0; i < leadingZeroCount; i++){
            checkNumberStr = "0" + checkNumberStr;
        }

        return checkNumberStr;

    }else{ //check type is deposit
        return "DEPOSIT"; 
    }
}

//---------------------------------------------------------------------------------------------
//MAIN FUNCTION DEFINITIONS


void sortByCheckNumber(Check arr[], int arrSize){
    //selection sort
    int minIndex = 0;

    for (int i = 0; i < arrSize; i++) {
        minIndex = i;
        //looking at all values in the array directly to the right of the value we have declared as being the minimum for this iteration
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[j].getCheckNumber() < arr[minIndex].getCheckNumber())
                minIndex = j;
        }
        //if we in fact found a value at position minIndex that is smaller than the value in arr[i], then we swap the value in arr[i] with the value in arr[minIndex]
       if (minIndex != i) {
            Check temp1= arr[i];
            Check temp2 = arr[minIndex];
            arr[minIndex] = temp1;
            arr[i] = temp2;
        }
    }
}

void printBankBalance(Check depositArr[], int depositSize, Check checkArr[], int checkSize,  Money& bankBalance){
    Money totalDeposits = 0;
    Money totalCashedChecks = 0;

    //counting how many checks were cashed
    int cashedCheckCount = 0;
    for(int i = 0; i < checkSize; i++){
        if(checkArr[i].getCashedVal()){
            cashedCheckCount++;
        }
    }

    std::cout << std::endl;
    if(cashedCheckCount + depositSize > 0){
        std::cout << "You have made " << depositSize << " deposits and " << std::endl;
        std::cout << "you have cashed " << cashedCheckCount << " checks." << std::endl;
        std::cout << "Here is the information regarding these cleared transactions" << std::endl;
        std::cout << "and your resulting balance: " << std::endl;
            if(depositSize > 0){ 
                for(int i = 0; i < depositSize; i++){
                    int depositNo = i + 1;
                    std::cout << "Deposit #" << depositNo << ": " << depositArr[i].getCheckAmount()/1<< " \tDeposited \t";
                    std::cout << " \tTransaction Type " << depositArr[i].generateCheckNumber(depositArr[i].getCheckNumber());
                    std::cout << std::endl;
                    totalDeposits = totalDeposits + depositArr[i].getCheckAmount()/1;

                    } 
            }
            if(checkSize > 0){
                for(int i = 0; i < checkSize; i++){
                    int checkNo = i + 1;
                    if(checkArr[i].getCashedVal()){
                        std::cout << "Check #" << checkNo << ": " << checkArr[i].getCheckAmount()/1<< " \tCashed \t";
                        std::cout << " \t\tCheck No. " << checkArr[i].generateCheckNumber(checkArr[i].getCheckNumber());
                        std::cout << std::endl;
                        totalCashedChecks = totalCashedChecks - checkArr[i].getCheckAmount()/1;
                    } 
                }
            }
        std::cout << std::endl;
        std::cout << "The total amount of deposits is " << totalDeposits << std::endl;  
        std::cout << "The total amount of cashed checks is -" << totalCashedChecks << std::endl;        
        std::cout << std::endl;
        std::cout << "Your final balance according to the bank: " << bankBalance << std::endl;

    }else{
        std::cout << "No cleared checks available to show! " << std::endl;
        std::cout << "All checks are still in pending status!" << std::endl;
        std::cout << "Your current balance according to the bank is " << bankBalance << std::endl;
    }
}

void printActualBalance(Check arr[], int arrSize, Money& actualBalance){
    //counting uncashed checks
    int unCashedCheckCount = 0;
    for(int i = 0; i < arrSize; i++){
        if(arr[i].getCashedVal() == false){ //if getCashedVal is true
            unCashedCheckCount++;
        }
    }
    std::cout << std::endl;
    if(unCashedCheckCount > 0){ 
        std::cout << "You have " << unCashedCheckCount << " checks left to clear." << std::endl;
        std::cout << "Here is a summary of the check details, " << std::endl;std::cout << "and the resulting total once they clear: " << std::endl;;
        for(int i = 0; i < arrSize; i++){
            int checkNo = i+ 1;
            if(arr[i].getCashedVal() == false){
                std::cout << "Check #" << checkNo << ": " << arr[i].getCheckAmount()/1<< " \tNot Cashed \t";
                std::cout << " \tCheck No. " << arr[i].generateCheckNumber(arr[i].getCheckNumber());
                std::cout << std::endl;
            } 
        }
        std::cout << std::endl;
        std::cout << "Final balance once you cash all checks: " << actualBalance << std::endl;

    }else{ 
        std::cout << "No uncleared transactions available to show! "<< std::endl;
        std::cout << "All transactions have cleared!" << std::endl;
        std::cout << "Your true account balance is " << actualBalance << std::endl;
    }
}

void printBalanceDifferences(Money actualBalance, Money bankBalance){ 
    std::cout << std::endl;
    if(bankBalance.get_value() > actualBalance.get_value()){
        std::cout << "Please note, you don't have as much money " << std::endl;
        std::cout << "in your account as you think! You will have " << std::endl; 
        std::cout << bankBalance - actualBalance << " less dollars in your account "<< std::endl;
        std::cout << "once all transactions clear." << std::endl;
    }else{ //if bankBalance == actualBalance
        if(bankBalance < 0){
            std::cout << "Congratulations on reconciling your accounts." << std::endl;
            std::cout << "The bank's balance matches your actual balance: " << bankBalance <<std::endl;
            std::cout << "But I regret to inform you that you" << std::endl;
            std::cout << "are in the red!. Please deposit more money soon!";
        }else{ 
           std::cout << "The bank's balance matches your actual balance: " << std::endl;
            std::cout << actualBalance << "!" << std::endl;
            std::cout << "Congratulations on reconciling your accounts!" << std::endl;
        }
    }
    //there is no instance where the actualBalance would be greater than the bankBalance because all deposits cash right away, therefore there are no uncashed deposits (positive values)
}