/*
** EPITECH PROJECT, 2021
** vlib
** File description:
** vector_pop macro unit tests
*/

#include <criterion/criterion.h>
#include <vlib.h>

Test(vector_pop_elem, empty)
{
    vector(int) *vector = vector_create(int);

    vector_pop_elem(vector, 0);
    vector_destroy(vector);
}

Test(vector_pop_elem, filled)
{
    vector(int) *vector = vector_create(int);

    for (int i = 0; i < 10; ++i)
        vector_emplace_back(vector, i);
    for (int i = 0; i < 10; ++i) {
        cr_assert_eq(*vector_front(vector), i);
        cr_assert_eq(vector_size(vector), 10 - i);
        vector_pop_elem(vector, 0);
    }
    vector_destroy(vector);
}

Test(vector_pop_elem, middle)
{
    vector(int) *vector = vector_create(int);

    for (int i = 0; i < 10; ++i)
        vector_emplace_back(vector, i);
    cr_assert_eq(vector->data[2], 2);
    vector_pop_elem(vector, 2);
    cr_assert_eq(vector->data[2], 3);
    vector_destroy(vector);
}