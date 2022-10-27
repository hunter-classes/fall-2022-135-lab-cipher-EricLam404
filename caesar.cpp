#include <iostream>
#include "caesar.h"

// add functions here

char shiftChar(char c, int rshift){
    int newC = c + rshift;
    if(c >= 65 && c <= 90){
        if(newC < 65){
            return newC + 26;
        }
        if(newC > 90){
            return newC - 26;
        }
        return newC;
    }
    if(c >= 97 && c <= 122){
        if(newC < 97){
            return newC + 26;
        }
        if(newC > 122){
            return newC - 26;
        }
        return newC;
    }
    return c;
}

std::string encryptCaesar(std::string plaintext, int rshift){
    std::string str = "";

    for(int i = 0; i < plaintext.length(); i++){
		str += shiftChar(plaintext[i], rshift);
	}
    return str;
}