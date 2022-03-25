#include <iostream>

using namespace std;

void T1() {
    int n, k;
    cout << "Input: ";
    cin >> n;
    cout << endl;
    for (int i = 0; i <= n; i++) {
        for (k = 0; k <= i; k++) {
            cout << k;
        }
        cout << endl;
    }
}

void T2() {
    int n, c;
    cout << "Input positive integer number: ";
    cin >> n;
    if (n > 0) {
        c = n;
        for (int k = 1; k <= n; ++k) {
            cout << c << endl;
            c *= (n - k);
            c /= (k + 1);
        }
    }
}

void T3() {
    double sum = 0, key;
    int k = 0;
    cout << "Vvodite chisla (zero to stop): " << endl;
    cin >> key;
    while (key != 0) {
        k++;
        sum += key;
        cin >> key;
    }
    cout << sum / k << endl;
}

int main() {
    int key;
    while (true) {
        cout << endl << "Vvedite nomer zadania: ";
        cin >> key;
        cout << endl;
        switch (key) {
        case 1: {
            T1();
            break;
        }
        case 2: {
            T2();
            break;
        }
        case 3: {
            T3();
            break;
        }
        case 4:
            return 0;
        default:
            cout << "Error" << endl;
        }
    }
}