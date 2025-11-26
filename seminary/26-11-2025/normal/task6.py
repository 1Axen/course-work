length = int(input("Enter the size of the array: "))
threshold = int(input("Enter the threshold number: "))
numbers = list((int(input("Enter a number: ")) for _ in range(length)))

average = sum(numbers) / length
valid_numbers = []
for number in numbers:
    if number < average and number > threshold:
        valid_numbers.append(number)

print(valid_numbers)