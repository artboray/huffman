#ifndef HUFFMAN
#define HUFFMAN

#include <iostream>
#include <vector>
#include <map>
#include <memory>

class Huffman {

public:

    static void Encode(std::istream &is, std::ostream &os);
    static bool Decode(std::istream& is, std::ostream& os);

private:
    struct Tree;
    static std::shared_ptr<Huffman::Tree> Build(const std::map<char, uint64_t>&);
    static void GetCodes(const std::shared_ptr<Huffman::Tree>&, std::map<char, std::vector<bool>>&, std::vector<bool>&);
    static bool Check(std::shared_ptr<Huffman::Tree> &,
                      std::shared_ptr<Huffman::Tree> &,
                      char, char, std::ostream&, size_t&, char []);
    struct cmp;
    static const uint32_t BUFFER_SIZE = 1024*1024;
};


#endif
