#include <iostream>
#include "vigenere.h"
#include "caesar.h"

std::string encryptVigenere(std::string plaintext, std::string keyword){
    std::string str = "";
    char arr[keyword.length()];
    strcpy(arr, keyword.c_str()); 
    int count = -1; 

    for(int i = 0; i < plaintext.length(); i++){ 
        if(isalpha(plaintext[i])){
            count++;
            str += shiftChar(plaintext[i],  (int)arr[count % keyword.length()] - 97);
        }
        else{
            str += plaintext[i];
        }
	}
    return str;
}