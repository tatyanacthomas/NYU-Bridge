#include <iostream>

const int MAX_N_VAL = 5;

void generateRandomArray(int arr[], int arrSize);
//      generates a random array (userArr) using a random number as the array size AND maximum value
//      this array is used as the input for the rest of the program
int* countDigits(int arr[], int arrSize, int& outArrSize);
//      iterates through userArr and counts how many of each number is present. Stores the results in a digitArr of size 0 to randN 
int* findMissing(int arr[], int n, int &resArrSize);
//      iterates through digitArr and prints out any where the value is 0 (because the userArr did not contain that value)
void printArray(int arr[], int arrSize);
//      print! 

int main(){
    srand((int)time(0));

    //creating a random N value for testing, can be as little as 1 and as big as 20 (MAX_N_VAL). 
    int randN = (rand() % MAX_N_VAL);
    std::cout << "randN= " << randN << std::endl << std::endl;

    //creates an array on heap where the size is equal to the random N value, and the values  in the array are random between 0 and randN
    int * userArr = new int [randN];
    generateRandomArray(userArr, randN);
    int arrSize = randN;

    std::cout << "USER ARR" << std::endl;
    printArray(userArr, arrSize);
    std::cout << std::endl;

    int newArrSize = 0;
    int digitArrSize = 0;

    int * digitArr = NULL;
    int * finalArr = NULL;


    //creates an array that holds the counts of numbers in a given array
    //ex: array that prints 0 0 4 2 means no 0's, no 1's, four 2's, and two 3's
    digitArr = countDigits(userArr, arrSize, digitArrSize);

    //passes in digitArr and creates an array from 0 to randN where only the indexes of digitArr value == 0 is printed
    finalArr = findMissing(digitArr, digitArrSize, newArrSize);

    std::cout <<  "MISSING NUMBERS ARR" << std::endl;
    printArray(finalArr,newArrSize);

    std::cout << std::endl;

    //since we now have access to the arrays created on heap via the digitalArr and finalArr pointers
    //We can release the memory here
    delete [] finalArr;
    finalArr = NULL;

    delete [] digitArr;
    digitArr = NULL;

    //now that the program has ended, we can release the memory here
    delete [] userArr;
    userArr = NULL;

    return 0;
}
int* countDigits(int arr[], int arrSize, int& outArrSize){
    //the size of the digitArr will be randN + 1 because the range is {0, 1, 2, ... , n}
    int digitArrSize = (arrSize + 1);
    outArrSize = digitArrSize; //outArrSize will get edited in main

    int * digitArr = new int [digitArrSize];

    //filling in the array with 0s
    std::cout << "DIGIT COUNT ARR" << std::endl;
    for(int i = 0; i < digitArrSize; i++){
        digitArr[i] = 0;
    }

    //filling in the array with the number counts aligned with the index number
    //ex: an array with two 1's and three 6's will fill in: 0 2 0 0 0 0 3
    for(int i = 0; i < arrSize ; i++){
        *(digitArr + arr[i]) = *(digitArr + arr[i]) + 1;
    }

    //printing digitArr
    printArray(digitArr, digitArrSize);

    std::cout << std::endl;

    return digitArr;

    //runtime of about 2n, therefore theta(n)
}

int* findMissing(int arr[], int n, int &resArrSize){

    //initializes a new array on the heap of size randN
    int * missingArr = new int [n];
    int index = 0;


    for(int i = 0 ; i < n; i++){
        if(arr[i] == 0){
            missingArr[index] = i;
            index++;
        }
    }
    
    resArrSize = index; //passing the size of the resulting array to main so it can be used in printArray().
    return missingArr;

    //runtime of n, therefore theta(n)
}

void printArray(int arr[], int arrSize){
    for(int i = 0; i <  arrSize ; i++){
        std::cout << (arr[i]) << " ";
    }
    std::cout << std::endl;
}

void generateRandomArray(int arr[], int arrSize){
    int randNumPos;

    for(int i = 0; i < arrSize; i++){
        randNumPos = (rand() % arrSize);
        arr[i] = randNumPos;
    }

}