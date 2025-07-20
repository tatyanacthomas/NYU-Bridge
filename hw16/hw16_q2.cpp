#include <iostream>
#include <fstream>

template<class T> class Stack; //forward declaration for Stack

//QUEUE DECLARATIONS ------------------------------------------------------------------------------------------------
template <class T> class Queue{
    public:
        //constructor
        Queue(); //defined below

        //assignment operator
        Queue& operator=(Queue queueName); //defined below

        //copy constructor
        Queue(const Queue& old){currentStart = old.currentStart; originalStart = old.originalStart;}

        //destructor - simply calls clear function
        //will clear from the original queue start
        virtual ~Queue(){clear(); std::cout << "Queue destructor called" << std::endl;}

        void push(T newItem); //defined below

        void pop(); //defined below

        int top(){return currentStart;}

        void clear(); //defined below

        //refers to if the active vector is empty, not the whole vector is empty
        bool isEmpty(){return size() == 0;}

        int size(); //defined below 

        int capacity(){return maxSize;} //defined below

        void printQueue(); //defined below

        void printSize(); //defined below

        void printCapacity(); //defined below

        std::vector<T> getVectorQueue(){return vectorQueue;}

    private:
        std::vector<T> vectorQueue;
        int currentStart;
        int originalStart; 
        int maxSize; //total amount of space the vector takes up as it pushes/pops
};

//OTHER FUNCTIONS Not associated with classes Declarations --------------------------------------------------------------

void openFile(std::ifstream& inFile);

//brings in a file of integers and pushes them into a queue
void ingestData(std::ifstream& inFile, Queue<int>& intQueue);


//QUEUE Additional Function Definitions --------------------------------------------------------------------------------
//constructor
template <class T> Queue<T>::Queue(): currentStart(0), originalStart(0){
    //intentionally blank
};

//overloaded assignment operator
template <class T>  Queue<T>& Queue<T>::operator=(Queue<T> queueName){
    vectorQueue = queueName.vectorQueue;
    currentStart = queueName.currentStart;
    originalStart = queueName.currentStart;
    
    return *this;
    
}

//clears out the queue including items that were already "popped" out (always still there but simply inaccessible)
template <class T> void Queue<T>::clear(){
   vectorQueue.clear();
   maxSize = 0;
   currentStart = 0;

} 

//for every item that is pushed, the total amount of space the vector takes (maxSize) is incremented
template <class T> void Queue<T>::push(T newItem){
    vectorQueue.push_back(newItem);
    maxSize++;
}


template <class T> void Queue<T>::pop(){
    //not actually deleting anything, just making it inaccessible by adjusting the current start
    if(size() > 0){
        currentStart = currentStart + 1;
        //if moving currentStart makes the size now equal to 0, then clear the queue
        if(size() ==0){
            clear();
        }
    }
}

template<class T> int Queue<T>::size(){
    if(vectorQueue.size() == 0){
        return 0;
    }else{
        //.size() in this case is NOT recursive, it is referring to the .size() from the vector class
        int size = vectorQueue.size() - currentStart;
        return size;
    }
    
}

//prints only the active items in the vector (logical queue items)
template<class T> void Queue<T>::printQueue(){
    for(int i = currentStart; i < vectorQueue.size(); i++){
        std::cout << vectorQueue[i] << std::endl;
    }
    std::cout << std::endl;
}

//prints active vector size (logical size)
template <class T> void Queue<T>::printSize(){  
    std::cout << size() << std::endl;
}

//prints how much space the queue is taking up (physical size)
template <class T> void Queue<T>::printCapacity(){
    std::cout << capacity() << std::endl;
}

//MAIN -----------------------------------------------------------------------------------------------------------------
int main(){

    Queue<int> * newQueue = new Queue <int>;

    newQueue->push(5);
    newQueue->push(3);
    newQueue->push(9);
    newQueue->push(2);
    newQueue->push(8);
    newQueue->push(12);
    newQueue->push(1);

    std::cout << "currentStart is: " << newQueue->top() << std::endl;
    std::cout << "size is " << newQueue->size() << std::endl;;
    newQueue->printQueue();
    
    newQueue->pop();
    newQueue->pop();

    std::cout << "currentStart is: " << newQueue->top() << std::endl;
    std::cout << "size is " << newQueue->size() << std::endl;;
    newQueue->printQueue();


    delete newQueue;
    newQueue = NULL;

    return 0;
}
