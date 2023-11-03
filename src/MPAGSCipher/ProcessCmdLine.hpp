#ifndef MPAGSCIPHER_PROCESSCMDLINE_HPP
#define MPAGSCIPHER_PROCESSCMDLINE_HPP
#include <vector>
#include <string>
using namespace std;

bool processCmdLine(const vector<string>& args,
                    bool& helpRequested,
                    bool& versionRequested,
                    string& inputFileName,
                    string& outputFileName,
                    bool& encrypt,
                    bool& decrypt,
                    bool& keySupplied,
                    int& key);

                
#endif