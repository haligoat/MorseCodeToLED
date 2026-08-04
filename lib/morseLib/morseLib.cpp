#include "morseLib.h"

#include <ctype.h>

int getLength(char a[]) {
    int length = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        length++;
    }
    return length;
}

int findNextEmptySlot(char arr[]) {
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == '?') {
            return i;
        }
    }
    return -1;
}
void charToMorse(char chara, char emptyArr[]) {
    for (int i = 0; i < 6; i++) {
        emptyArr[i] = '\0';
    }

    switch (chara) {
        case 'a':
            emptyArr[0] = '.';
            emptyArr[1] = '-';
            emptyArr[2] = '!';
            break;

        case 'b':
            emptyArr[0] = '-';
            emptyArr[1] = '.';
            emptyArr[2] = '.';
            emptyArr[3] = '.';
            emptyArr[4] = '!';
            break;

        case 'c':
            emptyArr[0] = '-';
            emptyArr[1] = '.';
            emptyArr[2] = '-';
            emptyArr[3] = '.';
            emptyArr[4] = '!';
            break;

        case 'd':
            emptyArr[0] = '-';
            emptyArr[1] = '.';
            emptyArr[2] = '.';
            emptyArr[3] = '!';
            break;

        case 'e':
            emptyArr[0] = '.';
            emptyArr[1] = '!';
            break;

        case 'f':
            emptyArr[0] = '.';
            emptyArr[1] = '.';
            emptyArr[2] = '-';
            emptyArr[3] = '.';
            emptyArr[4] = '!';
            break;

        case 'g':
            emptyArr[0] = '-';
            emptyArr[1] = '-';
            emptyArr[2] = '.';
            emptyArr[3] = '!';
            break;

        case 'h':
            emptyArr[0] = '.';
            emptyArr[1] = '.';
            emptyArr[2] = '.';
            emptyArr[3] = '.';
            emptyArr[4] = '!';
            break;

        case 'i':
            emptyArr[0] = '.';
            emptyArr[1] = '.';
            emptyArr[2] = '!';
            break;

        case 'j':
            emptyArr[0] = '.';
            emptyArr[1] = '-';
            emptyArr[2] = '-';
            emptyArr[3] = '-';
            emptyArr[4] = '!';
            break;

        case 'k':
            emptyArr[0] = '-';
            emptyArr[1] = '.';
            emptyArr[2] = '-';
            emptyArr[3] = '!';
            break;

        case 'l':
            emptyArr[0] = '.';
            emptyArr[1] = '-';
            emptyArr[2] = '.';
            emptyArr[3] = '.';
            emptyArr[4] = '!';
            break;

        case 'm':
            emptyArr[0] = '-';
            emptyArr[1] = '-';
            emptyArr[2] = '!';
            break;

        case 'n':
            emptyArr[0] = '-';
            emptyArr[1] = '.';
            emptyArr[2] = '!';
            break;

        case 'o':
            emptyArr[0] = '-';
            emptyArr[1] = '-';
            emptyArr[2] = '-';
            emptyArr[3] = '!';
            break;

        case 'p':
            emptyArr[0] = '.';
            emptyArr[1] = '-';
            emptyArr[2] = '-';
            emptyArr[3] = '.';
            emptyArr[4] = '!';
            break;

        case 'q':
            emptyArr[0] = '-';
            emptyArr[1] = '-';
            emptyArr[2] = '.';
            emptyArr[3] = '-';
            emptyArr[4] = '!';
            break;

        case 'r':
            emptyArr[0] = '.';
            emptyArr[1] = '-';
            emptyArr[2] = '.';
            emptyArr[3] = '!';
            break;

        case 's':
            emptyArr[0] = '.';
            emptyArr[1] = '.';
            emptyArr[2] = '.';
            emptyArr[3] = '!';
            break;

        case 't':
            emptyArr[0] = '-';
            emptyArr[1] = '!';
            break;

        case 'u':
            emptyArr[0] = '.';
            emptyArr[1] = '.';
            emptyArr[2] = '-';
            emptyArr[3] = '!';
            break;

        case 'v':
            emptyArr[0] = '.';
            emptyArr[1] = '.';
            emptyArr[2] = '.';
            emptyArr[3] = '-';
            emptyArr[4] = '!';
            break;

        case 'w':
            emptyArr[0] = '.';
            emptyArr[1] = '-';
            emptyArr[2] = '-';
            emptyArr[3] = '!';
            break;

        case 'x':
            emptyArr[0] = '.';
            emptyArr[1] = '-';
            emptyArr[2] = '-';
            emptyArr[3] = '.';
            emptyArr[4] = '!';
            break;

        case 'y':
            emptyArr[0] = '-';
            emptyArr[1] = '.';
            emptyArr[2] = '-';
            emptyArr[3] = '-';
            emptyArr[4] = '!';
            break;

        case 'z':
            emptyArr[0] = '-';
            emptyArr[1] = '-';
            emptyArr[2] = '.';
            emptyArr[3] = '.';
            emptyArr[4] = '!';
            break;

        case ' ':
            emptyArr[0] = ' ';
            emptyArr[1] = '!';
            break;

    }
}
void initArray(char a [], int len) {
    for (int i = 0; i<len; i++) {
        a[i] = '?';
    }
    a[len-1] = '\0';
}


void convertToMorse(char a[SIZE_INPUT], char newArr[]) {
    int length = getLength(a);
    char m[SIZE_OUTPUT];
    m[SIZE_OUTPUT-1] = '\0';
    initArray(m, SIZE_OUTPUT);
    for (int i = 0; i<length; i++) {
        int index = findNextEmptySlot(m);
        char bui [6];
        bui [5] = '\0';

        charToMorse(a[i], bui);
        int totalLen = getLength(bui);
        for (int i = 0; i<totalLen; i++){
            m[index + i] = tolower(bui[i]);
        }

    }

    int len = getLength(m);

    for (int i = 0; i<len+1; i++) {
        if (m[i] != '?') {
            if (m[i] == '!') {
                newArr[i] = ' ';
            }else{
                newArr[i] = m[i];
            }
        }else {
            newArr[i] = '\0';
            i=len;
        }

    }



}














