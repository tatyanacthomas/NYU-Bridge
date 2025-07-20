#include <iostream>

int main() {
    
    //user input variable (used for both sections)
    int n;
    
    //looping variable (used for both sections)
    int i;
    
    //retrieve user input
    std::cout << "Please enter a positive integer: " << std::endl;
    std::cin>> n;
   
    //while loop
    std::cout << "section a: " << std::endl;
    
    i = 1;
    while(i <= n){
        std::cout << i * 2 << std::endl;;
        i++;
    }
     
    std::cout << std::endl;

     //for loop
    std::cout << "section b: " << std::endl;
    
    for(i = 1; i <= n; i++){
         std::cout << i * 2 << std::endl;;
     }
     
    
    return 0;
}
       
    

