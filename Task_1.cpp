#include <iostream>
#include <cmath>
#include <string>

void menu()
{
    int choice;
    std::cout << "-Главное меню-\n";
    std::cout << "Задание 1.\n";
    std::cout << "Используя цикл while вычислить N (от 1 до 30) = ∑ (ai - bi)^2,\n";
    std::cout << "где a и b определены по формуле: \n";
    std::cout << "ai = { i, если i нечётное || i/2, если i чётное}\n";
    std::cout << "bi = { i^2, если i нечётное || i^3, если i чётное}\n";
    std::cout << "Выполнила Горбачёва Анна, гр.453504\n";
    std::cout << "1 - Результат\n";
    std::cout << "0 - Выход\n";
}

int get_input()
{
    std::string input;
    while (true)
    {
        std::getline(std::cin, input);
        if (input.length() == 1 && (input[0] == '0' || input[0] == '1'))
        {
            return input[0] - '0';
        }
        else
        {
            std::cout << "Введите 0 или 1: ";
        }
    }
}

void result()
{
    std::cout << "Результат: \n";
    int i = 1;
    double N = 0;
    while (i <= 30)
    {
        double a, b;
        if (i % 2 == 0)
        {
            a = i / 2;
            b = pow(i, 3);
        }
        else if (i % 2 == 1)
        {
            a = i;
            b = pow(i, 2);
        }
        N += pow((a - b), 2);
        i++;
    }
    std::cout << N << "\n";
}

int main()
{
    while (true)
    {
        menu();
        std::cout << "Выберите действие: ";
        int choice = get_input();
        if (choice == 1)
        {
            result();
        }
        else if (choice == 0)
        {
            std::cout << "Вы вышли из программы.\n";
            break;
        }
        std::cout << ".\n";
        std::cout << ".\n";
        std::cout << ".\n";
        std::cout << "Желаете повторить программу? (1 - да, 0 - нет): ";
        int retry = get_input();
        if (retry == 0)
        {
            std::cout << "Вы вышли из программы.\n";
            break;
        }
        else if (retry == 1)
        {
            continue;
        }
    }
    return 0;
}