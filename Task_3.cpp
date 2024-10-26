#include <iostream>
#include <cmath>
#include <string>

//контекстное меню
void menu() {
    int choice;
    std::cout << "-Главное меню-\n";
    std::cout << "Задание 3.\n";
    std::cout << "Используя цикл for составить программу вычисления значений функции\n";
    std::cout << "y = sin(x) - cos(x) на отрезке [A, B] в точках Xi= A + i * H,\n";
    std::cout << "где H = (B - A) / M, M = 20, A = 0, B = pi / 2.\n";
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

void result() {
    std::cout << "Результат: \n";
    const int M = 20;
    const double A = 0.0;
    const double B = M_PI_2;
    double H = (B - A) / M;
    double Xi = 0.0;
    for (int i = 0; Xi < B; i++)
    {
        Xi = A + i * H;
        double res = sin(Xi) - cos(Xi);
        std::cout << res << "\n";
    }    
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
            std::cout << "Вы вышли из программы.\n";
            break;
        }
        else if (retry == 1) {
            continue;
        }
    }
    return 0;
}