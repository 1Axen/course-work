#include <stdio.h>
#include <stdlib.h>

#define DEBUG_PRINT true

int length = 0;
int* array = NULL;

void print_contents() {
    if (DEBUG_PRINT == false) {
        return;
    }

    printf("array contents: ");
    for (int index = 0; index < length; index++) {
        printf("%d ", array[index]);
    }
    printf("\n");
}

void add(int x) {
    array = (int*)realloc(array, (length + 1) * sizeof(int));
    
    int index;
    for (index = length; index > 0; index--) {
        if (array[index - 1] < x) {
            break;
        } 
        array[index] = array[index - 1];
    }

    array[index] = x;
    length += 1;
}

bool delete(int x) {
    bool removed = false;
    for (int index = 0; index < length; index++) {
        if (array[index] > x) {
            removed = true;
            array[index - 1] = array[index];
        }
    }

    if (removed == false) {
        printf("The array does not contain %d.\n");
        return false;
    }

    length -= 1;
    array = realloc(array, length * sizeof(int));

    return true;
}

bool smallest(int x) {
    if (length < x) {
        printf("The array has less than %d elements.\n", x);
        return false;
    }

    printf("%d\n", array[x - 1]);
    return true;
}

int main() {
    int command, x;
    while (scanf("%d %d", &command, &x) == 2)
    {
        switch (command)
        {
        case 1:
            add(x);
            print_contents();
            break;
        case 2:
            delete(x);
            print_contents();
            break;
        case 3:
            smallest(x);
            break;
        default:
            printf("Invalid command: %d", command);
            break;
        }
    }
    
    return 0;
}