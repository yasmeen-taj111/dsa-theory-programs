#include <stdio.h>

#define MAX 100
char tree[MAX];

void setRoot(char key) {
    tree[0] = key;
}

void setLeft(char key, int parent) {
    int left = 2 * parent + 1;
    tree[left] = key;
}

void setRight(char key, int parent) {
    int right = 2 * parent + 2;
    tree[right] = key;
}

void printTree() {
    for (int i = 0; i < 15; i++) {
        if (tree[i] != '\0')
            printf("%c ", tree[i]);
        else
            printf("- ");
    }
}

int main() {
    setRoot('A');
    setLeft('B', 0);
    setRight('C', 0);
    setLeft('D', 1);
    setRight('E', 1);
    setLeft('F', 2);

    printTree();
    return 0;
}
