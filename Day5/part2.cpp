#include <bits/stdc++.h>

using namespace std;

//         [H]     [W] [B]
//     [D] [B]     [L] [G] [N]
// [P] [J] [T]     [M] [R] [D]
// [V] [F] [V]     [F] [Z] [B]     [C]
// [Z] [V] [S]     [G] [H] [C] [Q] [R]
// [W] [W] [L] [J] [B] [V] [P] [B] [Z]
// [D] [S] [M] [S] [Z] [W] [J] [T] [G]
// [T] [L] [Z] [R] [C] [Q] [V] [P] [H]
//  1   2   3   4   5   6   7   8   9

int main() {
    stack<char> one;
    one.push('T');
    one.push('D');
    one.push('W');
    one.push('Z');
    one.push('V');
    one.push('P');

    stack<char> two;
    two.push('L');
    two.push('S');
    two.push('W');
    two.push('V');
    two.push('F');
    two.push('J');
    two.push('D');

    stack<char> three;
    three.push('Z');
    three.push('M');
    three.push('L');
    three.push('S');
    three.push('V');
    three.push('T');
    three.push('B');
    three.push('H');

    stack<char> four;
    four.push('R');
    four.push('S');
    four.push('J');

    stack<char> five;
    five.push('C');
    five.push('Z');
    five.push('B');
    five.push('G');
    five.push('F');
    five.push('M');
    five.push('L');
    five.push('W');

    stack<char> six;
    six.push('Q');
    six.push('W');
    six.push('V');
    six.push('H');
    six.push('Z');
    six.push('R');
    six.push('G');
    six.push('B');

    stack<char> seven;
    seven.push('V');
    seven.push('J');
    seven.push('P');
    seven.push('C');
    seven.push('B');
    seven.push('D');
    seven.push('N');

    stack<char> eight;
    eight.push('P');
    eight.push('T');
    eight.push('B');
    eight.push('Q');

    stack<char> nine;
    nine.push('H');
    nine.push('G');
    nine.push('Z');
    nine.push('R');
    nine.push('C');

    string line;
    ifstream myfile("input.txt");

    vector<int> amount;
    vector<int> from;
    vector<int> to;

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            if (line.length() == 18) {
                // minus 48 due to ASCII code math
                amount.push_back(int(line[5] - 48));
                from.push_back(int(line[12] - 48));
                to.push_back(int(line[17] - 48));
            }
            else if (line.length() == 19)
            {
                string temp = line.substr(5, 6);
                amount.push_back(stoi(temp));
                from.push_back(int(line[13] - 48));
                to.push_back(int(line[18] - 48));
            }
        }
    }

    map<int, stack<char>> mymap = {{1, one}, {2, two}, {3, three}, {4, four}, {5, five}, {6, six}, {7, seven}, {8, eight}, {9, nine}};

    stack<char> temp_stack;

    for (int i = 0; i < amount.size(); i++) {
        for (int j = 0; j < amount[i]; j++) {
            if (amount[i] == 1) {
                char temp = mymap.at(from[i]).top();
                mymap.at(from[i]).pop();
                mymap.at(to[i]).push(temp);
            } else {
                char temp = mymap.at(from[i]).top();
                mymap.at(from[i]).pop();
                temp_stack.push(temp);
            }
        }

        while (!temp_stack.empty()) {
            char temp = temp_stack.top();
            temp_stack.pop();
            mymap.at(to[i]).push(temp);
        }
    }

    for (int i = 1; i < 10; i++) {
        cout << mymap.at(i).top() << endl;
    }
}