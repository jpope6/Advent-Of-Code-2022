#include <bits/stdc++.h>

using namespace std;

void checkForCycle(vector<int>& signal_strength, int& cycle, int& count) {
    int cycle_counts[6] = {20, 60, 100, 140, 180, 220};

    for (int x : cycle_counts) {
                if (cycle == x) {
                    signal_strength.push_back(count * x);
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

    int cycle = 1;
    int count = 1;

    vector<int> signal_strength;

    for (int i = 0; i < directions.size(); i++) {
        if (directions[i] == "noop") {
            cycle++;

            checkForCycle(signal_strength, cycle, count);
        } else {
            cycle++;
            int num = stoi(directions[i].substr(5, directions[i].length() - 1));

            checkForCycle(signal_strength, cycle, count);

            count = count + num;
            cycle++;

            checkForCycle(signal_strength, cycle, count);
        }
    }

    int sum = 0;

    for (int x : signal_strength) {
        sum = sum + x;
    }

    cout << sum << endl;
}