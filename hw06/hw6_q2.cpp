#include <iostream>

void printShiftedTriangle(int n, int m, char symbol);
//precondition: int n (height), int m (space away from margin, char symbol are provided
//   either by the user or by the programmer
//postcondition: triangle printed n rows tall, and n+2 wide, m spaces from the margin, composed of provided char symbol

void printPineTree(int n, char symbol);
//precondition: int n and char symbol are retrieved from the user
//postcondition: prints a pine tree shape by calling printShiftedTriangle n times
//   creating increasingly larger triangles with the largest triangle being a height of n+1;

int main(){
    
    int treeSize;
    char symbolType;
    
    //retrieve input to print the pine tree, both variables will be fed into the printPineTree function as arguments
    std::cout<< "Please enter the size of the tree: " <<std::endl;
    std::cin>> treeSize;
        
    std::cout<< "Please enter the symbol type: " << std::endl;
    std::cin>> symbolType;
    
    printPineTree(treeSize, symbolType);
    
    return 0;
}

void printShiftedTriangle(int n, int m, char symbol){
    //variables to guide incrementation required to create a triangle shape
    int spaceCount;
    int symbolCount;
    
    //triangle is composed of the space, declared below, and the char symbol, which is applied to this function from an
    //argument that was passed into it
    char space;
    space = ' ';
    
    //initialize the space and symbol counts to align with the tip of the triangle
    spaceCount = n - 1;
    symbolCount = 1;
    
    //i refers to rows tall, j refers to characters across
    for(int i = 1; i <= n; i++){
        
        //prints the marginal spaces
        for(int j = 1; j<= m; j++){
            std::cout<< space;
        }
        //prints the spaces that surround the triangle
        for(int k = 1; k<= spaceCount; k++){
            std::cout << space;
        }
        //prints the triangle using char symbol
        for (int l =1; l <= symbolCount; l++){
            std::cout << symbol;
        }
        
        //increment/decrement to generate the triangle shape
        spaceCount--;
        symbolCount = symbolCount + 2;
        std::cout << std::endl;
    }
}

void printPineTree(int n, char symbol){
    int m;
    int h;
    
    //m is programmer declared spaces from the margin to create the pine tree shape where
    //  smaller triangles are further from the margin. Will be decremented as triangles increase.
    m = n-1;
    
    //h is programmer declared height of the first triangle. Will be incremented as triangles increase.
    h = 2;
    
    //i refers to number of triangles to print
    for (int i = 1; i <= n; i++){
        printShiftedTriangle(h, m, symbol);
        m--;
        h++;
    }
}


