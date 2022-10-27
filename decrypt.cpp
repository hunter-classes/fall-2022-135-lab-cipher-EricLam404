#include <iostream>
#include "decrypt.h"
#include "caesar.h"

std::string decryptCaesar(std::string ciphertext, int rshift){
    std::string str = "";

    for(int i = 0; i < ciphertext.length(); i++){
		str += shiftChar(ciphertext[i], rshift * -1);
	}
    return str;
}

std::string decryptVigenere(std::string ciphertext, std::string keyword){
    std::string str = "";
    char arr[keyword.length()];
    strcpy(arr, keyword.c_str()); 
    int count = -1; 

    for(int i = 0; i < ciphertext.length(); i++){ 
        if(isalpha(ciphertext[i])){
            count++;
            str += shiftChar(ciphertext[i],  (((int)arr[count % keyword.length()] - 97) * -1));
        }
        else{
            str += ciphertext[i];
        }
	}
    return str;
}