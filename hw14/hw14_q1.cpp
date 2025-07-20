#include <iostream>
#include <vector>
#include <cstdlib>

const int MIN_INDEX = 0;
const int MAX_INDEX = 1;

void generateRandomVector(std::vector <int>& randVector);
//creates a random vector of values from -100 to 100, can be a length of any amount from 1 - 20

std::vector<int> minAndMax(std::vector <int>& inputVector); //driver for minAndMax
std::vector<int> minAndMax(std::vector<int>& inputVector, int start, int end, std::vector <int>& minMax);
//takes input vector, as well as start/end, and outputs a minmax vector of size 2
//calls the divideAndConquer() function, which contains minAndMax, making minAndMax a recursive function 

std::vector<int> divideAndConquer(std::vector <int>& inputVector, int start, int end, std::vector<int>& minMax);
//while inside minAndMax,  calls minAndMax on left vs right of the whole vector 

void printMinMax(std::vector<int>& minMax);
//self explanatory 


int main(){

    srand((int)time(0));

    //generates random vector
    std::vector <int> inputVector;
    generateRandomVector(inputVector);

    //test vector
    //inputVector = {109, 1, 34, 45,66, 86}; 

    //prints out starting vector
    std::cout << "Starting vector: ";
    for(int i = 0; i < inputVector.size(); i++){
        std::cout << inputVector[i] << " ";
    }
    std::cout << std::endl;

    //calling minAndMax, and assigning its result to minMax vector to be printed 
    std::vector <int> minMax = minAndMax(inputVector);

    //print!
    printMinMax(minMax);


    return 0;
}

std::vector<int> minAndMax(std::vector<int>& inputVector, int start, int end, std::vector <int>& minMax){

    if(start == end){ //base case 1, if there is one item, that item is both max and min
        minMax[MIN_INDEX] = inputVector[start];
        minMax[MAX_INDEX] = inputVector[end];
        return minMax;

    }else if(end - start == 1){ //base case 2, if there are two items, compare to determine max and min
        if(inputVector[start] >= inputVector[end]){
            minMax[MAX_INDEX] = inputVector[start];
            minMax[MIN_INDEX] = inputVector[end];
        }else{
            minMax[MAX_INDEX] = inputVector[end];
            minMax[MIN_INDEX] = inputVector[start];
        }
        return minMax;

    }else{ //otherwise split the input and recursively find min and max (minAndMax() is called within dividAndConquer)
        divideAndConquer(inputVector, start, end, minMax);
        return minMax;
    }
}

//driver for minAndMax
std::vector <int> minAndMax(std::vector <int>& inputVector){ 
    //creating a vector size 2 that will store min and max
    std::vector <int> minMax;
    minMax.resize(2);
    
    //driving thus commences
    return minAndMax(inputVector, 0, inputVector.size()-1, minMax);
    
}

std::vector <int> divideAndConquer(std::vector <int>& inputVector, int start, int end, std::vector <int>& minMax){
    
    //split the two halves, recursively finding the min and max
    int mid = (end + start) / 2;
    std::vector <int> left = minAndMax(inputVector, start,  mid, minMax);
    std::vector <int> right = minAndMax(inputVector, mid+1, end, minMax);

    //two additional comparisons, produce the max and min for the whole problem 

    //minimum comparison
    if(left[MIN_INDEX] >= right[MIN_INDEX]){
        minMax[MIN_INDEX] = right[MIN_INDEX];
    }else{
        minMax[MIN_INDEX] = left[MIN_INDEX];
    }
    //maximum comparison
    if(left[MAX_INDEX] >= right[MAX_INDEX]){
        minMax[MAX_INDEX] = left[MAX_INDEX];
    }else{
        minMax[MAX_INDEX] = right[MAX_INDEX];
    }

    return minMax;
}

void generateRandomVector(std::vector <int>& randVector){
    //randomly selecting vector size from 1 to 20
    int randomVectorSize = rand() % 12 + 1;
    randVector.resize(randomVectorSize);

    //creating a random negative value that will be added to a random positive value
    //resulting in sometimes filling in the vector with positive numbers, and sometime with negative numbers
    int randomNegative = -(rand() % 100 + 1);

    for(int i = 0; i < randomVectorSize; i++){
        int element = ((rand() % 100) +1) + randomNegative;
        randVector[i] = element;
    }
}

void printMinMax(std::vector<int>& minMax){
    for(int i = 0; i < 2; i++){
        std::cout << std::endl;
        if(i == 0){
            std::cout << "Minimum Value is: ";
            std::cout << minMax[i];
        }else{ 
            std::cout << "Maximum Value is: ";
            std::cout << minMax[i];
        }
    }
    std::cout << std::endl << std::endl;

}