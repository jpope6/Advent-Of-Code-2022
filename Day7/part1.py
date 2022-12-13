from collections import deque

with open("Day7/input.txt") as file:
    lines = [line.rstrip() for line in file.readlines()]


class Node:
    def __init__(self, parent, name):
        self.parent = parent
        self.name = name
        self.children = []
        self.files = []
        self.size = 0

    def getSize(self):
        total_size = 0

        for file in self.files:
            total_size += file
            
        for child in self.children:
            total_size += child.size

        self.size = total_size
        return self.size

    def getChild(self, name):
        for child in self.children:
            if child.name == name:
                return child


def main():
    root = Node(None, "/")
    curr = root

    for line in lines:
        line = line.split()

        if line[0] == "$":
            if line[1] == "ls":
                pass
                # print("bing bong")
            else:
                if line[2] == "..":
                    curr = curr.parent
                else:
                    curr = curr.getChild(line[2])

        if line[0] == "dir":
            curr.children.append(Node(curr, line[1]))

        if line[0].isnumeric():
            curr.files.append(int(line[0]))

    stack = []
    queue = deque([root])
    while queue:
        root = queue.popleft()
        stack.append(root)
        for child in root.children:
            queue.append(child)

    total = 0
    while stack:
        root = stack.pop()
        if root.getSize() < 100000:
            total += root.size
        # stack.pop()

    print(total)

if __name__ == "__main__":
    main()
