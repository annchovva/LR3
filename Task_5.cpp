#include <iostream>
#include <cmath>
#include <string>
#include <limits>

void menu()
{
    int choice;
    std::cout << "-Главное меню-\n";
    std::cout << "Задание 5. Вариант 7.\n";
    std::cout << "Необходимо приближенно найти корень уравнения f(x) = 0 \n";
    std::cout << "для функции cos2x - 1/(1 + x^2) на интервале x = [2;3]\n";
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

double f(double x)
{
    return cos(2 * x) - (1 / (1 + pow(x, 2)));
}

void result()
{
    int n;
    double a = 2.0, b = 3.0;
    std::cout << "Введите, на сколько частей разделить область поиска корня: ";
    while (!(std::cin >> n) or std::cin.get() != '\n' or n <= 0)
    {
        std::cout << "Введите целое положительное число x: ";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }
    double h = (b - a) / n;
    std::cout << "Тогда шаг h = " << h << "\n";
    double min_res = std::numeric_limits<double>::max();
    double root = a;
    for (double x = a; x <= b; x += h)
    {
        double res = f(x);
        if (std::fabs(res) < std::fabs(min_res))
        {
            min_res = res;
            root = x;
        }
    }
    std::cout << "Приближенный корень уравнение f(x) = 0: x = " << root << "\n";
    std::cout << "Значение функции в этой точке: f(" << root << ") = " << f(root) << "\n";
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