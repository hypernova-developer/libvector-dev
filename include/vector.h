#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>

#define VECTOR_TYPE(T) \
    typedef struct \
    { \
        T *data; \
        size_t size; \
        size_t capacity; \
    } Vector_##T; \
    \
    static inline void vector_init_##T(Vector_##T *v) \
    { \
        v->size = 0; \
        v->capacity = 4; \
        v->data = (T*)malloc(sizeof(T) * v->capacity); \
    } \
    \
    static inline void vector_push_##T(Vector_##T *v, T value) \
    { \
        if (v->size == v->capacity) \
        { \
            v->capacity *= 2; \
            v->data = (T*)realloc(v->data, sizeof(T) * v->capacity); \
        } \
        v->data[v->size++] = value; \
    } \
    \
    static inline void vector_at_##T(Vector_##T *v, size_t index) \
    { \
        return v->data[index]; \
    } \
    \
    static inline void vector_free_##T(Vector_##T *v) \
    { \
        free(v->data); \
        v->data = NULL; \
        v->size = v->capacity = 0; \
    }

#endif
