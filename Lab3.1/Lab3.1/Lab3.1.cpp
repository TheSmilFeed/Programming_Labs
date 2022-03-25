#include <iostream>

using namespace std;

const int K = 1000; 

class Sorts { 
public:
    void Bubble(int* Arr) { //Сортировка пузырьком
        int temp;
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K - i - 1; j++) {
                if (Arr[j] > Arr[j + 1]) {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;
                }
            }
        }
    }

    void CountSort(char* Arr) { //Сортировка подсчетом
        int abc = 26, j = 0, i = 0;
        int countArr[26] = { 0 };
        for (i = 0; i < K; i++) {
            j = (int)(Arr[i] - 'a');
            countArr[j]++;
        }
        i = 0; j = 0;
        while (j <= abc) {
            if (countArr[j] > 0) {
                Arr[i] = (char)((int)('a') + j);
                i++;
                countArr[j]--;
            }
            else
                j++;
        }
    }

    void MergeSort(int* Arr, int begin, int end) { //Сортировка слиянием

        if (begin < end) {
            MergeSort(Arr, begin, (begin + end) / 2);
            MergeSort(Arr, (begin + end) / 2 + 1, end);
            Merge(Arr, begin, end);
        }
    }

private:
    void Merge(int* Arr, int begin, int end) {
        int middle = (begin + end) / 2;
        int start = begin, final = middle + 1, j;
        int tempArr[1000];
        for (j = begin; j <= end; j++) {
            if ((begin <= middle) && ((final > end) || (Arr[start] < Arr[final]))) {
                tempArr[j] = Arr[start];
                start++;
            }
            else {
                tempArr[j] = Arr[final];
                final++;
            }
        }

        for (j = begin; j < end; j++) Arr[j] = tempArr[j];
    }
};

class Input {
public:
    void Int(int* Arr) {
        cout << "Input numbers: " << endl;
        for (int i = 0; i < K; i++)
            cin >> Arr[i];
        cout << endl;
    }
    void Char(char* Arr) {
        cout << "Input symbols: " << endl;
        for (int i = 0; i < K; i++)
            cin >> Arr[i];
        cout << endl;
    }
};

class Output {
public:
    void Int(int* Arr) {
        for (int i = 0; i < K; i++)
            cout << Arr[i] << ' ';
        cout << endl;
    }
    void Char(char* Arr) {
        for (int i = 0; i < K; i++)
            cout << Arr[i] << ' ';
        cout << endl;
    }
};

int main() {
    while (true) { 
        cout << endl << "Input task's number: ";
        int N; cin >> N; cout << endl;
        Input input; Sorts sorts; Output output;
        switch (N) {
        case(1): {
            int* Arr = new int[1000];
            input.Int(Arr);
            sorts.Bubble(Arr);
            output.Int(Arr);
            delete[] Arr;
            break;
        }
        case(2): {
            char* Arr = new char[1000];
            input.Char(Arr);
            sorts.CountSort(Arr);
            output.Char(Arr);
            delete[] Arr;
            break;
        }
        case(3): {
            int* Arr = new int[1000];
            input.Int(Arr);
            sorts.MergeSort(Arr, 0, K - 1);
            output.Int(Arr);
            delete[] Arr;
            break;
        }
        case(4):
            return 0;
        default:
            cout << "Error" << endl;
        }
    }
}