#include <stdio.h>
#include <string.h>

int areAnagrams(char *s1, char *s2) {
    size_t length = strlen(s1);
    if (length != strlen(s2)) {
        return 0;
    }

    unsigned int count[256] = {0};
    for (size_t i = 0; i < length; i++) {
        count[(unsigned char)s1[i]]++;
    }
    for (size_t i = 0; i < length; i++) {
        count[(unsigned char)s2[i]]--;
    }
    
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }
    
    return 1;
}

int main(void) {
    char s1[100], s2[100];
    
    printf("Enter the first string: ");
    scanf("%s", s1);
    
    printf("Enter the second string: ");
    scanf("%s", s2);
    
    if (areAnagrams(s1, s2)) {
        printf("the strings are anagrams");
    } else {
        printf("the strings are NOT anagrams");
    }
    
    return 0;
}