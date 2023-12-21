#include "cipher.h"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        int key;
        std::cout << "Введите ключ: ";
        std::cin >> key;
        if (key <= 0) {
            throw cipher_error("Длина ключа должна быть положительным числом");
        }
        Cipher cipher(key);
        std::string text;
        std::cout << "Введите текст: ";
        std::cin >> text;
        if (text.empty()) {
            throw cipher_error("Текст не может быть пустым");
        }
        std::string encrypted_text = cipher.encrypt(text);
        std::cout << "Зашифрованный текст: " << encrypted_text << std::endl;
        std::string decrypted_text = cipher.decrypt(encrypted_text);
        std::cout << "Расшифрованный текст: " << decrypted_text << std::endl;
    } catch (const cipher_error& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
