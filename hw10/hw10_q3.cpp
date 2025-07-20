#include <iostream>
#include <vector>

int main1();
    int * retrieveInputArr(int& outArrSize);
    //      retrieves input and calls resizeArray to update array size to double size once input array fills up
    void resizeArray(int arr[], int& arrSize);
    //      resizes the input array by creating a temp array, copying all items to the temp, and reassigning the pointer, at a runtime of amortized theta(1)
    void findNumberInArr(int* arr, int arrSize, int n);
    //      searches array for the search value and prints accordingly

int main2();
    void retrieveInputVect(std::vector<int>& vect);
    //      retrieves input and vector class auto-sizes the vector size
    //      call by reference allows the empty vector in main to be updated, and then used in next function call
    void findNumberInVect(std::vector<int> v, int n);
    //      searches vector for the search value and prints accordingly


int main(){

    std::cout << "VERSION 1: Method Used - Resize Array on Heap" << std::endl;
    main1();

    std::cout << std::endl;

    std::cout << "VERSION 2: Method Used - Vector" << std::endl;
    main2();

    return 0;
}

int main1(){
    int inputArrSize = 0;
    int searchNum;
    
    //initializes a pointer to nothing and then assigns that pointer to the array that results from retrieveInputArr. 
    //being able to assign the return value of the function call to a pointer is why I made this function int* instead of void
    int * userArr = NULL;
    userArr = retrieveInputArr(inputArrSize);

    std::cout<< "Please enter the number you want to search for: ";
    std::cin >> searchNum;
    findNumberInArr(userArr, inputArrSize, searchNum);

    //now that the program has ended, deleting the array that is created when calling retrieveInputArr()
    delete [] userArr;
    userArr = NULL;

    return 0;
}

int * retrieveInputArr(int& outArrSize){
    int userInput;

    //we start with an array that is size 1, and will increase it to 2x as the array fills up
    int arrSize = 1;

    int inputCount = 0;    
    bool inputComplete = false;

    std::cout << "Please enter a sequence of positive integer, each in a separate line " << std::endl;
    std::cout << "Enter your input by typing -1" << std::endl;

    //this array is going to be the one that the empty pointer in main is going to point to after the function call is complete
    int * userArr = new int[arrSize];

    while(inputComplete == false){
        std::cin >> userInput;
        inputCount++; //incrementing input count immediately after input is given, but before inserting the value to the arr and before resizing arr
        if(userInput >= 0){ //assignment says all entries will be positive integers
            userArr[inputCount - 1] = userInput; //first assigns the userInput to the correct index in userArr
            if (inputCount == arrSize){
                resizeArray(userArr, arrSize); //then resizes if needed
            }
            
        }else{ 
            inputComplete = true; 
        }
    }

    outArrSize = inputCount - 1; //subtracted by 1 because it counts the "end with -1" input as an input

    return userArr;
}

void resizeArray(int arr[], int& arrSize){
    arrSize = arrSize * 2; //important: the original array size will NOT be retained, figured its probably not important to keep

    //initializing the temporary array where we will copy over values, into an array that is 2x the size of the last
    int* newArr = new int [arrSize];

    //since we already doubled the array, I am only iterating through arrSize/2 , which is the size of the "old" array
    for(int i = 0; i < arrSize/2; i++){
        newArr[i] = arr[i];
    }

    //first changes changes where the pointer is pointing to
    arr = newArr;

    //then empties the stuff in the temporary array pointer
    delete [] newArr;

}

void findNumberInArr(int* arr, int arrSize, int n){
    int foundCount = 0;
    
    for(int i = 0; i < arrSize; i++){
        if(arr[i] == n){
            if(foundCount == 0){ //putting this line here makes sure that only when the first match is found will the "n is found in line" will print
                std::cout << n << " shows in line: ";
            }
            if(foundCount > 0){ //this makes sure that the comma only prints after the first find, and also doesnt print after the last find
                std::cout << ", ";
            }
            std::cout << i + 1; //line number is 1 more than the index
            foundCount++;       //after the number is printed, then increment the foundCount
        }
    }
    std::cout << std::endl;

    if(foundCount == 0){
        std::cout << n << " not found in this list!" << std::endl;
    }

}

//--------------

int main2(){
    int searchNum;
 
    //initializing an empty vector (pass by reference permits edits to vector in main from function call)
    std::vector<int> v;

    retrieveInputVect(v);
    std::cout<< "Please enter the number you want to search for: ";
    std::cin >> searchNum;
    findNumberInVect(v, searchNum);

    return 0;
}

void retrieveInputVect(std::vector<int>& vect){

    bool inputComplete = false;
    int userInput;

    std::cout << "Please enter a sequence of positive integer, each in a separate line " << std::endl;
    std::cout << "Enter your input by typing -1" << std::endl;

    while(inputComplete == false){
        std::cin >> userInput;
        if(userInput >= 0){
            vect.push_back(userInput); 
        }else{
            inputComplete = true;
        }
    }

}

void findNumberInVect(std::vector<int> v, int n){
    int foundCount = 0;

    for(unsigned int i = 0; i < v.size(); i++){
        if(v[i] == n){
            if(foundCount == 0){ //putting this line here makes sure that only when the first match is found will the "n is found in line" will print
                std::cout << n << " shows in line: ";
            }
            if(foundCount > 0){ //this makes sure that the comma only prints after the first find, and also doesnt print after the last find
                std::cout << ", ";
            }
            std::cout << i + 1; //line number is 1 more than index
            foundCount++; 
        }
    }
    std::cout << std::endl;

    if(foundCount == 0){
        std::cout << n << " not found in this list!" << std::endl;
    }

}

