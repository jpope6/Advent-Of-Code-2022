#include <bits/stdc++.h>

using namespace std;

void drawSquare(int position[3], int& index, int& count, vector<string>& s) {
    int row = index % 6;
    int col = index % 40;

    cout << row << ", " << col << endl;

    for (int i = 0; i < 3; i++) {
        if (col == position[i]) {
            s[row][col] = '#';
        }
    }
}

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
    vector<string> grid;

    for (int i = 1; i <= 240; i++) {
        s = s + '.';

        if (i % 40 == 0) {
            grid.push_back(s);
            s = "";
        }
    }

    grid.push_back(s);

    int cycle = 1;
    int X = 1;

    int index = 0;

    int position[3] = {0, 1, 2};

    for (int i = 0; i < directions.size(); i++) {
        drawSquare(position, index, X, grid);
        if (directions[i] == "noop") {
            index++;
        } else {
            int num = stoi(directions[i].substr(5, directions[i].length() - 1));
            index++;

            // cout << num << endl;

            drawSquare(position, index, X, grid);
            X = X + num;
            index++;

            // cout << X << endl;

            position[0] = X - 1;
            position[1] = X;
            position[2] = X + 1;

            // cout << position[0] << ", " << position[1] << ", " << position[2] << endl;
        }
    }

    for (string s : grid) {
        for (char c : s) {
            if (c == '.') {
                // black square
                cout << "\U00002B1B";
            } else {
                // white square
                cout << "\U00002B1C";
            }
        }
        cout << endl;
    }
}