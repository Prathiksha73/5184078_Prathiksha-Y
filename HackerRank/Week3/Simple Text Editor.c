#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000000  // max length for the string

typedef struct StackNode {
    char *str;
    struct StackNode* next;
} StackNode;

void push(StackNode** top_ref, char* s) {
    StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
    new_node->str = strdup(s); // duplicate string
    new_node->next = *top_ref;
    *top_ref = new_node;
}

char* pop(StackNode** top_ref) {
    if (*top_ref == NULL) return NULL;
    StackNode* temp = *top_ref;
    char* res = temp->str;
    *top_ref = temp->next;
    free(temp);
    return res;
}

int main() {
    int Q;
    scanf("%d", &Q);
    char* S = (char*)malloc(MAX_LEN * sizeof(char));
    S[0] = '\0'; // initially empty

    StackNode* history = NULL; // stack to keep history

    for (int i = 0; i < Q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            // append
            char appendStr[100005];
            scanf("%s", appendStr);
            push(&history, S);
            strcat(S, appendStr);

        } else if (type == 2) {
            // delete
            int k;
            scanf("%d", &k);
            int len = strlen(S);
            push(&history, S);
            if (k <= len) {
                S[len - k] = '\0';
            }

        } else if (type == 3) {
            // print kth character
            int k;
            scanf("%d", &k);
            if (k - 1 < (int)strlen(S) && k > 0) {
                printf("%c\n", S[k - 1]);
            }

        } else if (type == 4) {
            // undo
            char* prev = pop(&history);
            if (prev != NULL) {
                strcpy(S, prev);
                free(prev);
            }
        }
    }

    free(S);

    // clean remaining stack memory if any
    while (history != NULL) {
        char* prev = pop(&history);
        free(prev);
    }

    return 0;
}

