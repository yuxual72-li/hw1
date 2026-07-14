#include "hw1.h"
#include <iostream>
#include <cstring>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "usage: " << argv[0] << " [-L|-S|-N|-C NUM|-W] [-O]" << std::endl;
        return 1;
    }

    bool verbose = false;
    int result = 0;

    if (strcmp(argv[1], "-L") == 0) {
        if (argc != 2) {
            std::cerr << "usage: " << argv[0] << " -L" << std::endl;
            return 1;
        }
        if (std::cin.peek() == EOF) { return 2; }
        result = countLines(std::cin);
    }
    else if (strcmp(argv[1], "-S") == 0) {
        if (argc == 3 && strcmp(argv[2], "-O") == 0) {
            verbose = true;
        } else if (argc != 2) {
            std::cerr << "usage: " << argv[0] << " -S [-O]" << std::endl;
            return 1;
        }
        if (std::cin.peek() == EOF) { return 2; }
        result = countTotalSymbols(std::cin, verbose);
    }
    else if (strcmp(argv[1], "-N") == 0) {
        if (argc == 3 && strcmp(argv[2], "-O") == 0) {
            verbose = true;
        } else if (argc != 2) {
            std::cerr << "usage: " << argv[0] << " -N [-O]" << std::endl;
            return 1;
        }
        if (std::cin.peek() == EOF) { return 2; }
        result = countNumberOccur(std::cin, verbose);
    }
    else if (strcmp(argv[1], "-C") == 0) {
        if (argc < 3) {
            std::cerr << "usage: " << argv[0] << " -C NUM [-O]" << std::endl;
            return 1;
        }
        int numSpaces = std::stoi(argv[2]);
        if (std::cin.peek() == EOF) { return 2; }
        result = contractSpaces(std::cin, numSpaces);
    }
    else if (strcmp(argv[1], "-W") == 0) {
        if (argc != 2) {
            std::cerr << "usage: " << argv[0] << " -W" << std::endl;
            return 1;
        }
        if (std::cin.peek() == EOF) { return 2; }
        result = countBlankLines(std::cin);
    }
    else {
        std::cerr << "usage: " << argv[0] << " [-L|-S|-N|-C NUM|-W] [-O]" << std::endl;
        return 1;
    }

    std::cout << result << std::endl;
    return 0;
}
