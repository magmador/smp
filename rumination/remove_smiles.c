// "qwe:-:-)))))((((" -> "qwe:-(((("
// "123:-)123:-(" -> "123123"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void remove_smiles(char *str) {
    bool smile_found = false;
    size_t smile_index = 0;
    char smile_symbol = 0;

    for (size_t i = 0; i < strlen(str); i++) {
        if (   !smile_found
            && str[i] == ':' && str[i + 1] == '-'
            && (str[i + 2] == ')' || str[i + 2] == '(')) {
            i += 2;
            smile_symbol = str[i];
            smile_found = true;
            continue;
        }

        if (smile_found && str[i] == smile_symbol) {
            continue;
        }

        if (smile_found) {
            smile_found = false;
        }

        str[smile_index++] = str[i];
    }

    str[smile_index] = '\0';
}

int main() {
    char str[] = "123:-)123:-(";
    remove_smiles(str);
    printf("%s\n", str);

    char str2[] = "qwe:-:-)))))((((";
    remove_smiles(str2);
    printf("%s\n", str2);

    return 0;
}
