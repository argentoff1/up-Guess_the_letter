#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char goal[27] = letters[rand() % 27];

    registerUser();
    guessTheLetter(letters, goal);
    writeInFile(registerUser());

    return 0;
}

// Логика игры
void guessTheLetter(char letters[26], char goal[26]) {
    setlocale(LC_ALL, "Russian");

    int steps = 0; // Переменная для записи количества ходов
    char inputChar[1];

    printf("Попробуйте угадать букву от a до z");

    while(1)
    {
        printf("Введите ваш вариант буквы: ");
        inputChar = scanf("%s", &inputChar);

        while(1)
        {
            if(inputChar > goal)
            {
                printf("Загаданная буква находится левее");
                steps++;
            }
            else if(inputChar < goal)
            {
                printf("Загаданная буква находится правее");
                steps++;
            }
            else if(inputChar == goal)
            {
                printf("Угадал");
                steps++;
                break;
            }
        }
    }
}

// Функция для регистрации пользователя
char registerUser()
{
    setlocale(LC_ALL, "Russian");

    char username[20];
    printf("Введите ваше имя для записи в таблицу рекордов: ");
    username = scanf("%s", username);

    return username;
}

// Функция для записи пользователя в таблицу рекордов
void writeInFile(char username[20])
{
    FILE *f;
    f = fopen("test.txt", "w");
    fprintf(f, "%s", username);

    fclose(f);
}
