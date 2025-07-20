#include <iostream>

bool isPalindrome(std::string str);
//precondition: receives a string
//postcondition: the string is evaluated against a reversed version of the string to determine if it is a palindrome

int main(){
    std::string userInput;

    std::cout << "Please enter a word in all lowercase: ";
    
    //opted for getline so that I could evaluate a whole palindrome sentence too
    std::getline(std::cin, userInput);
    if(isPalindrome(userInput) == true){
        std::cout << userInput << " is a palindrome" << std::endl;
    }else{
        std::cout << userInput << " is not a palindrome" << std::endl;
    }

    return 0;
}

bool isPalindrome(std::string str){
    bool palindrome;
    std::string strReverse;

    for(int i = str.length()-1 ; i >= 0; i--){
        strReverse = strReverse + str[i];
    }
    //debugging output
    //std::cout << strReverse << std::endl;

    if (str == strReverse){
        palindrome = true;
    }else{
        palindrome = false;
    }

    return palindrome;
}
