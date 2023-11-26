#include <iostream>
#include <string>
#include <format>
#include "Task9.h"
#include <algorithm>

using namespace std;

/// <summary>
/// ��������� ���������� (����� 3) ������ #9 (3.24)
/// ���������: ��������� �����
/// ��������: 
///     
///     ������������ ������, �������� � ����������� 3.22 � 3.23, ��� ��-
///     ������ ���������, ������� ����������� ������� �������� ����.
/// 
/// </summary>
/// <returns>��� ���������� ���������� ���������</returns>
int runTask9()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// ���������� ������������ � ������� ����
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
������ ������� (����� 3) ������ #9 (3.24)...
��������: "��������� �����"
��������: 
        
    ������������ ������, �������� � ����������� 3.22 � 3.23, ��� ��-
    ������ ���������, ������� ����������� ������� �������� ����.

    ����������: ��� ������ ��������� ���������� ����� ������ ����������� ����� � �� 
         
��� ������� ��������� ������� ������� Y. ��� ������ ������� ������� \q.)STRING" << endl;

        cin >> input;

        /// 
        /// ����������, �������� �� ��������� �������� ����������
        /// 
        if (input == "Y" || input == "y") {
            while (input != "\\q") {
                system("CLS");
                bool isProgramEnding = false;
                while (!isProgramEnding) {
                    cout << "��������� ��������.\n������� ������ ������:" << endl;
                    cin >> input;
                    /// 
                    /// ����������, �������� �� ��������� �������� ���������� ��������� (������) � ��������� ��������������� ������
                    /// 
                    if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                        int size = stoi(input);
                        string symbol;
                        cout << "������� ����������� ��� ������ (1 ������):" << endl;
                        cin >> symbol;
                        if (symbol.size() == 1) {
                            cout << "������� ��� ������ (1 - �������, 2 - �����������, 3 - ����):" << endl;
                            cin >> input;
                            
                            if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                                int code = stoi(input);
                                switch (code) {
                                case 1:
                                    for (int i = 0; i < size; i++)
                                    {
                                        for (int j = 0; j < size; j++)
                                        {
                                            cout << format("{} ", symbol);
                                        }
                                        cout << endl;
                                    }
                                    isProgramEnding = true;
                                    break;
                                case 2:
                                    for (int i = 1; i <= size; i++) {
                                        for (int j = 1; j <= i; j++) {
                                            cout << format("{} ", symbol);
                                        }
                                        cout << endl;
                                    }
                                    isProgramEnding = true;
                                    break;
                                case 3:
                                    for (int i = 1; i <= size; i++)
                                    {
                                        for (int j = 0; j < (size - i); j++)
                                            std::cout << " ";
                                        for (int j = 1; j <= i; j++)
                                            cout << symbol;
                                        for (int j = 1; j < i; j++)
                                            cout << symbol;
                                        std::cout << endl;
                                    }
                                    for (int i = size - 1; i >= 1; i--)
                                    {
                                        for (int j = 0; j < (size - i); j++)
                                            std::cout << " ";
                                        for (int j = 1; j <= i; j++)
                                            std::cout << symbol;
                                        for (int j = 1; j < i; j++)
                                            std::cout << symbol;
                                        std::cout << endl;
                                    }
                                    isProgramEnding = true;
                                    break;
                                default:
                                    system("CLS");
                                    cout << "�������� �������� �� ������������� ����������� (1, 2 ��� 3)!" << endl;
                                    break;
                                }
                            }
                        }
                        else {
                            system("CLS");
                            cout << "��������� ������ ������ ������! ���������� ��������� �������� ������� �� 1" << endl;
                            continue;
                        }
                    }
                    else {
                        system("CLS");
                        cout << "��������� �������� �� �������� ������!" << endl;
                        continue;
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