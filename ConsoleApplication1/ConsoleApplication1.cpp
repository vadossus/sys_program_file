// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <conio.h>



int main() {
    setlocale(LC_ALL, "RU");
    char day[25];
    char time_begin[25];
    char time_end[25];

    std::cout << "День: ";
    std::cin >> day;
    std::cout << "Время начала: ";
    std::cin >> time_begin;
    std::cout << "Время окончания: ";
    std::cin >> time_end;

    FILE* file;
    errno_t err = fopen_s(&file, "1.txt", "a");

    if (err != 0 || file == NULL) {
        std::cout << "Файл невозможно открыть или создать" << std::endl;
    }
    else {
        fprintf(file, "%s | %s | %s\n", day, time_begin, time_end);
        fclose(file);
        std::cout << "Файл записан" << std::endl;
    }

    _getch();
    return 0;
}
