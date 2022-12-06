#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    ifstream myfile("input.txt");

    vector<string> first;
    vector<string> second;

    int index = 0;

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == ',') {
                    index = i;
                }
            }

            string one = line.substr(0, index);
            string two = line.substr(index + 1);

            first.push_back(one);
            second.push_back(two);
        }
    }

    int job_one_start = 0;
    int job_one_end = 0;
    int job_two_start = 0;
    int job_two_end = 0;
    int count = 0;

    for (int i = 0; i < first.size(); i++) {
        for (int j = 0; j < first[i].length(); j++) {
            if (first[i][j] == '-') {
                index = j;
            }
        }

        job_one_start = stoi(first[i].substr(0, index));
        job_one_end = stoi(first[i].substr(index + 1));

        for (int j = 0; j < second[i].length(); j++) {
            if (second[i][j] == '-') {
                index = j;
            }
        }

        job_two_start = stoi(second[i].substr(0, index));
        job_two_end = stoi(second[i].substr(index + 1));

        // check if the one job completely overlaps another job
        if ((job_one_start >= job_two_start && job_one_end <= job_two_end) || (job_two_start >= job_one_start && job_two_end <= job_one_end)) {
            count++;
        }
    }

    cout << count << endl;
}