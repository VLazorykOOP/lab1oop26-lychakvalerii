//завдання 1
#include <iostream>
#include <vector>

using namespace std;


void Task31(double*& A, int& n) {
    cout << "Input n: ";
    cin >> n;

    A = new double[n];
    if (A == NULL) exit(1);

    for (int i = 0; i < n; i++) {
        cout << "A[" << i << "]=";
        cin >> A[i];
    }
}


void Task33(double* A, int n) {
    if (A == NULL) { cout << "Firstly input the array!" << endl; return; }

    double* C = new double[n];
    if (C == NULL) exit(1);

    cout << "Result C (2^i * Ai):" << endl;
    for (int i = 0; i < n; i++) {
       
        double p = 1;
        for (int j = 0; j <= i; j++) {
            p *= 2;
        }
        C[i] = p * A[i];
        cout << C[i] << "\t";
    }
    cout << endl;

    delete[] C;
}


void Task34(double* A, int n) {
    if (A == NULL) return;
    vector<double> v;
    for (int i = 0; i < n; i++) v.push_back(A[i]);

    cout << "data from the vector: ";
    for (double x : v) cout << x << " ";
    cout << endl;
}

int main() {
    double* A = NULL;
    int n = 0;
    int choice;

    do {
       
        cin >> choice;

        if (choice == 1) Task31(A, n);
        if (choice == 3) Task33(A, n);
        if (choice == 4) Task34(A, n);

    } while (choice != 0);

    if (A != NULL) delete[] A;
    return 0;
}