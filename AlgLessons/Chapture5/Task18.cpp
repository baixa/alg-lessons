#include <iostream>
#include <string>
#include <format>
#include "Task18.h"

using namespace std;

/// <summary>
/// ��������� ���������� (����� 5) ������ #18 (5.30)
/// ���������: ��� ������ ��� ���������?
/// ��������: 
/// 
///     ��� ������ ��� ���������?
///     
///     #include <iostream.h>
///     int mystery3(const char *, const char *);
/// 
///     main()
///     {
///         char string1 [80], string2 [80];
///         
///         cout << " ������� ��� ������: ";
///         cin >> string1 >> string2;
///         cout << " ��������� �����: "
///             << mystery3(string1, string2) << endl;
///         return 0;
///     }
///     
///     int mystery3(const char *s1, const char *s2)
///     {
///         for ( ; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
///             if (*s1 != *s2)
///                 return 0;
///         return 1;
///     }
/// 
/// </summary>
/// <returns>��� ���������� ���������� ���������</returns>
int runTask18()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// ���������� ������������ � ������� ����
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
������ ������� (����� 5) ������ #18 (5.30)...
��������: "��� ������ ��� ���������"
��������: 
        
        ��� ������ ��� ���������?
     
        #include <iostream.h>
        int mystery3(const char *, const char *);
 
        main()
        {
            char string1 [80], string2 [80];
         
            cout << " ������� ��� ������: ";
            cin >> string1 >> string2;
            cout << " ��������� �����: "
                << mystery3(string1, string2) << endl;
            return 0;
        }
     
        int mystery3(const char *s1, const char *s2)
        {
            for ( ; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
                if (*s1 != *s2)
                    return 0;
            return 1;
        }
    
         
��� ������� ��������� ������� ������� Y. ��� ������ ������� ������� \q.)STRING" << endl;

        cin >> input;

        /// 
        /// ����������, �������� �� ��������� �������� ����������
        /// 
        if (input == "Y" || input == "y") {
            while (input != "\\q") {
                system("CLS");

                cout << "������� ��������� ������ ����, �������� ������������� ����� �� ������� ��������� ����� � ������. "
                    << "���� ���� �� �������� ������������� ����� �������� ������� ������ (�������� ��� ����� \"����\" � \"���������\") "
                    << "������� ������ 1, � ���� ������ ������ 0.\n\n������ ������:\n\n" << endl;

                char string1[80], string2[80];

                cout << " ������� ��� ������: ";
                cin >> string1 >> string2;
                cout << " ��������� �����: "
                    << mystery3(string1, string2) << endl;


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
/// ������� ��������� ��������� ��������� ����� ������ � ������
/// </summary>
/// <param name="s1">������ ������</param>
/// <param name="s2">������ ������</param>
/// <returns>1 - ��������� �������, 0 - �� �������</returns>
int mystery3(const char* s1, const char* s2)
{
    for ( ; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
        if (*s1 != *s2)
            return 0;
    return 1;
}

