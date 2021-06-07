/*
** EPITECH PROJECT, 2021
** vlib
** File description:
** vector_emplace_back macro unit tests
*/

#include <criterion/criterion.h>
#include <vlib.h>

Test(vector_emplace_back, empty_int)
{
    vector(int) *vector = vector_create(int);

    for (int i = 0; i < 10; ++i)
        vector_emplace_back(vector, i);
    for (int i = 0; i < 10; ++i)
        cr_assert_eq(vector->data[i], i);
    cr_assert_eq(vector->size, 10);
    vector_destroy(vector);
}
