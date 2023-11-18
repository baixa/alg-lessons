#include <iostream>
#include <string>
#include <format>
#include "Task7.h"

using namespace std;

/// <summary>
/// ��������� ���������� (����� 2) ������ #7 (3.22)
/// ���������: ��������� �������� �� ���������
/// ��������: 
///     
///     �������� ���������, ������� ���������� � ������ ���� ������ 
///     �������� ������� �� ��������� ������� �������� ������� �����
///     ���������� side. ��������, ���� side ����� 4, ������� ������ 
///     ���������� ��������� ��������:
///     
///     * * * *
///     * * * *
///     * * * *
///     * * * *
/// 
/// </summary>
/// <returns>��� ���������� ���������� ���������</returns>
int runTask7()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// ���������� ������������ � ������� ����
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
������ ������� (����� 2) ������ #7 (3.22)...
��������: "��������� �������� �� ���������"
��������: 
        
    �������� ���������, ������� ���������� � ������ ���� ������ 
    �������� ������� �� ��������� ������� �������� ������� �����
    ���������� side. ��������, ���� side ����� 4, ������� ������ 
    ���������� ��������� ��������:
     
    * * * *
    * * * *
    * * * *
    * * * *
        
��� ������� ��������� ������� ������� Y. ��� ������ ������� ������� \\q.)STRING" << endl;

        cin >> input;

        /// 
        /// ����������, �������� �� ��������� �������� ����������
        /// 
        if (input == "Y" || input == "y") {
            while (input != "\\q") {
                system("CLS");
                bool isProgramEnding = false;
                while (!isProgramEnding) {
                    cout << "��������� ��������.\n������� ������ ��������:" << endl;
                    cin >> input;
                    /// 
                    /// ����������, �������� �� ��������� �������� ���������� ��������� (������) � ��������� ��������������� ������
                    /// 
                    if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                        int size = stoi(input);
                        for (int i = 0; i < size; i++)
                        {
                            for (int j = 0; j < size; j++)
                            {
                                cout << "* ";
                            }
                            cout << endl;
                        }
                        isProgramEnding = true;
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