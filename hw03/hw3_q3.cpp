#include <iostream>
#include <cmath>

const int NO_REAL_SOLUTIONS = 0;
const int ONE_REAL_SOLUTION = 1;
const int TWO_REAL_SOLUTIONS = 2;
const int INFINITE_SOLUTIONS = 3;
const int NO_SOLUTIONS = 4;

int main(){
    double a;
    double b;
    double c;
    int solutionResult;
    double discriminantVal;
    double x1;
    double x2;

    //receive input from user
    std::cout<< "Please enter value of a: \n";
    std::cin>>a;

    std::cout<< "Please enter value of b: \n";
    std::cin>>b;

    std::cout<< "Please enter value of c: \n";
    std::cin>>c;

    if(a == 0 && b == 0 && c == 0){
        solutionResult = INFINITE_SOLUTIONS;
        std::cout << "Infinite Solutions \n";
    }else if(a == 0 && b == 0){
        solutionResult = NO_SOLUTIONS;
        std::cout << "No Solutions \n";
    }else if (a == 0){
        solutionResult = ONE_REAL_SOLUTION; 
        std::cout << "One Solution, Linear \n";
    }else{ //in all other remaining instances, a != 0
        discriminantVal = (b * b) - (4 * (a * c));
        if(discriminantVal > 0){
            solutionResult = TWO_REAL_SOLUTIONS;
            std::cout << "Two Solutions \n";
        }else if(discriminantVal < 0){
            solutionResult = NO_REAL_SOLUTIONS;
            std::cout << "No Real Solutions \n";
        }else{ //if discriminantVal = 0
            solutionResult = ONE_REAL_SOLUTION;
            std::cout<< "One Solution, Quadratic \n";
        }
    }
    
    //solve for x1 and x2 when they are part of quadratic equation (when a != 0)
    if(solutionResult == ONE_REAL_SOLUTION ){
        if(a == 0){
            // solving for x1 as a linear equation = (-c) / b
            if(b == 0){
                x1 = c * -1;
            }else{
                x1 = (c * -1)/b;
            }
        }else{ 
            //solve for x1 as quadratic, remove the discriminant because it is 0
            x1 = ((b * -1)/(2 * a));
        }
        std::cout << "This equation has a single real solution x = " << x1 << std::endl;

    }else if(solutionResult == TWO_REAL_SOLUTIONS){
        //solve for x1
        //solve for x2
        x1 = ((b * -1) + sqrt((b*b) - (4 * a * c)))/(2 * a);
        x2 = ((b * -1) - sqrt((b*b) - (4 * a * c)))/(2 * a);
        std::cout << "This equation has two real solutions x1 = " << x1 << " and x2 =" << x2 << std::endl;  
    }

    return 0;
}