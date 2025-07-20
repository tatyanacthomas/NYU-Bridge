#include <iostream>


int main(){

    int n; //user input (which will also be the number of iterations for the outer FOR loops)
    int lineLength; //determines how many iterations are needed for each line
    int asteriskQuantity; //how many asterisks need to be printed on each line
    int spaceQuantity; //how many spaces need to be printed on each line
    
    // retrieves user input
    std::cout<< "Enter a positive number: " << std::endl;
    std::cin>> n;
    
    //initializes the variables for the loops
    lineLength = (2 * n) - 1;
    asteriskQuantity = lineLength;
    spaceQuantity = 0;
    
    //top half iteration count is equal to the original input value. 
    for(int i = n; i > 0; i--){
        //SpaceQuantity starts at 0 but after being incremented outside this loop, the number of space printing loops will increase for each line
        for (int k = spaceQuantity; k > 0  ; k--){
            std::cout << " ";
        }
        //asteriskQuantity starts equal to the longest linelength but after being decremented outside this loop, the number of asterisk printing loops will decrease for each line
        for (int j = asteriskQuantity; j > 0 ; j--){
            std::cout << "*";
        }

        std::cout << std::endl;
        //only decrements the asteriskQuantity by -2 if we are in the second to last or earlier loops. Otherwise it the asteriskQuantity would go negative and and not be helpful in the bottom half. Since the asteriskQuantity is not being decremented in the last loop, then the spaceQuantity should not be incremented in the last loop either.
        if(i >= 2){
            asteriskQuantity = asteriskQuantity - 2;
            spaceQuantity++;
        }
    }
        
    
    //bottom half
    
    for(int i = n; i > 0; i--){
        //SpaceQuantity starts at the last value that was recorded for it from the top half but after being decremented outside this loop, the number of space printing loops will decrease for each line
        for (int k = 0; k < spaceQuantity  ; k++){
            std::cout << " ";
        }
        //asteriskQuantity starts equal to the last value that was recorded for it from the top half but after being incremented outside this loop, the number of asterisk printing loops will increase for each line
        for (int j = 0; j < asteriskQuantity ; j++){
            std::cout << "*";
        }


        std::cout << std::endl;
        asteriskQuantity = asteriskQuantity + 2;
        spaceQuantity--;
    }
    
    
    return 0;
}

