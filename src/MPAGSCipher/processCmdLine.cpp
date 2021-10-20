#include "processCmdLine.h"

bool processCmdLine(const std::vector<std::string>& cmdLineArgs, 
                    bool& helpRequested, 
                    bool& versionRequested,
                    bool& encrypt,
                    std::size_t& key,
                    std::string& inputFile, 
                    std::string& outputFile){

    bool status(true);

    const std::size_t nCmdLineArgs{cmdLineArgs.size()};

    // Process command line arguments - ignore zeroth element, as we know this
    // to be the program name and don't need to worry about it
    for (std::size_t i{1}; i < nCmdLineArgs; ++i) {
        if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help") {
            helpRequested = true;
        } else if (cmdLineArgs[i] == "--version") {
            versionRequested = true;
        } else if (cmdLineArgs[i] == "-i") {
            // Handle input file option
            // Next element is filename unless "-i" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -i requires a filename argument"
                          << std::endl;

                status = false;
            } else {
                // Got filename, so assign value and advance past it
                inputFile = cmdLineArgs[i + 1];
                ++i;
            }
        } else if (cmdLineArgs[i] == "-o") {
            // Handle output file option
            // Next element is filename unless "-o" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -o requires a filename argument"
                          << std::endl;

                status = false;
            } else {
                // Got filename, so assign value and advance past it
                outputFile = cmdLineArgs[i + 1];
                ++i;
            }
        }else if(cmdLineArgs[i] == "-encrypt"){
            
            encrypt = true;

            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -encrypt requires a key"
                          << std::endl;

                status = false;
            } else {
                // Got filename, so assign value and advance past it
                key = stoi(cmdLineArgs[i + 1]);
                ++i;
            }
        }else if(cmdLineArgs[i] == "-decrypt"){
            
            encrypt = false;

            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -decrypt requires a key"
                          << std::endl;

                status = false;
            } else {
                // Got filename, so assign value and advance past it
                key = stoi(cmdLineArgs[i + 1]);
                ++i;
            }
        }else {
            // Have an unknown flag to output error message and return non-zero
            // exit status to indicate failure
            std::cerr << "[error] unknown argument '" << cmdLineArgs[i]
                      << "'\n";

            status = false;
        }
    }

    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << "  -encrypt KEY     Encrypt input with Caesar Cipher with given KEY\n\n"
            << "  -decrypt KEY     Decrypt input with Caesar Cipher with given KEY\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        status = true;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        status = true;
    }

    return status;
}