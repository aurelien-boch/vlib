/*
** EPITECH PROJECT, 2021
** vlib
** File description:
** private header
*/

#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

#define _emplace_at_pos(vector, elem, pos)                          \
        {                                                           \
            typeof(vector->data) new_data = malloc(                 \
                sizeof(*vector->data) * (vector->size + 1)          \
            );                                                      \
                                                                    \
            if (vector->data != NULL) {                             \
                memmove(                                            \
                    new_data,                                       \
                    vector->data,                                   \
                    pos * sizeof(*vector->data)                     \
                );                                                  \
                memmove(                                            \
                    new_data + pos + 1,                             \
                    vector->data + pos,                             \
                    (vector->size - pos) * sizeof(*vector->data)    \
                );                                                  \
                free(vector->data);                                 \
            }                                                       \
            new_data[pos] = elem;                                   \
            vector->data = new_data;                                \
            vector->size += 1;                                      \
        }

#define _pop_at_pos(vector, pos)                            \
    {                                                       \
        typeof(vector->data) new_data = malloc(             \
            sizeof(*vector->data) * (                       \
                (vector->size == 0) ?                       \
                    0 :                                     \
                    --vector->size                          \
            )                                               \
        );                                                  \
                                                            \
        if (vector->data != NULL) {                         \
            memmove(                                        \
                new_data,                                   \
                vector->data,                               \
                pos * sizeof(*vector->data)                 \
            );                                              \
            memmove(                                        \
                new_data + pos,                             \
                vector->data + pos + 1,                     \
                (vector->size - pos) * sizeof(*vector->data)\
            );                                              \
            free(vector->data);                             \
        }                                                   \
        vector->data = new_data;                            \
    }

#endif //UTILS_H
