#include <bits/stdc++.h>

using namespace std;

void drawPixel(int X, int cycle, vector<string>& grid) {
    int row = (cycle - 1) % 6;
    int col = (cycle - 1) % 40;

    cout << row << ", " << col << endl;

    for (int x : {X - 1, X, X + 1}) {
        if (col == x) {
            grid[row][col] = '#';
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

    int cycle = 0;
    int X = 1;

    for (int i = 0; i < directions.size(); i++) {
        if (directions[i] == "noop") {
            cycle++;
            drawPixel(X, cycle, grid);
        } else {
            cycle++;
            drawPixel(X, cycle, grid);

            cycle++;
            drawPixel(X, cycle, grid);
            X = X + stoi(directions[i].substr(5, directions[i].length() - 4));
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
    