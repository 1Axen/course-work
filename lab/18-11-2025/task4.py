max = int(input("Enter a number: "))
numbers = list(range(1, max + 1))

map = {}
for n in range(1, max + 1):
    map[n] = numbers[max - n]

print(numbers)
print(map)