with open("Day9/input.txt") as file:
    lines = [line.rstrip() for line in file.readlines()]

visited = set()
head = [0, 0]
tail = [0, 0]
index = 0

for line in lines:
    line = line.split()

    index = int(line[1])

    for i in range(index):

        if line[0] == "R":
            head[0] += 1

        if line[0] == "L":
            head[0] -= 1

        if line[0] == "U":
            head[1] += 1

        if line[0] == "D":
            head[1] -= 1

        if head[0] - tail[0] == 2:
            tail[1] = head[1]
            tail[0] += 1

        if head[0] - tail[0] == -2:
            tail[1] = head[1]
            tail[0] -= 1

        if head[1] - tail[1] == 2:
            tail[0] = head[0]
            tail[1] += 1

        if head[1] - tail[1] == -2:
            tail[0] = head[0]
            tail[1] -= 1

        visited.add((tail[0], tail[1]))


print(len(visited))
