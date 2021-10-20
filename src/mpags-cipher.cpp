#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "transformChar.h"
#include "processCmdLine.h"
#include "CaesarCipher.h"

int main(int argc, char* argv[]){

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    bool encrypt{false};
    std::size_t key;
    std::string inputFile{""};
    std::string outputFile{""};

    // Command line vector string
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};

    bool status = processCmdLine(cmdLineArgs, helpRequested, versionRequested, encrypt, key, inputFile, outputFile);
 
    // Close program if status is not ok or if help/version was requested

    if(!status) return 1;

    if(helpRequested || versionRequested) return 0;

    // Open I/O files

    std::ifstream in_file{inputFile};
    std::ofstream out_file{outputFile};

    // Check files correctly opened

    bool use_stdin{false};
    bool use_stdout{false};

    if(!in_file.good()){
        std::cerr << "[warning] input file not opened correctly, will use stdin\n";

        use_stdin = true;
    }

    if(!out_file.good()){
        std::cerr << "[warning] output file not opened correctly, will use stdout\n";

        use_stdout = true;
    }

    // Initialise variables
    std::string inputText;
    std::string transformedText;
    std::string outputText;
    char inputChar{'x'};

    // Read in user input from stdin/file
    // Warn that input file option not yet implemented
    if (!inputFile.empty()) {
        std::cerr << "[warning] input from file ('" << inputFile
                  << "') not implemented yet, using stdin\n";
    }

    // loop over each character from user input

    if(use_stdin){
        while (std::cin >> inputChar) {

            inputText+=inputChar;
            transformedText += transformChar(inputChar);

        }
    }else{
        while (in_file >> inputChar) {

            inputText+=inputChar;
            transformedText += transformChar(inputChar);

        } 
    }         

    // Encrypt/Decrypt input

    outputText = runCaesarCipher(inputText, key, encrypt);

    // Warn that output file option not yet implemented
    if (!outputFile.empty()) {
        std::cerr << "[warning] output to file ('" << outputFile
                  << "') not implemented yet, using stdout\n";
    }

    if(use_stdout){
        std::cout << inputText << std::endl;
        std::cout << "Encrypted/Decrypted output \t" + outputText << std::endl;
    }
    out_file << inputText;
    out_file << outputText;

    // Close files

    in_file.close();
    out_file.close();

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}
