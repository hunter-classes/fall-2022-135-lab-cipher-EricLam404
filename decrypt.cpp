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
