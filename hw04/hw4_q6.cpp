#include <iostream>

int main() {
    //variable for original input
    int userInput;
    
    //variables to determine number of digits per number
    int digitCheckTemp;     //decremental total of the number being checked as we move through the digits
    int digitCount;
    
    //variables to determine if a number is even or odd
    int evenOddCheckTemp;   //decremental total of the number being checked as we move through the digits
    int digitVal;           //value of the individual digit
    int evenCount;
    int oddCount;
    
    //collect user input
    std::cout <<  "Enter a number: " << std::endl;
    std::cin>> userInput;
    
    //the loop that will go from 1 to userInput, evaluating each number for the number of even/odd digits in each
    for(int i = 1 ; i <= userInput ; i++){
        
        //Determining how many digits are in a number
        digitCheckTemp = i;
        digitCount = 1;
        while(digitCheckTemp > 0){
            digitCheckTemp = digitCheckTemp/10;
            if( digitCheckTemp == 0){
                continue;
            }
            digitCount++;
            }
        
        //initializing the even/odd counts for evaluating each number in the range from 1 to userInput
        evenCount = 0;
        oddCount = 0;
        
        //looping each digit of a number i (labelled temporarily for this loop as evenOddCheckTemp)
        //and incrementing even/odd counts if the digit is even or odd
        evenOddCheckTemp = i;
        
        for(int j = 1; j <= digitCount ; j++){
            digitVal = evenOddCheckTemp % 10;
            evenOddCheckTemp = (evenOddCheckTemp - digitVal)/10;

            if (digitVal % 2 == 0){
                evenCount++;
            }else{
                oddCount++;
            }

        }
        
        //After evaluating the even/odd count for  number i, only printing the i value that contains more even digits than odd digits
        if (evenCount > oddCount) {
            std::cout << i << std::endl;
        }
    }
    
    return 0;
}
