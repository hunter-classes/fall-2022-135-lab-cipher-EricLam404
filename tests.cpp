#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

// add your tests here

TEST_CASE("Caesar Shift"){
    CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
    CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
}

TEST_CASE("Vigenere Shift"){
    CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
}

TEST_CASE("Caesar Decrypt"){
    CHECK(decryptCaesar("Bfd yt Lt!", 5) == "Way to Go!");
    CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
}

TEST_CASE("Vigenere Decrypt"){
    CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
}
