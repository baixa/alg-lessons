#include <iostream>
#include <string>
#include <format>
#include "Task13.h"

using namespace std;

int whatIsThis(int[], int);

/// <summary>
/// ��������� ���������� (����� 4) ������ #13 (4.18)
/// ���������: ��� ������ ���������
/// ��������: 
///     
///     ��� ������ ��������� ���������?
/// 
///     int whatIsThis(int [ ], int);
///     main()
///     {
///         int arraySize = 10;
///         int a[arraySize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
///     
///         int result = whatIsThis(a, arraySize);
///         cout << "��������� ����� " << result << endl;
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
/// <returns>��� ���������� ���������� ���������</returns>
int runTask13()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// ���������� ������������ � ������� ����
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
������ ������� (����� 4) ������ #13 (4.18)...
��������: "��� ������ ���������"
��������: 
        
        ��� ������ ��������� ���������?
 
         const int whatIsThis(int [ ], int);
         main()
         {
             int arraySize = 10;
             int a[arraySize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     
             int result = whatIsThis(a, arraySize);
             cout << "��������� ����� " << result << endl;
 
             return 0;
         }
         int whatIsThis(int b[ ], int size)
         {
             if (size == 1)
                 return b[0];
             else
                 return b[size - 1] + whatIsThis(b, size - 1);
         }
         
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
��������� ����� ��� �������, ���� �� ������� main - ���������� ��� ������� ���������, � ������, whatIsThis, ��������� ������� ����� ��������� � �������. 
��������� ����� �������� ������� whatIsThis ������������ ����� ��������� � �������, �������� ��� ������ ������ ����� ���� �������� ��������� size �� 1.
��� ��������� size = 1, ������� ���������� ������� ������� �������, � ���� ������ ��� ���������� ����� (size-1)-����� �������� ������� � �������� �������
��� �������� �� � �������� ���������� ���� �� ������� � �������� size, ������������ �� 1. � ������ ������ ��������� ������� ������ "��������� ����� 55"

������������� ���������� (���������� ���������, ����������� � ������� ������������� ����):
                )STRING" << endl;

                const int arraySize = 10;
                int a[arraySize] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

                int result = whatIsThis(a, arraySize);
                cout << "��������� ����� " << result << endl;

                cout << "\n\n��� ������ ������� \\q" << endl;
                cin >> input;
            }
        }
    }
    system("CLS");
    std::cout << "���������� ������ ��������� ���������...";

    return 0;
}

int whatIsThis(int b[], int size)
{
    if (size == 1)
        return b[0];
    else
        return b[size - 1] + whatIsThis(b, size - 1);
}