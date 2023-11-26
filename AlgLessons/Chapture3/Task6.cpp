#include <iostream>
#include <string>
#include <format>
#include "Task6.h"
#include <algorithm>

using namespace std;

/// <summary>
/// Запускает выполнение (Глава 3) Задача #6 (3.21)
/// Заголовок: Функция проверки четности числа
/// Описание: 
///     
///     Напишите программу, которая вводит посделовательность целых
///     чисел и передает их по одному функции even, которая использует 
///     операцию вычисления остатка для определения четности числа.
///     Функция должна принимать целый аргумент и возращать 1, если
///     аргумент - четное число, и 0 в противном случае
/// 
/// </summary>
/// <returns>Код результата выполнения программы</returns>
int runTask6()
{
    system("chcp 1251");
    std::string input;

    while (input != "\\q") {
        /// 
        /// Отображаем документацию и базовое меню
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
Запуск решения (Глава 3) Задача #6 (3.21)...
Название: "Функция проверки четности числа"
Описание: 
        
    Напишите программу, которая вводит посделовательность целых
    чисел и передает их по одному функции even, которая использует 
    операцию вычисления остатка для определения четности числа.
    Функция должна принимать целый аргумент и возращать 1, если
    аргумент - четное число, и 0 в противном случае
        
Для запуска программы введите команду Y. Для выхода введите команду \q.)STRING" << endl;

        cin >> input;

        /// 
        /// Определяем, является ли введенное значение допустимым
        /// 
        if (input == "Y" || input == "y") {
            while (input != "\\q") {
                system("CLS");
                bool isProgramEnding = false;
                while (!isProgramEnding) {
                    cout << "Программа запущена.\nВведите количество чисел, которые будут введены в программу:" << endl;
                    cin >> input;
                    /// 
                    /// Определяем, является ли введенное значение допустимым значением (числом) и запускаем соответствующую задачу
                    /// 
                    if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                        int count = stoi(input);
                        int* values = new int[count];
                        int lengthVals = count;
                        while(count > 0)
                        {
                            cout << std::format("Введите {}-е число: ", lengthVals - count + 1) << endl;
                            cin >> input;
                            if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                                values[count - 1] = stoi(input);
                                --count;
                            }
                            else
                            {
                                cout << "Введенное значение не является числом!" << endl;
                            }
                        }
                        cout << "\n\n-----------------------\n" << endl;
                        for (int i = lengthVals - 1; i >= 0; i--)
                        {
                            cout << std::format("{}. Функция even с аргументом {} вернула значение {}", lengthVals - i, values[i], even(values[i]))
                                 << endl;
                            isProgramEnding = true;
                        }
                    }
                    else {
                        cout << "Введенное значение не является числом!" << endl;
                    }
                }
                cout << "\n\nДля выхода введите \\q" << endl;
                cin >> input;
            }
        }
    }
    system("CLS");
    std::cout << "Завершение работы программы программы...";

    return 0;
}

int even(int value) {
    return value % 2 ? 0 : 1;
}
