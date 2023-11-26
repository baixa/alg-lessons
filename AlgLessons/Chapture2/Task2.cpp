#include <iostream>
#include <string>
#include <format>
#include "Task2.h"

using namespace std;

/// <summary>
/// ��������� ���������� (����� 2) ������ #2 (2.22)
/// ���������: ����� ���������� �������� �� 10 �����
/// ��������: ��������� ������ ���������� 2.20, ������� ��� ���������� �������� �� 10 �����. 
///             ��������: �� ������ ������ ������ ����� ������ ���� ���
/// </summary>
/// <returns>��� ���������� ���������� ���������</returns>
int runTask2()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// ���������� ������������ � ������� ����
        /// 
        system("CLS");

        std::cout << "������ ������� (����� 2) ������ #2 (2.22)...\n" <<
            "��������: \"����� ���������� �������� �� 10 �����\"\n" <<
            "��������: ��������� ������ ���������� 2.20, ������� ��� ���������� �������� �� 10 �����. " <<
            " ��������: �� ������ ������ ������ ����� ������ ���� ���." << 
            " ��� ������� ��������� ������� ������� Y. ��� ������ ������� ������� \\q. ";

        cin >> input;

        /// 
        /// ����������, �������� �� ��������� �������� ����������
        /// 
        if (input == "Y" || input == "y") {
            while (input != "\\q") {
                system("CLS");
                
                int number;
                int largest;
                int largest_2;

                for (int counter = 0; counter < 10; counter++)
                {
                    cout << format("������� {}-� ����� (��� ����� ����������� �������� ��������������� �������� 0): ", counter + 1) << endl;
                    cin >> number;
                    if (counter == 0) {
                        largest = number;
                    }
                    else if (counter == 1) {
                        if (largest < number) {
                            largest_2 = number;
                        }
                        else {
                            largest_2 = largest;
                            largest = number;
                        }
                    }
                    else {
                        if (largest_2 < number) {
                            if (largest < number) {
                                largest_2 = largest;
                                largest = number;
                            }
                            else {
                                largest_2 = number;
                            }
                        }
                    }
                }
                cout << format("���������� �������� ��������: {}, {}", largest, largest_2) << endl;

                cout << "\n\n��� ������ ������� \\q" << endl;
                cin >> input;
            }
        }
    }
    system("CLS");
    std::cout << "���������� ������ ��������� ���������...";

    return 0;
}
