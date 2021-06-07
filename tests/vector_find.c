/*
** EPITECH PROJECT, 2021
** vlib
** File description:
** vector_find macro unit tests
*/

#include <criterion/criterion.h>
#include <stdbool.h>
#include <vlib.h>

static bool cmp_fun(int *e, int cmp)
{
    return (*e == cmp);
}

Test(vector_find, empty_vector)
{
    vector(int) *vector = vector_create(int);
    int *res = (int *)-1;

    vector_find(vector, res, cmp_fun, 15);
    cr_assert_eq(res, (int *)-1);
    vector_destroy(vector);
}

Test(vector_find, filled_vector)
{
    vector(int) *vector = vector_create(int);
    int *res;

    for (int i = 0; i < 100; ++i)
        vector_emplace_back(vector, i);
    vector_find(vector, res, cmp_fun, 15);
    cr_assert_eq(*res, 15);
    vector_destroy(vector);
}

Test(vector_find, non_existing_elem)
{
    vector(int) *vector = vector_create(int);
    int *res = (int *)-1;

    for (int i = 0; i < 100; ++i)
        vector_emplace_back(vector, i);
    vector_find(vector, res, cmp_fun, 96546);
    cr_assert_eq(res, (int *)-1);
    vector_destroy(vector);
}
