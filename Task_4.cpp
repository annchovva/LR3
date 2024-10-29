#include <iostream>
#include <cmath>
#include <string>

void menu()
{
    int choice;
    std::cout << "-Главное меню-\n";
    std::cout << "Задание 4. Вариант 7.\n";
    std::cout << "Необходимо разложить функцию Y(x) = (1 + x^2 / 2) * arctgx - (x / 2) \n";
    std::cout << "в ряд S(x) = (x^3 / 3) - (x^5 / 15) + ... + (-1)^(n + 1) * (x^(2n + 1)) / (4n^2 - 1),\n";
    std::cout << "затем с помощью полученного ряда найти значение функции и сравнить его\n";
    std::cout << "со значением, вычисленным с помощью стандартных функций.\n";
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
        if (input.length() == 1 && (input[0] == '1' || input[0] == '0'))
        {
            return input[0] - '0';
        }
        else
        {
            std::cout << "Введите 0 или 1: ";
        }
    }
}

double S(double x, int i)
{
    return (pow(-1, i + 1)) * (pow(x, 2 * i + 1)) / (4 * pow(i, 2) - 1);
}

void result()
{
    double x;
    int n, N;
    std::cout << "Введите количество членов ряда: ";
    while (!(std::cin >> n) or std::cin.get() != '\n' or n <= 0)
    {
        std::cout << "Введите целое положительное число x: ";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }
    std::cout << "Введите, количество чисел, от которых хотите посчитать функцию: ";
    while (!(std::cin >> N) or std::cin.get() != '\n' or N <= 0)
    {
        std::cout << "Введите целое положительное число x: ";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }
    for (int N0 = 1; N0 <= N; N0++)
    {
        std::cout << "Введите x" << N0 << " (от 0.1 до 1): ";
        while (!(std::cin >> x) or std::cin.get() != '\n' or (x < 0.1 or x > 1.0))
        {
            std::cout << "Введите число x от 0.1 до 1.0 : ";
            std::cin.clear();
            while (std::cin.get() != '\n');
        }
        double my_res = 0.0;
        for (int i = 1; i <= n; i++)
        {
            double dn = S(x, i);
            my_res += dn;
        }
        std::cout << "S(x) = " << my_res << "\n";
        double res;
        res = ((1 + pow(x, 2)) * atan(x) / 2) - (x / 2);
        std::cout << "Y(x) = " << res << "\n";
    }
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
        std::cout << "Желаете повторить программу (1 - да, 0 - нет)? ";
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