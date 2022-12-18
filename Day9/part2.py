with open("Day9/input.txt") as file:
    lines = [line.rstrip() for line in file.readlines()]

visited = set()
head = [0, 0]
tail = [0, 0]
index = 0

rope = [[0, 0], [0, 0], [0, 0], [0, 0], [0, 0], [0, 0], [0, 0], [0, 0], tail]
current = head

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

        current = head

        for knot in rope:
            check = True
            if abs(current[0] - knot[0]) > 1 and abs(current[1] - knot[1]) > 1:
                check = False

            if current[0] - knot[0] == 2:
                if check:
                    knot[1] = current[1]
                knot[0] += 1

            if current[0] - knot[0] == -2:
                if check:
                    knot[1] = current[1]
                knot[0] -= 1

            if current[1] - knot[1] == 2:
                if check:
                    knot[0] = current[0]
                knot[1] += 1

            if current[1] - knot[1] == -2:
                if check:
                    knot[0] = current[0]
                knot[1] -= 1

            current = knot

        visited.add((tail[0], tail[1]))

print(len(visited))
