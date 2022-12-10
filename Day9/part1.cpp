#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    ifstream myfile("input.txt");

    vector<char> direction;
    vector<int> amount;

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            direction.push_back(line[0]);
            amount.push_back(int(line[2] - 48));
        }
    }

    vector<vector<char>> grid;
    set<tuple<int, int>> myset;

    for (int i = 0; i < 5; i++) {
        grid.push_back({'.', '.', '.', '.', '.'});
    }

    // starting position
    grid[0][0] = '#';

    int count = 0;

    for (int i = 0; i < direction.size(); i++) {
        for (int j = 0; j < amount[i]; j++) {

        }
    }
}