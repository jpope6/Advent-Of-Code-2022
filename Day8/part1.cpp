#include <bits/stdc++.h>

using namespace std;

int main() {

    string line;
    ifstream myfile("input.txt");

    vector<vector<int>> grid;
    vector<int> temp;

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            for (char c : line) {
                temp.push_back(int(c) - 48);
            }
            grid.push_back(temp);
            temp.clear();
        }
    }

    int rows = grid.size();
    int cols = grid[0].size();
    cout << rows << ", " << cols << endl;

    int count = 0;

    cout << count << endl;
}