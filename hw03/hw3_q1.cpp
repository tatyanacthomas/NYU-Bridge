#include <iostream>

int main(){
    //variables
    float item1;
    float item2;
    float item1AfterDiscount;
    float item2AfterDiscount;
    char memberConfirmation;
    float memberDiscount;
    float taxRate;
    float basePrice;
    float discountedPrice;
    float finalPrice;


    //user input 2 items 
    std::cout<< "Enter price of first item: \n";
    std::cin>> item1;

    std::cout<< "Enter price of second item: \n";
    std::cin>> item2;

    if(item1 > item2){ //item 2 is less than item 1
        item1AfterDiscount = item1;
        item2AfterDiscount = item2/2.0;
    }else{ //item 1 is less than item 2
        item1AfterDiscount = item1/2.0;
        item2AfterDiscount = item2;
    }

    //Club card verification 
    std::cout << "Does customer have a club card? (Y/N): \n";
    std::cin>> memberConfirmation;
    if(memberConfirmation == 'y' || memberConfirmation == 'Y'){
        memberDiscount = 0.1;
    }else{
        memberDiscount = 0;
    }

    //tax rate input 
    std::cout<< "Enter tax rate, e.g. 5.5 for 5.5% tax: \n";
    std::cin>> taxRate;
    taxRate = taxRate / 100.0;

    //final calculation 
    basePrice = item1 + item2;
    discountedPrice = ((item1AfterDiscount + item2AfterDiscount) - ((item1AfterDiscount + item2AfterDiscount) * memberDiscount));
    //discountedPrice = item1AfterDiscount + item2AfterDiscount;
    finalPrice = (discountedPrice * (1 + taxRate));

    //output: 
        //base price
        std::cout.precision(1);
        std::cout<< "Base price: " <<std::fixed << basePrice << "\n";
        //price after discount 
        std::cout << "Price after discounts: "<< std::fixed << discountedPrice << "\n";
        //total price
        std::cout.precision(5); //set precision to 5 according to the example in the instructions
        std::cout << "Total price: " << finalPrice << "\n";

    return 0;
}