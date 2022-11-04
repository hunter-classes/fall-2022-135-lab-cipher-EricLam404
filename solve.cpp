#include <iostream>
#include <vector>
#include <cmath>
#include "caesar.h"
#include "decrypt.h"
#include "solve.h"

std::vector<double> get_freq(std::string encrypted_string){
    std::vector<double> string_freq;
    for(int i = 0; i < 26; i++)
        string_freq.push_back(0);

    int charShift = 97;
    double letter_freq = 1.0 / encrypted_string.length();
    for(int i = 0; i < encrypted_string.length();i++){
        char c = encrypted_string[i];
        if(isalpha(c)){
            if (isupper(c)) c = tolower(c);
            string_freq[(int) c - charShift] += letter_freq;
        }
    }
    return string_freq;
}

double distance(std::vector<double> freq, std::vector<double> string_freq){
    double sum = 0;
    for(int i = 0; i < freq.size(); i++){
        sum += pow(freq[i] - string_freq[i], 2);
    }
    return sum;
}


std::string solve(std::string encrypted_string){
    std::vector<double> freq = {0.082, 0.015, 0.028, 0.043, 0.13, 0.022, 0.02, 0.061, 0.07, 0.0015, 0.0077, 0.04, 0.024, 0.067, 0.075, 0.019, 0.00095, 0.06, 0.063, 0.091, 0.028, 0.0098, 0.024, 0.0015, 0.02, 0.00074};
    std::vector<double> string_freq = get_freq(encrypted_string);

    int index = 0;
    double dist = distance(freq, string_freq);

    for(int i = 1; i < 26; i++){
        std::string temp_str = decryptCaesar(encrypted_string, i);
        string_freq = get_freq(temp_str);
        double temp_dist = distance(freq, string_freq);
        if(temp_dist < dist){
            index = i;
            dist = temp_dist;
        }
    }
    std::cout << index << "\n"; 
    return decryptCaesar(encrypted_string, index);
}