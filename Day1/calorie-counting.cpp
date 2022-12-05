#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    ifstream myfile("calorie-input.txt");

    vector<int> calories;
    int calorie_count = 0;

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            if (line.empty()) {
                calories.push_back(calorie_count);
                calorie_count = 0;
            }
            else
            {
                calorie_count += stoi(line);
            }
        }
        myfile.close();
    }

    sort(calories.begin(), calories.end(), greater<int>());

    cout << calories[0] + calories[1] + calories[2] << endl;
}
