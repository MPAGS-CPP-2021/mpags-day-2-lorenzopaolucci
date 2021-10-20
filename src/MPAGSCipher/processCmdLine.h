#ifndef PROCESSCMDLINE_H
#define PROCESSCMDLINE_H

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

bool processCmdLine(const std::vector<std::string>& cmdLineArgs, 
                    bool& helpRequested, 
                    bool& versionRequested,
                    bool& encrypt, 
                    std::size_t& key,
                    std::string& inputFile, 
                    std::string& outputFile);

#endif 