#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


int findMax(int* arr) {
    int length = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int findMin(int* arr) {
    int length = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0];
    for (int i = 0; i < length; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i]
                ;
        }
    }
    return min;
}

int* createArr() {
    int n;

    cout << "enter length";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 20 + -10;
    }

    return arr;
}

int findMinInd(int* arr, int n) {

    int min = abs(arr[0]);
    int idxMin = 0;

    for (int i = 0; i < n; i++) {
        if (abs(arr[i]) < min) {
            min = abs(arr[i]);
            idxMin = i;
        }
    }
    return idxMin;
}

int negate(int h)
{
    return -h;
}

void matrix()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));
    int i = 0, j = 0, ** A, sz = 4, count = 0, stroka = 0, sum = 0;
    A = new int* [sz];
    for (i = 0; i < 4; i++)
    {
        A[i] = new int[sz];
        for (j = 0; j < 4; j++)
        {
            A[i][j] = rand() % 99 - 25;
            cout << A[i][j] << "\t";
        }
        cout << "\n";
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (A[i][j] > 0)
            {
                count++;
                sum += A[i][j];
            }
        }
        if (count == 4)
        {
            stroka = ++i;
            break;
        }
        else
        {
            count = 0;
            sum = 0;
        }
    }
    cout << "Первая положительная строка: " << stroka << endl;
    cout << "Сумма элементов этой строки: " << sum << endl;
    cout << "Новая матрица, уменьшенная на эту сумму:\n";
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cout << A[i][j] - sum << "\t";
        }
        cout << "\n";
    }
}
double MinimumOfTheRow(double N, double First, ...)
{
    double* D = &First;
    double* Min = &First;
    while (N--)
    {
        if (*(++D) < *Min)
            *Min = *D;
    }
    return *Min;
}
int MinimumOfTheRow(int N, int First, ...)
{
    int* U = &First;
    int* Min = &First;
    while (N--)
    {
        if (*Min > *(++U))
            *Min = *U;
    }
    return *Min;
}

int findMin(int** A, int row, int col)
{
    for (int j = 0; j < col; j++)
    {
        int negativeNum = 0;
        for (int i = 0; i < row; i++)
        {
            if (*(*(A + i) + j) < 0)
                negativeNum = negativeNum + 1;
        }
        if (negativeNum == row)
            return j;
    }
    return -1;
}
int getAverage(int** A, int row, int nn)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
        sum = sum + *(*(A + i) + nn);
    return sum / row;
}
void deduct(int** A, int row, int col, int* nc)
{
    for (int j = 0; j < col; j++)
        for (int i = 0; i < row; i++)
            *(*(A + i) + j) = *(*(A + i) + j) - *nc;
}


int findAllMinus(int** A, int row, int col)
{
    for (int j = 0; j < col; j++)
    {
        int negativeNum = 0;
        for (int i = 0; i < row; i++)
        {
            if (*(*(A + i) + j) < 0)
                negativeNum = negativeNum + 1;
        }
        if (negativeNum == row)
            return j;
    }
    return -1;
}

void dop1_1() {
    int* arr = createArr();
    int length = sizeof(arr) / sizeof(arr[0]);
    int idx = findMinInd(arr, length);

    int count = 0;

    for (int i = idx + 1; i < length; i++)
    {
        if (arr[i] < 0) {
            count++;
        }
    }

    cout << "count " << count << endl;
}




void dop1_2()
{
    setlocale(LC_ALL, "RUS");
    int** A, row, col, i, j;
    cout << "Введите число строк матрицы "; cin >> row;
    cout << "Введите чиcло столбцов "; cin >> col;
    A = new int* [row];
    for (int i = 0; i < row; i++)
    {
        A[i] = new int[col];
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {

            *(*(A + i) + j) = rand() % 20 + 1;
        }
    }
    int negCol = findAllMinus(A, row, col);
    if (negCol >= 0)
    {
        cout << "Индекс отрицательного столбца: " << negCol << endl;


    }
    cout << "Результирующая матрица:" << endl;

    for (int i = 0; i < row; i++)
    {
        cout << endl;
        for (int j = 0; j < col; j++)
        {
            if (j == negCol)
            {
                *(*(A + i) + j) = abs(*(*(A + i) + j));
            }
            cout << "A[" << i << "," << j << "] =" << *(*(A + i) + j) << "\t";
        }

    }
    cout << endl;
}

void dop2_1() {
    int arr[15];

    for (int i = 0; i < 15; i++)
    {
        arr[i] = rand() % 200 + 1;
    }

    int res = 1;

    for (int i = 2; i <= 7; i++)
    {
        res *= arr[i];
    }

    cout << "res = " << res << endl;
}


void dop2_2()
{
    setlocale(LC_CTYPE, "Rus");
    int** A, row, col, i, j;
    cout << "Введите число строк матрицы "; cin >> row;
    cout << "Введите чиcло столбцов "; cin >> col;
    A = new int* [row];
    for (int i = 0; i < row; i++)
        A[i] = new int[col];
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
        {
            *(*(A + i) + j) = rand() % 20 + 1;
        }
    int negCol = findMin(A, row, col);
    if (negCol >= 0)
    {
        cout << "Индекс отрицательного столбца: " << negCol << endl;
        int average = getAverage(A, row, negCol);
        cout << "Среднее арифметическое: " << average << endl;
        deduct(A, row, col, &average);
    }
    cout << "Результирующая матрица:" << endl;
    for (int i = 0; i < row; i++)
    {
        cout << endl;
        for (int j = 0; j < col; j++)
            cout << "A[" << i << "," << j << "] =" << *(*(A + i) + j) << "\t";
    }
    for (int k = 0; k < row; k++)
        delete A[k];
    delete[] A;
}

void dop3_1() {
    int arr[15];

    for (int i = 0; i < 15; i++)
    {
        arr[i] = rand() % 4 - 1;
    }

    int times = 0;
    int idxFirst;
    int idxSecond;

    for (int i = 0; i < 15; i++)
    {
        if (arr[i] == 0 && times == 0) {
            idxFirst = i;
            times++;
        }

        if (arr[i] == 0 && times == 1) {
            idxSecond = i;
        }
    }

    int sum = 0;

    for (int i = idxFirst; i < idxSecond; i++)
    {
        sum += arr[i];
    }

    cout << sum;
}

void dop3_2()
{

    setlocale(LC_CTYPE, "Russian");
    matrix();


}
void main1(int& n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = 10 - rand() % 20;
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void main2(int& ROW, int& COLUMN)
{
    setlocale(LC_CTYPE, "Russian");
    int** matrica = new int* [ROW];
    int k = 0, summa = 0, o = 0, index;
    for (int i = 0; i < COLUMN; i++)
    {
        matrica[i] = new int[COLUMN];
    }

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            matrica[i][j] = 8 - rand() % 15;
            cout << matrica[i][j] << " " << ends;
        }
        cout << endl;
    }

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if (matrica[i][j] < 0)
            {
                k += 1;
            }
        }
        if (k == 0)
        {
            for (int v = 0; v < ROW; v++) {
                summa += matrica[i][v];
            }
            cout << summa << endl;
        }
        k = 0;
        summa = 0;
    }
    cout << endl;

}


int main()
{
    srand(time(NULL));

    setlocale(LC_CTYPE, "Russian");
    int n;
    cout << "Введите количество элементов массива = ";
    cin >> n;
    main1(n);


    int N;
    cout << "Введите количество строк и столбцов матрицы = ";
    cin >> N;
    main2(N, N);

    dop1_2();
    dop2_1();
    dop2_2();
    dop3_1();
    dop3_2();
}

