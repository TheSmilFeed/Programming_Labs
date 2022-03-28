#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    string word;
    int amount = 0;
    map<string, int> counter;
    cout << "Type words (or '_' - to stop input):" << endl;
    while (true) {
        cin >> word;
        if (word == "_") break;
        amount++;
        counter[word]++;
    }
    map<string, int>::iterator it;
    for (it = counter.begin(); it != counter.end(); ++it)
        cout << it->first << ': ' << it->second * 100 / amount << '%' << endl;
    return 0;
}