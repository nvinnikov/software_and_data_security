#include <iostream>
#include <string>
#include <cstdlib>

std::string generate_key(std::string login){
    std::string generated_key;
    for (char c : login) {
        int ascii_code = static_cast<int>(c);
        generated_key += std::to_string(ascii_code);
    }
    return generated_key;
}


int main() {
    std::string login;
    std::cout << "Введите логин: ";
    std::getline(std::cin, login);

    // Алгоритм генерации ключа
    std::string generated_key;
    generated_key = generate_key(login);
    
    std::string user_key;
    std::cout << "Введите ключ: ";
    std::getline(std::cin, user_key);

    if (user_key == generated_key) {
        std::cout << "TRUE - поздравляем!" << std::endl;
    } else {
        std::cout << "FALSE - ошибка!" << std::endl;
    }

    return 0;
}
