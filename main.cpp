#include <iostream>

#include <vector>

#include "Block.h"
#include "Crypto.h"

int main() {
    std::vector<Block> chain;

    chain.push_back(mineBlock(Crypto::hash(""), "genesis", 0));
    printBlock(chain.at(0));

    for (unsigned int i=1; i<5; i++) {
        Block b = mineBlock(chain.at(i-1).getHash(), "block "+std::to_string(i), i);
        chain.push_back(b);
        printBlock(b);
    }

    return 0;
}