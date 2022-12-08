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

    int highest = 0;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int left = row;
            int left_count = 0;
            while (left > 0) {
                if (grid[left - 1][col] >= grid[row][col]) {
                    left_count++;
                    break;
                } else {
                    left_count++;
                    left--;
                }
            }

            int right = row;
            int right_count = 0;
            while (right < rows - 1) {
                if (grid[right + 1][col] >= grid[row][col]) {
                    right_count++;
                    break;
                } else {
                    right_count++;
                    right++;
                }
            }

            int up = col;
            int up_count = 0;
            while (up > 0) {
                if (grid[row][up - 1] >= grid[row][col]) {
                    up_count++;
                    break;
                } else {
                    up_count++;
                    up--;
                }
            }

            int down = col;
            int down_count = 0;
            while (down < cols - 1) {
                if (grid[row][down + 1] >= grid[row][col]) {
                    down_count++;
                    break;
                } else {
                    down_count++;
                    down++;
                }
            }

            int score = left_count * right_count * up_count * down_count;

            highest = max(highest, score);
        }
    }

    cout << highest << endl;
}