#if !defined(VECTOR_H)
#define VECTOR_H
typedef struct Vector
{
    int *data;
    int size;
    int capacity;
} Vector;

void init(Vector *v);
void push_back(Vector *v, int value);
void pop_back(Vector *v);
int size(Vector *v);
int capacity(Vector *v);
int empty(Vector *v);
int front(Vector *v);
int back(Vector *v);

#endif // VECTOR_H
