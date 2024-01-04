﻿#include <iostream>
#include <string>
#include "Chaptures.h"
#include <algorithm>
#include <windows.h>

int main()
{
    system("chcp 1251");
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

    std::string input;
    const int MIN_TASK_NUMBER = 1;
    const int MAX_TASK_NUMBER = 20;

    while (input != "\\q") {
        /// 
        /// Отображаем документацию и базовое меню
        /// 
        system("CLS");
        std::cout << "Программа содержит решения задач, доступных в конце 2-5 глав учебника по С++. " <<
            "Ниже приведен список задач, решения которых доступны к просмотру. Рядом с программой доступен цифровой код, который необходимо ввести. " <<
            "После ввода будет отображена дополнительная информация по задаче с предложением запуска решения по ней. " <<
            "Запуск решения задачи посволит протестировать его, оценить ее работоспособность. Для выхода введите команду \\q. " <<
            "Для дополнительной информации по программе изучите документацию, приведенную в файле README.md\n";

        std::cout   << "|\t___\t|\t___________________________\t|\t__________\t|\t___\t|\t\n"
                    << "|\t # \t|\tСписок доступных задач     \t|\tНазвание  \t|\tКод\t|\t\n"
                    << "|\t___\t|\t___________________________\t|\t__________\t|\t___\t|\t\n"
                    << "|\t 1 \t|\t(Глава 2) Задача #1 (2.21) \t|\tНазвание #\t|\t1  \t|\t\n"
                    << "|\t 2 \t|\t(Глава 2) Задача #2 (2.22) \t|\tНазвание #\t|\t2  \t|\t\n"
                    << "|\t 3 \t|\t(Глава 2) Задача #3 (2.23) \t|\tНазвание #\t|\t3  \t|\t\n"
                    << "|\t 4 \t|\t(Глава 2) Задача #4 (2.24) \t|\tНазвание #\t|\t4  \t|\t\n"
                    << "|\t 5 \t|\t(Глава 2) Задача #5 (2.25) \t|\tНазвание #\t|\t5  \t|\t\n"
                    << "|\t 6 \t|\t(Глава 3) Задача #6 (3.21) \t|\tНазвание #\t|\t6  \t|\t\n"
                    << "|\t 7 \t|\t(Глава 3) Задача #7 (3.22) \t|\tНазвание #\t|\t7  \t|\t\n"
                    << "|\t 8 \t|\t(Глава 3) Задача #8 (3.23) \t|\tНазвание #\t|\t8  \t|\t\n"
                    << "|\t 9 \t|\t(Глава 3) Задача #9 (3.24) \t|\tНазвание #\t|\t9  \t|\t\n"
                    << "|\t 10\t|\t(Глава 3) Задача #10 (3.25)\t|\tНазвание #\t|\t10 \t|\t\n"
                    << "|\t 11\t|\t(Глава 4) Задача #11 (4.16)\t|\tНазвание #\t|\t11 \t|\t\n"
                    << "|\t 12\t|\t(Глава 4) Задача #12 (4.17)\t|\tНазвание #\t|\t12 \t|\t\n"
                    << "|\t 13\t|\t(Глава 4) Задача #13 (4.18)\t|\tНазвание #\t|\t13 \t|\t\n"
                    << "|\t 14\t|\t(Глава 4) Задача #14 (4.26)\t|\tНазвание #\t|\t14 \t|\t\n"
                    << "|\t 15\t|\t(Глава 4) Задача #15 (4.35)\t|\tНазвание #\t|\t15 \t|\t\n"
                    << "|\t 16\t|\t(Глава 5) Задача #16 (5.11)\t|\tНазвание #\t|\t16 \t|\t\n"
                    << "|\t 17\t|\t(Глава 5) Задача #17 (5.26)\t|\tНазвание #\t|\t17 \t|\t\n"
                    << "|\t 18\t|\t(Глава 5) Задача #18 (5.28)\t|\tНазвание #\t|\t18 \t|\t\n"
                    << "|\t 19\t|\t(Глава 5) Задача #19 (5.32)\t|\tНазвание #\t|\t19 \t|\t\n"
                    << "|\t 20\t|\t(Глава 5) Задача #20 (5.35)\t|\tНазвание #\t|\t20 \t|\t\n";

        std::cin >> input;

        /// 
        /// Определяем, является ли введенное значение допустимым значением (числом) и запускаем соответствующую задачу
        /// 
        if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()
            && stoi(input) >= MIN_TASK_NUMBER && stoi(input) <= MAX_TASK_NUMBER) {
            switch (stoi(input))
            {
                case 1:
                    runTask1();
                    break;
                case 2:
                    runTask2();
                    break;
                case 3:
                    runTask3();
                    break;
                case 4:
                    runTask4();
                    break;
                case 5:
                    runTask5();
                    break;
                case 6:
                    runTask6();
                    break;
                case 7:
                    runTask7();
                    break;
                case 8:
                    runTask8();
                    break;
                case 9:
                    runTask9();
                    break;
                case 10:
                    runTask10();
                    break;
                case 11:
                    runTask11();
                    break;
                case 12:
                    runTask12();
                    break;
                case 13:
                    runTask13();
                    break;
                case 14:
                    runTask14();
                    break;
                case 15:
                    runTask15();
                    break;
                case 16:
                    runTask16();
                    break;
                case 17:
                    runTask17();
                    break;
                case 18:
                    runTask18();
                    break;
                case 19:
                    runTask19();
                    break;
                case 20:
                    runTask20();
                    break;
                default:
                    break;
            }
            input = "";
        }
    }
    system("CLS");
    std::cout << "Завершение работы программы программы...\n";
}
