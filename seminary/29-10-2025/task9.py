minutes = int(input("Enter the number of minutes: "))

hours = int(minutes / 60)
minutes -= (hours * 60)

days = int(hours / 24)
hours -= (days * 24)

print(f"Days: {days}, Hours: {hours}, Minutes: {minutes}")