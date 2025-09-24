#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main()
{
    Vector v;
    init(&v);

    push_back(&v, 10);
    push_back(&v, 11);
    push_back(&v, 12);

    for (int i = 0; i < v.size; i++)
    {
        printf("%d ", v.data[i]);
    }
    printf("\n");
    pop_back(&v);
    for (int i = 0; i < v.size; i++)
    {
        printf("%d ", v.data[i]);
    }

    return 0;
}

int empty(Vector *v)
{
    return v->size == 0;
}

int capacity(Vector *v)
{
    return v->capacity;
}

int size(Vector *v)
{
    return v->size;
}

void pop_back(Vector *v)
{
    if (v->size == 0)
    {
        return;
    }
    v->size--;
}

void push_back(Vector *v, int value)
{
    if (v->capacity == v->size)
    {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, sizeof(int) * v->capacity);
    }

    v->data[v->size] = value;
    v->size++;
}

void init(Vector *v)
{
    v->size = 0;
    v->capacity = 1;
    v->data = (int *)malloc(sizeof(int) * v->capacity);
}