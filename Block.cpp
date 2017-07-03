//
// Created by Jake Billings on 7/3/17.
//

#include "Block.h"
#include "Crypto.h"
#include "Encode.h"
#include <iostream>
#include <openssl/rand.h>

Block::Block(std::string previousHash, std::string data, std::string nonce, unsigned long height) {
    this->previousHash = previousHash;
    this->data = data;
    this->nonce = nonce;
    this->height = height;

    this->hash = Crypto::hash(encode(previousHash) + data + encode(nonce));
}

const std::string &Block::getPreviousHash() const {
    return previousHash;
}

void Block::setPreviousHash(const std::string &previousHash) {
    Block::previousHash = previousHash;
}

const std::string &Block::getHash() const {
    return hash;
}

void Block::setHash(const std::string &hash) {
    Block::hash = hash;
}

const std::string &Block::getData() const {
    return data;
}

void Block::setData(const std::string &data) {
    Block::data = data;
}

const std::string &Block::getNonce() const {
    return nonce;
}

void Block::setNonce(const std::string &nonce) {
    Block::nonce = nonce;
}

unsigned long Block::getHeight() const {
    return height;
}

void Block::setHeight(unsigned long height) {
    Block::height = height;
};

const std::string Block::getNonceEncoded() const {
    return encode(this->getNonce());
}

const std::string Block::getHashEncoded() const {
    return encode(this->getHash());
}

const std::string Block::getPreviousHashEncoded() const {
    return encode(this->getPreviousHash());
}

std::string generateNonce() {
    unsigned char cnonce[NONCE_SIZE];
    RAND_bytes(cnonce, NONCE_SIZE);
    return std::string(cnonce, cnonce + sizeof cnonce / sizeof cnonce[0]);
}

Block mineBlock(std::string previous_hash, std::string data, unsigned long height) {
    while (true) {
        std::string nonce = generateNonce();
        Block b = Block(previous_hash, data, nonce, height);
        const char* chash = b.getHashEncoded().c_str();

//        printBlock(b);
//        std::cout << encode(nonce) << ", " << b.getHashEncoded() << std::endl;

        bool valid = true;
        for (unsigned int i=0; i<DIFFICULTY_ORDER; i++) {
            if (chash[i] != '0') {
                valid =false;
                break;
            }
        }
        if (valid) {
            return b;
        }
    }
}

void printBlock(Block block) {
    printf("----------block %d----------\nnonce %s\nprev %s\ndata\n----------\n%s\n----------\nhash %s\n----------End Block----------\n",
           (int) block.getHeight(), block.getNonceEncoded().c_str(), block.getPreviousHashEncoded().c_str(),
           block.getData().c_str(), block.getHashEncoded().c_str());
}