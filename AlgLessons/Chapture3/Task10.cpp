#include <iostream>
#include <string>
#include <format>
#include "Task10.h"

using namespace std;

/// <summary>
/// Запускает выполнение (Глава 3) Задача #10 (3.25)
/// Заголовок: Фрагменты программ для обработки чисел
/// Описание: 
///     
///     Напишите фрагменты программ, которые бы выполняли следующее:
///     
///     а) Вычислить целую часть частное от деления целого числа а на
///     целое число b.
/// 
///     b) Вычислить целый остаток от деления целого числа а на целое
///     число b.
/// 
///     c) Использовать фрагменты программ, созданные в пунктах a) и b),
///     для написания функции, котрая вводит целое число из диапазона
///     от 1 до 32767 и печатает его как последовательность цифр, каждая
///     из которых отделена от соседней двумя пробелами. Например, целое
///     число 4562 должно быть напечатано в виде
///     
///     4 5 6 2
/// 
/// </summary>
/// <returns>Код результата выполнения программы</returns>
int runTask10()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// Отображаем документацию и базовое меню
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
Запуск решения (Глава 3) Задача #10 (3.25)...
Название: "Фрагменты программ для обработки чисел"
Описание: 
        
    Напишите фрагменты программ, которые бы выполняли следующее:
     
    а) Вычислить целую часть частное от деления целого числа а на
    целое число b.

    b) Вычислить целый остаток от деления целого числа а на целое
    число b.

    c) Использовать фрагменты программ, созданные в пунктах a) и b),
    для написания функции, котрая вводит целое число из диапазона
    от 1 до 32767 и печатает его как последовательность цифр, каждая
    из которых отделена от соседней двумя пробелами. Например, целое
    число 4562 должно быть напечатано в виде
     
    4 5 6 2
         
Для запуска программы введите команду Y. Для выхода введите команду \\q.)STRING" << endl;

        cin >> input;

        /// 
        /// Определяем, является ли введенное значение допустимым
        /// 
        if (input == "Y" || input == "y") {
            while (input != "\\q") {
                system("CLS");
                bool isProgramEnding = false;
                while (!isProgramEnding) {
                    int a, b;
                    cout << "Пункт а. Введите число а для вычисления целой части частного от деления: " << endl;
                    cin >> input;
                    if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                        a = stoi(input);
                        cout << "Введите число b: " << endl;
                        cin >> input;
                        if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                            b = stoi(input);
                            cout << format("Результат работы функции из пункта а. Входные параметры: а = {}, b = {}. Результат: {}", a, b, 
                                intDivide(a , b)) << endl;
                            isProgramEnding = true;
                        }
                        else {
                            system("CLS");
                            cout << "Введенное значение не является числом!" << endl;
                            continue;
                        }
                    }
                    else {
                        system("CLS");
                        cout << "Введенное значение не является числом!" << endl;
                        continue;
                    }
                    
                }
                isProgramEnding = false;
                while (!isProgramEnding) {
                    int a, b;
                    cout << "Пункт b. Введите число а для вычисления целого остатка от деления: " << endl;
                    cin >> input;
                    if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                        a = stoi(input);
                        cout << "Введите число b: " << endl;
                        cin >> input;
                        if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                            b = stoi(input);
                            cout << format("Результат работы функции из пункта b. Входные параметры: а = {}, b = {}. Результат: {}", a, b, 
                                divideByRemainder(a, b)) << endl;
                            isProgramEnding = true;
                        }
                        else {
                            system("CLS");
                            cout << "Введенное значение не является числом!" << endl;
                            continue;
                        }
                    }
                    else {
                        system("CLS");
                        cout << "Введенное значение не является числом!" << endl;
                        continue;
                    }
                }
                isProgramEnding = false;
                while (!isProgramEnding) {
                    int value;
                    cout << "Пункт c. Введите число печати его последовательности: " << endl;
                    cin >> input;
                    if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                        value = stoi(input);
                        cout << format("Результат работы функции из пункта c. Входные параметры: а = {}. Результат: {}", value,
                            numToSequence(value)) << endl;
                        isProgramEnding = true;
                    }
                    else {
                        system("CLS");
                        cout << "Введенное значение не является числом!" << endl;
                        continue;
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

int intDivide(int x, int y) {
    return x / y;
}

int divideByRemainder(int x, int y) {
    return x % y;
}

string numToSequence(int value) {
    string result = "";
    while (value > 0) {
        result = format("{} ", divideByRemainder(value, 10)) + result;
        value = intDivide(value, 10);
    }
    return result;
}