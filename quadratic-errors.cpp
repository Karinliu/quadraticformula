#include <iostream>
#include <cmath>
#include <stdexcept>
#include <sstream>

double discriminantFormula(double a, double b, double c)
{
    double discriminant;

    discriminant = b * b - 4 * a * c;

    return discriminant;
}

int quadraticFormula(double a, double b, double c){
    double solution1, solution2;
    double d = discriminantFormula(a, b, c);

    if (d > 0){
        solution1 = (-b + sqrt(d)) / (2 * a);
        solution2 = (-b - sqrt(d)) / (2 * a);

        std::cout << "There are 2 solutions." << std::endl;
        std::cout << "The solutions are: " << solution1 << " and " << solution2 << std::endl;
    }
    else if (d == 0){
        solution1 = -b / (2 * a);

        std::cout << "There is 1 solution." << std::endl;
        std::cout << "The solution is: " << solution1 << std::endl;
    }
    else{
        std::cout << "There is no solution." << std::endl;
    }

    return 0;
}

bool isNumber(const std::string &STR){

    for (int i = 0; i < STR.size(); i++){
        char emptyString = ' ';
        char dotString = '.';

        if (std::isdigit(STR[i]) == false && (STR[i] != emptyString) && (STR[i] != dotString)){
            return false;
        }
    }
    return true;
}

bool countInput(const std::string &STR){
    std::stringstream counterInputs(STR);
    std::string individualInput;

    int count = 0;
    while (counterInputs >> individualInput){
        count++;
        if (count == 3){
            return true;
        }
    }
    return false;
}

void validateInput(){
    std::string line;
    getline(std::cin, line);
    std::stringstream stringInput(line);

    stringInput << line;

    double a, b, c;

    stringInput >> a >> b >> c;

    if (countInput(line) == false){
        throw std::runtime_error("Malformed user input");
    }
    if (isNumber(line) == false){
        throw std::runtime_error("Malformed user input");
    }
    if (a == 0){
        throw std::runtime_error("a must not be zero");
    }

    quadraticFormula(a, b, c);
}

int main(){
    try{
        std::cout << "Please enter the values of a, b, and c: " << std::endl;

        validateInput();
    }
    catch (std::runtime_error &excpt){
        std::cout << "An error occurred: " << excpt.what() << std::endl;
    }

    return 0;
}