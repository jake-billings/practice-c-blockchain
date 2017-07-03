//
// Created by Jake Billings on 7/3/17.
//

#ifndef PRACTICE_C_BLOCKCHAIN_BLOCK_H
#define PRACTICE_C_BLOCKCHAIN_BLOCK_H

#include <string>

#define DIFFICULTY_ORDER 3
#define ENCODING_ORDER 64

#define NONCE_SIZE 8

const int DIFFICULTY = DIFFICULTY_ORDER  * ENCODING_ORDER;

class Block {

private:
    std::string previousHash;
    std::string hash;
    std::string data;
    std::string nonce;
    unsigned long height;

public:
    Block(std::string previous_hash, std::string data, std::string nonce, const unsigned long height);


    const std::string &getPreviousHash() const;
    void setPreviousHash(const std::string &previous_hash);

    const std::string &getHash() const;
    void setHash(const std::string &hash);

    const std::string &getData() const;
    void setData(const std::string &data);

    const std::string &getNonce() const;
    void setNonce(const std::string &nonce);

    unsigned long getHeight() const;
    void setHeight(unsigned long height);

    const std::string getNonceEncoded() const;
    const std::string getHashEncoded() const;
    const std::string getPreviousHashEncoded() const;
};

Block mineBlock(std::string previous_hash, std::string data, unsigned long height);
void printBlock(Block block);

#endif //PRACTICE_C_BLOCKCHAIN_BLOCK_H
