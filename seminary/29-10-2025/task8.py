distance = float(input("Enter the travel distance in kilometres: "))
litres_per_hundred = float(input("Enter the litres consumed per 100km travelled: "))

litres_needed = (litres_per_hundred / 100) * distance
print(f"The amount of fuel needed is: {litres_needed:.1f}L")