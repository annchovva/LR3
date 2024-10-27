#include <iostream>
#include <string>
#include <limits>
#include <cmath>

const double pi = 3.14159265358979323846;
const double e = 2.71828182845904523536;

void menu() {
    int choice;
    std::cout << "-Главное меню-\n";
    std::cout << "Задание 6.\n";
    std::cout << "Из величин, определяемых выражениями a = sinx, b = cosx, c = ln|x| при заданном х,\n"; 
    std::cout << "определить и вывести на экран дисплея минимальное значение.\n";
    std::cout << "Использование стандартных математических методов запрещено.\n";
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

double norm(double x) {
    double now = pi * 2;
    while (now < std::abs(x)) {
        now *= 2;
    }
    now /= 2.0;
    if (x > 0) {
        while (now > pi * 4) {
            if (x - now > 0) {
                x -= now;
            }
            now /= 2.0;
        }
    } 
    else {
        while (now > pi * 4) {
            if (x + now < 0) {
                x += now;
            }
            now /= 2.0;
        }
    }
    if (x > 0) {
        while (x > 2 * pi) {
            x -= 2 * pi;
        }
    }
    else {
        while (x < -2 * pi) {
            x += 2 * pi;
        }
    }
    return x;
}

double my_sin(double x) {
    x = norm(x);
    double term = x;
    double sum = term;
    int n = 1;
    while (std::abs(term) > 1e-10) {
        term *= -x * x / ((2 * n) * (2 * n + 1));
        sum += term;
        n++;
    }
    return sum;
}

double my_cos(double x) {
    x = norm(x);
    double term = 1.0;;
    double sum = term;
    int n = 1;
    while (std::abs(term) > 1e-10) {
        term *= -x * x / ((2 * n) * (2 * n - 1));
        sum += term;
        n++;
    }
    return sum;
}

long double my_ln(long double x) {
    x = x < 0 ? -x : x;
    double E = e;
    long long n = 1, N = 0;
    while (x >= 2) {
        E = e;
        n = 1;
        while (x > E * E) {
            E *= E;
            n += n;
        }
        x /= E;
        N += n;
    }
    long double c = x - 1, d = -(x - 1), sum = 0;
    for (n = 1; n <= 50; n++, c *= d) {                           
      sum += c / n;
    }
    return sum + N;
}    

double min(double cos, double sin, double ln) {
    if (sin <= cos && sin <= ln) {
        return sin;
    }
    else if (cos <= sin && cos <= ln) {
        return cos;
    }
    else {
        return ln;
    }
}

bool is_digit(std::string &input) {
    for (char c : input) {
        if (isalpha(c)) {
            return false;
        }
    }
    return true;
}

void result() {
    double x;
    std::cout << "Введите значение x: ";
    while (!(std::cin >> x)) {
        std::cout << "Ошибка ввода. Введите корректное числовое значение x: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    double sinx = my_sin(x);
    double cosx = my_cos(x);
    double lnx = my_ln(x);

    std::cout << "sin(" << x << ") = " << sinx << '\n';
    std::cout << "cos(" << x << ") = " << cosx << '\n';
    if (x == 0) {
        std::cout << "Ошибка: натуральный логарифм недопустим для нуля.\n";
    } else {
        std::cout << "ln(|" << x << "|) = " << lnx << '\n';
        std::cout << "Минимальное значение: " << min(sinx, cosx, lnx) << '\n';
        std::cout << "lg(cmath) (" << x << ") = " << log(fabs(x)) << '\n'; 
        std::cout << "cos(cmath) (" << x << ") = " << cos(x) << '\n'; 
        std::cout << "sin(cmath) (" << x << ") = " << sin(x) << '\n'; 
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
        std::cout << "Желаете повторить программу (1 - да, 0 - нет)? ";
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