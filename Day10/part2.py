with open("/home/jpope/Advent-Of-Code-2022/Day10/input.txt") as file:
    lines = [line.rstrip() for line in file.readlines()]

def drawPixel(X, cycle, grid):
    pos = (cycle - 1) % 40
    if pos in {X - 1, X, X+ 1}:
        grid[cycle - 1] = "#"

X = 1
cycle = 0
grid = list("." * 40 * 6)

for line in lines:
    line = line.split()

    if line[0] == "noop":
        cycle += 1
        drawPixel(X, cycle, grid)

    elif line[0] == "addx":
        cycle += 1
        drawPixel(X, cycle, grid)

        cycle += 1
        drawPixel(X, cycle, grid)
        X += int(line[1])

answer = []

for i in range(0, 201, 40):
    answer.append("".join(grid[i: i + 40]))

for i in answer:
    for c in i:
        if c == '.':
            print("\U00002B1B", end='')
        else:
            print("\U00002B1C", end='')

    print("")