#include <iostream>
#include <cstdlib> //used to generate random numbers

//declared as string so that it can accept passwords that start with number 0
const std::string PASSWORD = "12345";

void generateUX(int arrRandNums[], int arrSize);
//creates the "user interface" for the user

std::string retrieveUserInput();
//collects the user input (a 123-user-input number)


std::string generatePasswordHash(int arrRandNums [], int arrSize);
//determines the 123 value that is equal to the password

bool authenticateUserInput(std::string input, int arrRandNums [], int arrSize);
//checks to see if the 123-password-hash matches the 123-user-input


int main(){
    int arr[10];
    int arrSize = 0;

    generateUX(arr, arrSize);

    if(authenticateUserInput(retrieveUserInput(), arr, arrSize) == true){
        std::cout << "Your pin is correct" << std::endl;
    }else{
        std::cout << "Your pin is not correct" << std::endl;
    }

    return 0;
}
void generateUX(int arrRandNums[], int arrSize){
    srand((int)time(0));

    std::cout << "Please enter your PIN according to the following mapping: " << std::endl;
    std::cout << "PIN: \t";

    for(int i = 0; i < 10; i++){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "NUM: \t";
    for(int i = 0; i < 10; i++){
        arrRandNums[i] = (rand() % 3 + 1);
    }
    for(int i = 0; i< 10; i++){
        std::cout << arrRandNums[i] << " ";
    }
    std::cout << std::endl;

}

std::string retrieveUserInput(){
    std::string userInput;
    std::cin>> userInput;

    return userInput;
}

std::string generatePasswordHash(int arrRandNums [], int arrSize){
    //declaring a tempVar so that the password does not get altered
    //index_match helps match the value in password to the value in arrRandNums
    std::string tempPASSWORD = PASSWORD;
    int index_match = 0;

    //will be output:
    std::string passwordHash = "";
    
     for(int i = 0; i <= PASSWORD.length() - 1;i++ ){
        //assigning index_match to the password's ith value, subtracting from char 0 to effectively cast from char to int
        index_match = PASSWORD[i] - '0';
        //concatenating values from each iteration to create final passwordHash     
        //since arrRandNums values were created via random number generator, needed to cast to string in order to concatenate 
        passwordHash += std::to_string(arrRandNums[index_match]);
     }

    //debugging output
    //std::cout<< "Password hash: " << passwordHash << std::endl;

    return passwordHash;
}

bool authenticateUserInput(std::string input, int arrRandNums [], int arrSize){
    bool authenticated = false;
    std::string passwordHash;

    //takes the numerical hash value that was generated in generatePasswordHash and compares to user's input
    passwordHash = generatePasswordHash(arrRandNums, arrSize);

    if(passwordHash == input){
        authenticated = true;
    }else{
        authenticated = false;
    }

    return authenticated;
}
