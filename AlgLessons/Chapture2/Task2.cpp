#include <iostream>
#include <string>
#include <format>
#include "Task2.h"

using namespace std;

/// <summary>
/// Запускает выполнение (Глава 2) Задача #2 (2.22)
/// Заголовок: Поиск наибольших значений из 10 чисел
/// Описание: Используя подход упражнения 2.20, найдите два наибольших значения их 10 чисел. 
///             Указание: вы можете ввести каждое число только один раз
/// </summary>
/// <returns>Код результата выполнения программы</returns>
int runTask2()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// Отображаем документацию и базовое меню
        /// 
        system("CLS");

        std::cout << "Запуск решения (Глава 2) Задачи #2 (2.22)...\n" <<
            "Название: \"Поиск наибольших значений из 10 чисел\"\n" <<
            "Описание: Используя подход упражнения 2.20, найдите два наибольших значения их 10 чисел. " <<
            " Указание: вы можете ввести каждое число только один раз." << 
            " Для запуска программы введите команду Y. Для выхода введите команду \\q. ";

        cin >> input;

        /// 
        /// Определяем, является ли введенное значение допустимым
        /// 
        if (input == "Y" || input == "y") {
            while (input != "\\q") {
                system("CLS");
                
                int number;
                int largest;
                int largest_2;

                for (int counter = 0; counter < 10; counter++)
                {
                    cout << format("Введите {}-е число (при вводе нечислового значения устанавливается значение 0): ", counter + 1) << endl;
                    cin >> number;
                    if (counter == 0) {
                        largest = number;
                    }
                    else if (counter == 1) {
                        if (largest < number) {
                            largest_2 = number;
                        }
                        else {
                            largest_2 = largest;
                            largest = number;
                        }
                    }
                    else {
                        if (largest_2 < number) {
                            if (largest < number) {
                                largest_2 = largest;
                                largest = number;
                            }
                            else {
                                largest_2 = number;
                            }
                        }
                    }
                }
                cout << format("Наибольшие введеные значения: {}, {}", largest, largest_2) << endl;

                cout << "\n\nДля выхода введите \\q" << endl;
                cin >> input;
            }
        }
    }
    system("CLS");
    std::cout << "Завершение работы программы программы...";

    return 0;
}
