length = int(input("Enter the size of the array: "))
numbers = list((int(input("Enter a number: ")) for _ in range(length)))

def larger_than_ten(numbers: list[int]) -> list[int]:
    result = []
    for number in numbers:
        if number > 10:
            result.append(number)

    return result

print(larger_than_ten(numbers))