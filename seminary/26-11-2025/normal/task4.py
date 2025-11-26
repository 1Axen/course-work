length = int(input("Enter the size of the array: "))
numbers = list((int(input("Enter a number: ")) for _ in range(length)))

odd_numbers = []
even_numbers = []
for number in numbers:
    if number % 2 == 0:
        even_numbers.append(number)
    else:
        odd_numbers.append(number)

print(f"The odd numbers are: {odd_numbers}")
print(f"The even numbers are: {even_numbers}")