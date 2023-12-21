#include "cipher.h"

std::string Cipher::encrypt(std::string text)
{
    std::string buff;
    int key_1 = key_;
    while (text.size() % key_ != 0)
        text.push_back('*');
    for (int i = 0; i < key_; i++) {
        for (int x = 0; x < (text.size() / key_); x++) {
            buff.push_back(text[key_1 - 1]);
            key_1 += key_;
        }
        key_1 = key_ - i - 1;
    }
    return buff;
}

std::string Cipher::decrypt(std::string text)
{
    std::string buff;
    int rows = text.size() / key_;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key_; j++) {
            int index = (key_ - j - 1) * rows + i;
            buff.push_back(text[index]);
        }
    }
    buff.erase(std::remove(buff.begin(), buff.end(), '*'),
               buff.end());
    return buff;
}
