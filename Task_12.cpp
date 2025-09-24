#include <iostream>

double cor(double x) {
    if (x < 0) return -1;
    double low = 0, high = x >= 1 ? x : 1, mid;
    for (int i = 0; i < 100; i++) {
        mid = (low + high) / 2;
        double square = mid * mid;
        if (square - x < 1e-10 && square - x > -1e-10) return mid;
        if (square < x) low = mid;
        else high = mid;
    }
    return mid;
}

void kvad(double a, double b, double c, double& x1, double& x2) {
    double D = b * b - 4 * a * c;
    if (D < 0) return;
    else if (D == 0) {
        x1 = -b / (2 * a);
    }
    else {
        x1 = (-b + cor(D)) / (2 * a);
        x2 = (-b - cor(D)) / (2 * a);
    }
}

void solveType2(double a, double b, double c) {
    std::cout << "Тип 2: Симметричное уравнение\n";
    if (a == 0) {
        std::cout << "Это не симметричное уравнение.\n";
        return;
    }

    // az^2 + bz + (c-2a) = 0
    double z1, z2, x1, x2, x3, x4;
    double D = b * b - 4 * a * (c - 2 * a);
    if (D < 0) {
        std::cout << "Нет действительных корней.\n";
        return;
    }
    else if (D == 0) {
        z1 = -b / (2 * a);
        kvad(1, -z1, 1, x1, x2);
        std::cout << x1 << " " << x2;
    }
    else {
        z1 = (-b + cor(D)) / (2 * a);
        z2 = (-b - cor(D)) / (2 * a);
        kvad(1, -z1, 1, x1, x2);
        kvad(1, -z2, 1, x3, x4);
        std::cout << x1 << " " << x2 << " " << x3 << " " << x4;
    }

}

int main() {
    setlocale(LC_ALL, "RU");
    double a, b, c;
    std::cout << "Введите a, b, c: ";
    std::cin >> a >> b >> c;
    solveType2(a, b, c);
}