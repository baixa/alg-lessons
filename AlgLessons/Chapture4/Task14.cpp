﻿#include <iostream>
#include <string>
#include <format>
#include "Task14.h"

using namespace std;

/// <summary>
/// Запускает выполнение (Глава 4) Задача #14 (4.26)
/// Заголовок: Восемь Ферзей
/// Описание: 
///     
///     Другой шахматной головоломкой является задача
///     о Восьми Ферзях: можно ли поставить на пустой шахматной доске
///     восемь ферзей так, чтобы ни один из них не «атаковал» другого,
///     т.е.никакие два ферзя не стояли бы на одном и том же столбце
///     или на одной и той же строке или на одной и той же диагонали?
///     Используйте размышления, приведенные в упражнении 4.24, чтобы
///     сформулировать эвристику для решения задачи о Восьми Ферзях.
///     Запустите вашу программу. (Совет: можно присвоить значение каж-
///     дой клетке шахматной доски, указывая, сколько клеток пустой шах-
///     матной доски «исключается», если ферзя поместить на эту клетку.
///     Каждому углу должно быть присвоено значение 22, как на рис.
///     4.26.) Как только эти «числа исключения» будут присвоены всем
///     64 клеткам, можно предложить эвристику: ставить каждого следу-
///     ющего ферзя на клетку с наименьшим числом исключения.Почему
///     эта стратегия интуитивно привлекательна?
/// 
/// </summary>
/// <returns>Код результата выполнения программы</returns>
int runTask14()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// Отображаем документацию и базовое меню
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
Запуск решения (Глава 4) Задача #14 (4.26)...
Название: "Восемь Ферзей"
Описание: 
        
    Другой шахматной головоломкой является задача
    о Восьми Ферзях: можно ли поставить на пустой шахматной доске
    восемь ферзей так, чтобы ни один из них не «атаковал» другого,
    т.е.никакие два ферзя не стояли бы на одном и том же столбце
    или на одной и той же строке или на одной и той же диагонали?
    Используйте размышления, приведенные в упражнении 4.24, чтобы
    сформулировать эвристику для решения задачи о Восьми Ферзях.
    Запустите вашу программу. (Совет: можно присвоить значение каж-
    дой клетке шахматной доски, указывая, сколько клеток пустой шах-
    матной доски «исключается», если ферзя поместить на эту клетку.
    Каждому углу должно быть присвоено значение 22, как на рис.
    4.26.) Как только эти «числа исключения» будут присвоены всем
    64 клеткам, можно предложить эвристику: ставить каждого следу-
    ющего ферзя на клетку с наименьшим числом исключения.Почему
    эта стратегия интуитивно привлекательна?

    
    
         
Для запуска программы введите команду Y. Для выхода введите команду \q.)STRING" << endl;

        cin >> input;

        /// 
        /// Определяем, является ли введенное значение допустимым
        /// 
        if (input == "Y" || input == "y") {
            while (input != "\\q") {
                system("CLS");

                cout << "Результат работы программы: \n\n" << endl;
                
                printEightQueensBoard();

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
/// Выводит в консоль возможную расстановку 8 фигур "Ферзь"
/// </summary>
/// <returns>0 - успешно, -1 - не удалось выполнить расстановку</returns>
int printEightQueensBoard() {
    int boardRow[9] = { 0 };
    int column = 1;
    int isRowAvailable;

    while (1) {
        if (boardRow[column] == 8) {
            if (column > 1) {
                boardRow[column] = 0;
                column--;
                continue;
            }
            else {
                cout << "Выполнить расстановку фигур не удалось!" << endl;
                return -1;
            }
        }
        else {
            boardRow[column]++;
        }

        isRowAvailable = true;
        for (int i = 1; i <= 7 && isRowAvailable; i++) {
            for (int j = i + 1; j <= 8 && isRowAvailable; j++) {
                if (boardRow[i] != 0 && boardRow[i] == boardRow[j]) {
                    isRowAvailable = false;
                }
                if (boardRow[i] != 0 && boardRow[j] != 0 && abs(i - j) == abs(boardRow[i] - boardRow[j])) {
                    isRowAvailable = false;
                }
            }
        }

        if (!isRowAvailable) {
            continue;
        }
        if (column == 8) {
            break;
        }
        ++column;
    }

    for (int i = 1; i <= 8; i++) {
        for (int k = 1; k <= 8; k++) {
            cout << "+---";
        }
        cout << "+" << endl;
        for (int j = 1; j <= 8; j++) {
            cout << format("| {} ", boardRow[j] == i ? 'Q' : ' ');
        }
        cout << "|" << endl;
    }
    for (int k = 1; k <= 8; k++) {
        cout << "+---";
    }
    cout << "+" << endl;

    return 0;
}