#include <iostream>
#include <string>
#include <format>
#include "Task18.h"

using namespace std;

/// <summary>
/// Запускает выполнение (Глава 5) Задача #18 (5.30)
/// Заголовок: Что делает эта программа?
/// Описание: 
/// 
///     Что делает эта программа?
///     
///     #include <iostream.h>
///     int mystery3(const char *, const char *);
/// 
///     main()
///     {
///         char string1 [80], string2 [80];
///         
///         cout << " Введите две строки: ";
///         cin >> string1 >> string2;
///         cout << " Результат равен: "
///             << mystery3(string1, string2) << endl;
///         return 0;
///     }
///     
///     int mystery3(const char *s1, const char *s2)
///     {
///         for ( ; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
///             if (*s1 != *s2)
///                 return 0;
///         return 1;
///     }
/// 
/// </summary>
/// <returns>Код результата выполнения программы</returns>
int runTask18()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// Отображаем документацию и базовое меню
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
Запуск решения (Глава 5) Задача #18 (5.30)...
Название: "Что делает эта программа"
Описание: 
        
        Что делает эта программа?
     
        #include <iostream.h>
        int mystery3(const char *, const char *);
 
        main()
        {
            char string1 [80], string2 [80];
         
            cout << " Введите две строки: ";
            cin >> string1 >> string2;
            cout << " Результат равен: "
                << mystery3(string1, string2) << endl;
            return 0;
        }
     
        int mystery3(const char *s1, const char *s2)
        {
            for ( ; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
                if (*s1 != *s2)
                    return 0;
            return 1;
        }
    
         
Для запуска программы введите команду Y. Для выхода введите команду \q.)STRING" << endl;

        cin >> input;

        /// 
        /// Определяем, является ли введенное значение допустимым
        /// 
        if (input == "Y" || input == "y") {
            while (input != "\\q") {
                system("CLS");

                cout << "Функция выполняет анализ двух, вводимых пользователем строк на предмет вхождения одной в другую. "
                    << "Если одна из вводимых пользователем строк является началом другой (например два слова \"прог\" и \"программа\") "
                    << "функция вернет 1, в ином случае вернет 0.\n\nПример работы:\n\n" << endl;

                char string1[80], string2[80];

                cout << " Введите две строки: ";
                cin >> string1 >> string2;
                cout << " Результат равен: "
                    << mystery3(string1, string2) << endl;


                cout << "\n\nДля выхода введите \\q" << endl;
                cin >> input;
            }
        }
    }
    system("CLS");
    std::cout << "Завершение работы программы программы...";

    return 0;
}

/// <summary>
/// Функция проверяет начальное вхождение одной строки в другую
/// </summary>
/// <param name="s1">Первая строка</param>
/// <param name="s2">Вторая строка</param>
/// <returns>1 - вхождение найдено, 0 - не найдено</returns>
int mystery3(const char* s1, const char* s2)
{
    for ( ; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
        if (*s1 != *s2)
            return 0;
    return 1;
}

