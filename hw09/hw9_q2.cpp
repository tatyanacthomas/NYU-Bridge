#include <iostream>

void initializeCountArrs(int outCountArr1[], int outCountArr2[]);
//creates two "empty" arrays that will hold the counts for each character in the input text

void countCharacters(int outCountArr[], std::string input);
//counts characters and stores the counts in an array

bool compareSentences(int outCountArr1[], int outCountArr2[]);
//since all counts are in the same index locations between the two strings of text, the two filled-in arrays can be compared to determine if the phrases are anagrams

int main(){
    std::string userInput1;
    std::string userInput2;

    int outCountArr1[27];
    int outCountArr2[27];

    std::cout << "Please enter each line of text followed by an enter to indicate the entry is complete " << std::endl;
    getline(std::cin, userInput1);
    getline(std::cin, userInput2);

    //userInput1 = "I am a weakish speller...";
    //userInput2 = "Shakespeare, William";

    initializeCountArrs(outCountArr1, outCountArr2);
    countCharacters(outCountArr1, userInput1);
    countCharacters(outCountArr2, userInput2);
    if(compareSentences(outCountArr1, outCountArr2) == true){
        std::cout << "\"" << userInput1 << "\" and \"" << userInput2 << "\" are anagrams." << std::endl;
    }else{
        std::cout << "\"" << userInput1 << "\" and \"" << userInput2 << "\" are not anagrams." << std::endl;
    }

    return 0;
}

void initializeCountArrs(int outCountArr1[], int outCountArr2[]){
    //creating two arrays where index 0 will represent the count of all non-letter items
    //all other indexes from 1-26 will contain the count of alphabet letters 
    for(int i = 0;i <= 26; i++){
            outCountArr1[i]= 0;
            outCountArr2[i]= 0;
    }
    
    //theta(1) runtime
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
        //We will not compare the counts of the values in index 0 when doing the anagram review 
        if(input[i] == ' ' || input[i] == '.' || input[i] ==','){
            outCountArr[0]++;
        }else{
            //all letter counts are stored in index 1-26 for ease of reference (ex: ind. 1 carries letter count of 'a' and ind. 5 carries letter count of 'e')
            letterIndex = input[i] - 'a' + 1;   //calculating the index number that needs to be jumped to
            outCountArr[letterIndex]++;         //incrementing the value at that index
        }
    }

    //theta(n) runtime where n represents the length of the input
}

bool compareSentences(int outCountArr1[], int outCountArr2[]){
    bool anagram = false;
    //starts at index 1 because index 0 holds the space/period/commas that are being ignored
    for(int i = 1; i < 27; i++){
        if(outCountArr1[i] == outCountArr2[i]){
            anagram = true;
        }else{
            anagram = false;
            break;
        }
    }

    //theta(1) runtime
    return anagram;
}