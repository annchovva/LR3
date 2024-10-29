#include <iostream>
#include <cmath>
#include <string>

void menu()
{
    int choice;
    std::cout << "-Главное меню-\n";
    std::cout << "Задание 8.\n";
    std::cout << "Вычислить a0 - 2a1 + 4a2 - 8a3 + ... + (2^(n-1) * (-1)^(n-1) * an-1\n";
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

int res(int n)
{
    int sum = 0, multi = 1, sign = 1;
    int a;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Введите a" << i << ": ";
        while (!(std::cin >> a) or std::cin.get() != '\n')
        {
            std::cout << "Введите корректное значение a: ";
            std::cin.clear();
            while (std::cin.get() != '\n')
                ;
        }
        sum += sign * multi * a;
        sign *= -1;
        multi *= 2;
    }
    std::cout << "Результат: " << sum << "\n";
}

void result()
{
    int n;
    std::cout << "Введите n: ";
    while (!(std::cin >> n) or std::cin.get() != '\n')
    {
        std::cout << "Введите целое положительное число n: ";
        std::cin.clear();
    }
    std::cout << res(n) << "\n";
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