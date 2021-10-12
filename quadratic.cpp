#include <iostream>
#include <cmath>

float discriminantFormula(float a, float b, float c){
    float discriminant;

    discriminant = b * b - 4 * a * c;

    return discriminant;
}

int quadraticFormula(float a, float b, float c){
    float solution1, solution2;
    float d = discriminantFormula(a, b, c);

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

int main(){
    float a, b, c;

    std::cout << "Please enter the values of a, b, and c: " << std::endl;
    std::cin >> a >> b >> c;

    quadraticFormula(a, b, c);

    return 0;
}