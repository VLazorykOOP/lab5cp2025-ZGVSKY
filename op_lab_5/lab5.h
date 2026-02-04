#pragma once

#define _NO_W32_PSEUDO_MODIFIERS

#include <windows.h>

#include <vector>
#include <cmath>
#include <iostream>

struct Point {
    double x, y;
};

// Прототипи функцій малювання
void DrawHermiteCurve(HDC hdc, Point P1, Point P2, Point V1, Point V2);
void DrawDragonFractal(HDC hdc, int depth, Point P1, Point P2);
void DrawClouds(HDC hdc, int width, int height); // Задача 2.7

// Точка входу
int run_lab5();