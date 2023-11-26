#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialty { PC_Science, IT, Math_Economic, Physics_IT, Work_Training };
string SpecialtyStr[] = { "��������� �����      ", "�����������            ", "���������� �� ��������", "Գ���� �� �����������  ", "������� ��������       " };

union ThirdGrade {
    int Programming;
    int NumericalMethods;
    int Pedagogy;
};

struct Student {
    int Sort_Number;
    string Last_Name;
    int Course;
    Specialty speciality;
    int PhysicsGrade;
    int MathGrade;
    ThirdGrade ThirdSubject;
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void DisplayAverageGrade(Student* p, const int N);
double CalculatePercentageWith45PhysicsGrade(Student* p, const int N);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    cout << "������ ������� �������� N: "; cin >> N;

    Student* p = new Student[N];

    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "������� ��:" << endl << endl;
        cout << " [1] - �������� ����� � ���������" << endl;
        cout << " [2] - ���� ����� �� �����" << endl;
        cout << " [3] - ���� ������ � ���������� ����" << endl;
        cout << " [4] - ���������� �������� �������� � ������ ������ �5� ��� �4�" << endl;
        cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
        cout << "������ ��������: "; cin >> menuItem;
        cout << endl << endl << endl;

        switch (menuItem) {
        case 1:
            Create(p, N);
            break;
        case 2:
            Print(p, N);
            break;
        case 3:
            DisplayAverageGrade(p, N);
            break;
        case 4:
            cout << "������� �������� � ������ ������ �5� ��� �4�: " << CalculatePercentageWith45PhysicsGrade(p, N) << "%" << endl;
            break;
        case 0:
            break;
        default:
            cout << "�� ����� ��������� ��������! "
                "��� ������ ����� - ����� ��������� ������ ����" << endl;
        }
    } while (menuItem != 0);

    return 0;
}

void Create(Student* p, const int N) {
    int speciality;
    for (int i = 0; i < N; i++) {
        cout << "����� " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();

        cout << " ���������� ����� �������� � ����: "; cin >> p[i].Sort_Number;
        cout << " �������: "; cin >> p[i].Last_Name;
        cout << " ����: "; cin >> p[i].Course;
        cout << " ������������: 0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������"; cin >> speciality;
        p[i].speciality = static_cast<Specialty>(speciality);
        cout << " ������ � ������: "; cin >> p[i].PhysicsGrade;
        cout << " ������ � ����������: "; cin >> p[i].MathGrade;

        switch (p[i].speciality) {
        case PC_Science:
            cout << " ������ � �������������: "; cin >> p[i].ThirdSubject.Programming;
            break;
        case IT:
            cout << " ������ � ��������� ������: "; cin >> p[i].ThirdSubject.NumericalMethods;
            break;
        default:
            cout << " ������ � ���������: "; cin >> p[i].ThirdSubject.Pedagogy;
            break;
        }

        cout << endl;
    }
}

void Print(Student* p, const int N) {
    cout << "============================================================================================================================================="
        << endl;
    cout << "| � | ����� � ���� | ������� | ���� | ������������          | Գ����   | ���������� | ������������� | ��������� ������ | ���������      |"
        << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++) {
        cout << "| " << setw(0) << right << i + 1 << " ";
        cout << "| " << setw(14) << left << p[i].Sort_Number
            << "| " << setw(9) << left << p[i].Last_Name
            << "| " << setw(4) << right << p[i].Course << " "
            << "| " << setw(12) << left << SpecialtyStr[p[i].speciality]
            << "| " << setw(9) << right << p[i].PhysicsGrade
            << "| " << setw(9) << right << p[i].MathGrade << " | ";

        switch (p[i].speciality) {
        case PC_Science:
            cout << setw(15) << right << p[i].ThirdSubject.Programming << " |";
            cout << setw(17) << right << "|";
            cout << setw(17) << right << "|";
            break;
        case IT:
            cout << setw(17) << right << "|";
            cout << setw(15) << right << p[i].ThirdSubject.NumericalMethods << " |";
            cout << setw(17) << right << "|";
            break;
        default:
            cout << setw(17) << right << "|";
            cout << setw(17) << right << "|";
            cout << setw(15) << right << p[i].ThirdSubject.Pedagogy << " |";
            break;
        }
        cout << endl;
        
    }
    cout << "============================================================================================================================================="
        << endl;
    cout << endl;
}

void DisplayAverageGrade(Student* p, const int N) {
    cout << "============================================================================================================================================="
        << endl;
    cout << "| � | ������� | ������� ��� |"
        << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------"
        << endl;

    for (int i = 0; i < N; i++) {
        int sum = 0;
        switch (p[i].speciality) {
        case PC_Science:
            sum = p[i].PhysicsGrade + p[i].MathGrade + p[i].ThirdSubject.Programming;
            break;
        case IT:
            sum = p[i].PhysicsGrade + p[i].MathGrade + p[i].ThirdSubject.NumericalMethods;
            break;
        default:
            sum = p[i].PhysicsGrade + p[i].MathGrade + p[i].ThirdSubject.Pedagogy;
            break;
        }
        
        double average = static_cast<double>(sum) / 3.0;

        cout << "| " << setw(0) << right << i + 1 << " ";
        cout << "| " << setw(13) << left << p[i].Last_Name
            << "| " << setw(12) << right << setprecision(2) << fixed << average << " |" << endl;
    }

    cout << "============================================================================================================================================="
        << endl;
    cout << endl;
}

double CalculatePercentageWith45PhysicsGrade(Student* p, const int N) {
    int count45 = 0;

    for (int i = 0; i < N; i++) {
        if (p[i].PhysicsGrade == 4 || p[i].PhysicsGrade == 5) {
            count45++;
        }
    }

    return (static_cast<double>(count45) / N) * 100.0;
}
