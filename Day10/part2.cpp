#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    ifstream myfile("input.txt");

    vector<string> directions;

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            directions.push_back(line);
        }
    }

    string s = "";

    for (int i = 0; i < 240; i++) {
        s = s + '.';
    }

    int cycle = 1;
    int count = 1;
    vector<int> signal_strength;

    int position[3] = {1, 2, 3};
    bool isVisible = false;

    for (int i = 0; i < directions.size(); i++) {
        if (directions[i] == "noop") {
            int x = 0;
        }
        else
        {
            int num = stoi(directions[i].substr(5, directions[i].length() - 1));

            count = count + num;

            position[0] = count - 1;
            position[1] = count;
            position[2] = count + 1;

            
        }
    }
}