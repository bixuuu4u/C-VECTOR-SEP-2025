#if !defined(VECTOR_H)
#define VECTOR_H
typedef struct Vector
{
    int *data;
    int size;
    int capacity;
} Vector;

int vector_init(Vector *v);
void vector_push_back(Vector *v, int value);
void vector_pop_back(Vector *v);
void vector_display(Vector *v);
int vector_size(Vector *v);
int vector_capacity(Vector *v);
int vector_empty(Vector *v);
int vector_front(Vector *v);
int vector_back(Vector *v);
int vector_at(Vector *v, int position);
void vector_insert(Vector *v, int position, int value);
void vector_erase(Vector *v, int position);
void vector_clear(Vector *v);
void vector_destroy(Vector *v);

#endif // VECTOR_H
