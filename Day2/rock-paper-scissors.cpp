#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    ifstream myfile("input.txt");

    vector<char> opponent_moves;
    vector<char> player_moves;

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            opponent_moves.push_back(line[0]);
            player_moves.push_back(line[2]);
        }
    }

    int points = 0;

    for (int i = 0; i < player_moves.size(); i++) {
        if (player_moves[i] == 'Y') {
            points += 3;
            if (opponent_moves[i] == 'A') {
                points += 1;
            } else if (opponent_moves[i] == 'B') {
                points += 2;
            } else if (opponent_moves[i] == 'C') {
                points += 3;
            }
        } else if (player_moves[i] == 'X') {
            if (opponent_moves[i] == 'A') {
                points += 3;
            } else if (opponent_moves[i] == 'C') {
                points += 2;
            } else if (opponent_moves[i] == 'B') {
                points += 1;
            } 
        } else if (player_moves[i] == 'Z') {
            points += 6;
            if (opponent_moves[i] == 'B') {
                points += 3;
            } else if (opponent_moves[i] == 'C') {
                points += 1;
            } else if (opponent_moves[i] == 'A') {
                points += 2;
            }
        }
    }

    cout << points << endl;
}