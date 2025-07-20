#include <iostream>

int jumpIt(int arr[], int arrSize, int ogArrSize);
//incrementally adds up the values in an array, to arrive at the lowest sum of adjacent 
//or skipping 1 element
//ogArrSize is the unchanged array size

int smallerVal (int val1, int val2, bool& skip);
//brings back which of 2 values is smaller, 
//marks "skip" as true or false
//true: this value does not need to be added to the total cost
//false: we will add this value to the total cost


int main(){
    int arr[6] ={0, 3, 80, 6, 57, 10};
    int arrSize = 6;
    
    int cost = 0;
    int ogArrSize = arrSize;
    cost = jumpIt(arr, arrSize, ogArrSize);

    std::cout << "finalCost " << cost << std::endl;
    return 0;
}

int jumpIt(int arr[], int arrSize, int ogArrSize){
    int index = arrSize - 1;

    int val1; //holds the value for the element 2 places over from "where we are" 
    int val2; //holds the value for the element adjacent from "where we are"
    int jumpTo; //the minimum value that we "jump to"

    bool skip = false;

    int cost = 0;

    if(arrSize == 2){
        //if there are just 2 elements, the cost is just the adjacent element
        cost = arr[index]; 
        return cost;
    }else{   
        val2 = arr[index]; 
        val1 = arr[index - 1];

        //calculates the smaller of the 2 values to choose where to "jump to"
        //also returns a true/false value for skip
        //when skip is true, we will skip over it and not add the value to the cost
        //when skip is false, we will add the value to the cost
        //in both cases we make the recursive call to arrSize-1 (index)
        jumpTo = smallerVal(val1, val2, skip); 

        if(skip == false){
            cost = jumpTo + jumpIt(arr, index, ogArrSize);
        }else{
            cost = jumpIt(arr, index, ogArrSize);
        }

        //before returning the final cost we do some corrective action
        if(arrSize % 2 == 1){ 
            //This forces the program to add the value of the last element to the final total
            if(arrSize == ogArrSize && arr[index] > arr[index - 1]){
                std::cout << "cost before added line " << cost << std::endl;
                cost = cost + arr[index];
                std::cout << "added line " << cost << std::endl;
            }
        }else{
            //when there are even number of elements, when we are at the end of the array, if the second to last element is less than the last element, it will subtract the value of the second to last element from the total, because even if it is smaller, it is better to be skipped to reach the end than to accumulate.

            //ex: {0, 3, 15, 12, 8, 10} without the below would evaluate to 3+12+8+10
            //the below code evaluates it to (3+12+8+10 - 8) 
            if(arrSize == ogArrSize && arr[index] > arr[index - 1]){
                std::cout << cost << " // " << arr[index - 1] << std::endl;
               cost = cost - arr[index - 1]; 
            }
        }
        return cost;
    }
}

int smallerVal(int val1, int val2, bool& skip){

        int smallerVal = val1;
        std::cout << val1 << " " << val2 << std::endl;
        if(val1 < val2){
            smallerVal = val1;
            skip = true;
        }
        else{
            smallerVal = val2;
            skip = false;
        }        
        std::cout << smallerVal << std::endl;
        return smallerVal;
}
