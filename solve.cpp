#include <iostream>
#include <vector>
#include "caesar.h"
#include "solve.h"

std::string solve(std::string encrypted_string){
    std::vector<double> freq = {0.082, 0.015, 0.028, 0.043, 0.13, 0.022, 0.02, 0.061, 0.07, 0.0015, 0.0077, 0.04, 0.024, 0.067, 0.075, 0.019, 0.00095, 0.06, 0.063, 0.091, 0.028, 0.0098, 0.024, 0.0015, 0.02, 0.00074};
    double total = 0;
    int charShift = 97;
    for(int i = 0; i < freq.size(); i++){
        std::cout << char(charShift + i) << " " << freq[i] << "\n";
        total += freq[i];
    }
    std::cout << total << "\n";
    std::cout << freq.size() << "\n";
    return "";
}