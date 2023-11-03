#include <iostream>
#include <vector>
#include <string>
#include "ProcessCmdLine.hpp"
using namespace std;


bool processCmdLine(const vector<string>& args,
                    bool& helpRequested,
                    bool& versionRequested,
                    string& inputFileName,
                    string& outputFileName,
                    bool& encrypt,
                    bool& decrypt,
                    bool& keySupplied,
                    int& key)
{   
    
    const size_t nCmdLineArgs{args.size()};    

    
    for (size_t i{1}; i < nCmdLineArgs; ++i) 
    {
        if (args[i] == "-h" || args[i] == "--help") {                                                               //help
            helpRequested = true;
            break;
        } else if (args[i] == "--version" || args[i] == "-V") {                                                     //version
            versionRequested = true;
            break;
        } else if (args[i] == "-i") {                                                                               //input
            if (i == nCmdLineArgs - 1) {                                                                            //No Filename
                cerr << "\033[31m Error \033[0m  No input file specified after -i \033[34m [Usage: -i <file>]\033[0m "
                          << endl;
                return false;
            } else {
                inputFileName = args[i + 1];
                ++i;
            }
        } else if (args[i] == "-o") {                                                                               //output
          
            if (i == nCmdLineArgs - 1) {                                                                            //No Filename
                cerr << "\033[31m Error \033[0m No output file specified after -o \033[34m [Usage: -o <file>]\033[0m "
                          << endl;
                return false;
            } else {
                
                outputFileName = args[i + 1];
                ++i;
            }
        } else if(args[i] == "--encrypt") {                                                                     //encrypt
            if(!decrypt) {  
                if(i == nCmdLineArgs - 1) { 
                    if(keySupplied){
                        encrypt = true; 
                    } else {                                                                                   //No Key
                        cerr << "\033[31m Error \033[0m no key argument "  
                                << endl;
                        return false;
                    }
                } else if (i != nCmdLineArgs - 1 and !keySupplied){
                    for(size_t j{i};j<nCmdLineArgs;j++){   
                        if(args[j]=="--key"){                                                                           //Key
                            keySupplied = true; 
                            encrypt = true;
                            continue;  
                        } 
                    }
                    if(keySupplied){    
                        encrypt = true;
                    } else {                                                                                    //No Key
                        cerr << "\033[31m Error \033[0m no key argument "
                                << endl;
                        return false;
                    }
                }
            } else {                                                                                                //Encrypt + Decrypt
                cerr << "\033[31m Error \033[0m --encrypt and --decrypt cannot not be used at the samee time"
                          << endl;
                return false;
            }
        } else if(args[i] == "--decrypt") {                                                                         //Decrypt
            if(!encrypt) {
                if(i == nCmdLineArgs - 1) {
                    if(keySupplied){
                        decrypt = true;
                    } else {                                                                                   //No Key
                        cerr << "\033[31m Error \033[0m no key argument "
                                << endl;
                        return false;
                    }
                } else {
                    for(size_t j{i};j<nCmdLineArgs;j++){
                        if(args[j]=="--key"){                                                                                   //Key
                            keySupplied = true;
                            decrypt = true;
                            continue;
                        } 
                    }
                    if(keySupplied){
                        decrypt = true;
                    } else {                                                                                   //No Key
                        cerr << "\033[31m Error \033[0m no key argument "
                                << endl;
                        return false;
                    }
                }
            } else {                                                                                               //Encrypt + Decrypt
                cerr << "\033[31m Error \033[0m --encrypt and --decrypt cannot not be used at the same time"
                            << endl;
                return false;
            }
        } else if (args[i] == "--key") {   
            if (i == nCmdLineArgs - 1) {                                                                            //Key= -ve
                cerr << "\033[31m Error \033[0m --key cannot take negative integer argument" 
                          << endl;
                return false;
            } else {   
                if (stoi(args[i+1]) >= 0){  
                    keySupplied = true; 
                    key = stoi(args[i+1]);
                    ++i; 
                } else {                                                                                          //Key= -ve
                  cerr << "\033[31m Error \033[0m --key cannot take negative integer argument"
                            << endl;

                    return false;  
                }
            }
        } else {                                                                                                     // For unknown flags 
            cerr << "\033[31m Error \033[0m Unknown argument '" << args[i]
                      << "'\n";
            return false;
        }
    }
    
    return true;
}
