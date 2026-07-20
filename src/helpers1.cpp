// Define all helper functions for hw1 in this file

#include "helpers1.h"
#include <map>

const int MAX_ASCII = 127;

int countLines(std::istream& in){
    char c;
    int total = 0;
    while(in.get(c)){
        if( c < 0 || c > MAX_ASCII){
            break;
        }
        if(c =='\n'){
            total++;
        }
    }
    return total;
}
int countTotalSymbols(std::istream& in, bool verbose){
    std::map<char, int> symbolCounts;
    char c;
    int total = 0 ;
    while(in.get(c)){
        if(c < 0 || c > MAX_ASCII){
            break;
        }
        else if(!isalnum(c) && c >= 0x21 && c <= 0x7E){
            total++;
            if (verbose){
                symbolCounts[c]++;
            }
        }
    }
    if (verbose){
        for (auto item: symbolCounts){
            std::cerr<<item.first << ' '<<item.second<<std::endl;
        }
    }
    return total;
}
int countNumberOccur(std::istream& in, bool verbose){
    char c;
    int total = 0;
    bool inNumber = false;
    std::string currentNumber = "";
    while(in.get(c)){
        if(c <0 || c > MAX_ASCII){
            break;
        }
        if(isdigit(c)){
            inNumber = true;
            currentNumber += c;
        }
        else{
            if(inNumber){
                total++;
                inNumber = false;
                if(verbose){
                    std::cerr << currentNumber <<std::endl;
                }
                currentNumber = "";
            }
        }
    }
    if(inNumber){
        total++;
        if( verbose){
            std::cerr << currentNumber << std::endl;
        }
    }
    return total;
}
int contractSpaces(std::istream& in, int numSpaces){
    char c;
    int total = 0;
    int spaceCount = 0;
    while(in.get(c)){
        if(c < 0 || c > MAX_ASCII){
            break;
        }
        if(c == ' '){
            spaceCount++;
            if(spaceCount == numSpaces){
                total++;
                std::cerr << '\t';
                spaceCount = 0;
            }
        }
        else{
            for(int i = 0; i < spaceCount; i++){
                std::cerr << ' ';
            }
            spaceCount = 0;
            std::cerr << c;
        }
    }
    for(int i = 0; i < spaceCount; i++){
        std::cerr << ' ';
    }
    return total;
}
int countBlankLines(std::istream& in){
    std::string current = "";
    int total = 0;
    bool lastWasNewline = false;
    char c;
    while(in.get(c)){
        if(c < 0 || c > MAX_ASCII){
            break;
        }
        if(c == '\n'){
            bool allWhitespace = true;
            for(char ch : current){
                if(!isspace(ch)){
                    allWhitespace = false;
                    break;
                }
            }
            bool isBad = false;
            if(current.empty() || allWhitespace){
                isBad = true;
            }
            else if(isspace(current.front()) || isspace(current.back())){
                isBad = true;
            }
            if(isBad){
                total++;
            }
            else{
                std::cerr << current << std::endl;
            }
            current = "";
            lastWasNewline = true;
        }
        else{
            current += c;
            lastWasNewline = false;
        }
    }
    if(lastWasNewline){
        total++;
    }
    else if(!current.empty()){
        bool allWhitespace = true;
        for(char ch : current){
            if(!isspace(ch)){
                allWhitespace = false;
                break;
            }
        }
        bool isBad = false;
        if(allWhitespace){
            isBad = true;
        }
        else if(isspace(current.front()) || isspace(current.back())){
            isBad = true;
        }
        if(isBad){
            total++;
        }
        else{
            std::cerr << current << std::endl;
        }
    }
    return total;
}
