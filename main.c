#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Логика игры
void guessTheLetter(char letters[], char goal) {
    setlocale(LC_ALL, "Russian");

    printf("Попробуйте угадать букву от a до z");

    int steps = 0; // Переменная для записи количества ходов

    while(1) 
    {
        char inputChar;
        printf("Введите ваш вариант буквы: ");
        inputChar = scanf("%c", &inputChar);

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
        break;
    }
}

// Функция для регистрации пользователя
string registerUser() 
{
    setlocale(LC_ALL, "Russian");

    string username;
    printf("Введите ваше имя для записи в таблицу рекордов: ");
    username = scanf("%s", username)
    return username;
}

// Функция для записи пользователя в таблицу рекордов
void writeInFile(string username) 
{

}

int main()
{
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char goal = letters[rand() % 27];

    registerUser();
    guessTheLetter(letters, goal);
    writeInFile(registerUser());
    
    return 0;
}
