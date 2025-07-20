#include <iostream>

const int WORD_COUNT = 100;

void sliceSentence(std::string input, std::string arr[], int arrSize);
//creates an array that stores the words in the sentence

bool isOnlyNumbers(std::string input);
//checks to see if array values are all numbers only

std::string obfuscateNumbers(std::string input);
//if an array value is all numbers it replaces each character in the array item with x's

int main(){
    std::string arrSentence[WORD_COUNT];
    int arrSize = WORD_COUNT;

    //input vars
    std::string userInput;
    int inputLength = 0;

    //output vars
    std::string output;
    int outputLength = 0; 

    std::cout << "Please enter a line of text: ";
    std::getline(std::cin, userInput);

    inputLength = userInput.length();

    sliceSentence(userInput, arrSentence, arrSize);

    for(int i = 0; i < arrSize; i++){

        //only checks items in the array that have a value in it
        if(arrSentence[i] != ""){

            if(isOnlyNumbers(arrSentence[i]) == true){
                std::cout << obfuscateNumbers(arrSentence[i]); 
                //prints out the xxx'd version of the array item
            }else{
                std::cout << arrSentence[i];
                //prints the array item as is
            }

            //only prints out a space after the word if we have not yet reached the end of the input
            outputLength = outputLength + arrSentence[i].length() + 1;
            if (outputLength < inputLength){
                std::cout << " ";            
            }

        }
    }


    return 0;
}

void sliceSentence(std::string input, std::string arr[], int arrSize){
    bool noMoreSpaces; 
    int spacePosition; 
    int startExtractPosition;
    int endExtractPosition; 
    std::string extractedName;
    int i = 0;

    startExtractPosition = 0;
    spacePosition = 0;
    noMoreSpaces = false;
    
    while(noMoreSpaces == false){
        if(spacePosition != -1 || spacePosition != std::string::npos){
            //finds the next space
            spacePosition = input.find(" ");
            //assigns that space to be the end of the extraction
            endExtractPosition = spacePosition;

            //extract the word and put it in an array
            arr[i] = input.substr(startExtractPosition, endExtractPosition);
            i++;

            //extract the rest of the string that comes after the word
            input = input.substr(endExtractPosition + 1, (input.length() - endExtractPosition));
            
        }else{ 
            //if it doesnt find a space, it ends the loop, so it only will run as many times as there is a space
            noMoreSpaces = true;
        }
    }
}

bool isOnlyNumbers(std::string input){
    int letterCount = 0;
    bool isOnlyNumbers;

    for(int i = 0; i < input.length(); i++){
        //looks through the input 
        if(input[i] > '0' && input[i] < '9'){
            //if theres a number, do nothing
        }else{
            //otherwise increment letter count
            letterCount++;
        }
    }
    if (letterCount > 0){
        //even if a word is partially made of numbers
        //once there is any letter, it is no longer a strictly numerical value
        isOnlyNumbers = false;
    }else{
        //if it is all numbers, it will never increment letterCount
        isOnlyNumbers = true;   
    }

    return isOnlyNumbers;
}

std::string obfuscateNumbers(std::string input){
    std::string xOut = "";

    //prints number of x's equal to the length of the string
    for(int i = 0; i < input.length(); i++){
        xOut = "x"+ xOut;
    }

    input = xOut;
    return input;
}


