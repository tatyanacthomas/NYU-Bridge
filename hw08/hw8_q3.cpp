#include <iostream>

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main() {

    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;

}

void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++) {
        std::cout<<arr[i]<<' ';
    }
    std::cout<<std::endl;
}

void reverseArray(int arr[], int arrSize){
    int i = 0;
    int j = arrSize - 1;
    int tempI;
    int tempJ;

    //increments and decrements i and j until they converge at the center, swapping the value of i and j
    //therefore runs theta(n/2) as it only runs for 1/2 the size of n
    while(i < j){
        tempI = arr[i];
        tempJ = arr[j];
        arr[i] = tempJ;
        arr[j] = tempI;
        i++;
        j--;
    }
}
void removeOdd(int arr[], int& arrSize){
    int evenCount = 0;
    
    //if its even, overwrites what is in the 0th, 1st, 2nd etc, positions of the array with the even number
    //keeps track of how many even numbers there are
    for(int i = 0; i < arrSize; i++){
        if (arr[i] % 2 == 0){
            arr[evenCount] = arr[i];
            evenCount++;
        }
    } 
 
    //uses even number count to replace the trailing (odd) numbers with NULL value   
    for(int i = arrSize - evenCount; i > 0; i--){
        arr[arrSize -  i] = (int)NULL;
    }
    //debugging output
    //for(int i = 0; i < arrSize; i++){
    //    std::cout <<arr[i] << " ";
    //}
    // std::cout << std::endl;
    
    //defined a new arrSize which will be used in the printArray function that is called next
    arrSize = evenCount;
}


void splitParity(int arr[], int arrSize){
    int i = 0;
    int j = arrSize - 1;
    int tempI;
    int tempJ;
    
    while(i < j){
        //i < j ensures the inner loop does not run after i and j converge
        while(i < j && arr[i] % 2 != 0){
            i++;
        }
        while(i < j && arr[j] % 2 == 0){
            j--;
        }
        //will only swap if i and j have not converged yet
        if(i < j){
            tempI = arr[i];
            tempJ = arr[j];
            arr[i] = tempJ;
            arr[j] = tempI;
        }
    }
}
