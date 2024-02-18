#include <iostream>
#include <cstring>

class String {
private:
    char* string_;
    int size;

public:
    // Конструктор по умолчанию
    String() {
        size = 80;
        string_ = new char[size + 1];
        //std::fill(string_, string_ + size, '\0');
        std::memset(string_, 0, sizeof(char) * (size + 1));      // memset вроде как работает быстрее, но что то я вычитал что если запонять '\0' скорость практически схожа
    }

    // Конструктор с произвольным размером
    String(int length) {
        size = length;
        string_ = new char[size + 1];
        std::fill(string_, string_ + size, '\0');
        //std::memset(string_, 0, sizeof(char) * (length + 1));   
    }

    // Конструктор с инициализацией от пользователя
    String(const char* input) {
        size = strlen(input);
        string_ = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            string_[i] = input[i];
        }
        string_[size] = '\0';
    }

    // Метод для ввода строки с клавиатуры
    void input() {
        std::cout << "Введите строку: ";
        std::cin.getline(string_, size + 1);
    }

    // Метод для вывода строки на экран
    void output() {
        std::cout << string_ << std::endl;
    }

    // Деструктор
    ~String() {
        delete[] string_;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    String defaultString; // Создание строки длиной 80 символов
    defaultString.input();
    defaultString.output();

    String customString(10); // Создание строки длиной 100 символов
    customString.input(); // Ввод строки с клавиатуры
    customString.output();
    

    String userString("Привет, мир!"); // Создание строки с инициализацией от пользователя  
    userString.output();     

    return 0;
}