//
// Created by Jake Billings on 7/3/17.
//

#include <string>
#include <openssl/sha.h>


namespace Crypto {
    std::string hash(std::string data) {
        unsigned char digest[SHA512_DIGEST_LENGTH];

        SHA512_CTX ctx;
        SHA512_Init(&ctx);
        SHA512_Update(&ctx, data.c_str(), strlen(data.c_str()));
        SHA512_Final(digest, &ctx);

        return std::string(digest, digest + sizeof digest / sizeof digest[0]);
    }
}