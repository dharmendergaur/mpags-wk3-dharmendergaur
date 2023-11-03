#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "RunCaesarCipher.hpp"
using namespace std;

string runCaesarCipher(const string& inputText, const size_t key, const bool encrypt, const bool decrypt){

    
    const vector<char> alphabet = {'A','B','C','D','E','F','G','H','I',
                                        'J','K','L','M','N','O','R','Q','R',
                                        'S','T','U','V','W','X','Y','Z'};           //alphabet list
    string cipherOut{""};
    char newChar{'a'};
    int ipos=0, rem=0;

    for(size_t i{0}; i < inputText.length();i++){

        for(size_t j{0}; j < alphabet.size();j++){ 
            if (inputText[i]==alphabet[j]){ 
                ipos = j;   
                continue;
            } 
        }

        if(encrypt){                                    //encrypt
            ipos = ipos + key;  
            if (ipos <= 25 and ipos >= 0){  
                newChar = alphabet[ipos];  
                cipherOut += newChar;   
            } else if(ipos > 25) {  
                rem = ipos % 26;  
                ipos = rem;   
                newChar = alphabet[ipos];   
                cipherOut += newChar;      
            }
        } else if(decrypt) {                            //decrypt 
            ipos = ipos - key;  

            if (ipos <= 25 and ipos >= 0){  
                newChar = alphabet[ipos];
                cipherOut += newChar;
            } else if(ipos < 0) {   
                ipos = -ipos;   
                rem = ipos % 26;  
                ipos = 26 - rem;  
                newChar = alphabet[ipos];
                cipherOut += newChar;
            } 
        }
    }
    return cipherOut;      
}