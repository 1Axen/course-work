exchange_rates = {
    "USD": 0.59,
    "EUR": 0.51,
    "GBP": 0.45,
}

bgn = float(input("Enter the amount of BGN to convert: "))
currency = input(f"Choose the currency to convert to (USD, EUR, GBP): ")

if not currency in exchange_rates:
    print(f"Invalid currency: \"{currency}\"")
else:
    exchange_rate = exchange_rates[currency]
    print(f"Exchange rate: {exchange_rate:.2f}")
    print(f"{bgn:.2f} BGN = {bgn * exchange_rate:.2f} {currency}")
