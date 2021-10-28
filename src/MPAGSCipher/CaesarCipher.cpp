#include "CaesarCipher.h"

std::string runCaesarCipher(std::string& inputText, const std::size_t key, const bool encrypt){

    // Create output string

    std::string outputText;

    // Loop over input

    const std::size_t w_length = inputText.size();

    for(std::size_t i = 0; i < w_length; i++){
        
        // Check lowercase/uppercase letter with ASCII code

        int ascii = int(inputText[i]);

        if(encrypt){
            if(ascii > 64 && ascii < 91){

                int tmp = ascii - 65 + key;

                if(tmp%26 == tmp) ascii +=key;
                else              ascii = 65 + tmp%26;
            }
            else if(ascii > 96 && ascii < 123){

                int tmp = ascii - 97 + key;

                if(tmp%26 == tmp) ascii +=key;
                else              ascii = 97 + tmp%26;
            }
        }
        else{
            if(ascii > 64 && ascii < 91){

                int tmp = ascii - 65 - key;

                if(tmp%26 >= 0) ascii -=key;
                else            ascii = 91 + tmp%26;
            }
            else if(ascii > 96 && ascii < 123){

                int tmp = ascii - 97 + key;

                if(tmp%26 >= 0) ascii -=key;
                else            ascii = 97 + tmp%26;
            }
        }

        outputText += char(ascii);        
    }

    return outputText;
}