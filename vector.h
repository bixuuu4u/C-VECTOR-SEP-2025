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


#endif // VECTOR_H
