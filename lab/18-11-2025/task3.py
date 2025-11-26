text = input("Enter some text: ")
character_count = {}

for character in text:
    count = character_count.get(character, 0)
    character_count[character] = count + 1

print(f"The dict contains {len(character_count)} elements:")
print(character_count)