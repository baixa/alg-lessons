#include <iostream>
#include <string>
#include <format>
#include "Task17.h"

using namespace std;

/// <summary>
/// ��������� ���������� (����� 5) ������ #17 (5.24)
/// ���������: ������� ����������
/// ��������: 
/// 
///     (� ����� ��������, ����� �������� ������� �������)
///     �������� ����������� ������� quickSort ��� ���������� ����������� ������� �����.
///     ������� ������ ��������� � �������� ���������� ������ �����, ��������� ������
///     � ������������� ������.������� partition ������ ���������� �������� quickSort
///     ��� ���������� ���� ������������.
/// 
/// </summary>
/// <returns>��� ���������� ���������� ���������</returns>
int runTask17()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// ���������� ������������ � ������� ����
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
������ ������� (����� 5) ������ #17 (5.24)...
��������: "������� ����������"
��������: 
        
    (� ����� ��������, ����� �������� ������� �������)
    �������� ����������� ������� quickSort ��� ���������� ����������� ������� �����.
    ������� ������ ��������� � �������� ���������� ������ �����, ��������� ������
    � ������������� ������. ������� partition ������ ���������� �������� quickSort
    ��� ���������� ���� ������������.
    
    
    
         
��� ������� ��������� ������� ������� Y. ��� ������ ������� ������� \q.)STRING" << endl;

        cin >> input;

        /// 
        /// ����������, �������� �� ��������� �������� ����������
        /// 
        if (input == "Y" || input == "y") {
            while (input != "\\q") {
                system("CLS");

                int arr[] = { 99, 12, 7, 16, 1, 5, 10, 19, 67, 124 };
                int n = 10;

                cout << "�������� ������: ";

                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }

                cout << endl;

                quickSort(arr, 0, n - 1);

                cout << "��������������� ������: ";

                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }

                cout << endl;


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
/// ��������� ������������ �������, �������� ������ ������� ����������������
/// ������� � ��������� ��� ������������� ������� � ������������� �������.
/// </summary>
/// <param name="arr">�������� ������</param>
/// <param name="start">����� ������� ���������</param>
/// <param name="end">������ ������� ���������</param>
/// <returns>������ �������, ��� ������� ����� ��������� ��� ����� ������, 
/// ��� ��������� �������, � ������ - ������</returns>
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

/// <summary>
/// ��������� ���������� ������� ������� "������� ����������"
/// </summary>
/// <param name="arr">������</param>
/// <param name="start">����� ������� ������</param>
/// <param name="end">������ ������� ������</param>
void quickSort(int arr[], int start, int end)
{
    if (start >= end) {
        return;
    }
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

