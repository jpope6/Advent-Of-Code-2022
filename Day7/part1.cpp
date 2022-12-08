#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    vector<Node> children;
    string name;

    Node(string name_) {
        name = name_;
    }

    void addChild(Node node) {
        children.push_back(node);
    }
};

int main() {
    Node root("/");
}