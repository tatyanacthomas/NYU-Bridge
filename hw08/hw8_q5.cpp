#include <iostream>


int main(){
    //name vars
    std::string firstName;
    std::string middleName;
    std::string lastName;

    std::cout << "Please enter a name: ";
    std::cin>>firstName>>middleName>>lastName;

    std::cout << lastName << ", " << firstName << " " << middleName[0] << "." << std::endl;

    return 0;
}