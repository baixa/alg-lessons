#include <iostream>
#include <string>
#include <format>
#include "Task13.h"

using namespace std;

int whatIsThis(int[], int);

/// <summary>
/// Запускает выполнение (Глава 4) Задача #13 (4.18)
/// Заголовок: Что делает программа
/// Описание: 
///     
///     Что делает следующая программа?
/// 
///     int whatIsThis(int [ ], int);
///     main()
///     {
///         int arraySize = 10;
///         int a[arraySize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
///     
///         int result = whatIsThis(a, arraySize);
///         cout << "Результат равен " << result << endl;
/// 
///         return 0;
///     }
///     int whatIsThis(int b[ ], int size)
///     {
///         if (size == 1)
///             return b[0];
///         else
///             return b[size - 1] + whatIsThis(b, size - 1);
///     }
///     
/// 
/// </summary>
/// <returns>Код результата выполнения программы</returns>
int runTask13()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// Отображаем документацию и базовое меню
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
Запуск решения (Глава 4) Задача #13 (4.18)...
Название: "Что делает программа"
Описание: 
        
        Что делает следующая программа?
 
         const int whatIsThis(int [ ], int);
         main()
         {
             int arraySize = 10;
             int a[arraySize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     
             int result = whatIsThis(a, arraySize);
             cout << "Результат равен " << result << endl;
 
             return 0;
         }
         int whatIsThis(int b[ ], int size)
         {
             if (size == 1)
                 return b[0];
             else
                 return b[size - 1] + whatIsThis(b, size - 1);
         }
         
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
Программа имеет две функции, одна из который main - вызывается при запуске программы, а другая, whatIsThis, выполняет подсчет суммы элементов в массиве. 
Используя метод рекурсии функция whatIsThis подсчитывает сумму элементов в массиве, уменьшая при каждом вызове самой себя значение параметра size на 1.
При получении size = 1, функция возвращает нулевой элемент массива, в ином случае она возвращает сумму (size-1)-нного элемента массива и значения функции
при передаче ей в качестве аргументов того же массива и значения size, уменьшенного на 1. В данном случае программа выведет строку "Результат равен 55"

Подтверждение результата (выполнение программы, приведенной в задании предоставлено ниже):
                )STRING" << endl;

                const int arraySize = 10;
                int a[arraySize] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

                int result = whatIsThis(a, arraySize);
                cout << "Результат равен " << result << endl;

                cout << "\n\nДля выхода введите \\q" << endl;
                cin >> input;
            }
        }
    }
    system("CLS");
    std::cout << "Завершение работы программы программы...";

    return 0;
}

int whatIsThis(int b[], int size)
{
    if (size == 1)
        return b[0];
    else
        return b[size - 1] + whatIsThis(b, size - 1);
}