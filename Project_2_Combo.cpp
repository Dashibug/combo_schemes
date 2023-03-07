/////////////////////////////
// Цыбикжапов Даши БПМ-21-1//
/////////////////////////////
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <locale.h>

using namespace std;

int bin_coef(int n, int k) {//биномин коэф 
    if (k == 0 || k == n) {
        return 1;
    }
    else {
        return bin_coef(n - 1, k - 1) + bin_coef(n - 1, k);
    }
}

int combination(int n, int k) {
    return bin_coef(n, k);
}

void sum() {
    int n, k, sum = 0;
    cout << "Введите n: ";
    cin >> n;
    cout << "Введите k:";
    cin >> k;
    sum = n + k;
    cout << "Сумма:" << sum << endl;
}

void umnozh() {////////////////////////////!!
    int n, k, mnozh = 1;
    cout << "Введите n: !";
    cin >> n;
    cout << "Введите k:";
    cin >> k;
    for (int i = 1; i <= k; i++) {
        mnozh *= (n-i+1.0) / i;
    }
    cout << "Произведение: " << 2*mnozh << endl;
}

void combo_without_rep() {
    int n, k;
    cout << "Введите n: ";
    cin >> n;
    cout << "Введите k:";
    cin >> k;
    cout << "Число сочетаний: " << bin_coef(n, k) << endl;
}

void combo_with_rep() {
    int n, k;
    cout << "Введите n: ";
    cin >> n;
    cout << "Введите k: ";
    cin >> k;
    cout << "Число сочетаний: " << bin_coef(n + k - 1, n-1) << endl;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int permutation(int n, int k) {//перестановка
    return factorial(n) / factorial(n - k);
}

int permutation_without_repetition(int n) {
    return factorial(n);
}

void permutations() {
    int n;
    cout << "Введите число элементов n: ";
    cin >> n;
    int result = permutation(n, n);
    cout << "Число перестановок: " << result << endl;
}

void permutations_without_repetition() {
    int n;
    cout << "Введите число элементов n: ";
    cin >> n;
    int result = permutation_without_repetition(n);
    cout << "Число перестановок без повторений: " << result << endl;
}

void arrangements() {//размещения
    int n, k;
    cout << "Введите число элементов n: ";
    cin >> n;
    cout << "Введите число элементов в каждой перестановке k: ";
    cin >> k;
    int result = pow(n, k);
    cout << "Число размещений:" << result << endl;
}

void arrangements_without_repetition() {
    int n, k;
    cout << "Введите число элементов n: ";
    cin >> n;
    cout << "Введите число элементов в каждой перестановке k: ";
    cin >> k;
    int result = factorial(n) / factorial(n - k);
    cout << "Число размещений без повторений: " << result << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int choice;
    do {
        cout << "Выберите действие:" << endl;
        cout << "(1)-Посчитать сумму" << endl;
        cout << "(2)-Посчитать произведение" << endl;
        cout << "(3)-Посчитать число сочетаний без повторений" << endl;
        cout << "(4)-Посчитать число сочетаний с повторениями" << endl;
        cout << "(5) Вычислить число перестановок" << endl;
        cout << "(6) Вычислить число перестановок без повторений" << endl;
        cout << "(7) Вычислить число размещений" << endl;
        cout << "(8) Вычислить число размещений без повторений" << endl;
        cout << "(9) Завершить программу" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            sum();
            break;
        case 2:
            umnozh();
            break;
        case 3:
            combo_without_rep();
            break;
        case 4:
            combo_with_rep();
            break;
        case 5:
            permutations();
            break;
        case 6:
            permutations_without_repetition();
            break;
        case 7:
            arrangements();
            break;
        case 8:
            arrangements_without_repetition();
            break;
        case 9:
            return 0;
        default:
            cout << "Неправильный выбор!" << endl;
            break;
        }
    } while (true);
    return 0;
}

