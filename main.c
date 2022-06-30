#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WIN32_WINNT 0x0A00
#include <windows.h>
#define WIDTH 400
#define HEIGHT 300
#define ID_EDIT 1
#define ID_BUTTON1 2
#define ID_BUTTON2 3

char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

LRESULT CALLBACK WndProc( HWND, UINT, WPARAM, LPARAM );

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int nShowCmd )
{
    HWND hwnd;
    MSG  msg;
    WNDCLASSW wc = {0};
    wc.lpszClassName = L"Edit control";
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);

    RegisterClassW(&wc);
    hwnd = CreateWindowW(wc.lpszClassName, L"Edit control",
                  WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  220, 220, WIDTH, HEIGHT, 0, 0, hInstance, 0);

    while (GetMessage(&msg, NULL, 0, 0)) {

      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    static HWND name;
    static HWND bukva;
    static HWND label1;
    static HWND label2;
    static HWND label3;
    int zBukva;
    int steps = 0;
    char goal;
    HWND start;
    HWND check;
    HWND showWin;
    wchar_t nickname[255];
    // char name[255];
    char parol[255];


    switch(msg) {

        case WM_CREATE:
            label1 = CreateWindowW(L"static", L"Nickname: ",
                WS_VISIBLE | WS_CHILD, 100, 50, 70, 20,
                hwnd, (HMENU) NULL, NULL, NULL);
            name = CreateWindowW(L"Edit", NULL,
                WS_CHILD | WS_VISIBLE | WS_BORDER,
                100, 70, 150, 20, hwnd, (HMENU) ID_EDIT,
                NULL, NULL);
            start = CreateWindowW(L"button", L"Start",
                WS_VISIBLE | WS_CHILD, 100, 95, 80, 25,
                hwnd, (HMENU) ID_BUTTON1, NULL, NULL);
            break;

        case WM_COMMAND:
            if (LOWORD(wParam) == ID_BUTTON1)
            {

                int len1 = GetWindowTextLengthW(name) + 1;

                if (len1 > 3)
                {
                    nickname[len1];

                    GetWindowTextW(name, nickname, 30);
                    SetWindowTextW(hwnd, nickname);

                    label2 = CreateWindowW(L"static", L"Bukva: ",
                        WS_VISIBLE | WS_CHILD, 100, 130, 70, 20,
                        hwnd, (HMENU) NULL, NULL, NULL);
                    bukva = CreateWindowW(L"Edit", NULL,
                        WS_CHILD | WS_VISIBLE | WS_BORDER,
                        100, 155, 150, 20, hwnd, (HMENU) ID_EDIT,
                        NULL, NULL);
                    check = CreateWindowW(L"button", L"Start",
                        WS_VISIBLE | WS_CHILD, 100, 180, 80, 25,
                        hwnd, (HMENU) ID_BUTTON2, NULL, NULL);

                    goal = letters[rand() % 27];
                    printf("%d\n", goal);
                }
                else
                {
                    MessageBox(hwnd, "Имя должно содержать больше 3 символов!", "Ошибка", 1);
                }

            }

            if (LOWORD(wParam) == ID_BUTTON2)
            {
                wchar_t otvet[1];
                GetWindowTextW(bukva, otvet, 30);
                printf("%d\n", otvet);

                if(otvet > goal)
                {
                    MessageBox(hwnd, "Загаданная буква находится левее", "Попробуй еще раз!", 1);
                    steps++;
                }
                else if(otvet < goal)
                {
                    MessageBox(hwnd, "Загаданная буква находится правее", "Попробуй еще раз!", 1);
                    steps++;
                }
                else if(otvet == goal)
                {
                    MessageBox(hwnd, "Отлично ты справился!", "Угадал", 1);
                    steps++;

                    FILE *f;
                    f = fopen("test.txt", "w");
                    fprintf(f, "%s - %d", nickname, steps);

                    fclose(f);
                }
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}
