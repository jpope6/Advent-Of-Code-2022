class Monkey:
    def __init__(self, items, operation, test, true_monkey, false_monkey) -> None:
        self.items = items
        self.operation = operation
        self.test = test
        self.true_monkey = true_monkey
        self.false_monkey = false_monkey

    def doOperation(self, worry):
        symbol = self.operation[0]
        num = self.operation[1]

        if num == "old":
            num = worry

        return eval(f"{worry}{symbol}{num}")

    def doTest(self, worry):
        if worry % self.test == 0:
            pass
        else:
            pass


directions = []

with open("Day11/test.txt") as file:
    lines = [line.rstrip() for line in file.readlines()]

temp = []
for line in lines:
    if line == "":
        directions.append(temp)
        temp = []
    else:
        temp.append(line)
directions.append(temp)

monkeys = []

for direction in directions:
    items = operation = []
    test = true_monkey = false_monkey = 0

    for line in direction:
        line = line.split()
        if line[0] == "Starting":
            for i in range(2, len(line)):
                num = line[i][0] + line[i][1]
                items.append(int(num))

        if line[0] == "Operation:":
            operation = [line[4], line[5]]

        if line[0] == "Test:":
            test = int(line[3])

        if line[0] == "If":
            if line[1] == "true:":
                true_monkey = int(line[5])
            else:
                false_monkey = int(line[5])

    monkeys.append(Monkey(items, operation, test, true_monkey, false_monkey))