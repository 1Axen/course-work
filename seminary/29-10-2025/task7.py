price_before = float(input("Enter the base price of the good: "))
tax_percentage = float(input("Enter the sales tax as a percentage: "))

tax_fraction = (tax_percentage / 100)
price_after = price_before + (price_before * tax_fraction)
sales_tax = (price_after - price_before)

print(f"The sales tax is: {sales_tax:.2f}")
print(f"The price after sales tax is: {price_after:.2f}")