// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <conio.h>

bool proverka_date(const char* date) {
    if (strlen(date) != 10) return false;

    if (date[2] != '.' || date[5] != '.') return false;

    for (int i = 0; i < 10; ++i) {
        if (i != 2 && i != 5 && (date[i] < '0' || date[i] > '9')) {
            return false;
        }
    }

    int day = (date[0] - '0') * 10 + (date[1] - '0');
    int month = (date[3] - '0') * 10 + (date[4] - '0');
    int year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');

    return (day >= 1 && day <= 31 && month >= 1 && month <= 12 && year > 0);
}

bool proverka_time(const char* time) {
    if (strlen(time) != 8) return false;

    if (time[2] != ':' || time[5] != ':') return false;

    for (int i = 0; i < 8; ++i) {
        if (i != 2 && i != 5 && (time[i] < '0' || time[i] > '9')) {
            return false;
        }
    }

    int hour = (time[0] - '0') * 10 + (time[1] - '0');
    int minute = (time[3] - '0') * 10 + (time[4] - '0');
    int second = (time[6] - '0') * 10 + (time[7] - '0');

    
    return (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59 && second >= 0 && second <= 59);
}


int main() {
    setlocale(LC_ALL, "RU");
    char day[25];
    char time_begin[25];
    char time_end[25];

    std::cout << "День: ";
    std::cin >> day;
    if (!proverka_date(day))
    {
        std::cout << "Ошибка с вводом данных поля День";
        return 0;
    }
    std::cout << "Время начала: ";
    std::cin >> time_begin;
    if (!proverka_time(time_begin))
    {
        std::cout << "Ошибка с вводом данных поля День";
        return 0;
    }
    std::cout << "Время окончания: ";
    std::cin >> time_end;
    if (!proverka_time(time_end))
    {
        std::cout << "Ошибка с вводом данных поля День";
        return 0;
    }

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

    return 0;
}
