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

    int count = 0;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int left = row;
            while (left > 0) {
                if (grid[left - 1][col] >= grid[row][col]) {
                    break;
                } else {
                    left--;
                }
            }

            int right = row;
            while (right < rows - 1) {
                if (grid[right + 1][col] >= grid[row][col]) {
                    break;
                } else {
                    right++;
                }
            }

            int up = col;
            while (up > 0) {
                if (grid[row][up - 1] >= grid[row][col]) {
                    break;
                } else {
                    up--;
                }
            }

            int down = col;
            while (down < cols - 1) {
                if (grid[row][down + 1] >= grid[row][col]) {
                    break;
                } else {
                    down++;
                }
            }

            if (left == 0 || right == rows - 1 || up == 0 || down == cols - 1) {
                count++;
            }
        }
    }

    cout << count << endl;
}