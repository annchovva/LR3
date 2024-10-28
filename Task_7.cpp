#include <iostream>
#include <cmath>
#include <string>

void menu() {
    int choice;
    std::cout << "-Главное меню-\n";
    std::cout << "Задание 7.\n";
    std::cout << "Вывести все числа Армстронга, меньше введенного числа.\n";
    std::cout << "Выполнила Горбачёва Анна, гр.453504\n";
    std::cout << "1 - Результат\n";
    std::cout << "0 - Выход\n";
}

int get_input() {
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        if (input.length() == 1 && (input[0] == '0' || input[0] == '1')) {
            return input[0] - '0';
        }
        else {
            std::cout << "Введите 0 или 1: ";
        }
    }
}

bool is_Arm(int x) {
    int sum = 0;
    int x1 = x;
    int digits = 0;
    while (x1 > 0) {
    x1 /= 10;
    digits++;
    }
    x1 = x;
    while (x1 > 0) {
        int digit = x1 % 10;
        sum += std::pow(digit, digits);
        x1 /= 10;
    }
    return sum == x;
}

void result() {
double X;
std::cout << "Введите положительное число больше единицы: ";
while (!(std::cin >> X) or std::cin.get() != '\n')
    {
        std::cout << "Ошибка ввода. Введите корректное числовое значение: ";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }
    if (X <= 1) {
            std::cout << "Нет чисел Армстронга меньших " << X << "\n";
    } else {
        std::cout << "Числа Армстронга меньшие " << X << ":\n";
        for(int i = 1; i < X; i++) {
            if (is_Arm(i)) {
                std::cout << i << "\n";
            }
        }
    }     
}

int main() {
    while(true) {
        menu();
        std::cout << "Выберите действие: ";
        int choice = get_input();
        if (choice == 1) {
            result();
        }
        else if (choice == 0) {
            std::cout << "Вы вышли из программы.\n";
            break;
        }
        std::cout << ".\n";
        std::cout << ".\n";
        std::cout << ".\n";
        std::cout << "Желаете повторить программу? (1 - да, 0 - нет): ";
        int retry = get_input();
        if (retry == 0) {
            std::cout << "Вы вышли из программы.\n";
            break;
        } 
        else if (retry == 1) {
            continue;
        }
    }
    return 0;
}