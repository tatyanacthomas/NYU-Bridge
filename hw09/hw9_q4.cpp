#include <iostream>
#include <cstdlib>
#include <ctime>

void generateRandomArrayWithNeg(int arr[], int arrSize);
//fills in an empty array with random positive and negative numbers for testing purposes

void generateRandomArrayAllPos(int arr[], int arrSize);
//fills in an empty array with random positive numbers only for testing purposes

void printArray(int arr[], int arrSize);
//prints array at any given point 

void oddsKeepEvensFlip(int arr[], int arrSize);
//moves all odd numbers to the left (overwriting preexisting values)
//moves all even numbers to a temporary array, to then be reentered into the original array
//      starting off where the odd numbers end.
//      Logic was added to account for negative numbers treating mod (%) differently 


int main(){

    srand((int)time(0));

    //creates an array to be filled in with random values from -10 to 20 for testing
    int arrSize = 19;
    int randomArr[arrSize];


    std::cout << "TEST 1: Random array with positive and negative numbers: " << std::endl;
    generateRandomArrayWithNeg(randomArr, arrSize);
    printArray(randomArr, arrSize);
    oddsKeepEvensFlip(randomArr, arrSize);
    printArray(randomArr, arrSize);
    std::cout << std::endl;

    std::cout << "TEST 2: Random array with only positive numbers: " << std::endl;
    generateRandomArrayAllPos(randomArr,arrSize);
    printArray(randomArr, arrSize);
    oddsKeepEvensFlip(randomArr, arrSize);
    printArray(randomArr, arrSize);
    std::cout << std::endl;

    std::cout << "TEST 3: Fixed array sequential order: " << std::endl;
    int fixedArr[19] = {1, 2, 3 , 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,15,16, 17, 18, 19};
    printArray(fixedArr, arrSize);
    oddsKeepEvensFlip(fixedArr, arrSize);
    printArray(fixedArr, arrSize);
    std::cout << std::endl;

    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize){
    //flag to indicate when a number was altered since it was negative, so that it can be changed back
    bool negNum = false; 

    int i = 0;

    //initialized to be the same size as original array in the event it is all evens
    int tempEvenArr[arrSize]; 
        
    int evenCount = 0;
    int oddCount = 0;
    
    //if its odd, overwrites what is in the 0th, 1st, 2nd etc, positions of the array with the odd number
    //keeps track of how many odd numbers there are
    for(int i = 0; i < arrSize; i++){

        //if the number is neg, temporarily changes it to pos so that its parity can be evaluated more easily
        if(arr[i] < 0){ 
            arr[i] = arr[i] * -1;
            negNum = true;
        }
        if (arr[i] % 2 == 1){
            //oddCount represents the index on the left hand side of the array that odd numbers will be moved to 
            //increments each time a new oddVal is added so next oddVal can be next to the last one 
            arr[oddCount] = arr[i];

            //if the number was negative then changes it back to positive 
            //once it has been placed in the correct array in the correct spot
            if(negNum == true){
                arr[oddCount] = arr[oddCount] * -1;
                negNum = false;
            }

            oddCount++;
        }else{
            //evenCount represents the index of the temporary array where the evens will throw a party for a bit before joining the odds later
            tempEvenArr[evenCount] = arr[i];

            //if the number was negative then changes it back to positive 
            //once it has been placed in the correct array in the correct spot
            if(negNum == true){
                tempEvenArr[evenCount] = tempEvenArr[evenCount] * -1;
                negNum = false;
            }

            evenCount++;
        }

    }

    //evens are done with their party and are reentering the original array backwards
    //with the first value being dropped in righ after the last oddVal.
    for(int i = oddCount ; i < arrSize ; i++){
        arr[i] = tempEvenArr[evenCount - 1];
        evenCount--;
    }

    //oddsKeepEvensFlip runtime of theta(n) -- 3N total
}

void generateRandomArrayWithNeg(int arr[], int arrSize){
    int randNumPos;
    int randNumNeg;

    for(int i = 0; i < arrSize; i++){
        randNumPos = (rand() % 20) +1;
        randNumNeg = (rand() % 10) +1;
        arr[i] = randNumNeg - randNumPos;
    }
    //runtime of theta(n) -- 1N total
}

void generateRandomArrayAllPos(int arr[], int arrSize){
    int randNumPos;

    for(int i = 0; i < arrSize; i++){
        randNumPos = (rand() % 20) +1;
        arr[i] = randNumPos;
    }
    
    //runtime of theta(n) -- 1N total
}

void printArray(int arr[], int arrSize){
    for(int i = 0; i <  arrSize; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    //runtime of theta(n) -- 1N total
}