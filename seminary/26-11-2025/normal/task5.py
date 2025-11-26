length = int(input("Enter the size of the array: "))
numbers = list((int(input("Enter a number: ")) for _ in range(length)))

average = sum(numbers) / length
larger_than_average = []
for number in numbers:
    if number > average:
        larger_than_average.append(number)

print(larger_than_average)