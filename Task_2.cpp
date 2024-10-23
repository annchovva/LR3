#include <iostream>
#include <cmath>
#include <string>

//контекстное меню
void menu() {
    int choice;
    std::cout << "-Главное меню-\n";
    std::cout << "Задание 2.\n";
    std::cout << "Используя цикл do while найти сумму ряда с точностью eps = 10^-3,\n";
    std::cout << "общий член которого dn = 1/2^n + 1/3^n. \n";
    std::cout << "При составлении программы считать, что точноcть достигнута, если dn < eps.\n";
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
            std::cout << "Введите 0 или 1!\n";
        }
    }
}

void result() {
    std::cout << "Результат: \n";
    const double eps = 1e-3;
    int n = 1;
    double res = 0;
    double dn;
    do
    {
        dn = ((1 / pow(2, n)) + (1 / pow(3, n)));
        n++;
        res += dn;
    } while (dn >= eps);
    std::cout << res << std::endl;
}

int main()
{
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
            break;
        }
    }
    return 0;
}