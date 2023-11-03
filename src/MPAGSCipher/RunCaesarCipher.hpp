#ifndef MPAGSCIPHER_RUNCAESARCIPHER_HPP
#define MPAGSCIPHER_RUNCAESARCIPHER_HPP
#include <string>
using namespace std;


string runCaesarCipher(const string& inputText, const size_t key, const bool encrypt, const bool decrypt);

#endif 