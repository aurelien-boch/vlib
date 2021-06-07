/*
** EPITECH PROJECT, 2021
** vlib
** File description:
** main header
*/

#ifndef VLIB_H
#define VLIB_H

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "internal/utils.h"

/*
** The vector macro create a "templated" vector
** @param type
** The type param refers to the data type that will be stored by the vector
**/

#define vector(type)    \
    struct {            \
        size_t size;    \
        type *data;     \
    }


/*
** The vector_size macro gives you the size of a vector
** @param vector
** The vector param refers to the vector that you want to know the size
** @return
** vector's size
**/

#define vector_size(vector) (vector->size)


/*
** The vector_empty macro tells you if a vector is empty
** @param vector
** The vector param refers to the vector that you wanna heck the emptiness
** @return
** vector emptiness
**/

#define vector_empty(vector) (vector->size == 0)


/*
** The vector_front macro gives you a pointer to the first element of a
** vector
** @param vector
** The vector param refers to the vector that you want to get the first
** element
** @return
** vector's first element
**/

#define vector_front(vector)    \
    ((vector->data == NULL) ?   \
    NULL :                      \
    &(vector->data[0]))


/*
** The vector_back macro gives you a pointer to the last element of a
** vector
** @param vector
** The vector param refers to the vector that you want to get the last
** element
** @return
** vector's last element
**/

#define vector_back(vector)             \
    ((vector->data == NULL) ?           \
    NULL :                              \
    &(vector->data[vector->size - 1]))


/*
** The vector_get macro gives you a pointer to an element at the given pos
** of a vector
** @param vector
** The vector param refers to the vector that you want to get the element
** @param pos
** The pos param refers to the position of the element you are looking for
** @return
** vector's element at the given pos
**/

#define vector_get(vector, pos) \
    (&(vector->data[pos]))


/*
** The vector_set macro allow you to set the value of an element at a
** given position
** @param vector
** The vector param refers to the vector that you want to set the element
** @param elem
** The elem param refers to the new value of the element
** @param pos
** The pos param refers to the position of the element you wanna set
** @return
** vector's element at the given pos
**/

#define vector_set_elem(vector, elem, index) \
    vector->data[index] = elem


/*
** The vector_foreach macro allow you to iterate over a vector
** @param vector
** The vector param refers to the vector you wanna iterate on
** @param elem_name
** The elem_name param refers to the name of the current element
**/

#define vector_foreach(vector, elem_name)                               \
    for (                                                               \
        typeof(vector->data) elem_name = vector_front(vector);          \
        elem_name != NULL && elem_name < &(vector->data[vector->size]); \
        elem_name += 1                                                  \
    )


/*
** The vector_reversed_foreach macro allows you to iterate over a vector
** in reversed order
** @param vector
** The vector param refers to the vector you wanna iterate on
** @param elem_name
**  The elem_name param refers to the name of the current element
**/

#define vector_reversed_foreach(vector, elem_name)              \
    for (                                                       \
        typeof(vector->data) elem_name = vector_back(vector);   \
        elem_name != NULL && elem_name >= &(vector->data[0]);   \
        elem_name -= 1                                          \
    )


/*
** The vector_emplace macro allows you to add an element at the front of
** a vector
** @param vector
** The vector param refers to the vector you wanna push an element into
** @param elem
** The elem param refers to the element to push into the vector
**/

#define vector_emplace(vector, elem)                    \
    do {                                                \
        vector->data = reallocarray(                    \
            vector->data,                               \
            vector->size + 1,                           \
            sizeof(*vector->data)                       \
        );                                              \
        memmove(                                        \
            vector->data + 1,                           \
            vector->data,                               \
            vector->size * sizeof(*vector->data)        \
        );                                              \
        vector->data[0] = elem;                         \
        vector->size += 1;                              \
    } while (0)

/*
** The vector_emplace_back macro allows you to add an element at the back of
** a vector
** @param vector
** The vector param refers to the vector you wanna push an element into
** @param elem
** The elem param refers to the element to push into the vector
**/

//todo variable temporaire
#define vector_emplace_back(vector, elem)               \
    do {                                                \
        vector->data = reallocarray(                    \
            vector->data,                               \
            vector->size + 1,                           \
            sizeof(*vector->data)                       \
        );                                              \
        vector->data[vector->size++] = elem;            \
    } while (0)

/*
** The vector_emplace_elem macro allows you to add an element at a given pos
** of a vector
** @param vector
** The vector param refers to the vector you wanna push an element into
** @param elem
** The elem param refers to the element to push into the vector
** @param pos
** The pos param refers to the position of the new element
**/

#define vector_emplace_elem(vector, elem, pos)  \
    if (pos >= 0 && pos <= vector->size)        \
        _emplace_at_pos(vector, elem, pos)


/*
** The vector_pop macro allows you to pop the first element of a vector
** @param vector
** The vector param refers to the vector you wanna pop an element out
**/

#define vector_pop(vector)                              \
    do {                                                \
        size_t new_size = (vector->size > 0) ?          \
                            vector->size - 1 :          \
                            0;                          \
        memmove(                                        \
            vector->data,                               \
            vector->data + 1,                           \
            new_size * sizeof(*vector->data)            \
        );                                              \
        vector->data = reallocarray(                    \
            vector->data,                               \
            new_size,                                   \
            sizeof(*vector->data)                       \
        );                                              \
        vector->size = new_size;                        \
    } while (0)


/*
** The vector_pop macro allows you to pop the last element of a vector
** @param vector
** The vector param refers to the vector you wanna pop an element out
**/

#define vector_pop_back(vector)                             \
    do {                                                    \
        size_t new_size = (vector->size > 0) ?              \
            vector->size - 1 :                              \
            0;                                              \
        vector->data = reallocarray(                        \
            vector->data,                                   \
            new_size,                                       \
            sizeof(*vector->data)                           \
        );                                                  \
        vector->size = new_size;                            \
    } while (0)


/*
** The vector_pop_elem macro allows you to pop an element of a vector
** @param vector
** The vector param refers to the vector you wanna pop an element out
** @param pos
** The pos param refers to the position of the element you wanna pop
**/

#define vector_pop_elem(vector, pos)  \
    if (pos <= vector->size)    \
        _pop_at_pos(vector, pos)


/*
** The vector_create macro allows you create a vector of a given type
** @param type
** The type param refers to the type you wanna store into the vector
**/

#define vector_create(type) \
    calloc(1, sizeof(vector(type)))


/*
** The vector_clear macro allows you empty a vector
** @param vector
** The vector param refers to the vector you wanna empty
**/

#define vector_clear(vector)        \
    if (vector->data != NULL) {     \
        free(vector->data);         \
        vector->data = NULL;        \
        vector->size = 0;           \
    }


/*
** The vector_destroy macro allows you destroy a vector
** @param vector
** The vector param refers to the vector you wanna destroy
**/

#define vector_destroy(vector) \
    free(vector->data);        \
    free(vector)


/*
** The vector_find macro allows you to find data into a vector
** using a comparison function
** @param vector
** The vector param refers to the vector wanna find an element into
** @param target_variable
** The target_variable param refers to the variable you wanna assign
** the found value
** @param cmp_function
** The cmp_function param refers to the comparison function you wanna use
** @param cmp_function_arg
** The cmp_function_param refers to the second argument that will be passed
** to the cmp_function
**/

#define vector_find(                                    \
    vector,                                             \
    target_variable,                                    \
    cmp_function,                                       \
    cmp_function_arg)                                   \
    do {                                                \
        vector_foreach(vector, e) {                     \
            if (cmp_function(e, cmp_function_arg)) {    \
                target_variable = e;                    \
                break;                                  \
            }                                           \
        }                                               \
    } while (0)

#endif //VLIB_H
