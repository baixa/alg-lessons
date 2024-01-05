#include <iostream>
#include <string>
#include <format>
#include "Task15.h"

using namespace std;

int board[8][8];

/// <summary>
/// Запускает выполнение (Глава 4) Задача #15 (4.35)
/// Заголовок: Восемь Ферзей (рекурсия)
/// Описание: 
///     
///     Модифицируйте программу Восемь ферзей, которую
///     вы создали в упражнении 4.26, для рекурсивного решения задачи
/// 
/// </summary>
/// <returns>Код результата выполнения программы</returns>
int runTask15()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// Отображаем документацию и базовое меню
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
Запуск решения (Глава 4) Задача #15 (4.35)...
Название: "Восемь Ферзей (рекурсия)"
Описание: 
        
    Модифицируйте программу Восемь ферзей, которую
    вы создали в упражнении 4.26, для рекурсивного решения задачи

    
    
         
Для запуска программы введите команду Y. Для выхода введите команду \q.)STRING" << endl;

        cin >> input;

        /// 
        /// Определяем, является ли введенное значение допустимым
        /// 
        if (input == "Y" || input == "y") {
            while (input != "\\q") {
                system("CLS");

                cout << "Результат работы программы: \n\n" << endl;

                findQueenPlaceInVertical(0);

                for (int i = 1; i <= 8; ++i)
                {
                    for (int k = 1; k <= 8; k++) {
                        cout << "+---";
                    }
                    cout << "+" << endl;
                    for (int j = 0; j < 8; ++j) {
                        cout << format("| {} ", board[i][j] ? 'Q' : ' ');
                    }
                    cout << "|" << endl;
                }
                for (int k = 1; k <= 8; k++) {
                    cout << "+---";
                }
                cout << "+" << endl;

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
/// Выполняет проверку на возможность размещения ферзя в ряду row и колонке column
/// </summary>
/// <param name="column">Номер колонки</param>
/// <param name="row">Номер строки</param>
/// <returns>1 - ферзь размещен, 0 - ферзя установить не удалось</returns>
int isAvailableToPlaceQueen(int column, int row)
{
    for (int i = 0; i < column; ++i)
    {
        bool isRowOccured = board[i][row];
        if (isRowOccured) {
            return 0;
        }
        if (row - column + i >= 0 && board[i][row - column + i]) {
            return 0;
        }
        if (row + column - i < 8 && board[i][row + column - i]) {
            return 0;
        }
    }
    return 1;
}

/// <summary>
/// Выполняет анализ шахматной доски на строке, номер которой соответствует параметру column,
/// и помечает возможное расположение ферзя
/// </summary>
/// <param name="column">Номер строки для анализа</param>
/// <returns>1 - ферзь размещен, 0 - ферзя установить не удалось</returns>
int findQueenPlaceInVertical(int column)
{
    if (column == 8) return 1;
    for (int j = 0; j < 8; ++j) {
        if (isAvailableToPlaceQueen(column, j))
        {
            board[column][j] = 1;
            if (findQueenPlaceInVertical(column + 1)) {
                return 1;
            }
            board[column][j] = 0;
        }
    }
    return 0;
}