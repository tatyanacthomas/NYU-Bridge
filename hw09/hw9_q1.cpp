#include <iostream>

void initializeCountArr(int outCountArr[]);
//creates an "empty" array that will hold the counts for each character in the input text

void countCharacters(int outCountArr[], std::string input);
//counts characters and stores the counts in an array called outCountArr

int countWords(std::string input);
//counts words by delimiting by space,period, and comma. Each are treated as equal delimiters, and consecutive commas, periods, spaces are ignored

void printResults(int wordCount, int outCountArr[]);
// prints word count in row 1, prints character count from outCountArr and then prints alphabet letter using char arithmetic

int main(){
    std::string userInput;
    int outCountArr[27];

    std::cout << "Please enter a line of text: " << std::endl;
    getline(std::cin, userInput);
    //userInput = "I say hi.";

    initializeCountArr(outCountArr);
    countCharacters(outCountArr, userInput);
    printResults(countWords(userInput), outCountArr);

    return 0;
}

void initializeCountArr(int outCountArr[]){
    //creates 1 array which will store character counts and initializes the array with all zero values    
    for(int i = 0;i <= 26; i++){
            outCountArr[i]=0;
        }
    //runtime theta(1)
}

void countCharacters(int outCountArr[], std::string input){
    int letterIndex;
    for(int i = 0 ; i < input.length(); i++){
        if(input[i] >= 'A' && input[i] <= 'Z'){
            //if it is an uppercase letter, changing the char value from uppercase, to lower case
            //'a' - input[i] updates the value to 'a' 
            //      (takes you from upper case letter range to the lowercase letter range)
            //input[i] - 'A' takes you to the lowercase equivalent of the uppercase letter, from 'a' 
            //      (how far from the letter 'a' is the lower case equivalent  of the uppercase letter)
            input[i] = input[i] + ('a' - input[i] + (input[i] - 'A'));
        }
        //incrementing counts in the outCountArr for non-letter characters
        //I don't technically need to store these, but I do anyways because then I can start storing letters from index  1 - 26
        if(input[i] == ' ' || input[i] == '.' || input[i] ==','){
            outCountArr[0]++;
        }else{
            //all letter counts are stored in index 1-26 for ease of reference (ex: ind. 1 carries letter count of 'a' and ind. 5 carries letter count of 'e')
            letterIndex = input[i] - 'a' + 1; //calculating the index number that needs to be jumped to
            outCountArr[letterIndex]++;       //incrementing the value at that index
        }
    }
    //runtime theta(n)
}

int countWords(std::string input){
    int delimiterCount = 0;
    int wordCount = 0; 

    for(int i = 0; i < input.length(); i++){
        if(input[i] == ' ' || input[i] == ',' || input[i] == '.'){
            //this skips over any instance where there are spaces, commas, and periods in a row
            if(input[i+1] == ' ' || input[i+1] == ',' || input[i+1] == '.'){
                continue;
            }else{
                if(i < input.length()- 1){
                    delimiterCount++;
                }
            }
        }
    }
    wordCount = delimiterCount + 1;
    return wordCount;

    //runtime theta(n)
}

void printResults(int wordCount, int outCountArr[]){
    std::cout << wordCount << "\t" << "words" << std::endl;
    char letter;
    for(int i = 1 ; i <= 26; i++){
        if(outCountArr[i] > 0){
            //prints the counts from outCountArr only if they contain a value more than 0, and uses char arithmetic to print the associated letter
            letter = 'a'+ i - 1;
            std::cout << outCountArr[i] << "\t" << letter <<std::endl;
        }
    }
    //runtime theta(1)
}