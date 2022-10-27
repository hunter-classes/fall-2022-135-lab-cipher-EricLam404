#include <iostream>

void printAscii(std::string str){
	for(int i = 0; i < str.length(); i++){
		std::cout << str[i] << " " << (int)str[i] << std::endl;
	}
}

int main(){
	printAscii("Cat :3 Dog");

    return 0;
}