#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <format>
#include "Task20.h"


using namespace std;

string encodeLatin(const string& phrase);
void printLatinWord();

/// <summary>
/// ��������� ���������� (����� 5) ������ #20 (5.35)
/// ���������: ������������
/// ��������: 
/// 
///    �������� ���������, ������� �������� ����� ����������� �����
///    �������������.������������ � ��� ����� ������������� �����,
///    ����� ������������ ��� �����������.���������� ����� ���������
///    ������������ ���� �� ������������.��� �������� �����������
///    ��������� ��������:
///
///    ����� ������������ ����� �� ������������ �� ����� �� ������-
///    ���� �����, �������� ����� �� ����� � ������� ������� strtok.
///    ��� �������� ������� ����������� ����� �� ���� ������������
///    ��������� ������ ����� ����������� ����� � ����� �����������
///    ����� � ��������� ����� ���.����� ������� ����� �jump� ��� -
///    �������� � �umpjay�, ����� �the� ����������� � �hetay�, � �����
///    �computer� ����������� � �omputercay�. �������� ����� �������
///    �����������.������ ��������� ���������: ���������� ����� ��-
///    ����� �� ����, ����������� ����������, ���������� �����������,
///    ��� ����� ������� �� ����� ��� �� ���� ����. ������� printLatin-
///    Word ������ ���������� ������ �����. ���������: ������ ���-
///    ������ � ������� ������� strtok ������� ������ ���������� ���-
///    ������ �� ������� ������� printLatinWord, ������� �������� �����
///    �� ������������.
/// 
/// </summary>
/// <returns>��� ���������� ���������� ���������</returns>
int runTask20()
{
    string input;

    while (input != "\\q") {
        /// 
        /// ���������� ������������ � ������� ����
        /// 
        system("CLS");

        cout <<
            R"STRING(
������ ������� (����� 5) ������ #20 (5.35)...
��������: "������������"
��������: 
        
    �������� ���������, ������� �������� ����� ����������� �����
    �������������. ������������ � ��� ����� ������������� �����,
    ����� ������������ ��� �����������. ���������� ����� ���������
    ������������ ���� �� ������������. ��� �������� �����������
    ��������� ��������:

    ����� ������������ ����� �� ������������ �� ����� �� ������-
    ���� �����, �������� ����� �� ����� � ������� ������� strtok.
    ��� �������� ������� ����������� ����� �� ���� ������������
    ��������� ������ ����� ����������� ����� � ����� �����������
    ����� � ��������� ����� ���. ����� ������� ����� �jump� ��� -
    �������� � �umpjay�, ����� �the� ����������� � �hetay�, � �����
    �computer� ����������� � �omputercay�. �������� ����� �������
    �����������.������ ��������� ���������: ���������� ����� ��-
    ����� �� ����, ����������� ����������, ���������� �����������,
    ��� ����� ������� �� ����� ��� �� ���� ����. ������� printLatin-
    Word ������ ���������� ������ �����. ���������: ������ ���-
    ������ � ������� ������� strtok ������� ������ ���������� ���-
    ������ �� ������� ������� printLatinWord, ������� �������� �����
    �� ������������.
    
         
��� ������� ��������� ������� ������� Y. ��� ������ ������� ������� \q.)STRING" << endl;

        cin >> input;

        /// 
        /// ����������, �������� �� ��������� �������� ����������
        /// 
        if (input == "Y" || input == "y") {
            while (input != "\\q") {
                system("CLS");
                printLatinWord();
                cout << "\n\n��� ������ ������� \\q" << endl;
                cin >> input;
            }
        }
    }
    system("CLS");
    cout << "���������� ������ ��������� ���������...";

    return 0;
}

void printLatinWord() {
    string phrase;
    cout << "������� ����� �� ���������� �����:";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, phrase);

    string encodedPhrase = encodeLatin(phrase);
    cout << "�������������� �����: " << encodedPhrase << endl;
}

/// <summary>
/// ��������� ��������� ����� �� ����������, �������� �� ��� ������ � ������������
/// </summary>
/// <param name="phrase">�������� �����</param>
/// <returns>������� �� ������������</returns>
string encodeLatin(const string& phrase) {
    char* str = new char[phrase.length() + 1];
    strcpy(str, phrase.c_str());
    char* token = strtok(str, " ");
    string encodedPhrase = "";
    while (token != nullptr) {
        char firstLetter = token[0];
        string encodedWord = string(token + 1) + firstLetter + "ay";
        encodedPhrase += encodedWord + " ";
        token = strtok(nullptr, " ");
    }
    delete[] str;
    return encodedPhrase;
}

