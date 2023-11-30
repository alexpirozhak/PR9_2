#include <iostream>
#include <iomanip>
#include <string>
//#include <Windows.h>
using namespace std;

enum Spec { KN, IT, ME, PI, TN };

//string specStr[] = { "Комп’ютернi науки", "Iнформатика", "Математика та економiка", "Фiзика та iнформатика", "Трудове навчання" };
string specStr[] = { "КН", "ІТ", "МЕ", "ФІ", "ТН" };

struct Student
{
    string prizv;
    Spec spec;
    int kurs;
    double physicm;
    double mathm;
    double itm;

};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
double Average(Student st, const int N);
double SearchProc(Student* p, const int N);
void Exelent(Student* p, const int N);
int* IndexSort(Student* p, const int N);
void PrintIndexSorted(Student* p, int* I, const int N);
void Sort(Student* p, const int N);
int BinSearch(Student* p, const int N, const string prizv, const Spec spec, const int kurs);


int main()
{
    // SetConsoleCP(1251); 
    // SetConsoleOutputCP(1251);
    int N;
    cout << "Введіть N: "; cin >> N;
    cout << endl;
    Student* p = new Student[N];

    double percent;
    int ispec, ikurs;
    Spec spec;
    string prizv;
    int found;

    int menuItem;
    do
    {
        cout << endl << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << "[1]  -  введення даних з клавіатури" << endl;
        cout << "[2]  -  вивід даних у таблиці на екран" << endl;
        cout << "[3]  -  вивід прізвищ відмінників та студентів, чий середній бал більший, ніж 4,5" << endl;
        cout << "[4]  -  фізичне впорядкування таблиці" << endl;
        cout << "[5]  -  індексне впорядкування таблиці та її виведення" << endl;
        cout << "[6]  -  бінарний пошук студента" << endl;
        cout << "[0]  -  завершити роботу" << endl;
        cout << "Введіть значення: ";
        cin >> menuItem;
        cout << endl << endl;

        switch (menuItem)
        {
        case 1:
            Create(p, N);
            break;

        case 2:
            Print(p, N);
            break;

        case 3:
            Exelent(p, N);
            percent = SearchProc(p, N);
            cout << "Процент студентів, у яких середній бал більший за 4,5 = " << percent << "%" << endl
                << endl;
            break;
        case 4:
            Sort(p, N);
            break;

        case 5:
            //IndexSort(p, N);
            PrintIndexSorted(p, IndexSort(p, N), N);
            break;

        case 6:
            cout << "Введіть ключі пошуку:" << endl;
            cout << "спеціальність (0 - Комп’ютерні науки (КН), 1 - Iнформатика (IT), 2 - Математика та економiка (МЕ), 3 - Фiзика та iнформатика (ФI), 4 - Трудове навчання (ТН) ): ";
            cin >> ispec;
            spec = (Spec)ispec;
            cout << "Введіть курс: ";
            cin >> ikurs;
            cin.get();
            cin.sync();
            cout << "Прізвище: "; getline(cin, prizv);
            cout << endl;

            if ((found = BinSearch(p, N, prizv, spec, ikurs)) != -1)
                cout << "Такий студент є у заданому списку в позиції " << found + 1 << endl;
            else
                cout << "Такого студента не знайдено" << endl;
            break;

        case 0:
            break;

        default:
            cout << "Ви ввели помилкове значення! "
                "Слід ввести число - номер вибраного пункту меню" << endl;
        }
    } while (menuItem != 0);

    delete[] p;
    return 0;
}

void Create(Student* p, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент No " << i + 1 << ":" << endl; cin.get();
        cout << "прізвище: "; getline(cin, p[i].prizv);
        cout << "курс: "; cin >> p[i].kurs;
        cout << "спеціальність (0 - Комп’ютерні науки (КН), 1 - Iнформатика (IT), 2 - Математика та економiка (МЕ), 3 - Фiзика та iнформатика (ФI), 4 - Трудове навчання (ТН) ): "; cin >> spec;
        p[i].spec = (Spec)spec;
        cout << "оцінка з фізики: "; cin >> p[i].physicm;
        cout << "оцінка з математики: "; cin >> p[i].mathm;
        cout << "оцінка з інформатики: "; cin >> p[i].itm;
        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    cout << "| №     Прізвище     Курс    Спеціальність     Фізика    Математика   Інформатика|" << endl;
    cout << ".................................................................................." << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(2) << right << i + 1 << " "
            << setw(8) << right << p[i].prizv << "         "
            << setw(3) << right << p[i].kurs << "  "
            << setw(12) << right << specStr[p[i].spec] << "       "
            << setw(8) << right << p[i].physicm << " "
            << setw(10) << right << p[i].mathm << "    "
            << setw(10) << right << p[i].itm << " "
            << "    |" << endl;
    }
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    cout << endl;
}

double Average(Student st, const int N)
{
    return (st.physicm + st.mathm + st.itm) / 3.0;
}

double SearchProc(Student* p, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        double res = Average(p[i], N);
        if (res > 4.5)
            k++;
    }

    return (double)k / N * 100;
}

void Exelent(Student* p, const int N)
{
    cout << "Прізвища студентів, які вчаться на відмінно: ";
    for (int i = 0; i < N; i++)
    {
        if (Average(p[i], N) == 5)
            cout << p[i].prizv << " ";
    }
    cout << endl;
}

void Sort(Student* p, const int N)
{
    Student tmp;
    for (int i0 = 0; i0 < N - 1; i0++)
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if ((p[i1].spec > p[i1 + 1].spec) ||
                (p[i1].spec == p[i1 + 1].spec &&
                    p[i1].kurs > p[i1 + 1].kurs) ||
                (p[i1].spec == p[i1 + 1].spec &&
                    p[i1].kurs == p[i1 + 1].kurs &&
                    p[i1].prizv > p[i1 + 1].prizv))
            {
                tmp = p[i1];
                p[i1] = p[i1 + 1];
                p[i1 + 1] = tmp;
            }
}

int* IndexSort(Student* p, const int N)
{
    int* I = new int[N];
    for (int i = 0; i < N; i++)
        I[i] = i;
    int i, j, value;
    for (i = 1; i < N; i++)
    {
        value = I[i];
        for (j = i - 1;
            j >= 0 && ((p[I[j]].spec > p[value].spec) ||
                (p[I[j]].spec == p[value].spec &&
                    p[I[j]].kurs > p[value].kurs ||
                    (p[I[j]].spec == p[value].spec &&
                        p[I[j]].kurs == p[value].kurs &&
                        p[I[j]].prizv > p[value].prizv)));
            j--)
        {
            I[j + 1] = I[j];
        }
        I[j + 1] = value;
    }
    return I;
}

int BinSearch(Student* p, const int N, const string prizv, const Spec spec, const int kurs)
{
    int L = 0, R = N - 1, m;
    do
    {
        m = (L + R) / 2;
        if (p[m].prizv == prizv && p[m].spec == spec && p[m].kurs == kurs)
            return m;
        if ((p[m].spec < spec) ||
            (p[m].spec == spec &&
                p[m].prizv < prizv) ||
            (p[m].spec == spec &&
                p[m].prizv == prizv &&
                p[m].kurs < kurs))
        {
            L = m + 1;
        }
        else
        {
            R = m - 1;
        }
    } while (L <= R);
    return -1;
}

void PrintIndexSorted(Student* p, int* I, const int N)
{
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    cout << "| №     Прізвище     Курс    Спеціальність     Фізика    Математика   Інформатика|" << endl;
    cout << ".................................................................................." << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(2) << right << i + 1 << " "
            << setw(14) << right << p[I[i]].prizv << "   "
            << setw(3) << right << p[I[i]].kurs << "  "
            << setw(12) << right << specStr[p[I[i]].spec] << "       "
            << setw(8) << right << p[I[i]].physicm << " "
            << setw(10) << right << p[I[i]].mathm << "    "
            << setw(10) << right << p[I[i]].itm << " "
            << "    |" << endl;
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    }
}