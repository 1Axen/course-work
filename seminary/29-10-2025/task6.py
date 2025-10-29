first = float(input("Enter the first number: "))
second = float(input("Enter the second number: "))

result = (first / second)
remainder = result - int(result)
print(f"The remainder of the division is: {remainder}")