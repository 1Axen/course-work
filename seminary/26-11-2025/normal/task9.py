length = int(input("Enter the size of the array: "))
numbers = list((int(input("Enter a number: ")) for _ in range(length)))

def count_even_numbers(numbers: list[int]) -> int:
    count = 0
    for number in numbers:
        if number % 2 == 0:
            count += 1

    return count

print(f"There are {count_even_numbers(numbers)} even numbers")