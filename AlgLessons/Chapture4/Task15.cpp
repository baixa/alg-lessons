#include <iostream>
#include <string>
#include <format>
#include "Task15.h"

using namespace std;

int board[8][8];

/// <summary>
/// ��������� ���������� (����� 4) ������ #15 (4.35)
/// ���������: ������ ������ (��������)
/// ��������: 
///     
///     ������������� ��������� ������ ������, �������
///     �� ������� � ���������� 4.26, ��� ������������ ������� ������
/// 
/// </summary>
/// <returns>��� ���������� ���������� ���������</returns>
int runTask15()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// ���������� ������������ � ������� ����
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
������ ������� (����� 4) ������ #15 (4.35)...
��������: "������ ������ (��������)"
��������: 
        
    ������������� ��������� ������ ������, �������
    �� ������� � ���������� 4.26, ��� ������������ ������� ������

    
    
         
��� ������� ��������� ������� ������� Y. ��� ������ ������� ������� \q.)STRING" << endl;

        cin >> input;

        /// 
        /// ����������, �������� �� ��������� �������� ����������
        /// 
        if (input == "Y" || input == "y") {
            while (input != "\\q") {
                system("CLS");

                cout << "��������� ������ ���������: \n\n" << endl;

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

                cout << "\n\n��� ������ ������� \\q" << endl;
                cin >> input;
            }
        }
    }
    system("CLS");
    std::cout << "���������� ������ ��������� ���������...";

    return 0;
}

/// <summary>
/// ��������� �������� �� ����������� ���������� ����� � ���� row � ������� column
/// </summary>
/// <param name="column">����� �������</param>
/// <param name="row">����� ������</param>
/// <returns>1 - ����� ��������, 0 - ����� ���������� �� �������</returns>
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
/// ��������� ������ ��������� ����� �� ������, ����� ������� ������������� ��������� column,
/// � �������� ��������� ������������ �����
/// </summary>
/// <param name="column">����� ������ ��� �������</param>
/// <returns>1 - ����� ��������, 0 - ����� ���������� �� �������</returns>
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