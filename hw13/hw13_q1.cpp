#include <iostream>
#include <cstdlib>
#include <ctime>
//file to upload

//Organism - Base Class
class Organism{
    public:
        //big 3
        Organism(); //default constructor
        virtual ~Organism(){}; //destructor
        Organism(const Organism &old); //copy constructor

        //GETTERS and SETTERS for class member variables
        //breedingAge
        virtual void setBreedingAge(int inBreedingAge){};
        int getBreedingAge()const {return breedingAge;}
        void updateBreedingAge(int inBreedingAge){breedingAge = inBreedingAge;}

        //speciesID
        virtual void setSpeciesID(){}; 
        int getSpeciesID() const {return speciesID;}
        void updateSpeciesID(int inSpeciesID) {speciesID = inSpeciesID;}
        int getAntID() const {return ANT_ID;}
        int getDirtID() const {return DIRT_ID;}
        int getDoodlebugID() const {return DOODLEBUG_ID;}

        //speciesMark
        virtual void setSpeciesMark(){}; 
        char getSpeciesMark() const {return speciesMark;}
        void updateSpeciesMark(int inSpeciesMark) {speciesMark = inSpeciesMark;}
        char getAntMark() const {return ANT_MARKER;}
        char getDoodlebugMark() const {return DOODLEBUG_MARKER;}
        char getDirtMark() const {return DIRT_MARKER;}

        //organismCoordinates
        virtual void setOriginalCoordinates(){}; 
        int getCoordinates() const {return organismCoordinates;}
        void updateCoordinates(int inOrganismCoordinates) {organismCoordinates = inOrganismCoordinates;}

        //isMoved
        virtual void setMovedFlag(){}; 
        bool getMovedFlag() const {return isMoved;}
        void updateMovedFlag(bool inIsMoved) {isMoved = inIsMoved;}

        //age
        virtual void setAge(){}; 
        int getAge() const {return age;}
        void updateAge(int inAge) {age = inAge;}

        //operators
        Organism& operator=(Organism o);

        //OTHER class member functions
        int setMoveDirection();
        int setBreedLocation(int arrSize);
        virtual void move(Organism* ecosystem[], int direction){};
        //will be overriden in derived classes
        virtual void breed(Organism* ecosystem[]){};     
        //will be overriden in derived classes
        virtual void starve(Organism* ecosystem[]){}; 
        //will be overriden in derived class

    private:
        int breedingAge;
        int speciesID;
        char speciesMark;
        const int DIRT_ID = 100;
        const int DOODLEBUG_ID = 200;
        const int ANT_ID = 300;
        const char DIRT_MARKER = '-';
        const char DOODLEBUG_MARKER = 'X';
        const char ANT_MARKER = 'o';
        int organismCoordinates;
        bool isMoved;
        int age;
};

Organism::Organism(): breedingAge(0), speciesID(0), speciesMark(0), organismCoordinates(0), isMoved(false), age(0){
    //set all to 0 --> will be replaced with appropriate values in derived classes
    
}

Organism::Organism(const Organism &old){
        breedingAge =           old.breedingAge;
        speciesID =             old.speciesID;
        speciesMark =           old.speciesMark;
        organismCoordinates =   old.organismCoordinates;
        isMoved =               old.isMoved;
        age =                   old.age;
} 

Organism& Organism::operator=(Organism o){
    if(this != &o){
        breedingAge =           o.breedingAge;
        speciesID =             o.speciesID;
        speciesMark =           o.speciesMark;
        organismCoordinates =   o.organismCoordinates;
        isMoved =               o.isMoved;
        age =                   o.age;
    }
    return *this;
}

int Organism::setMoveDirection(){
    //picks number 1-4 for up/down/left/right switch statement that determines move direction
    int direction = 0;
    direction = (rand() % 4) + 1;
    return direction;
}

int Organism::setBreedLocation(int arrSize){
    //picks number between 0 and arrSize (array containing the availble unoccupied spots)
    //the selected number will be used in the breed() function to calculate the new organisms location
    int location = 0;
    location = (rand() %  arrSize);
    return location;

}

//------------------------------------------
//Dirt - Derived Class
class Dirt : public Organism {
    public:

    //big 3
    Dirt(); //default constructor
    virtual ~Dirt(){}; //destructor
    Dirt(const Dirt &old); //copy constructor


    //GETTERS and SETTERS for class member variables
    //breedingAge
    virtual void setBreedingAge(int inBreedingAge){updateBreedingAge(inBreedingAge);}

    //speciesID
    virtual void setSpeciesID(){updateSpeciesID(getDirtID());}

    //speciesMark
    virtual void setSpeciesMark(){updateSpeciesMark(getDirtMark());}

    //organismCoordinates
    virtual void setOriginalCoordinates();

    //isMoved
    virtual void setMovedFlag(){updateMovedFlag(getMovedFlag());}

    //age
    virtual void setAge(){updateAge(getAge());}

    private: 
        //no other member variables

};

Dirt::Dirt(){
    this->setBreedingAge(0); 
    this->setSpeciesID();
    this->setSpeciesMark();
    this->updateCoordinates(0);
    this->setMovedFlag();
    this->setAge();
}

Dirt::Dirt(const Dirt &old){
        this->setBreedingAge(old.getBreedingAge());
        this->setSpeciesID();
        this->setSpeciesMark();
        this->updateCoordinates(old.getCoordinates());
        this->setMovedFlag();
        this->setAge();
} 

void Dirt::setOriginalCoordinates(){
    //this function isnt used in this implementation, but since it is a virtual function, it is declared here
    int coordinate = 0;
    coordinate = (rand() % 399);
    this->updateCoordinates(coordinate);
}

//------------------------------------------
//Doodlebug - Derived Class
class Doodlebug : public Organism {
    public:

    //big 3
    Doodlebug(); //default constructor
    virtual ~Doodlebug(){}; //destructor
    Doodlebug(Doodlebug &old); //copy constructor


    //GETTERS and SETTERS for class member variables
    //starvingAge 
    void setStarvingAge(int starveAge){starvingAge = starveAge;} 
    int getStarvingAge(){return starvingAge;}

    //daysOfHunger
    void setDaysOfHunger(int inHungerDays){daysOfHunger = inHungerDays;} 
    int getDaysOfHunger(){return daysOfHunger;}

    //breedingAge
    virtual void setBreedingAge(int inBreedingAge){updateBreedingAge(inBreedingAge);}
    int getDoodleBreedingAge() const {return DOODLE_BREED_AGE;}

    //speciesID
    virtual void setSpeciesID(){updateSpeciesID(getDoodlebugID());}

    //speciesMark
    virtual void setSpeciesMark(){updateSpeciesMark(getDoodlebugMark());}

    //organismCoordinates
    virtual void setOriginalCoordinates();

    //isMoved
    virtual void setMovedFlag(){updateMovedFlag(getMovedFlag());}

    //age
    virtual void setAge(){updateAge(getAge());}
    

    //operators
    Doodlebug& operator=(const Doodlebug& d);


    //OTHER class member functions
    virtual void move(Organism* ecosystem[], int direction);
    virtual void breed(Organism* ecosystem[]);
    virtual void starve(Organism* ecosystem[]);

    private: 
        int starvingAge = 3;
        int daysOfHunger;
        const int DOODLE_BREED_AGE = 8;


};
//default constructor
Doodlebug::Doodlebug(): starvingAge(getStarvingAge()), daysOfHunger(0){
    this->setBreedingAge(getDoodleBreedingAge()); 
    this->setSpeciesID();
    this->setSpeciesMark();
    this->updateCoordinates(0);
    this->setMovedFlag();
    this->setAge();

}

//copy constructor
Doodlebug::Doodlebug(Doodlebug &old){
        this->setBreedingAge(old.getBreedingAge());
        this->setSpeciesID();
        this->setSpeciesMark();
        this->updateCoordinates(old.getCoordinates());
        this->setMovedFlag();
        this->setAge();
        this->setDaysOfHunger(old.getDaysOfHunger());
} 

//assignement operator
Doodlebug& Doodlebug::operator=(const Doodlebug& d){
    Organism::operator=(d);
    return *this;
}


void Doodlebug::setOriginalCoordinates(){
    int coordinate = 0;
    coordinate = (rand() % 399); 
    this->updateCoordinates(coordinate);
}

void Doodlebug::move(Organism* ecosystem[], int direction){
    //fxmove
    int oldCoordinates = this->getCoordinates();
    int newCoordinates = this->getCoordinates(); //will be udpated in each case
    bool offBoardFlag = false;

    //setting the new coordinates
    switch(direction){        
        case 1: //up
            newCoordinates = oldCoordinates - 20;
            if(newCoordinates < 0){
                offBoardFlag = true;
            }
            break;

        case 2: //down
            newCoordinates = oldCoordinates + 20; 
            if(newCoordinates>399){
                offBoardFlag = true;
            }
            break;

        case 3: //left
            newCoordinates = oldCoordinates - 1;
            if(oldCoordinates % 20 == 0){
                offBoardFlag = true;
            }
            break;

        case 4: //right
            newCoordinates = oldCoordinates + 1;
            if(oldCoordinates % 20 == 19){
                offBoardFlag = true;
            }
            break;
    }

    if(offBoardFlag == true){ //if doodle would end up off the board, don't move
        //do nothing
        this->setDaysOfHunger(daysOfHunger + 1);
    }else if(ecosystem[newCoordinates]->getSpeciesID() == 200){ //if the new location contains a doodle, don't move
        //do nothing
        this->setDaysOfHunger(daysOfHunger + 1);
    }else{
        if(this->getMovedFlag() == false){ //if the doodle under review is one that recently moved to this location

            if(ecosystem[newCoordinates]->getSpeciesID() == 100){ //if it lands on dirt, increment hunger count
                this->setDaysOfHunger(daysOfHunger + 1);

                if(daysOfHunger > 3){ //if hunger exceeds 3 timesteps, die  
                    this->starve(ecosystem);
                }

            }else{ //otherwise hunger is satiated and hunger countdown restarts
                this->setDaysOfHunger(0);
            }

            //move the doodle
            this->updateCoordinates(newCoordinates);
            this->updateMovedFlag(true);
            ecosystem[newCoordinates] = this;

            //putting dirt in the old location
            Dirt * babyDirt = new Dirt;
            babyDirt->updateCoordinates(oldCoordinates);
            ecosystem[oldCoordinates] = babyDirt;

        } //else do nothing
    }

}


void Doodlebug::breed(Organism* ecosystem[]){
    //fxbreed
    int doodleCoordinates = this->getCoordinates();
    int breedingCoordinates = this->getCoordinates(); //will be updated in the switch statement
    bool offBoardFlag = false;
    int breedLocationsArr[4]; //4 potential locations to breed
    int arrIndex = 0;

    //will go through 4 possibilities and store a potential location in an array to pick a random element from later to breed in
    for(int i = 1; i <= 4; i++){
        switch(i){
            case 1: //up
                breedingCoordinates = doodleCoordinates - 20;
                if(breedingCoordinates < 0){
                    //do not add to breedLocationsArr, Off Board Location
                }else if(ecosystem[breedingCoordinates]->getSpeciesID() != 100){ 
                    //do not add to breedLocationsArr, Already Occupied
                }else{
                    breedLocationsArr[arrIndex] = breedingCoordinates;
                    arrIndex++;
                }
                break;
            case 2: //down
                breedingCoordinates = doodleCoordinates + 20;
                if(breedingCoordinates>399){
                    //do not add to breedLocationsArr, Off Board Location
                }else if(ecosystem[breedingCoordinates]->getSpeciesID() != 100){ 
                    //do not add to breedLocationsArr, Already Occupied
                }else{
                    breedLocationsArr[arrIndex] = breedingCoordinates;
                    arrIndex++;
                }
                break;
            case 3: //left
                breedingCoordinates = doodleCoordinates - 1;
                if(doodleCoordinates % 20 == 0){
                    //do not add to breedLocationsArr, Off Board Location
                }else if(ecosystem[breedingCoordinates]->getSpeciesID() != 100){ 
                    //do not add to breedLocationsArr, Already Occupied
                }else{
                    breedLocationsArr[arrIndex] = breedingCoordinates;
                    arrIndex++;
                }
                break;
            case 4: //right
                breedingCoordinates = doodleCoordinates + 1;
                if(doodleCoordinates % 20 == 19){
                    //do not add to breedLocationsArr, Off Board Location
                }else if(ecosystem[breedingCoordinates]->getSpeciesID() != 100){ 
                    //do not add to breedLocationsArr, Already Occupied
                }else{
    
                    breedLocationsArr[arrIndex] = breedingCoordinates;
                    arrIndex++;
                }
            }
        }
        if(arrIndex>0){
            int breedDirection = setBreedLocation(arrIndex);
            breedingCoordinates = breedLocationsArr[breedDirection];

            Doodlebug * babyDoodle = new Doodlebug;
            babyDoodle->updateCoordinates(breedingCoordinates);
            ecosystem[breedingCoordinates] = babyDoodle;
            this->updateAge(0);

        }
        arrIndex = 0;
}


void Doodlebug::starve(Organism* ecosystem[]){
    //put dirt in place of where a doodle that has exceeded its hunger limit once lived
    if(daysOfHunger > 3){
        Dirt * babyDirt = new Dirt;
        babyDirt->updateCoordinates(this->getCoordinates());
        ecosystem[this->getCoordinates()] = babyDirt;
    }
}


//------------------------------------------
//Ant - Derived Class
class Ant : public Organism {
    public:

    //big 3
    Ant(); //default constructor
    virtual ~Ant(){}; //destructor
    Ant(const Ant &old); //copy constructor


    //GETTERS and SETTERS for class member variables
    //breedingAge
    virtual void setBreedingAge(int inBreedingAge){updateBreedingAge(inBreedingAge);}
    int getAntBreedingAge() const {return ANT_BREED_AGE;}

    //speciesID
    virtual void setSpeciesID(){updateSpeciesID(getAntID());}

    //speciesMark
    virtual void setSpeciesMark(){updateSpeciesMark(getAntMark());}

    //organismCoordinates
    virtual void setOriginalCoordinates();

    //isMoved
    virtual void setMovedFlag(){updateMovedFlag(getMovedFlag());}

    //age
    virtual void setAge(){updateAge(getAge());}

    //operators
    Ant& operator=(const Ant& a);

    //OTHER class member functions
    virtual void move(Organism* ecosystem[], int direction);
    virtual void breed(Organism* ecosystem[]);

    private: 
        const int ANT_BREED_AGE = 3;
};

//default constructor
Ant::Ant(){
    this->setBreedingAge(getAntBreedingAge()); 
    this->setSpeciesID();
    this->setSpeciesMark();
    this->updateCoordinates(0);
    this->setMovedFlag();
    this->setAge();
}

//copy constructor
Ant::Ant(const Ant &old){
        this->setBreedingAge(old.getBreedingAge());
        this->setSpeciesID();
        this->setSpeciesMark();
        this->updateCoordinates(old.getCoordinates());
        this->setMovedFlag();
        this->setAge();
} 

//assignment operator
Ant& Ant::operator=(const Ant& a){
    Organism::operator=(a);
    return *this;
}


void Ant::setOriginalCoordinates(){
    //picks number 0-399 for ant to be created in at first
    int coordinate = 0;
    coordinate = (rand() % 399);
    this->updateCoordinates(coordinate);
}

void Ant::move(Organism* ecosystem[], int direction){
    //fxmove
    int oldCoordinates = this->getCoordinates(); 
    int newCoordinates = this->getCoordinates(); //will be udpated in each case
    bool offBoardFlag = false;

    switch(direction){        
        case 1: //up
            newCoordinates = oldCoordinates - 20;
            if(newCoordinates < 0){
                offBoardFlag = true;
            }
            break;

        case 2: //down
            newCoordinates = oldCoordinates + 20;
            if(newCoordinates>399){
                offBoardFlag = true;
            }
            break;

        case 3: //left
            newCoordinates = oldCoordinates - 1;
            if(oldCoordinates % 20 == 0){
                offBoardFlag = true;
            }
            break;

        case 4: //right
            newCoordinates = oldCoordinates + 1;
            if(oldCoordinates % 20 == 19){
                offBoardFlag = true;
            }
            break;
    }
    if(offBoardFlag == true){
        //do nothing
    }else if(ecosystem[newCoordinates]->getSpeciesID() == 200 || ecosystem[newCoordinates]->getSpeciesID() == 300){
            //do nothing
    }else{
        if(this->getMovedFlag() == false){
            //move the ant
            this->updateCoordinates(newCoordinates);
            this->updateMovedFlag(true);
            ecosystem[newCoordinates] = this;

            //putting dirt in the old location
            Dirt * babyDirt = new Dirt;
            babyDirt->updateCoordinates(oldCoordinates);
            ecosystem[oldCoordinates] = babyDirt;

        } //else do nothing
    }
}

void Ant::breed(Organism* ecosystem[]){
    //fxbreed
    int antCoordinates = this->getCoordinates();
    int breedingCoordinates = this->getCoordinates(); //will be updated in the switch statement
    bool offBoardFlag = false;
    int breedLocationsArr[4]; //4 potential locations to breed
    int arrIndex = 0;


    for(int i = 1; i <= 4; i++){
        switch(i){
            case 1: //up
                breedingCoordinates = antCoordinates - 20;
                if(breedingCoordinates < 0){
                    //do not add to breedLocationsArr, Off Board Location
                }else if(ecosystem[breedingCoordinates]->getSpeciesID() != 100){ 
                    //do not add to breedLocationsArr, Already Occupied
                }else{
                    breedLocationsArr[arrIndex] = breedingCoordinates;
                    arrIndex++;
                }
                break;
            case 2: //down
                breedingCoordinates = antCoordinates + 20;
                if(breedingCoordinates>399){
                    //do not add to breedLocationsArr, Off Board Location
                }else if(ecosystem[breedingCoordinates]->getSpeciesID() != 100){ 
                    //do not add to breedLocationsArr, Already Occupied
                }else{
                    breedLocationsArr[arrIndex] = breedingCoordinates;
                    arrIndex++;
                }
                break;
            case 3: //left
                breedingCoordinates = antCoordinates - 1;
                if(antCoordinates % 20 == 0){
                    //do not add to breedLocationsArr, Off Board Location
                }else if(ecosystem[breedingCoordinates]->getSpeciesID() != 100){ 
                    //do not add to breedLocationsArr, Already Occupied
                }else{
                    breedLocationsArr[arrIndex] = breedingCoordinates;
                    arrIndex++;
                }
                break;
            case 4: //right
                breedingCoordinates = antCoordinates + 1;
                if(antCoordinates % 20 == 19){
                    //do not add to breedLocationsArr, Off Board Location
                }else if(ecosystem[breedingCoordinates]->getSpeciesID() != 100){ 
                    //do not add to breedLocationsArr, Already Occupied
                }else{
                    breedLocationsArr[arrIndex] = breedingCoordinates;
                    arrIndex++;
                }
            }

        }
        if(arrIndex>0){
            int breedDirection = setBreedLocation(arrIndex);
            breedingCoordinates = breedLocationsArr[breedDirection];
            Ant * babyAnt = new Ant;
            babyAnt->updateCoordinates(breedingCoordinates);
            ecosystem[breedingCoordinates] = babyAnt;
            this->updateAge(0);
        }

    arrIndex = 0;
}


//------------------------------------------
//Ecosystem - Composite class 
class Ecosystem{

    public:
        //big 3
        Ecosystem(); //default constructor
        Ecosystem(int inElementCount, int inAntCount, int inDoodlebugCount); //alt constructor 
        virtual ~Ecosystem(); //destructor
        Ecosystem(const Ecosystem &old){ecoelementCount = old.ecoelementCount;} //copy constructor 

        //GETTERS and SETTERS for class member variables
        //ecosystemBoard
        //void setEcosystemBoard(int inElementCount);
        Organism* getEcosystemBoard(){return *ecosystemBoard;}

        //ecoelementCount
        int getEcoelementCount() const {return ecoelementCount;}
        void setEcoelementCount(int inElementCount) {ecoelementCount = inElementCount;}

        //antCount
        int getAntCount() const {return antCount;}
        void setAntCount(int inAntCount) {antCount = inAntCount;}

        //doodleBugCount
        int getDoodlebugCount() const {return doodlebugCount;}
        void setDoodleBugCount(int inDoodlebugCount) {doodlebugCount = inDoodlebugCount;}

        //dirtCount
        int getDirtCount() const {return getEcoelementCount() - (getAntCount()+getDoodlebugCount());}
        void setDirtCount() {dirtCount = getEcoelementCount() - (getAntCount()+getDoodlebugCount());}

        //OTHER class member functions
        void enterTheBoard();

        void printBoard();

        void moveBoardMembers();

        void breedBoardMembers();

        void resetMovedFlag();

        void clickEnterToMove();

    private:
        int ecoelementCount;
        int antCount;
        int doodlebugCount;
        int dirtCount;  
        Organism* ecosystemBoard[400];
};

Ecosystem::Ecosystem(): ecoelementCount(0){
    //intentionally blank
}


Ecosystem::Ecosystem(int inElementCount, int inAntCount, int inDoodlebugCount): ecoelementCount(inElementCount), antCount(inAntCount), doodlebugCount(inDoodlebugCount){

    this-> setDirtCount();

    //creating a "blank" board to be filled in when the game is initialized
    for (int i = 0; i < inElementCount; i++) {
        ecosystemBoard[i] = new Organism();
    }

}

void Ecosystem::enterTheBoard(){
  
    bool foundEmpty = false;
    int housedAntCount = 0;
    int housedDoodleCount = 0;

    for(int i = 0; i <  antCount; i++){
        Ant * babyAnt = new Ant;
        babyAnt->setOriginalCoordinates();
        while(foundEmpty == false){
            //when an ant is created, it is given a random coordinate, and the below checks to see if that coordinate is empty before placing it there
            if(ecosystemBoard[babyAnt->getCoordinates()]->getSpeciesID() == 0){
                int antCoordinates = babyAnt->getCoordinates();
                delete ecosystemBoard[antCoordinates];
                ecosystemBoard[antCoordinates] = babyAnt; 
                housedAntCount++;

                foundEmpty = true;
            }else{
                //if not empty, then it sets coordinates again
                babyAnt->setOriginalCoordinates();
            }
        }
        foundEmpty = false;
    }

    foundEmpty = false;
    for(int i = 0; i <  doodlebugCount; i++){
        Doodlebug * babyDoodle = new Doodlebug;
        babyDoodle->setOriginalCoordinates();
        while(foundEmpty == false){
            //checking to see if the occupancy of randomly generated coordinates is empty
            if(ecosystemBoard[babyDoodle->getCoordinates()]->getSpeciesID() == 0){

                int doodleCoordinates = babyDoodle->getCoordinates();
                delete ecosystemBoard[doodleCoordinates];
                ecosystemBoard[babyDoodle->getCoordinates()] = babyDoodle; 
                housedDoodleCount++;

                foundEmpty = true;
            }else{
                //if not empty, generate new random coordinates
                babyDoodle->setOriginalCoordinates();
            }
        }
        foundEmpty = false;
    }
    
    for(int i = 0; i <  ecoelementCount; i++){
        Dirt * babyDirt = new Dirt;
        if(ecosystemBoard[i]->getSpeciesID() == 0){
            int dirtCoordinates = i;
            babyDirt->updateCoordinates(dirtCoordinates);
            delete ecosystemBoard[dirtCoordinates];
            ecosystemBoard[dirtCoordinates] = babyDirt;
        }
    }
};

Ecosystem::~Ecosystem(){
    std::cout << "Ecosystem destructor called";
    for (int i = 0; i < ecoelementCount; i++) {
            if(&(ecosystemBoard[i]) == nullptr){
                delete ecosystemBoard[i];
        }
    }
}

void Ecosystem::moveBoardMembers(){
        for(int i = 0; i < ecoelementCount; i++){
        if(ecosystemBoard[i]->getSpeciesID() == 200){
            //fxmove
            ecosystemBoard[i]->move(ecosystemBoard,ecosystemBoard[i]->setMoveDirection());
            if(ecosystemBoard[i]->getAge() > 8){
                ecosystemBoard[i]->updateAge(0);
            }else{
                //do nothing
            }        
            this->resetMovedFlag();
        }
    }

    for(int i = 0; i < ecoelementCount; i++){ 
    if(ecosystemBoard[i]->getSpeciesID() == 300){
        //fxmove
        ecosystemBoard[i]->move(ecosystemBoard,ecosystemBoard[i]->setMoveDirection());
        if(ecosystemBoard[i]->getAge() > 3){
            ecosystemBoard[i]->updateAge(0);
        }else{
            //do nothing
            }
        }        
        this->resetMovedFlag();
    }

}

void Ecosystem::breedBoardMembers(){
    for(int i = 0; i < ecoelementCount; i++){
        if(ecosystemBoard[i]->getSpeciesID() == 200 && ecosystemBoard[i]->getAge() == 8){
            //fxbreed
            ecosystemBoard[i]->breed(ecosystemBoard);
        }
    }

    for(int i = 0; i < ecoelementCount;i++){
        if(ecosystemBoard[i]->getSpeciesID() == 300 && ecosystemBoard[i]->getAge() == 3){
            //fxbreed
            ecosystemBoard[i]->breed(ecosystemBoard);
        }
    }
}

void Ecosystem::resetMovedFlag(){
    //update all moved flags to false after moving
    for(int i = 0; i < ecoelementCount; i++){
        ecosystemBoard[i]->updateMovedFlag(false);
    }
}

void Ecosystem::clickEnterToMove(){
    int doodleCount = 0;
    int antCount = 0;
    int dirtCount = 0; 
    bool gameEnded = false;
    int ageOfWorld = 0;

    for(int i = 0; i < ecoelementCount;i++){
        if(ecosystemBoard[i]->getSpeciesID() == 200){
            doodleCount++;
        }else if(ecosystemBoard[i]->getSpeciesID() ==  300){
            antCount++;
        }else{
            dirtCount++;;
        }
    }


    std::cout << std::endl;
    std::cout << "This world is plagued with " << doodleCount << " Doodlebugs!" << std::endl;
    std::cout << "This world is blessed with " << antCount << " Ants!" << std::endl;
    std::cout << std::endl;


    std::cout << "Click enter to move, type 'exit' to leave" << std::endl;
    std::string temp;
    std::getline(std::cin, temp);


    if(temp == "exit" || temp == "Exit" || temp == "EXIT"){
        exit(1);
    }else{
        if (doodleCount == 0){
            std::cout << "VICTORY!! Ants have reclaimed the world!" << std::endl;
            std::cout << "Thank you for playing!" << std::endl;
            exit(1);
        }else if(antCount == 0){
            std::cout << "OH NO!! Doodles have taken over the world!" << std::endl;
            std::cout << "Thank you for playing!" << std::endl;
            exit(1);
        }else{
            this->moveBoardMembers();
            for(int i = 0; i < ecoelementCount; i++){
                ecosystemBoard[i]->updateAge(ecosystemBoard[i]->getAge()+ 1);
                if(ecosystemBoard[i]->getAge()> 3 && ecosystemBoard[i]->getSpeciesID() == 300){
                    ecosystemBoard[i]->updateAge(0);
                }else if(ecosystemBoard[i]->getAge()> 8 && ecosystemBoard[i]->getSpeciesID() == 200){
                    ecosystemBoard[i]->updateAge(0);
                }
            }
            this->breedBoardMembers();
        }
    }

    this->printBoard();
}

void Ecosystem::printBoard(){ 
    int num = 0;
    for(int i= 0; i < 22 ; i++){
        std::cout << "■" << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            if(j == 0){
                std::cout << "■" << " ";
            }
            if(ecosystemBoard[num]->getSpeciesID() != 0){ 
                std::cout << (ecosystemBoard[num]->getSpeciesMark())<< " ";
            }else{
                std::cout << "# ";
            }
            num++;
        }
        std::cout << "■";
        std::cout << std::endl; 
        }
        for(int i= 0; i < 22 ; i++){
            std::cout << "■" << " ";
        }
}

int main(){ 
    int ageOfWorld = 0;

    srand((int)time(0));
    Ecosystem doodleTown(400,100,5);
    doodleTown.enterTheBoard();
    std::cout << "\t   WELCOME TO DOODLETOWN"<<std::endl;
    std::cout << "\t   ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" <<std::endl;
    std::cout << "\tWe hope you enjoy your stay!" << std::endl;
    std::cout << std::endl;
    doodleTown.printBoard();
    while(true){
        doodleTown.clickEnterToMove();
        ageOfWorld++;
        std::cout << std::endl;
        std::cout << "*:･ﾟ✧*:･ﾟ✧  The world is " << ageOfWorld << " time steps old!  *:･ﾟ✧*:･ﾟ✧" << std::endl;

    }

    return 0;
}