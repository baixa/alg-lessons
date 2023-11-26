#include <iostream>
#include <string>
#include <format>
#include "Task8.h"

using namespace std;

/// <summary>
/// ��������� ���������� (����� 3) ������ #8 (3.23)
/// ���������: ��������� �������� �� ��������
/// ��������: 
///     
///     ������������� �������, ��������� � ���������� 3.22, ���,
///     ����� ����������� ������� �� ������ ������ ��������, ���������
///     � ���������� ��������� fillCharacter. ����� �������, ���� side
///     ����� 5 � fillCharacter ����� #, �� ��� ������� ������ ����������:
///     
///     # # # # #
///     # # # # #
///     # # # # #
///     # # # # #
///     # # # # #
/// 
/// </summary>
/// <returns>��� ���������� ���������� ���������</returns>
int runTask8()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// ���������� ������������ � ������� ����
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
������ ������� (����� 3) ������ #7 (3.22)...
��������: "��������� �������� �� ��������"
��������: 
        
    ������������� �������, ��������� � ���������� 3.22, ���,
    ����� ����������� ������� �� ������ ������ ��������, ���������
    � ���������� ��������� fillCharacter. ����� �������, ���� side
    ����� 5 � fillCharacter ����� #, �� ��� ������� ������ ����������:
     
    # # # # #
    # # # # #
    # # # # #
    # # # # #
    # # # # #
        
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
                    cout << "��������� ��������.\n������� ������ ��������:" << endl;
                    cin >> input;
                    /// 
                    /// ����������, �������� �� ��������� �������� ���������� ��������� (������) � ��������� ��������������� ������
                    /// 
                    if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                        int size = stoi(input);
                        string symbol;
                        cout << "������� ����������� ��� �������� (1 ������):" << endl;
                        cin >> symbol;
                        if (symbol.size() == 1) {
                            for (int i = 0; i < size; i++)
                            {
                                for (int j = 0; j < size; j++)
                                {
                                    cout << format("{} ", symbol);
                                }
                                cout << endl;
                            }
                            isProgramEnding = true;
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