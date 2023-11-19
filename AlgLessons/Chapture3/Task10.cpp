#include <iostream>
#include <string>
#include <format>
#include "Task10.h"

using namespace std;

/// <summary>
/// ��������� ���������� (����� 3) ������ #10 (3.25)
/// ���������: ��������� �������� ��� ��������� �����
/// ��������: 
///     
///     �������� ��������� ��������, ������� �� ��������� ���������:
///     
///     �) ��������� ����� ����� ������� �� ������� ������ ����� � ��
///     ����� ����� b.
/// 
///     b) ��������� ����� ������� �� ������� ������ ����� � �� �����
///     ����� b.
/// 
///     c) ������������ ��������� ��������, ��������� � ������� a) � b),
///     ��� ��������� �������, ������ ������ ����� ����� �� ���������
///     �� 1 �� 32767 � �������� ��� ��� ������������������ ����, ������
///     �� ������� �������� �� �������� ����� ���������. ��������, �����
///     ����� 4562 ������ ���� ���������� � ����
///     
///     4 5 6 2
/// 
/// </summary>
/// <returns>��� ���������� ���������� ���������</returns>
int runTask10()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// ���������� ������������ � ������� ����
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
������ ������� (����� 3) ������ #10 (3.25)...
��������: "��������� �������� ��� ��������� �����"
��������: 
        
    �������� ��������� ��������, ������� �� ��������� ���������:
     
    �) ��������� ����� ����� ������� �� ������� ������ ����� � ��
    ����� ����� b.

    b) ��������� ����� ������� �� ������� ������ ����� � �� �����
    ����� b.

    c) ������������ ��������� ��������, ��������� � ������� a) � b),
    ��� ��������� �������, ������ ������ ����� ����� �� ���������
    �� 1 �� 32767 � �������� ��� ��� ������������������ ����, ������
    �� ������� �������� �� �������� ����� ���������. ��������, �����
    ����� 4562 ������ ���� ���������� � ����
     
    4 5 6 2
         
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
                    int a, b;
                    cout << "����� �. ������� ����� � ��� ���������� ����� ����� �������� �� �������: " << endl;
                    cin >> input;
                    if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                        a = stoi(input);
                        cout << "������� ����� b: " << endl;
                        cin >> input;
                        if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                            b = stoi(input);
                            cout << format("��������� ������ ������� �� ������ �. ������� ���������: � = {}, b = {}. ���������: {}", a, b, 
                                intDivide(a , b)) << endl;
                            isProgramEnding = true;
                        }
                        else {
                            system("CLS");
                            cout << "��������� �������� �� �������� ������!" << endl;
                            continue;
                        }
                    }
                    else {
                        system("CLS");
                        cout << "��������� �������� �� �������� ������!" << endl;
                        continue;
                    }
                    
                }
                isProgramEnding = false;
                while (!isProgramEnding) {
                    int a, b;
                    cout << "����� b. ������� ����� � ��� ���������� ������ ������� �� �������: " << endl;
                    cin >> input;
                    if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                        a = stoi(input);
                        cout << "������� ����� b: " << endl;
                        cin >> input;
                        if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                            b = stoi(input);
                            cout << format("��������� ������ ������� �� ������ b. ������� ���������: � = {}, b = {}. ���������: {}", a, b, 
                                divideByRemainder(a, b)) << endl;
                            isProgramEnding = true;
                        }
                        else {
                            system("CLS");
                            cout << "��������� �������� �� �������� ������!" << endl;
                            continue;
                        }
                    }
                    else {
                        system("CLS");
                        cout << "��������� �������� �� �������� ������!" << endl;
                        continue;
                    }
                }
                isProgramEnding = false;
                while (!isProgramEnding) {
                    int value;
                    cout << "����� c. ������� ����� ������ ��� ������������������: " << endl;
                    cin >> input;
                    if (std::find_if(input.begin(), input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end()) {
                        value = stoi(input);
                        cout << format("��������� ������ ������� �� ������ c. ������� ���������: � = {}. ���������: {}", value,
                            numToSequence(value)) << endl;
                        isProgramEnding = true;
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

int intDivide(int x, int y) {
    return x / y;
}

int divideByRemainder(int x, int y) {
    return x % y;
}

string numToSequence(int value) {
    string result = "";
    while (value > 0) {
        result = format("{} ", divideByRemainder(value, 10)) + result;
        value = intDivide(value, 10);
    }
    return result;
}