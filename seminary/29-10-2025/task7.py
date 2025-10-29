price_before = float(input("Enter the base price of the good: "))
tax_percentage = float(input("Enter the sales tax as a percentage: "))

tax_fraction = (tax_percentage / 100)
sales_tax = (price_before * tax_fraction)
price_after = price_before + sales_tax

print(f"The sales tax is: {sales_tax:.2f}")
print(f"The price after sales tax is: {price_after:.2f}")