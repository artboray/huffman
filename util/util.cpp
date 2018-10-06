#include <iostream>
#include <fstream>

#include "huffman.h"

void PrintUsage()
{
    std::cout << "usage: ./huffman ⟨-e | -d⟩ source target" << std::endl;
    exit(0);
}

int main(int argc, char* argv[]) {
    if (argc != 4)
        PrintUsage();

    auto option = std::string(argv[1]);
    auto source = argv[2];
    auto target = argv[3];

    std::ifstream in(source, std::ifstream::binary);
    std::ofstream out(target, std::ofstream::binary);

    if (!in.is_open() || !out.is_open()) {
        std::cout << "File opening error" << std::endl;
        exit(0);
    }

    if (option == "-e")
        Huffman::Encode(in, out);
    else if (option == "-d")
    {
        if (!Huffman::Decode(in, out))
        {
            std::cout << "File corrupted" << std::endl;
            exit(0);
        }
    }
    else
        PrintUsage();
}