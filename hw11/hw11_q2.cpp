#include <iostream>

int sumOfSquares(int arr[], int arrSize);
//adds up the squares of all elements in an array, positive or negative 

bool isSorted(int arr[], int arrSize);
//returns true if an array is sorted smallest to largest
//returns false if not 

int main(){
    std::cout << "SUM OF SQUARES" <<std::endl;
    int sumArr[6] = {-1,0, 1, 2, 3, 4};
    //expecting 1 + 0 + 1 + 4 + 9 + 16 == 31
    int sumArrSize = 6;
    std::cout << "sumOfSquares= " << sumOfSquares(sumArr, sumArrSize) << std::endl;

    std::cout << std::endl;

    std::cout << "IS SORTED" <<std::endl;
    int sortArr[6] = {0, 0 , 0, 1, 0, 0};
    int sortArrSize = 6;
    if(isSorted(sortArr, sortArrSize) == true){
        std::cout << "isSorted is TRUE" << std::endl;
    }else{
        std::cout << "isSorted is FALSE" << std::endl;
    }
    return 0;
}

int sumOfSquares(int arr[], int arrSize){
    int square = arr[arrSize - 1] * arr[arrSize - 1];

    if(arrSize == 1){
        return square;

    }else{
        int sum = square + sumOfSquares(arr,arrSize -1);
        return sum;
    }

}

bool isSorted(int arr[], int arrSize){
    int index = arrSize - 1;
    int min = arr[index];
    bool sort;
    
    if(arrSize == 1){
        if(arr[0] >= min){
            sort = true;
            return sort;
        }else{
            sort = false;
            return sort;
        }
    }else{
        if(arr[index - 1] <= arr[index]){
            sort = isSorted(arr, arrSize - 1);
            return sort;
        }else{
            sort = false;
            return sort;

        }
    }
}