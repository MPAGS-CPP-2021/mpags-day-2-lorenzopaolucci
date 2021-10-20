#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <string>

std::string runCaesarCipher(std::string& inputText, 
                            const size_t key, 
                            const bool encrypt);

#endif