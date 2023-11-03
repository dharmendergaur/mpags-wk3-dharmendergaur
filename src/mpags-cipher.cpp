//Main function
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "TransformChar.hpp"    
#include "ProcessCmdLine.hpp"   
#include "RunCaesarCipher.hpp"  
using namespace std;

int main(int argc, char* argv[])
{
    
    const vector<string> cmdLineArgs{argv, argv + argc};

    bool helpRequested{false};
    bool versionRequested{false};
    string inputFile{""};
    string outputFile{""};
    bool encrypt{false};
    bool decrypt{false};
    bool keysupplied{false};
    int key{0};

    bool processed{processCmdLine(cmdLineArgs,helpRequested,versionRequested,inputFile,outputFile,encrypt,decrypt,keysupplied,key)};        //required bool outputs

    if(!processed){
    return 1;
    }

    if (helpRequested) {                                                //help
        cout
            << "Usage: mpags-cipher [-h/--help] [-V/--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h or --help        HELP\n"
            << "  -V or --version     Version information\n"
            << "  -i <FILE>           Input file to read\n"
            << "  -o <FILE>           Output file\n"
            << endl;
        return 0;
    }
    if (versionRequested) {
        cout << " Version: \033[32m X.Y.Z \033[0m" << endl;
        return 0;
    }

    char inputChar{'x'};
    string inputText{""};
    string readinText{""}; 
    string outText{""};


    if (!inputFile.empty()) {  
        ifstream in_file{inputFile};  
        bool readinok = in_file.good(); 
        if(readinok){  
            in_file >> readinText; 
            for(size_t j{0}; j < readinText.length(); ++j){  
                inputChar = readinText[j];  
                inputText += transformChar(inputChar); 
            }
            if(encrypt or decrypt) {   
                inputText = runCaesarCipher(inputText,key,encrypt,decrypt); 
            }
            inputText += "\n";  
        } else {                                                                                                             //Input read error
            cerr << "[\033[34m Can't cannot read in from file ('" << inputFile  <<"')\033[0m \n";
            return 1;
        }
    } else {                                                                                                             //-i absent
        cout << "\033[34m No input file specified\033[0m , Enter input: (Use -i for specifying input file) " << endl; 
        while (cin >> inputChar) {
            
            inputText += transformChar(inputChar);  
           
        } 
        if(encrypt or decrypt) {    
            inputText = runCaesarCipher(inputText,key,encrypt,decrypt);
        }
        inputText += "\n";  
    }

   
    if (!outputFile.empty()) { 
        ofstream out_file{outputFile}; 
        bool printoutok = out_file.good();  
        if(printoutok){ 
            out_file << inputText; 
        } else {                                                                                                          //output error
            cerr << "\033[34m Can't output to file ('" << outputFile  << "')\033[0m \n";
            return 1;
        }
    } else {                                                                                                              //-o absent 
        cout << "\033[34m No output file specified \033[0m , Output: (Use -o for specifying output file)" << endl;
        cout << inputText;
    }
    return 0;
}
