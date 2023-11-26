#include <iostream>
#include <string>
#include <format>
#include "Task11.h"

using namespace std;

/// <summary>
/// ��������� ���������� (����� 4) ������ #11 (4.16)
/// ���������: ������� ��������� ��������� �������
/// ��������: 
///     
///     �������, � ����� ������� ����� ���������� �������� ����������
///     ������� sales �������� 3 �� 5 ��������� ���������� ���������:
/// 
///     for (row = 0; row < 3; row++)
///         for (column = 0; column < 5; column++)
///             sales[row] [column] = 0;
/// 
/// </summary>
/// <returns>��� ���������� ���������� ���������</returns>
int runTask11()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// ���������� ������������ � ������� ����
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
������ ������� (����� 4) ������ #11 (4.16)...
��������: "������� ��������� ��������� �������"
��������: 
        
    �������, � ����� ������� ����� ���������� �������� ����������
    ������� sales �������� 3 �� 5 ��������� ���������� ���������:
 
    for (row = 0; row < 3; row++)
         for (column = 0; column < 5; column++)
             sales[row] [column] = 0;
         
��� ������� ��������� ������� ������� Y. ��� ������ ������� ������� \q.)STRING" << endl;

        cin >> input;

        /// 
        /// ����������, �������� �� ��������� �������� ����������
        /// 
        if (input == "Y" || input == "y") {
            while (input != "\\q") {
                system("CLS");

                cout <<
                    R"STRING(
�������� �������� ��� �����, ����������� ���������������� ������� ���������. ������� �������� ��������� ������� � �������� � 0 �� ���������� 
�������� ������� 0 ������, ����� 1 ������, ����� ������ � �.�.  

������������� ���������� (���������� ���������, ����������� � ������� ������������� ����):
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
                        
                        // ����� �������������� ����������
                        cout << format("���� {}:", column + row * 5 + 1) << endl;
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
                cout << "\n\n��� ������ ������� \\q" << endl;
                cin >> input;
            }
        }
    }
    system("CLS");
    std::cout << "���������� ������ ��������� ���������...";

    return 0;
}