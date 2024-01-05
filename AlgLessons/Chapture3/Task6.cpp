#include <iostream>
#include <string>
#include <format>
#include "Task6.h"
#include <algorithm>

using namespace std;

/// <summary>
/// ��������� ���������� (����� 3) ������ #6 (3.21)
/// ���������: ������� �������� �������� �����
/// ��������: 
///     
///     �������� ���������, ������� ������ ������������������ �����
///     ����� � �������� �� �� ������ ������� even, ������� ���������� 
///     �������� ���������� ������� ��� ����������� �������� �����.
///     ������� ������ ��������� ����� �������� � ��������� 1, ����
///     �������� - ������ �����, � 0 � ��������� ������
/// 
/// </summary>
/// <returns>��� ���������� ���������� ���������</returns>
int runTask6()
{
    system("chcp 1251");
    std::string input;

    while (input != "\\q") {
        /// 
        /// ���������� ������������ � ������� ����
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
������ ������� (����� 3) ������ #6 (3.21)...
��������: "������� �������� �������� �����"
��������: 
        
    �������� ���������, ������� ������ ������������������ �����
    ����� � �������� �� �� ������ ������� even, ������� ���������� 
    �������� ���������� ������� ��� ����������� �������� �����.
    ������� ������ ��������� ����� �������� � ��������� 1, ����
    �������� - ������ �����, � 0 � ��������� ������
        
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
                    cout << "��������� ��������.\n������� ���������� �����, ������� ����� ������� � ���������:" << endl;
                    cin >> input;
                    /// 
                    /// ����������, �������� �� ��������� �������� ���������� ��������� (������) � ��������� ��������������� ������
                    /// 
                    if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                        int count = stoi(input);
                        int* values = new int[count];
                        int lengthVals = count;
                        while(count > 0)
                        {
                            cout << std::format("������� {}-� �����: ", lengthVals - count + 1) << endl;
                            cin >> input;
                            if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                                values[count - 1] = stoi(input);
                                --count;
                            }
                            else
                            {
                                cout << "��������� �������� �� �������� ������!" << endl;
                            }
                        }
                        cout << "\n\n-----------------------\n" << endl;
                        for (int i = lengthVals - 1; i >= 0; i--)
                        {
                            cout << std::format("{}. ������� even � ���������� {} ������� �������� {}", lengthVals - i, values[i], even(values[i]))
                                 << endl;
                            isProgramEnding = true;
                        }
                    }
                    else {
                        cout << "��������� �������� �� �������� ������!" << endl;
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

int even(int value) {
    return value % 2 ? 0 : 1;
}
