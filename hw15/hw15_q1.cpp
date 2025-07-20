#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

template<class T> class LList; //forward declaration for LList

//CLASS DECLARATIONS ---------------------------------------------------------------------------------------------------------

template <class T> class LLNode{
    public: 
        //LLNode constructor
        LLNode(T newData = T(), LLNode<T> * newNext = nullptr): data(newData) , next(newNext) {};
        
        virtual ~LLNode(){};
        friend class LList<T>;

        //T needs to be pass by reference otherwise it accesses a copy of the node not the node itself, so nothing would be updated
        T& getNodeData(){return data;}
        void setNodeData(T newData){data = newData;}

        LLNode<T> * getNodeNext(){return next;}
        void setNodeNext(LLNode<T>* newNext){next = newNext;}

    private:
        T data;
        LLNode<T> * next;
};

template <class T> class LList{
    public: 
        //LList constructor, default, blank
        LList(): head(nullptr){};

        //LList copy constructor
        LList(const LList& rhs) : head(nullptr) {*this = rhs;}

        //LList destructor
        virtual ~LList(){
            //going first to the 2nd node
            LLNode<T> * node = head;
            node = node->getNodeNext();

            //iterating through each actual node, assigning a temporary next ptr to the next node
            //deleting the node itself (calls the node destructor)
            //then assigning the temporary next ptr to the node variable
            LLNode<T> * next = node->getNodeNext();

            while(node->getNodeNext() != nullptr){
                next = node->getNodeNext();
                delete node;
                node = next;
            }

            //the while loop stops at the second to last node 
            //so, naming the last node "tail" by assigning a ptr to it 
            //and then updating the head's next to be the tail (the node that it was originally linked to is now deleted)
            LLNode<T> * tail = node->getNodeNext();
            head->setNodeNext(tail);
            
            delete tail;
            delete head;
            delete node;
            std::cout << "LList destructor called " << std::endl;

        }

        bool isEmpty() const {return head == nullptr;}
        void insertAtEnd(T newData);
        int size() const;

        void setHead(LLNode<T>* newHead){head = newHead;}
        LLNode<T>* getHead(){return head;}

    private:
        LLNode<T> * head;
};

class FriendPaymentProfile{
    public:
        //big 3
        FriendPaymentProfile(); //default constructor
        virtual ~FriendPaymentProfile(){}; //destructor
        FriendPaymentProfile(const FriendPaymentProfile &old); //copy constructor
        
        //overloaded assignment operator 
        FriendPaymentProfile& operator=(FriendPaymentProfile groupMember); 

        //getters and setters
        std::string getFirstName(){return firstName;}
        void setFirstName(std::string first){firstName = first;}

        void setMiddleInitial(std::string middle){middleInitial = middle;}
        std::string getMiddleInitial(){return middleInitial;}

        void setLastName(std::string last){lastName = last;}
        std::string getLastName(){return lastName;}

        void setFullName(std::string first,  std::string middle, std::string last, int numberOfNames); //defined below
        std::string getFullName(); //defined below

        void setAmountPaid(double amount){amountPaid = amount;}
        double getAmountPaid(){return amountPaid;}

        void setAmountOwed(double amount){amountOwed = amount;}
        double getAmountOwed(){return amountOwed;}

        void setAmountTransacted(double amount){amountTransacted = amount;}
        double getAmountTransacted(){return amountTransacted;}

        std::vector<FriendPaymentProfile>& getTransactioncounterparties(){return transactionCounterparties;}
        void updateTransactionCounterparties(const FriendPaymentProfile& counterparty);
    
    private:
        std::string firstName;
        std::string middleInitial;
        std::string lastName;
        double amountPaid;
        double amountOwed; //(+) = owes TO others, (-) = owed FROM others
        double amountTransacted;
        std::vector <FriendPaymentProfile> transactionCounterparties;
};

//OTHER FUNCTION DECLARATIONS NOT BELONGING TO A CLASS ----------------------------------------------------------------------------

//connects to file and opens it
void openFile(std::ifstream& inFile);

//reads in a file, parses the name and the amount (assumes amount is first), and adds every line item as a node in a linkedList called groupExpenseBook
void initializePaymentProfiles(std::ifstream& file, LList<FriendPaymentProfile>& groupExpenseBook);

//iterates groupExpenseBook to determine the evenly distributed value for each person returning an int value
double getEvenlyDividedCost(LList<FriendPaymentProfile>& groupExpenseBook, int groupSize);

//pulls in evenly divided cost and applies that value to "amount owed" accordingly (amount owed value will vary depending on over/under payment)
void updateAmountOwed(LList<FriendPaymentProfile>& groupExpenseBook,int groupSize, double evenlyDividedCost);

//iterates in nested loop to determine who needs money and who can give money. Anyone who is a giver will have their transactionCounterparties vector updated. Receivers do not have transactionCounterparties because the example in the instructions only showed "give instructions". All receivers will get the statement "does not need to do anything"
void redistributeExpenses(LList<FriendPaymentProfile>& groupExpenseBook, int groupSize);

//print! only prints transaction counterparties if there is at least 1 counterparty, and only prints amount owed if it is not $0.00
void printGroupExpenseBook(LList<FriendPaymentProfile>& groupExpenseBook, int groupSize); 

//LLIST Additional Function Definitions -----------------------------------------------------------------------------------

//function we were given
template <class T> int LList<T>::size()const{
    int count = 0;
    LLNode<T> * temp = head;
    while(temp != nullptr){
        count++;
        temp = temp-> next;
    }
    return count;
}

template <class T> void LList<T>::insertAtEnd(T newData){
    if(isEmpty()){
        head = new LLNode<T>(newData);
        return;
    }
    LLNode<T> * node = head;
    while(node->getNodeNext() != nullptr){
        node = node -> getNodeNext();
    }
    node->setNodeNext(new LLNode<T>(newData));
}

//FRIENDPAYMENTPROFILE Additional Function Definitions ---------------------------------------------------------------------------

//constructor
FriendPaymentProfile::FriendPaymentProfile(): firstName(""), middleInitial(""), lastName(""),amountPaid(0.00), amountOwed(0.00), amountTransacted(0.00), transactionCounterparties(){
    //intentionally blank    
}
//copy constructor
FriendPaymentProfile::FriendPaymentProfile(const FriendPaymentProfile &old){
        firstName =                 old.firstName;
        middleInitial =             old.middleInitial;
        lastName =                  old.lastName;
        amountPaid =                old.amountPaid;
        amountOwed =                old.amountOwed;
        amountTransacted =          old.amountTransacted;
} 

//overloaded assignment opperator
FriendPaymentProfile& FriendPaymentProfile::operator=(FriendPaymentProfile groupMember){
    if(this != &groupMember){
        firstName =                 groupMember.firstName;
        middleInitial =             groupMember.middleInitial;
        lastName =                  groupMember.lastName;
        amountPaid =                groupMember.amountPaid;
        amountOwed =                groupMember.amountOwed;
    } 
    return *this;
}

//when this function is called we already know the number of names. This function is primarily so we can dictate how many spaces are needed in FullName when it prints
void FriendPaymentProfile::setFullName(std::string first,  std::string middle, std::string last, int numberOfNames){

    switch(numberOfNames){
        case 1:
            firstName = first;
            middleInitial = "";
            lastName = "";
            break;
        case 2:
            firstName = first;
            middleInitial = "";
            lastName = last;
            break;
        case 3:
            firstName = first;
            middleInitial = middle;
            lastName = last;
            break;
    }
        
}

std::string FriendPaymentProfile::getFullName(){
    std::string fullName;
    fullName = firstName; //if there is just 1 name, then the full name is just first name

    //if middle name has something in it, then this must be a 3+ name 
    if(middleInitial.size() > 0){
        fullName = firstName + " " + middleInitial + " " + lastName;

    //otherwise its a 2 name person (first name, last name)
    }else if(middleInitial.size() == 0 && lastName.size() > 0){
        fullName = firstName + " " + lastName;
    }
    return fullName;
}

//adds a friendPaymentProfile to the counterparties list
void FriendPaymentProfile::updateTransactionCounterparties(const FriendPaymentProfile& counterparty){
    transactionCounterparties.push_back(counterparty);

}

//OTHER FUNCTIONS NOT BELONGING TO CLASSES Definitions ---------------------------------------------------------------------------

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


//reads in each line, parses name and amount, and adds the data into LList called groupExpenseBook
void initializePaymentProfiles(std::ifstream& file, LList<FriendPaymentProfile>& groupExpenseBook){
    std::string personData;

    while(getline(file, personData)){ //as long as there are lines to read in
        FriendPaymentProfile friendData;

        std::string  first;
        std::string middle;
        std::string last;
        double amount;

        //finding amount
        int space = personData.find(" ");

        //stod is "string to double"
        amount = stod(personData.substr(0,space));
        friendData.setAmountPaid(amount);

        //resets the rest of the line to what will contain just the name
        personData = personData.substr(space + 1,personData.size());
        int numberOfNames = 1;

        //iterates every character and counts the  spaces for how many names there are
        for(int i = 0; i < personData.size(); i++){
            if(personData[i] == ' '){
                numberOfNames++;
            }
        }

        //assigning the names
        if(numberOfNames == 1){
            //set first name to the rest of the string
            first = personData.substr(0, personData.size());
            friendData.setFullName(first, middle, last, 1);

        }else if(numberOfNames == 2){
            //set first name to the rest of the string until the first space
            space = personData.find(" ");
            first = personData.substr(0, space);
            //set last name to the rest of the string, starting from space
            last = personData.substr(space + 1, personData.size());
            friendData.setFullName(first, middle, last, 2);

        }else{ //if there are 3+ names
            //set first name to the rest of the string until the first space
            space = personData.find(" ");
            first = personData.substr(0, space);
            personData = personData.substr(space + 1, personData.size());
            middle  = personData[0];
            space = personData.find(" ");
            last = personData.substr(space + 1, personData.size());
            friendData.setFullName(first, middle, last, 3);

        }
        groupExpenseBook.insertAtEnd(friendData);
    }
}

double getEvenlyDividedCost(LList<FriendPaymentProfile>& groupExpenseBook, int groupSize){
    double totalGroupExpenditure = 0.00;

    LLNode<FriendPaymentProfile> * node = groupExpenseBook.getHead();

    //iterates the linked list and adds up total expenditures
    while(node != nullptr){
        totalGroupExpenditure = (node->getNodeData().getAmountPaid()) + totalGroupExpenditure;
        node = node->getNodeNext();
    }

    double evenlyDividedCost = totalGroupExpenditure/(double)groupSize;

    delete node;
    node = NULL;

    return evenlyDividedCost; 

}


void updateAmountOwed(LList<FriendPaymentProfile>& groupExpenseBook, int groupSize, double evenlyDividedCost){

    LLNode<FriendPaymentProfile> * node = groupExpenseBook.getHead();

    //iterates linked list and sets the amountOwed to the amount needed. 
    while(node != nullptr){
        double amountOwed = 0.00;
        amountOwed = evenlyDividedCost - (node->getNodeData().getAmountPaid());
        node->getNodeData().setAmountOwed(amountOwed);
        node = node->getNodeNext();
    }

    delete node;
    node = NULL;
}


void redistributeExpenses(LList<FriendPaymentProfile>& groupExpenseBook, int groupSize){
    //in the nested loop the process is the same for every if/else:

        //is i a giver or receiver
        //is j a giver or receiver
        //givers get their transactionCounterparty list updated
        //goes into their transactionCounterparty list and updates the counterparties "amountTransacted"
        //updates i and/or j's amounts accordingly 

    LLNode<FriendPaymentProfile> * iNode = groupExpenseBook.getHead();

    while(iNode != nullptr){
        //allows the jNode to reset after each i loop
        LLNode<FriendPaymentProfile> * jNode = groupExpenseBook.getHead();

        while(jNode != nullptr){
            if(iNode == jNode){
                //do nothing, skip
            }else{
                //this half is when i is a RECEIVER
                if(iNode->getNodeData().getAmountOwed() < 0.0){ //i is a RECEIVER

                    if(jNode->getNodeData().getAmountOwed() <= 0.0){ //j is also a RECEIVER or i is already zeroed out
                        //do nothing, skip

                    }else{ //j is a GIVER
                        if(-(iNode->getNodeData().getAmountOwed()) < jNode->getNodeData().getAmountOwed()){//j needs to give more than  receiver needs
                            //add i to j's transaction counterparty list (only givers have their counterparty list updated)
                            jNode->getNodeData().updateTransactionCounterparties(iNode->getNodeData());

                            //goes into j's transaction counterparty list and update's counterparty i's amount transacted 
                            //the index of getTransactionCounterparties() is the size of the vector 
                            jNode->getNodeData().getTransactioncounterparties()[jNode->getNodeData().getTransactioncounterparties().size() - 1].setAmountTransacted((iNode->getNodeData().getAmountOwed()) * -1);

                            //update j's amount owed
                            jNode->getNodeData().setAmountOwed(jNode->getNodeData().getAmountOwed() + iNode->getNodeData().getAmountOwed());

                            //update i's amount owed
                            iNode->getNodeData().setAmountOwed(0.0);

                        }else if(-(iNode->getNodeData().getAmountOwed()) > jNode->getNodeData().getAmountOwed()){ //j has only some of what the receiver needs
                            jNode->getNodeData().updateTransactionCounterparties(iNode->getNodeData());

                            jNode->getNodeData().getTransactioncounterparties()[jNode->getNodeData().getTransactioncounterparties().size() - 1].setAmountTransacted(jNode->getNodeData().getAmountOwed());

                            iNode->getNodeData().setAmountOwed(iNode->getNodeData().getAmountOwed() + jNode->getNodeData().getAmountOwed());

                            jNode->getNodeData().setAmountOwed(0.0);

                        }else{ //(i receives the exact amount j has)
                            jNode->getNodeData().updateTransactionCounterparties(iNode->getNodeData());


                            jNode->getNodeData().getTransactioncounterparties()[jNode->getNodeData().getTransactioncounterparties().size() - 1].setAmountTransacted(jNode->getNodeData().getAmountOwed());
                        
                            iNode->getNodeData().setAmountOwed(0.0);

                            jNode->getNodeData().setAmountOwed(0.0);
                        }
                    }

                //this half is when i is a GIVER
                }else if(iNode->getNodeData().getAmountOwed() > 0.0){ //i is is a GIVER

                    if(jNode->getNodeData().getAmountOwed() >= 0.0){ //j is also a GIVER or i is already zeroed out
                        //do nothing, skip

                    }else{ //j is a RECEIVER
                        if(-(jNode->getNodeData().getAmountOwed()) < iNode->getNodeData().getAmountOwed()){ //i (giver) has more than the receiver (j) needs
                            iNode->getNodeData().updateTransactionCounterparties(jNode->getNodeData());
                            iNode->getNodeData().getTransactioncounterparties()[iNode->getNodeData().getTransactioncounterparties().size()- 1].setAmountTransacted(jNode->getNodeData().getAmountOwed()* -1);

                            iNode->getNodeData().setAmountOwed(iNode->getNodeData().getAmountOwed() + jNode->getNodeData().getAmountOwed());

                            jNode->getNodeData().setAmountOwed(0.0);

                        }else if(-(jNode->getNodeData().getAmountOwed()) > iNode->getNodeData().getAmountOwed()){  // j(receiver) need more than the giver (i) has
                            iNode->getNodeData().updateTransactionCounterparties(jNode->getNodeData());

                            iNode->getNodeData().getTransactioncounterparties()[iNode->getNodeData().getTransactioncounterparties().size() - 1].setAmountTransacted(iNode->getNodeData().getAmountOwed());

                            jNode->getNodeData().setAmountOwed(jNode->getNodeData().getAmountOwed() + iNode->getNodeData().getAmountOwed());

                            iNode->getNodeData().setAmountOwed(0.0);
                        }else{ //(i receives the exact amount j has)
                            iNode->getNodeData().updateTransactionCounterparties(jNode->getNodeData());

                            iNode->getNodeData().getTransactioncounterparties()[iNode->getNodeData().getTransactioncounterparties().size() - 1].setAmountTransacted(iNode->getNodeData().getAmountOwed());

                            iNode->getNodeData().setAmountOwed(0.0);

                            jNode->getNodeData().setAmountOwed(0.0);
                        }
                    }
                }else{ //if i == 0, i has already been reconciled
                    //do nothing, skip
                }
            }
            //goes to next node
            jNode = jNode->getNodeNext();
        }
        //goes to next node
        iNode = iNode->getNodeNext();
    }
}

void printGroupExpenseBook(LList<FriendPaymentProfile>& groupExpenseBook, int groupSize){
    
    LLNode<FriendPaymentProfile> * node = groupExpenseBook.getHead();

    std::cout << "{" << std::endl;
    while(node != nullptr){
        std::cout <<  "\tName: " << node->getNodeData().getFullName() << std::endl;
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        std::cout << "\tAmount Paid: $" << node->getNodeData().getAmountPaid() << std::endl;
        if(node->getNodeData().getAmountOwed() != 0.0){
            //this line prevents -0.0 or 0.0 amount owed from printing due to set precision hiding the fact that the decimal value is minisculely small 
            if((node->getNodeData().getAmountOwed() > 0.0 && node->getNodeData().getAmountOwed() < 0.01) || (node->getNodeData().getAmountOwed() <0.0 && node->getNodeData().getAmountOwed() > -0.01)){
                //do nothing
            }else{
                std::cout << "\tAmount Owed: $" << node->getNodeData().getAmountOwed() << std::endl; 
            }
        }

        //if there is at least 1 element in transactionCounterparty vector, then prints #of transaction counterparties and who they are and how much is owed
        if(node->getNodeData().getTransactioncounterparties().size()> 0){
            std::cout << "\t" << node->getNodeData().getTransactioncounterparties().size() << " Transaction Counterparties: " << std::endl;

            //since transaction counterparties is a vector we can use a for loop to print them all out
            for(int j = 0; j < node->getNodeData().getTransactioncounterparties().size(); j++){
                std::cout << "\t\t--> Give $" << node->getNodeData().getTransactioncounterparties()[j].getAmountTransacted() << " to " << node->getNodeData().getTransactioncounterparties()[j].getFullName() << std::endl;
            }
        }else{
            if(node->getNodeData().getAmountOwed() == 0.0){
                std::cout << "\t\t--> Doesn't need to give anyone anything "<< std::endl;
            }else if((node->getNodeData().getAmountOwed() > 0.0 && node->getNodeData().getAmountOwed() < 0.01) || (node->getNodeData().getAmountOwed() <0.0 && node->getNodeData().getAmountOwed() > -0.01)){
                std::cout << "\t\t--> Doesn't need to give anyone anything "<< std::endl;
            }
        }
        //goes to next node
        node = node->getNodeNext();
        std::cout << std::endl;
    }
    std::cout <<  "}" << std::endl;

    delete node;
    node = NULL;
   
}

//MAIN ------------------------------------------------------------------------------------------------------------------------

int main(){

    LList<FriendPaymentProfile> groupExpenseBook;
    double dividedCost = 0.0;

    std::ifstream inputFile;
    openFile(inputFile);

    initializePaymentProfiles(inputFile, groupExpenseBook);
    dividedCost = getEvenlyDividedCost(groupExpenseBook, groupExpenseBook.size());
    updateAmountOwed(groupExpenseBook, groupExpenseBook.size(), dividedCost);
    
    std::cout << std::endl;
    std::cout << "STARTING BALANCES: " << std::endl;
    printGroupExpenseBook(groupExpenseBook, groupExpenseBook.size());

    redistributeExpenses(groupExpenseBook, groupExpenseBook.size());

    std::cout << "REDISTRIBUTION OF FUNDS: " << std::endl;
    printGroupExpenseBook(groupExpenseBook, groupExpenseBook.size());

    std::cout << std::endl;
    std::cout << "In the end, everyone will have spent $" << dividedCost << "!" << std::endl << std::endl;

    return 0;
}

