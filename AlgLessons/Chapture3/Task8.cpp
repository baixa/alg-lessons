#include <iostream>
#include <string>
#include <format>
#include "Task8.h"

using namespace std;

/// <summary>
/// Запускает выполнение (Глава 3) Задача #8 (3.23)
/// Заголовок: Отрисовка квадрата из символов
/// Описание: 
///     
///     Модифицируйте функцию, созданнуб в упражнении 3.22, так,
///     чтобы формировать квадрат из какихт угодно символов, указанных
///     в символьном параметре fillCharacter. Таким образом, если side
///     равна 5 и fillCharacter равен #, то эта функция должна напечатать:
///     
///     # # # # #
///     # # # # #
///     # # # # #
///     # # # # #
///     # # # # #
/// 
/// </summary>
/// <returns>Код результата выполнения программы</returns>
int runTask8()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// Отображаем документацию и базовое меню
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
Запуск решения (Глава 3) Задача #7 (3.22)...
Название: "Отрисовка квадрата из символов"
Описание: 
        
    Модифицируйте функцию, созданнуб в упражнении 3.22, так,
    чтобы формировать квадрат из какихт угодно символов, указанных
    в символьном параметре fillCharacter. Таким образом, если side
    равна 5 и fillCharacter равен #, то эта функция должна напечатать:
     
    # # # # #
    # # # # #
    # # # # #
    # # # # #
    # # # # #
        
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
                    cout << "Программа запущена.\nВведите размер квадрата:" << endl;
                    cin >> input;
                    /// 
                    /// Определяем, является ли введенное значение допустимым значением (числом) и запускаем соответствующую задачу
                    /// 
                    if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                        int size = stoi(input);
                        string symbol;
                        cout << "Введите заполнитель для квадрата (1 символ):" << endl;
                        cin >> symbol;
                        if (symbol.size() == 1) {
                            for (int i = 0; i < size; i++)
                            {
                                for (int j = 0; j < size; j++)
                                {
                                    cout << format("{} ", symbol);
                                }
                                cout << endl;
                            }
                            isProgramEnding = true;
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