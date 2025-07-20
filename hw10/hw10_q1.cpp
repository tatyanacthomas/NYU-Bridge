#include <iostream>

std::string* createWordsArray(std::string sentence, int& outWordsArrSize);
//      creates an array on the heap where each element is a word from input
int countWords(std::string sentence);
//      called by createWordsArray
//      iterates through the input by delimiter space and outputs number of words, which will be the size of the word array
void printArray(std::string arr[], int arrSize);
//      prints the a resulting array rray

int main(){
    std::string userInput;
    int arrSize = 0;

    //created a pointer so we can access the new array that will be created on the heap
    std::string * wordArr = NULL;

    std::cout   << "Please enter a line of text: ";
    getline(std::cin, userInput);

    //this function will create an array on the heap and here we assign it to the previously NULL pointer
    wordArr = createWordsArray(userInput, arrSize);

    //print array
    std::cout << "PRINTING SENTENCE FROM ARRAY: ";
    printArray(wordArr, arrSize);

    //printing arrSize to show that outWordArrSize was updated
    std::cout << "arrSize = " << arrSize << std::endl;    
   
    //since we now have access to the array created on heap via the wordArr pointer, we can release the memory here
    delete [] wordArr;
    wordArr = NULL;

    return 0;
}

std::string* createWordsArray(std::string sentence, int& outWordsArrSize){
    int spacePosition = 0;
    int startExtractPosition = 0;
    int endExtractPosition = 0;
    bool noMoreSpaces = false; 

    //called countWords function to get new outWordsArrSize value and initialized a new array on the heap with the new size
    outWordsArrSize = countWords(sentence);
    std::string * arr = new std::string[outWordsArrSize];

    int i = 0;
    while(noMoreSpaces == false){
        if(spacePosition != std::string::npos){
            spacePosition = sentence.find(" ");
            endExtractPosition = spacePosition;
            arr[i] = sentence.substr(startExtractPosition, endExtractPosition);
            i++;
            sentence = sentence.substr(endExtractPosition + 1, (sentence.length() - endExtractPosition));
        }else{
            noMoreSpaces = true;
        }
    }
    return arr;
}

int countWords(std::string sentence){
    int wordCount = 0;
    int characterCount = 0;
    for(int i : sentence){
        characterCount++;
        if(i == ' '){ //assumption was declared that all words in sentence are separated by a single space
            if (characterCount < sentence.length()){
                wordCount++;
            }
        }
    }

    wordCount = wordCount + 1;

    return wordCount;
}

void printArray(std::string arr[], int arrSize){
    //printing array in "array style"

    for(int i = 0 ; i < arrSize; i++){
        if(i == 0 ){
            std::cout << "[";
        }
   
        std::cout << "\"" << arr[i] << "\"";

        if(i < arrSize - 1){
            std::cout << ", ";
        }

        if(i == arrSize - 1){
            std::cout << "]";
        }

    }

    std::cout << std::endl;

}