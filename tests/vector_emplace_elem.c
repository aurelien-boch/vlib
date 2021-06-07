/*
** EPITECH PROJECT, 2021
** vlib
** File description:
** vector_emplace_elem macro unit tests
*/

#include <criterion/criterion.h>
#include <vlib.h>

Test(vector_emplace_elem, empty_int_at_front)
{
    vector(int) *vector = vector_create(int);

    for (int i = 0; i < 10; ++i)
        vector_emplace_elem(vector, i, 0);
    for (int i = 0; i < 10; ++i)
        cr_assert_eq(vector->data[i], 9 - i);
    vector_destroy(vector);
}

Test(vector_emplace_elem, empty_int_at_back)
{
    vector(int) *vector = vector_create(int);

    for (int i = 0; i < 10; ++i)
        vector_emplace_elem(vector, i, vector_size(vector));
    for (int i = 0; i < 10; ++i)
        cr_assert_eq(vector->data[i], i);
    vector_destroy(vector);
}

Test(vector_emplace_elem, empty_int_at_middle)
{
    vector(int) *vector = vector_create(int);

    for (int i = 0; i < 10; ++i)
        vector_emplace_back(vector, i);
    vector_emplace_elem(vector, 15, 3);
    cr_assert_eq(vector->size, 11);
    cr_assert_eq(vector->data[3], 15);
}
