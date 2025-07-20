#include <iostream>

void printTriangle(int n);
//prints triangle size of n recursively 

void printOppositeTriangles(int n);
//recursively prints upside down triangle followed by rightside up triangle, both size n

void printRuler(int n);
//prints a "ruler" with alternating dash lines

int main(){
    int size;

    std::cout << "Please enter a size: ";
    std::cin >> size;

    std::cout << "PART A: PRINT TRIANGLE" << std::endl;
    printTriangle(size);


    std::cout << "PART B: PRINT OPPOSITE TRIANGLES" << std::endl;
    printOppositeTriangles(size);


    std::cout << "PART C: PRINT RULER" << std::endl;
    printRuler(size);
  
    return 0;
}

void printTriangle(int n){
    if(n == 1){
        std::cout << "*" << std::endl;
    }else{
        printTriangle(n-1);
        for(int i = 0; i < n; i++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void printOppositeTriangles(int n){
    if(n == 0){
        //do nothing
    }else{
        for(int i = 0; i < n; i++){
            std::cout << "*";
        }
        std::cout << std::endl;
        printOppositeTriangles(n-1);
        for(int i = 0; i < n; i++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void printRuler(int n){
    if(n == 1){
        std::cout << "-" << std::endl;
    }else{
        printRuler(n-1);
        for(int i = 0; i < n; i++){
            std::cout << "-";
        }
        std::cout << std::endl;
        printRuler(n-1);
    }
}