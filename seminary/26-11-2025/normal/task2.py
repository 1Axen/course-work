length = int(input("Enter the size of the array: "))
strings = list((input("Enter some text: ") for _ in range(length)))

strings_larger_than_five = []
for string in strings:
    if len(string) > 5:
        strings_larger_than_five.append(string)

print(strings_larger_than_five)
