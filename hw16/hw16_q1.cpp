#include <iostream>
#include <fstream>

template<class T> class Stack; //forward declaration for Stack

//LLNODE DECLARATIONS ------------------------------------------------------------------------------------------------
template <class T> class LLNode{
    public:
        //constructor
        LLNode(T newData, LLNode<T> * newNext = nullptr): data(newData), next(newNext){};

        //assignment operator
        LLNode& operator=(LLNode node);//defined below

        //copy constructor
        LLNode(const LLNode& old); //defined below

        //destructor
        virtual ~LLNode(){};

        T& getData(){return data;}
        void setData(T newData){data = newData;}

        LLNode<T> * getNext(){return next;}
        void setNext(LLNode<T>* newNext){next = newNext;}

    private:    
        T data;
        LLNode<T> * next;

};

//STACK DECLARATIONS ------------------------------------------------------------------------------------------------
template <class T> class Stack{
    public:
        //constructor
        Stack(){head = nullptr;}

        //assignment operator
        Stack& operator=(Stack stackName){*head = stackName; return *this;}

        //copy constructor
        Stack(const Stack& old){head = old.head;}

        //destructor - simply calls clear function
        virtual ~Stack(){clear(head); std::cout << "Stack destructor called" << std::endl;}

        void push(T newItem); //defined below

        T pop(); //defined below

        LLNode<T>& top(){return *head;}

        void clear(LLNode<T> * listHead); //defined below

        bool isEmpty(){return head == nullptr;}

        int size(); //defined below 

        void printStack(); //defined below

        void printSize(); //defined below

    private:
        LLNode<T> * head;

};

//OTHER FUNCTIONS Not associated with classes Declarations --------------------------------------------------------------

//opens file, I know instructions said, for a file already opened but  for testing it was easier this way
void openFile(std::ifstream& inFile);

//assigns all of the text in the file to a string
std::string ingestData(std::ifstream& inFile);

//analyzes the string to determine: 
//  1. is it a proper Pascal file - determined with the help of fx beginEndExits()
//  2. is it properly paired
bool properlyPaired(std::string fileText, Stack<char>& pascalStack);

//looks at the first 5 and last 3 letter characters to determine if it starts with begin and closes with end
bool beginEndExist(std::string& inputData);

//added these 2 for readability and ease of writing
bool isOpeningBrace(char brace);
bool isClosingBrace(char brace);


//LLNODE Additional Function Defnitions --------------------------------------------------------------------------------
template <class T> LLNode<T>& LLNode<T>::operator=(LLNode<T> node){
    if(this != &node){
        data = node.data;
        next = node.next;   
    } 
    return *this;
}

template <class T> LLNode<T>::LLNode(const LLNode<T> &old){
    data = old.data;
    next = old.next;
}

//STACK Additional Function Definitions --------------------------------------------------------------------------------
template <class T> void Stack<T>::clear(LLNode<T> * listHead){
    if(!isEmpty()){
        if(listHead == nullptr){
            return;
        }else{
            clear(listHead ->getNext());
            delete listHead;
        }
    }
}

template <class T> void Stack<T>::push(T newItem){
    //creating a new node, and assigning the newItem T (data) 
    //and the node's Next is what used to be the head (if size == 0, then next naturally ends up being nullptr)
    LLNode<T>  * node  = new LLNode(newItem, head); 

    //assigning the address of the node as the new head of the stack
    head = node; 

}


template <class T> T Stack<T>::pop(){
    T headData = head->getData();
    if(!isEmpty()){ //if size() > 0
        LLNode<T> * newHead = head; //going to the head
        newHead = newHead->getNext(); //going to the head's next
        delete head; //deleting the OG head
        if(size() >= 1){
            head = newHead; //assigning the newHead as the head now
        }
    }
    return headData;
}

template<class T> int Stack<T>::size(){
    //as long as the stack is not empty
    if(!isEmpty()){
        int nodeCount = 0;

        //assigning the head to a temp pointer
        LLNode<T> * temp = head;

        //as long as temp is not nullptr, incrementing the # of nodes, and then
        //going to next node (this allows us to include the last node, not stop on the last node)
        while(temp != nullptr){
            nodeCount++;
            temp = temp->getNext();
        }

        delete temp;
        temp = NULL;

        return nodeCount;
    }else{
        //if empty, size == 0
        return 0;
    }
    
}

template<class T> void Stack<T>::printStack(){
    if(!isEmpty()){
        LLNode<T> * temp = head;
        while(temp != nullptr){
            if(temp->getData() == 'b'){
                std::cout << "begin" << std::endl;
            }else{ 
            std::cout << temp->getData() << std::endl;
            }

            temp = temp->getNext();
        }
        std::cout << std::endl;
        delete temp;
        temp = NULL;
    }
}

template <class T> void Stack<T>::printSize(){  
    if(isEmpty()){
        std::cout << "Stack is empty" << std::endl;
    }else{
        std::cout << "Stack has " << size() << " elements in it" << std::endl;
    }
}



//OTHER FUNCTIONS not associated with classes --------------------------------------------------------------------------
void openFile(std::ifstream& inFile){ 
    std::string fileName;
    std::cout << "What is the name of the file? " << std::endl;
    std::cout << "Note: \".txt\" will be added for you " << std::endl;
    std::cin>> fileName;

    //this way they dont have to type the extension
    fileName = fileName + ".txt";
    inFile.open(fileName);

    while(!inFile){
        std::cout << "File failed to open." << std::endl;
        inFile.clear();
        std::cout << "What is the name of the file? " << std::endl;
        std::cout << "Note: \".txt\" will be added for you " << std::endl;        
        std::cin>> fileName;
        fileName = fileName + ".txt";
        inFile.open(fileName);
    }
    std::cout << "Successfully opened " << fileName << std::endl; 
}


std::string ingestData(std::ifstream& inFile){
    std::string inputLine;
    std::string fileText;
    
    while(getline(inFile, inputLine)){
        fileText = fileText + inputLine;
        
    }
    return fileText;
}

bool beginEndExist(std::string& inputData){
    //passing inputData by reference so that if begin/end exists I can edit the input data to just contain everything except beginEnd
    bool beginExists = false;
    bool endExists = false;
    bool beginAndEndExist = false;

    //discarding any starting whitespaces (finding the index where letters begin)
    //and aborting the program if special chars or nums are found before 'begin'
    bool textBegins = false;
    int alphaStartIndex = 0;
    while(textBegins == false){
        if(isalpha(inputData[alphaStartIndex])){
            textBegins = true;
        }else if(isnumber(inputData[alphaStartIndex])){
            std::cout << "Numerical value found before begin " << std::endl;
            return false;
        }else if(!isalpha(inputData[alphaStartIndex]) && !isnumber(inputData[alphaStartIndex]) && !isspace(inputData[alphaStartIndex])){
            //if is special character
            std::cout << "Special character foudn before begin " << std::endl;
            return false;
        }else{ //if isspace()
            alphaStartIndex++;
        }
    }

    std::string firstFive = "";

    for(int i = alphaStartIndex ; i < alphaStartIndex + 5; i++){
        firstFive = firstFive + inputData[i];
    }

    if(firstFive == "begin"){
        beginExists = true;
    }
    
    std::string lastFive = inputData.substr(inputData.size() - 3); //end index is optional with substr, so this just goes to end
    if(lastFive == "end"){ 
        endExists = true;
    }

    if(beginExists && endExists){
        //cutting off the begin and end from the input data, which will be passed on to the next function
        inputData = inputData.substr(alphaStartIndex + 5, inputData.size() - 8);
        std::cout << "Proper Pascal file detected" << std::endl;
        return true;
    }else{
        return false;
    }

}
bool isOpeningBrace(char brace){
    if(brace == '[' || brace == '(' || brace == '{'){
        return true;
    }else{
        return false;
    }
}

bool isClosingBrace(char brace){
    if(brace == ']' || brace == ')' || brace == '}'){
        return true;
    }else{
        return false;
    }
}

bool properlyPaired(std::string fileText, Stack<char>& pascalStack){
    int bracketPairCount = 0;
    //the string that comes in as fileText has begin/end in it
    //once the if statemetn below runs, if begin/end exist, then "fileText" gets edited to drop off the begin/end
    //therefore the i loop runs only on the text that does not contain begin/end
    std::string singleWord = "";

   if(beginEndExist(fileText) == false){
        std::cout << "Not a valid Pascal file. Aborting program" << std::endl;
        exit(1);
    }else{
        for(int i = 0; i < fileText.size(); i++){
            //collecting words
            if(isalpha(fileText[i])){
                singleWord = singleWord + fileText[i];
            }else{
                if(isspace(fileText[i]) || isClosingBrace(fileText[i])){
                    //end of word found
                    //first check the status of the word
                    if(singleWord == "begin"){
                        pascalStack.push(singleWord[0]);
                        singleWord = "";
                    }else if(singleWord == "end"){
                        if(pascalStack.size() > 0){
                            if(pascalStack.top().getData() == 'b'){
                                pascalStack.pop();

                            }else{
                                std::cout << "Error! Improper pair: " << singleWord << " paired with " << pascalStack.top().getData() << std::endl;
                                return false;
                            }
                        }else{
                            std::cout << singleWord << " does not have a begin pairing" << std::endl;
                            return false;
                        }
                    }else{
                        //intentionally blank
                    }
                    //restart the word
                    //and start looking at the closing brace
                    singleWord = "";
                    if(pascalStack.size() > 0 && isClosingBrace(fileText[i])){
                        char stackChar = pascalStack.top().getData();
                        char comparisonChar = fileText[i];

                        if(stackChar == '{' && comparisonChar == '}'){
                            pascalStack.pop();
                        }else if(stackChar == '(' && comparisonChar == ')'){
                            pascalStack.pop();
                        }else if(stackChar == '[' && comparisonChar == ']'){
                            pascalStack.pop();    
                        }else{ 
                            std::cout << "Error! Improper pair: " << stackChar << " " << comparisonChar << std::endl;
                            return false;
                        }
                    }
                    singleWord = "";
 
                }else{
                    if(isOpeningBrace(fileText[i])){
                        pascalStack.push(fileText[i]);
                    }
                }
            }
        }
        if(pascalStack.size() == 0){
            return true;
        }else{
            std::cout << "The following items were left unpaired: " << std::endl;
            pascalStack.printStack();
            return false;
        }
    }
}
//MAIN -----------------------------------------------------------------------------------------------------------------
int main(){

    Stack<char> charStack;
    std::ifstream inputFile;
    std::string inputText;
    
    openFile(inputFile);
    
    inputText = ingestData(inputFile);

    if(properlyPaired(inputText, charStack) == false){
        std::cout << "Sorry, this file is not properly paired!" << std::endl;
    }else{
        std::cout << "Congratulations! Properly paired file :)" << std::endl;
    }
    inputFile.close();
    
    return 0;
}
