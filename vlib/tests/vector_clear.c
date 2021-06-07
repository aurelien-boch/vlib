/*
** EPITECH PROJECT, 2021
** vlib
** File description:
** vector_clear macro unit tests
*/

#include <criterion/criterion.h>
#include <vlib.h>

Test(vector_clear, empty_vector)
{
    vector(int) *vector = vector_create(int);

    vector_clear(vector);
    vector_destroy(vector);
}

Test(vector_clear, filled_vector)
{
    vector(int) *vector = vector_create(int);

    for (int i = 0; i < 100; ++i)
        vector_emplace_back(vector, i);
    cr_assert_eq(vector_size(vector), 100);
    vector_clear(vector);
    cr_assert_eq(vector_size(vector), 0);
    vector_destroy(vector);
}
