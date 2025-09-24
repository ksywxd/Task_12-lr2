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
    if (D < 0) {
        std::cout << "Нет действительных корней.\n";
        return;
    }
    else if (D == 0) {
        x1 = -b / (2 * a);
    }
    else {
        double y1 = (-b + cor(D)) / (2 * a);
        double y2 = (-b - cor(D)) / (2 * a);
    }
}

void solveType2(double a, double b, double c) {
    std::cout << "\nТип 2: Симметричное уравнение\n";
    if (a == 0) {
        std::cout << "Это не симметричное уравнение.\n";
        return;
    }

    // az^2 + bz + (c-2a) = 0

    