#include <iostream>
#include <map>
#include <vector>
#include <set>

#include "huffman.h"

struct Huffman::Tree
{
    char val;
    uint64_t fr;
    bool term;
    std::shared_ptr<Tree> l, r;
    Tree(char value, uint64_t frequency, bool term_c = 1, std::shared_ptr<Tree> l = nullptr, std::shared_ptr<Tree> r = nullptr) :
        val(value), fr(frequency), term(term_c), l(std::move(l)), r(std::move(r)) {}
};


struct Huffman::cmp
{
    bool operator ()(const std::shared_ptr<Tree> &l, const std::shared_ptr<Tree> &r)
    {
        return l->fr < r->fr;
    }
};

std::shared_ptr<Huffman::Tree> Huffman::Build(const std::map<char, uint64_t>& frequency)
{
    std::multiset<std::shared_ptr<Tree>, cmp> nodes;
    for (const auto& i : frequency)
        nodes.insert(std::make_shared<Tree>(i.first, i.second));
    while (nodes.size() > 1)
    {
        std::shared_ptr<Tree> ar[2];
        for (size_t i = 0; i < 2; i++)
            ar[i] = *nodes.begin(), nodes.erase(nodes.begin());
        nodes.insert(std::make_shared<Tree>(0, ar[0]->val + ar[1]->val, false, ar[0], ar[1]));
    }
    return *nodes.begin();
}

void Huffman::GetCodes(const std::shared_ptr<Huffman::Tree>& node,
                       std::map<char, std::vector<bool>>& code_of, std::vector<bool>& cur_code)
{
    if (node->term)
    {
        code_of[node->val] = cur_code;
        return;
    }
    cur_code.push_back(0);
    GetCodes(node->l, code_of, cur_code);
    cur_code.pop_back();
    cur_code.push_back(1);
    GetCodes(node->r, code_of, cur_code);
    cur_code.pop_back();
}

void Huffman::Encode(std::istream& in, std::ostream& out)
{
    std::map<char, uint64_t> frequency;
    frequency['a'] = 0;
    while (in.peek() != std::istream::traits_type::eof()) {
        char x;
        in.read(&x, sizeof(char));
        frequency[x]++;
    }

    std::map<char, std::vector<bool>> code_of;
    std::vector<bool> cur_code;
    Huffman::GetCodes(Huffman::Build(frequency), code_of, cur_code);

    in.seekg(in.beg);
    char zero = '0';
    out.write(&zero, sizeof(char));

    auto count = uint16_t(frequency.size());
    out.write((char*)(&count), sizeof count);
    for (auto& i : frequency)
    {
        char key = i.first;
        uint64_t val = i.second;
        out.write(&key, sizeof key);
        out.write((char*)(&val), sizeof val);
    }

    char buffer[BUFFER_SIZE];
    char out_buffer[BUFFER_SIZE];
    size_t pos = 0;
    const char b_size = 8;
    char buff = 0, current_sz = 0;

    while (in)
    {
        in.read(buffer, BUFFER_SIZE);
        auto size = in.gcount();
        for (size_t i = 0; i < size; ++i)
            for (auto bit : code_of[buffer[i]])
            {
                buff |= (bit << current_sz);
                current_sz++;
                if (current_sz == b_size)
                {
                    out_buffer[pos++] = buff;
                    if (pos == BUFFER_SIZE)
                    {
                        pos = 0;
                        out.write(out_buffer, BUFFER_SIZE * sizeof(char));
                    }
                    buff = current_sz = 0;
                }
            }
    }
    if (pos)
        out.write(out_buffer, pos * sizeof(char));
    if (current_sz)
    {
        current_sz = b_size - current_sz;
        out.write(&buff, sizeof buff);
    }
    out.seekp(0);
    out.write(&current_sz, sizeof current_sz);
}

bool Huffman::Check(std::shared_ptr<Huffman::Tree> &tree,
                    std::shared_ptr<Huffman::Tree> &temp,
                    char val, char id, std::ostream &out, size_t &pos, char out_buffer[])
{
    auto bit = (1 & (val >> id));
    temp = bit ? temp->r : temp->l;
    if (!temp) return false;
    if (temp->term)
    {
        out_buffer[pos++] = temp->val;
        if (pos == BUFFER_SIZE)
        {
            pos = 0;
            out.write(out_buffer, BUFFER_SIZE * sizeof(char));
        }
        temp = tree;
    }
    return true;
}

bool Huffman::Decode(std::istream &in, std::ostream &out)
{
    char check;
    in.read(&check, sizeof(char));
    if (!in) return false;

    std::map<char, uint64_t> frequency;
    uint16_t freq_size;
    in.read((char*)(&freq_size), sizeof(uint16_t));

    for (uint16_t i = 0; i < freq_size; i++)
    {
        char key;
        uint64_t val;
        in.read(&key, sizeof key);
        if (!in) return false;
        in.read((char*)(&val), sizeof val);
        if (!in) return false;
        frequency[key] = val;
    }

    std::shared_ptr<Huffman::Tree> tree = Huffman::Build(frequency), temp = tree;

    char buffer[BUFFER_SIZE];
    char out_buffer[BUFFER_SIZE];
    const char b_size = 8;
    size_t pos = 0;

    while (in)
    {
        in.read(buffer, BUFFER_SIZE);

        auto size = in.gcount();
        if (size == 0)
            break;

        for (size_t i = 0; i < size - 1; i++)
        {
            char symbol = buffer[i];
            for (size_t j = 0; j < b_size; j++)
                if (!Check(tree, temp, symbol, char(j), out, pos, out_buffer))
                    return false;
        }

        char symbol = buffer[size - 1];
        if (in)
        {
            for (size_t j = 0; j < b_size; j++)
                if (!Check(tree, temp, symbol, char(j), out, pos, out_buffer))
                    return false;
        }
        else
        {
            for (size_t j = 0; j < b_size - check; j++)
                if (!Check(tree, temp, symbol, char(j), out, pos, out_buffer))
                    return false;
        }
    }

    if (pos)
        out.write(out_buffer, pos * sizeof(char));
    return true;
}


