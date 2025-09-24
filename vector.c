#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main()
{
    Vector v;
    init(&v);

    push_back(&v, 1);
    push_back(&v, 2);
    push_back(&v, 3);
    push_back(&v, 4);
    push_back(&v, 5);

    // insert(&v, 0, 99);
    // insert(&v, 6, 991);
    insert(&v, 3, 991);
    display(&v);
    printf("Size %d\nCapacity %d\n", size(&v), capacity(&v));

    return 0;
}

void insert(Vector *v, int position, int value)
{
    if (position < 0 || position > v->size)
    {
        return;
    }

    if (position == 0)
    {
        for (int i = v->size; i > 0; i--)
        {
            v->data[i] = v->data[i - 1];
        }
        v->data[0] = value;
        v->size++;
        return;
    }

    if (position == v->size)
    {
        v->data[v->size] = value;
        v->size++;
        return;
    }

    for (int i = v->size; i > position; i--)
    {
        v->data[i] = v->data[i - 1];
    }
    v->data[position] = value;
    v->size++;
}

int at(Vector *v, int position)
{
    if (position >= 0 && position < v->size)
    {
        return v->data[position];
    }
    return -1;
}

int back(Vector *v)
{
    if (v->size > 0)
        return v->data[v->size - 1];
    else
        return -1;
}

int front(Vector *v)
{
    if (v->size > 0)
        return v->data[0];
    else
        return -1;
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

void display(Vector *v)
{
    for (int i = 0; i < v->size; i++)
    {
        printf("%d ", v->data[i]);
    }
    printf("\n");
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