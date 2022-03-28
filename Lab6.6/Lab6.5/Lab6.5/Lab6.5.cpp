#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    string surname;
    int group;
    list<string> listSurname;
    list<int> listGroup;
    cout << "Input student's group and surname (0 and 0 to stop):\n";
    while (true) {
        cin >> group >> surname;
        if (group == 0 || surname == "0") {
            break;
        }
        listSurname.push_back(to_string(group) + " " + surname);
        listGroup.push_back(group);
    }
    cout << endl;
    listGroup.sort();
    listGroup.unique();
    for (auto group : listGroup) {
        cout << group << ":\n";
        for (auto surname : listSurname) {
            if (surname.find(to_string(group)) != string::npos) {
                cout << surname << endl;
            }
        }
        cout << endl;
    }
}