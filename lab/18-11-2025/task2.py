import random

max = int(input("Enter a number: "))
random_numbers = [random.randint(1, max) for _ in range(0, max)]

result = []
for index in range(len(random_numbers)):
    first = random_numbers[index]
    result.append(first)
    if (index < len(random_numbers) - 1):
        second = random_numbers[index + 1]
        result.append(first + second)

print(result)