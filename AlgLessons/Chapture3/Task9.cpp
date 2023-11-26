#include <iostream>
#include <string>
#include <format>
#include "Task9.h"
#include <algorithm>

using namespace std;

/// <summary>
/// Запускает выполнение (Глава 3) Задача #9 (3.24)
/// Заголовок: Отрисовка фигур
/// Описание: 
///     
///     Испрользуйте подход, развитый в упражнениях 3.22 и 3.23, для со-
///     здания программы, которая вычерчивает широкий диапазон форм.
/// 
/// </summary>
/// <returns>Код результата выполнения программы</returns>
int runTask9()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// Отображаем документацию и базовое меню
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
Запуск решения (Глава 3) Задача #9 (3.24)...
Название: "Отрисовка фигур"
Описание: 
        
    Испрользуйте подход, развитый в упражнениях 3.22 и 3.23, для со-
    здания программы, которая вычерчивает широкий диапазон форм.

    Примечание: для работы программы необходимо будет ввести размерность фигур и их 
         
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
                    cout << "Программа запущена.\nВведите размер фигуры:" << endl;
                    cin >> input;
                    /// 
                    /// Определяем, является ли введенное значение допустимым значением (числом) и запускаем соответствующую задачу
                    /// 
                    if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                        int size = stoi(input);
                        string symbol;
                        cout << "Введите заполнитель для фигуры (1 символ):" << endl;
                        cin >> symbol;
                        if (symbol.size() == 1) {
                            cout << "Введите код фигуры (1 - квадрат, 2 - треугольник, 3 - ромб):" << endl;
                            cin >> input;
                            
                            if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                                int code = stoi(input);
                                switch (code) {
                                case 1:
                                    for (int i = 0; i < size; i++)
                                    {
                                        for (int j = 0; j < size; j++)
                                        {
                                            cout << format("{} ", symbol);
                                        }
                                        cout << endl;
                                    }
                                    isProgramEnding = true;
                                    break;
                                case 2:
                                    for (int i = 1; i <= size; i++) {
                                        for (int j = 1; j <= i; j++) {
                                            cout << format("{} ", symbol);
                                        }
                                        cout << endl;
                                    }
                                    isProgramEnding = true;
                                    break;
                                case 3:
                                    for (int i = 1; i <= size; i++)
                                    {
                                        for (int j = 0; j < (size - i); j++)
                                            std::cout << " ";
                                        for (int j = 1; j <= i; j++)
                                            cout << symbol;
                                        for (int j = 1; j < i; j++)
                                            cout << symbol;
                                        std::cout << endl;
                                    }
                                    for (int i = size - 1; i >= 1; i--)
                                    {
                                        for (int j = 0; j < (size - i); j++)
                                            std::cout << " ";
                                        for (int j = 1; j <= i; j++)
                                            std::cout << symbol;
                                        for (int j = 1; j < i; j++)
                                            std::cout << symbol;
                                        std::cout << endl;
                                    }
                                    isProgramEnding = true;
                                    break;
                                default:
                                    system("CLS");
                                    cout << "Введеное значение не соответствует допустимому (1, 2 или 3)!" << endl;
                                    break;
                                }
                            }
                        }
                        else {
                            system("CLS");
                            cout << "Требуется ввести только символ! Количество введенных символов отлично от 1" << endl;
                            continue;
                        }
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