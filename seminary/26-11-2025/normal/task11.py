length = int(input("Enter the size of the array: "))
numbers = list((int(input("Enter a number: ")) for _ in range(length)))

possible_lists = []
for start in range(length):
    for len in range(start + 1, length + 1):
        inner_list = list((numbers[index] for index in range(start, len)))
        possible_lists.append(inner_list)

print(possible_lists)