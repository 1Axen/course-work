length = int(input("Enter the size of the arrays: "))
first_list = list(input("Enter text for the first list: ") for _ in range(length))
second_list = list(input("Enter text for the second list: ") for _ in range(length))

matching_elements = []
for element in first_list:
    if element in second_list:
        matching_elements.append(element)

print(matching_elements)