length = int(input("Enter the size of the array: "))
numbers = list((int(input("Enter a number: ")) for _ in range(length)))
biggest_number = 0

for number in numbers:
    biggest_number = max(number, biggest_number)

print(f"The biggest number is: {biggest_number}")