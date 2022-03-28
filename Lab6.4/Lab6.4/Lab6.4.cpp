#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    set<string> stLogin;
    set<string> stLoginNum;
    string input = "";
    int inputNum;
    while (true) {
        cout << "Login: " << endl;
        cin >> input;
        if (input == "exit") {
            break;
        }
        if (input == "imteacher") {
            cout << "Collected data:" << endl;
            for (auto loginNum : stLoginNum) {
                cout << loginNum << endl;
            }
            cout << endl;
            continue;
        }
        cout << "Type your answers: " << endl;
        cin >> inputNum;
        if (stLogin.empty() || stLogin.find(input) == stLogin.end()) {
            cout << "Login Successefull: " << input << endl << endl;

            stLogin.insert(input);
            stLoginNum.insert(input + " " + to_string(inputNum));
        }
        else {
            cout << "Login Error: " << input << endl << endl;
        }
    }
    return 0;
}