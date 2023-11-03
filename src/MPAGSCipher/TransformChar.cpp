#include <iostream>
#include <string>
#include "TransformChar.hpp"
using namespace std;

string transformChar(const char in_Char)  
{
    
    string in_Text{""};

    if (isalpha(in_Char)) {
            in_Text += toupper(in_Char);
            return in_Text;
        }
    switch (in_Char) {
        case '0':
            in_Text += "ZERO";
            break;
        case '1':
            in_Text += "ONE";
            break;
        case '2':
            in_Text += "TWO";
            break;
        case '3':
            in_Text += "THREE";
            break;
        case '4':
            in_Text += "FOUR";
            break;
        case '5':
            in_Text += "FIVE";
            break;
        case '6':
            in_Text += "SIX";
            break;
        case '7':
            in_Text += "SEVEN";
            break;
        case '8':
            in_Text += "EIGHT";
            break;
        case '9':
            in_Text += "NINE";
            break;
    }

    return in_Text;

}
