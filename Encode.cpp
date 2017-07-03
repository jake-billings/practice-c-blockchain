//
// Created by Jake Billings on 7/3/17.
//

#include "string"
#include <iostream>

#include "lib/base64.h"

std::string encode(std::string data) {
    std::string out;
    Base64::Encode(data, &out);
    return out;
}
std::string decode(std::string data) {
    std::string out;
    Base64::Decode(data, &out);
    return out;
}