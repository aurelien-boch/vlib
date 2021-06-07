/*
** EPITECH PROJECT, 2021
** vlib
** File description:
** vector_empty macro unit tests
*/

#include <criterion/criterion.h>
#include <vlib.h>

Test(vector_empty, empty_vector)
{
    vector(int) *vector = vector_create(int);

    vector_clear(vector);
    cr_assert_eq(vector_empty(vector), 1);
    vector_destroy(vector);
}

Test(vector_empty, filled_vector)
{
    vector(int) *vector = vector_create(int);

    for (int i = 0; i < 100; ++i)
        vector_emplace_back(vector, i);
    cr_assert_eq(vector_size(vector), 100);
    cr_assert_eq(vector_empty(vector), 0);
    vector_clear(vector);
    cr_assert_eq(vector_size(vector), 0);
    vector_destroy(vector);
}
