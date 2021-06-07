/*
** EPITECH PROJECT, 2021
** vlib
** File description:
** vector_pop macro unit tests
*/

#include <criterion/criterion.h>
#include <vlib.h>

Test(vector_pop, empty)
{
    vector(int) *vector = vector_create(int);

    vector_pop_back(vector);
    vector_destroy(vector);
}

Test(vector_pop, filled)
{
    vector(int) *vector = vector_create(int);

    for (int i = 0; i < 10; ++i)
        vector_emplace_back(vector, i);
    for (int i = 0; i < 10; ++i) {
        cr_assert_eq(*vector_front(vector), i);
        cr_assert_eq(vector_size(vector), 10 - i);
        vector_pop(vector);
    }
    vector_destroy(vector);
}