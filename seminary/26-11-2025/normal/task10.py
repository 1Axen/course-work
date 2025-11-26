first_word = input("Enter the first word: ")
second_word = input("Enter the second word: ")

def are_anagrams(first_word: str, second_word: str) -> bool:
    first_characters = {}
    for char in first_word:
        count = first_characters.get(char, 0)
        first_characters[char] = count + 1

    for char in second_word:
        char_count = first_characters.get(char)
        if char_count == None:
            return False
        
        char_count -= 1
        if char_count == 0:
            first_characters.pop(char)
        
    for _ in first_characters:
        return False

    return True
        
if are_anagrams(first_word, second_word):
    print("The two words are anagrams")
else:
    print("The two words aren't anagrams")
