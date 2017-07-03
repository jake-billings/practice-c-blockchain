cmake_minimum_required(VERSION 3.7)
project(practice_c_blockchain)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Block.cpp Block.h Crypto.h Crypto.cpp Encode.h Encode.cpp lib/base64.h)
add_executable(practice_c_blockchain ${SOURCE_FILES})

find_package(OpenSSL REQUIRED)

message("OpenSSL include dir: ${OPENSSL_INCLUDE_DIR}")
message("OpenSSL libraries: ${OPENSSL_LIBRARIES}")

include_directories(${OPENSSL_INCLUDE_DIR})
list(APPEND LIB_LIST ${OPENSSL_LIBRARIES})
target_link_libraries (practice_c_blockchain  ${OPENSSL_LIBRARIES})