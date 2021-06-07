/*
** EPITECH PROJECT, 2021
** vlib
** File description:
** vector_pop_back macro unit tests
*/

#include <criterion/criterion.h>
#include <vlib.h>

Test(vector_pop_back, empty)
{
    vector(int) *vector = vector_create(int);

    vector_pop_back(vector);
    vector_destroy(vector);
}

Test(vector_pop_back, filled)
{
    vector(int) *vector = vector_create(int);

    for (int i = 0; i < 10; ++i)
        vector_emplace_back(vector, i);
    for (int i = 0; i < 10; ++i) {
        cr_assert_eq(*vector_back(vector), 9 - i);
        cr_assert_eq(vector_size(vector), 10 - i);
        vector_pop_back(vector);
    }
    vector_destroy(vector);
}