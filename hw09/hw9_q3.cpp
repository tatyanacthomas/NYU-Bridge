#include <iostream>
#include <cstdlib>
#include <ctime>

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

void printArray(int arr[], int arrSize);
void generateRandomArray(int arr[], int arrSize);

int main(){

    //these are used for all functions
    srand((int)time(0));
    int arrSize = 10;   

    //------------------------------------------------------------
    //FUNCTION 1: 
    int newSize1 = 0;

    //creates a new array on the heap, logical size of arrSize
    int * arr1 = new int[arrSize];

    std::cout << std::endl;
    std::cout << "GET POS NUMS 1" <<  std::endl;

    //fills in the array on the heap with random positive/negative numbers
    generateRandomArray(arr1, arrSize);
    //prints array for ease of reference
    printArray(arr1, arrSize);

    //calling the function and assigning the result of that function to pointer arr1
    arr1 = getPosNums1(arr1, arrSize, newSize1);

    //showing that newSize1 has changed following getPostNums1 call (was originally a value of 0)
    std::cout << "newSize1 is: " << newSize1 << std::endl;

    //showing that the array has changed
    printArray(arr1, newSize1);

    //now that the program has finished running, deleting arr1 from the heap
    delete [] arr1;
    arr1 = NULL;

    //------------------------------------------------------------
    //FUNCTION 2: 

    //creates a new array on the heap, logical size of arrSize
    int * arr2 = new int[arrSize];

    std::cout << std::endl;
    std::cout << "GET POS NUMS 2" <<  std::endl;

    //fills in the array on the heap with random positive/negative numbers
    generateRandomArray(arr2, arrSize);
    //prints array for ease of reference
    printArray(arr2, arrSize);

    //declaring an integer on the heap that will store the array's new size, and setting the dereferenced value to 0;
    int * newSizePtr2 = new int;
    *newSizePtr2 = 0;
    
    //calling the function and assigning the result of that function to pointer arr2
    arr2 = getPosNums2(arr2,arrSize,newSizePtr2);

    //showing that newSizePtr2's dereferenced value has changed following getPostNums2 call (was originally a value of 0)
    std::cout << "newSize2 is: " << *newSizePtr2 << std::endl;

    //showing that the array has changed
    printArray(arr2, *newSizePtr2);

    //now that the program has finished running, deleting newSizePtr2 from the heap
    delete newSizePtr2;
    newSizePtr2 = NULL;

    //now that the program has finished running, deleting arr2 from the heap
    delete [] arr2;
    arr2 = NULL;

    //------------------------------------------------------------
    //FUNCTION 3: 

    //creates a new array on the heap, logical size of arrSize
    int * arr3 = new int[arrSize];

    //initializes a regular variable which will store the new array's size
    int newSize3 = 0;

    std::cout << std::endl;
    std::cout << "GET POS NUMS 3" <<  std::endl;

    //fills in the array on the heap with random positive/negative numbers
    generateRandomArray(arr3, arrSize);
    //prints array for ease of reference
    printArray(arr3, arrSize);

    //creates a pointer to nothing for now, but will later be filled in with a new array on the heap (once the function is called)
    int *posArr3 = NULL;

    //calling the function. Since posArr3 and newSize3 are both call by reference, the values that are updated in the function will update in main too
    getPosNums3(arr3, arrSize, posArr3, newSize3);

    //showing that newSize3's value which was passed by reference back to main has changed following getPostNums3 call (was originally a value of 0)
    std::cout << "newSize3 is: " << newSize3 << std::endl;

    //I cannot change the value of arr3 in the function because it was not passed by reference and it was also not returned by the function
    //but since the values of posArr3 has been passed by reference, I can change what the pointer is pointing to here in main
    arr3 = posArr3;

    //showing that the array has changed
    printArray(arr3, newSize3);

    //now that the program has finished running, deleting arr3 from the heap
    delete [] posArr3;
    posArr3 = NULL;

    //------------------------------------------------------------
    //FUNCTION 4: 

    //creates a new array on the heap, logical size of arrSize
     int * arr4 = new int[arrSize];

    //declaring an integer on the heap that will store the array's new size, and setting the dereferenced value to 0;
    int * newSizePtr4 = new int;
    *newSizePtr4 = 0;

    //creating a second new array on the heap, logical size of arrSize, which will store the new array's values
    int *posArr4 = new int[arrSize];

    std::cout << std::endl;
    std::cout << "GET POS NUMS 4" <<  std::endl;

    //fills in the array on the heap with random positive/negative numbers
    generateRandomArray(arr4, arrSize);
    //prints array for ease of reference
    printArray(arr4, arrSize);

    //calling the function. Since posArr4 and newSize3 are both pointers, the values that are updated in the function will update in main too
    getPosNums4(arr4, arrSize,&posArr4,newSizePtr4);

    //showing that newSize4's value which was passed by pointer back to main has changed following getPostNums4 call (was originally a value of 0)
    std::cout << "newSize4 is: " << *newSizePtr4 << std::endl;

    //now that the program has finished running, deleting arr3 from the heap
    delete [] arr4;
    arr4 = NULL;

    //changing where the pointer is pointing too. Saying, "now when we say look at arr4, look instead at where posArr4 is located"
    arr4 = posArr4;

    //showing that the array has changed
    printArray(arr4, *newSizePtr4);

    //now that the program has finished running, deleting newSizePtr int from the heap
    delete newSizePtr4;
    newSizePtr4 = NULL;

    //now that the program has finished running, deleting the edited version of arr4 from the heap (used to be the temporary array)
    delete [] arr4;
    arr4 = NULL;

    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    //creates a new array on the heap that will store the only-pos numbers
    int *tempArr = new int[arrSize];

    //iterates through arr and copies the positive values over to the temporary array created on the heap
    for (int i = 0; i < arrSize; i++){
        if(arr[i] >= 0){
            tempArr[outPosArrSize] = arr[i];
            outPosArrSize++;
        }
    }

    //deletes the old array (empties it)
    delete [] arr;
    arr = NULL;

    //assigns tempArr to the arr pointer.
    arr = tempArr;

    //returns the address for the now changed arr (previously called tempArr)
    return arr;

}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
    //creates a new array on the heap that will store the only-pos numbers
    int *tempArr = new int[arrSize];

    //iterates through arr and copies the positive values over to the temporary array created on the heap
    //uses the dereferenced value of outPosArrSizePtr which was initially set as 0 in main before the function was called
    for (int i = 0; i < arrSize; i++){
        if(arr[i] >= 0){
            tempArr[*outPosArrSizePtr] = arr[i];
            *outPosArrSizePtr = *outPosArrSizePtr + 1;
        }
    }

    //deletes the old array (empties it)
    delete [] arr;
    arr = NULL;

    //assigns tempArr to the arr pointer.
    arr = tempArr;

    //returns the address for the now changed arr (previously called tempArr)
    return arr;

}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
        //outPossArr pointer was originally set to NULL before being passed into the function. Assigning it to a new array on the heap here
        outPosArr = new int[arrSize];

        //iterates through arr and copies the positive values over to the temporary array created on the heap
        for (int i = 0; i < arrSize; i++){
            if(arr[i] >= 0){
                outPosArr[outPosArrSize] = arr[i];
                outPosArrSize++;
            }
    }
    //deletes the old array (empties it)
    //cannot change anything in arr because arr was not passed in by reference, and the function does not return anything
    delete [] arr;
    arr = NULL;

}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
        //this line is not technically needed, but for ease of reference, created a pointer to the dereferenced value of *outPosArrPtr (which is an address)
        int *posArr4Ptr = *outPosArrPtr;

        //iterates through arr and copies the positive values over to the temporary array created on the heap
        //uses the dereferenced value of outPosArrSizePtr which was initially set as 0 in main before the function was called
        for (int i = 0; i < arrSize; i++){
            if(arr[i] >= 0){
                posArr4Ptr[*outPosArrSizePtr] = arr[i];
                *outPosArrSizePtr = *outPosArrSizePtr + 1;
            }
    }

    //cannot change anything in arr because arr was not passed in by reference, and the function does not return anything
    //no array was created here, so nothing to delete
    
}

void printArray(int arr[], int arrSize){
    for(int i = 0; i < arrSize; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void generateRandomArray(int arr[], int arrSize){
    int randNumPos;
    int randNumNeg;


    for(int i = 0; i < arrSize; i++){
        randNumPos = (rand() % 20) +1;
        randNumNeg = (rand() % 10) +1;
        arr[i] = randNumNeg - randNumPos;
    }

}