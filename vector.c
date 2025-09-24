#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

/************************************************************
 *  C Vector Implementation
 *  Author: Biswajeet Sahoo
 *  GitHub: https://github.com/bixuuu4u/C-VECTOR-SEP-2025.git
 *  Description: STL-like vector container implemented in C
 ************************************************************/

void erase(Vector *v, int position)
{
    if (position < 0 || position >= v->size)
    {
        return;
    }

    if (position == v->size - 1)
    {
        pop_back(v);
        return;
    }

    for (int i = position; i < v->size - 1; i++)
    {
        v->data[i] = v->data[i + 1];
    }
    v->size--;
}

void destroy(Vector *v)
{
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void clear(Vector *v)
{
    v->size = 0;
}

void insert(Vector *v, int position, int value)
{
    if (v->size == v->capacity)
    {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, sizeof(int) * v->capacity);
    }
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
        push_back(v, value);
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
    if (v->data == NULL || v->capacity == 0)
    {
        return;
    }
    if (v->capacity == v->size)
    {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, sizeof(int) * v->capacity);
    }

    v->data[v->size] = value;
    v->size++;
}

int init(Vector *v)
{
    if (!v)
    {
        fprintf(stderr, "Error: NULL vector pointer\n");
        return -1;
    }
    v->size = 0;
    v->capacity = 1;
    v->data = malloc(sizeof(int) * v->capacity);
    if (!v->data)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return -2;
    }
    return 0;
}