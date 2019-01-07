#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *number;
    char *str;
    int pr;
} Type;


struct Node {
    Type d;
    struct Node *next;
    struct Node *prev;
};

typedef struct {
    struct Node *head;
    struct Node *tail;
    int size;
} List;

List *list_create()
{
    List *tmp = (List*)malloc(sizeof(List));
    tmp->head = NULL;
    tmp->tail = NULL;
    tmp->size = 0;
    return tmp;
}

void list_destroy(List **list)
{
    struct Node *tmp = (*list)->head;
    struct Node *other = NULL;
    while (tmp != NULL) {
        other = tmp->next;
        free(tmp);
        tmp = other;
    }
    free(*list);
    (*list) = NULL;
}

void list_push_front(List *list, Type t)
{
    struct Node *elem = (struct Node*)malloc(sizeof(struct Node));
    if (elem == NULL) {
        exit(2);
    }
    elem->d = t;
    elem->next = list->head;
    elem->prev = NULL;
    struct Node *l = list->head;
    if (l != NULL) {
        l->prev = elem;
    }
    list->head = elem;
    if (list->tail == NULL) {
        list->tail = elem;
    }
    list->size++;
}

void list_push_back(List *l, Type t)
{
    struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->next = NULL;
    tmp->d = t;
    tmp->prev = l->tail;
    if (l->tail != NULL) {
        struct Node *list = l->tail;
        list->next = tmp;
    }
    l->tail = tmp;
    if (l->head == NULL) {
        l->head = tmp;
    }
    l->size++;
}

Type list_pop_front(List *list)
{
    struct Node *prev;
    if (list->head == NULL) {
        exit(5);
    }
    prev = list->head;
    Type t = prev->d;
    struct Node *l = list->head;
    list->head = l->next;
    l = l->next;
    if (list->head != NULL) {
        l->prev = NULL;
    }
    if (prev == list->tail) {
        list->tail = NULL;
    }
    free(prev);
    list->size--;
    return t;

}





void list_print(List *list)
{
    struct Node *tmp = list->head;
    int j;
    while (tmp != NULL) {
        for (j = 0; j < 13; j++) {
           printf("%d ", tmp->d.number[j]);
        }
        printf("\n");
        tmp = tmp->next;
    }
}

bool list_is_empty(List *list)
{
    return (list->head == NULL);
}


typedef struct {
    Type *mas;
    int size;
    int length;
} vector;

void create_vector(vector *v)
{
    v->mas = (Type*)malloc(2 * sizeof(Type));
    v->size = 2;
    v->length = 0;
    int i;
    int j;
    for (i = 0; i < 2; i++) {
        v->mas[i].number = (int*)malloc(13 * sizeof(int));
        for (j = 0; j < 13; j++) {
            v->mas[i].number[j] = 0;
        }
        v->mas[i].str = calloc(65, sizeof(char));
        v->mas[i].str[64] = '\0';
        v->mas[i].pr = 0;
    }
}

void plus_vector(vector *v)
{
    v->size = v->size * 2;
    int a = v->size;
    v->mas = (Type*)realloc(v->mas, a * sizeof(Type));
    int i;
    int j;
    for (i = v->size / 2; i < v->size; i++) {
        v->mas[i].number = (int*)malloc(13 * sizeof(int));
        for (j = 0; j < 13; j++) {
            v->mas[i].number[j] = 0;
        }
        v->mas[i].str = calloc(65, sizeof(char));
        v->mas[i].str[64] = '\0';
        v->mas[i].pr = 0;
    }
}

void delete_vector(vector *v)
{
	int i = 0;
	for (i = 0; i < v->size; i++) {
		free(v->mas[i].number);
		free(v->mas[i].str);
	}
	free(v->mas);
}

void str_print(char *str)
{
    int i = 0;
    while (str[i] != 0 || str[i] != '\0') {
        printf("%c", str[i]);
        i++;
    }
}

void print_vector(vector *v)
{
    int i;
    int j;
    for (i = 0; i < v->length; i++) {
        printf("+");
        for (j = 3 - v->mas[i].pr; j < 3; j++) {
            printf("%d", v->mas[i].number[j]);
        }
        for (j = 3; j < 13; j++) {
            if (j == 3)
                printf("-");
            if (j == 6)
                printf("-");
            printf("%d", v->mas[i].number[j]);
        }
        printf("\t");
        str_print(v->mas[i].str);
        printf("\n");
    }
}

void pods(vector *v, int i)
{
    List* C[10];
    int j;
    int pos;
    List *p;
    for (j = 0; j < 10; j++) {
        C[j] = list_create();
    }
    for (pos = 0; pos < v->length; pos++) {
        list_push_back(C[v->mas[pos].number[i]], v->mas[pos]);
    }
    int b = 0;
    for (j = 0; j < 10; j++) {
        p = C[j];
        while (!list_is_empty(p)) {
            v->mas[b] = list_pop_front(p);
            b++;
        }
    }
    for (j = 0; j < 10; j++) {
        list_destroy(&C[j]);
    }
    return;
}

void sorting(vector *v)
{
    int i;
    for (i = 12; i >= 0; i--) {
        pods(v, i);
    }
}


int main(void)
{
    int c;
    int g;
    int num = 0;
    int i = 0;
    int counter = 0;
    int l = 0;
    vector v;
    create_vector(&v);
    while ((c = getchar()) != EOF) {
        if (i == v.size) {
            plus_vector(&v);
        }
        if (c == '+') {
            while ((g = getchar()) != '-') {
                num++;
                v.mas[i].number[counter] = g - 48;
                counter++;
            }
            v.mas[i].pr = num;
            if (num < 3) {
                if (num == 1) {
                    g = v.mas[i].number[0];
                    v.mas[i].number[0] = 0;
                    v.mas[i].number[2] = g;
                } else {
                    g = v.mas[i].number[1];
                    v.mas[i].number[1] = v.mas[i].number[0];
                    v.mas[i].number[0] = 0;
                    v.mas[i].number[2] = g;
                }
            }
            counter = 3;
            num = 0;
        }
        if (c >= 48 && c <= 57) {
            v.mas[i].number[counter] = c - 48;
            counter++;
        }
        if (c == ' ' || c == '\t') {
            while ((g = getchar()) != '\n') {
                v.mas[i].str[l] = g;
                l++;
            }
            i++;
            v.length++;
            counter = 0;
            l = 0;
        }
    }
    sorting(&v);
    print_vector(&v);
	delete_vector(&v);
    return 0;
}
