#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    ifstream myfile("input.txt");

    string input;

    if (myfile.is_open()) {
        getline(myfile, line);
    }

    set<char> myset;

    for (int i = 0; i < line.length() - 4; i++) {
        string temp = line.substr(i, 4);

        for (char& c : temp) {
            myset.insert(c);
        }

        if (myset.size() == 4) {
            cout << i + 4 << endl;
            break;
        }
        else
        {
            myset.clear();
        }
    }
}