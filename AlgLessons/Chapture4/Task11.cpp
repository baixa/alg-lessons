#include <iostream>
#include <string>
#include <format>
#include "Task11.h"

using namespace std;

/// <summary>
/// Запускает выполнение (Глава 4) Задача #11 (4.16)
/// Заголовок: Порядок обнуления элементов массива
/// Описание: 
///     
///     Укажите, в каком порядке будут обнуляться элементы двумерного
///     массива sales размером 3 на 5 следующим фрагментом программы:
/// 
///     for (row = 0; row < 3; row++)
///         for (column = 0; column < 5; column++)
///             sales[row] [column] = 0;
/// 
/// </summary>
/// <returns>Код результата выполнения программы</returns>
int runTask11()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// Отображаем документацию и базовое меню
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
Запуск решения (Глава 4) Задача #11 (4.16)...
Название: "Порядок обнуления элементов массива"
Описание: 
        
    Укажите, в каком порядке будут обнуляться элементы двумерного
    массива sales размером 3 на 5 следующим фрагментом программы:
 
    for (row = 0; row < 3; row++)
         for (column = 0; column < 5; column++)
             sales[row] [column] = 0;
         
Для запуска программы введите команду Y. Для выхода введите команду \q.)STRING" << endl;

        cin >> input;

        /// 
        /// Определяем, является ли введенное значение допустимым
        /// 
        if (input == "Y" || input == "y") {
            while (input != "\\q") {
                system("CLS");

                cout <<
                    R"STRING(
Алгоритм содержит два цикла, выполняющих последовательный перебор элементов. Порядок перебора элементов состоит в переборе с 0 до последнего 
элемента сначала 0 строки, затем 1 строки, затем второй и т.д.  

Подтверждение результата (выполнение программы, приведенной в задании предоставлено ниже):
                )STRING" << endl;

                int sales[3][5] = {};
                for (int i = 0; i < size(sales); i++)
                {
                    for (int j = 0; j < size(sales[i]); j++)
                    {
                        sales[i][j] = 1;
                    }
                }
                int row, column;
                for (row = 0; row < 3; row++) {
                    for (column = 0; column < 5; column++) {
                        sales[row][column] = 0;
                        
                        // Вывод промежуточного результата
                        cout << format("Этап {}:", column + row * 5 + 1) << endl;
                        for (int i = 0; i < size(sales); i++)
                        {
                            for (int j = 0; j < size(sales[i]); j++)
                            {
                                cout << sales[i][j] << " ";
                            }
                            cout << endl;
                        }
                        cout << "\n\n";
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