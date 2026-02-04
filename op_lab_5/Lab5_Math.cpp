#include "lab5.h"
#include <random>

//Крива Ерміта
void DrawHermiteCurve(HDC hdc, Point P1, Point P2, Point V1, Point V2) {
    // Встановлюємо червоний колір для кривої
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, (int)P1.x, (int)P1.y, NULL);

    // t змінюється від 0 до 1 з малим кроком
    for (double t = 0; t <= 1.0; t += 0.005) {
        double t2 = t * t;
        double t3 = t * t * t;

        // Базисні функції Ерміта
        double h1 = 2 * t3 - 3 * t2 + 1;
        double h2 = -2 * t3 + 3 * t2;
        double h3 = t3 - 2 * t2 + t;
        double h4 = t3 - t2;

        // Обчислення координат
        double x = h1 * P1.x + h2 * P2.x + h3 * V1.x + h4 * V2.x;
        double y = h1 * P1.y + h2 * P2.y + h3 * V1.y + h4 * V2.y;

        LineTo(hdc, (int)x, (int)y);
    }
    DeleteObject(hPen);
}

// Фрактал
void DrawDragonFractalRecursive(HDC hdc, int depth, Point P1, Point P2, int sign) {
    if (depth == 0) {
        MoveToEx(hdc, (int)P1.x, (int)P1.y, NULL);
        LineTo(hdc, (int)P2.x, (int)P2.y);
    } else {
        // Знаходимо вершину рівнобедреного трикутника
        Point P3;
        P3.x = (P1.x + P2.x) / 2 + sign * (P2.y - P1.y) / 2;
        P3.y = (P1.y + P2.y) / 2 - sign * (P2.x - P1.x) / 2;

        // Рекурсивний виклик для двох нових відрізків
        DrawDragonFractalRecursive(hdc, depth - 1, P1, P3, 1);
        DrawDragonFractalRecursive(hdc, depth - 1, P3, P2, -1); // Зміна знаку
    }
}

// Функція для xмар
void DrawClouds(HDC hdc, int width, int height) {
    std::random_device rd;
    std::mt19937 gen(rd());

    // Випадкові координати
    std::uniform_int_distribution<> distX(50, width - 50);
    std::uniform_int_distribution<> distY(50, height / 2); // Хмари зверху
    std::uniform_int_distribution<> distColor(100, 255); // Відтінки синього
    std::uniform_int_distribution<> distLen(50, 150);

    // Малюємо 10 хмар
    for (int i = 0; i < 10; ++i) {
        int blue = distColor(gen);
        HPEN hPen = CreatePen(PS_SOLID, 1, RGB(100, 100, blue)); // Різні відтінки синього
        SelectObject(hdc, hPen);

        Point start;
        start.x = distX(gen);
        start.y = distY(gen);

        Point end;
        end.x = start.x + distLen(gen);
        end.y = start.y; // Горизонтальна основа хмари

        // Порядок рекурсії 10-14 дає класну пухнастість
        DrawDragonFractalRecursive(hdc, 12, start, end, 1);

        DeleteObject(hPen);
    }
}