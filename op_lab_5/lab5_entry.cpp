#include "Lab5.h"

// Обробник повідомлень вікна
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // Очистка фону (білий)
            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

            // --- ЗАДАЧА 1.1: Крива Ерміта ---
            TextOut(hdc, 10, 10, "Task 1.1: Hermite Curve (Red)", 29);
            Point P1 = {100, 400}, P2 = {400, 400};
            // Вектори задають напрямок вигину
            Point V1 = {100, -300}, V2 = {100, -300};
            DrawHermiteCurve(hdc, P1, P2, V1, V2);

            // --- ЗАДАЧА 2.7: Хмарне небо ---
            TextOut(hdc, 10, 50, "Task 2.7: Cloudy Sky (Fractals)", 31);
            RECT rect;
            GetClientRect(hwnd, &rect);
            DrawClouds(hdc, rect.right, rect.bottom);

            EndPaint(hwnd, &ps);
            return 0;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int run_lab5() {
    // 1. Реєстрація класу вікна
    const char CLASS_NAME[] = "Lab5_Graphics_Window";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW); // Курсор-стрілка

    RegisterClass(&wc);

    // 2. Створення вікна
    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, "Laboratory Work 5: Graphics",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, // Розмір 800x600
        NULL, NULL, GetModuleHandle(NULL), NULL
    );

    if (hwnd == NULL) return 0;

    ShowWindow(hwnd, SW_SHOW);

    // 3. Цикл повідомлень (тримає вікно відкритим)
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}