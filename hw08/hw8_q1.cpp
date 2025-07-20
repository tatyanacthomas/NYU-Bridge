#include <iostream>
const int ARR_SIZE = 20;

int minInArray(int arr[], int arrSize);
//precondition:  receives an array and related array size
//postcondition: reviews all items in the array to identify which item is the smallest
//               returns the minVal as int

void findMinValInArr(int arr[], int min);
//precondition:  enters the same user defined array, and inputs the previously identified minVal
//postcondition: to print out all index numbers that equal the minVal

int main(){

    int userInput;
    int userArr[ARR_SIZE];
    int minVal = 0;

    std::cout << "Please enter 20 integers separated by a space: " << std::endl;

    int i = 0;
    while(i < ARR_SIZE){
        std::cin>>userInput;
        userArr[i] = userInput;
        i++;
    }

    minVal = minInArray(userArr, ARR_SIZE);

    std::cout << "The minimum value is " << minVal << " and it is located in the following indices: ";

    findMinValInArr(userArr, minVal);

    std::cout << std::endl;


    return 0;
}

int minInArray(int arr[], int arrSize){
    int minVal;
    minVal = arr[0];
    //minVal has been assigned as the first item in the array and will repeatedly be updated 
    //to any value that is less than the previously identified minVal
    for(int i  = 0; i < arrSize; i++){
        if(minVal >= arr[i]){
            minVal = arr[i];
        }
    }

    return minVal;

}

void findMinValInArr(int arr[], int min){
    
    //prints the index of any item that is the same as the minVal
    for(int i = 0; i <= ARR_SIZE; i++){
        if(arr[i]== min){
            std::cout << i << " ";
        }
    }
}
