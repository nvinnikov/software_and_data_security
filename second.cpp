#include <iostream>
#include <string>
#include <cstdlib>

#ifdef __unix__
#include <sys/ptrace.h>
#include <unistd.h>
#endif

#ifdef _WIN32
#include <Windows.h>
#endif

using namespace std;

bool is_debugger_present() {

// Защита от отладки с помощью специальных функций языка
#ifdef __linux__
    // Проверка наличия отладчика в Linux
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1) {
        return true;
    }
    ptrace(PTRACE_DETACH, 0, 1, 0);
#endif

// Защита от отладки с помощью специальных функций языка
#ifdef _WIN32
    // Проверка наличия отладчика в Windows
    if (IsDebuggerPresent()) {
        //навязывание отладчику ложных точек останова
        srand(time(nullptr));
        int num_breakpoints = rand() % 10 + 1; // от 1 до 10
        for (int i = 0; i < num_breakpoints; ++i) {
            DebugBreak();
    }
        return true;
    }
#endif

// Защита от отладки с помощью директив препроцессора
#ifdef _DEBUG
    return true;
#endif

return false;
}

//функция генерации ключа
string generate_key(string login){
    string generated_key;
    //длина логина - подсчет количества букв в логине (1)
    int login_size = login.length();
    for (char c : login) {

        int ascii_code = static_cast<int>(c);

        //умножение аски кода на длина логина - преобразование генерации ключевой информации (1)
        generated_key += to_string(ascii_code*login_size);
    }
    return generated_key;
}

//функция для генерации ключа-обманки
string generate_key_new(string login){
    string generated_key;
    //рандом
    generated_key = to_string(rand() % 1000 + 1);
    return generated_key;
}

int main() {

    string login;
    cout << "Введите логин: ";
    getline(cin, login);

    // Реверс login - преобразование данных для генерации ключевой информации (1)
    reverse(login.begin(), login.end());

    // Алгоритм генерации ключа
    string generated_key;

    if (is_debugger_present()){
            // Вызов функции через указатель на нее (косвенный вызов) (2)
            string (*pgenerate_key_new)(string) = generate_key_new;
            generated_key = pgenerate_key_new(login);
            return 0;
    } else {
            // Вызов функции через указатель на нее (косвенный вызов) (2)
            string (*pgenerate_key)(string) = generate_key;
            generated_key = pgenerate_key(login);
    }

    

    string user_key;
    cout << "Введите ключ: ";
    getline(cin, user_key);

    if (user_key == generated_key) {
        cout << "TRUE - поздравляем!" << endl;
    } else {
        cout << "FALSE - ошибка!" << endl;
    }

    return 0;
}
