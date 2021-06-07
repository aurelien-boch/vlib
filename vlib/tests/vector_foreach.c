/*
** EPITECH PROJECT, 2021
** vlib
** File description:
** vector_foreach macro unit tests
*/

#include <criterion/criterion.h>
#include <vlib.h>

Test(vector_foreach, empty_vector)
{
    vector(int) *vector = vector_create(int);
    int res = 0;

    vector_foreach(vector, e)
        ++res;
    cr_assert_eq(res, 0);
}

Test(vector_foreach, one_element_vector)
{
    vector(int) *vector = vector_create(int);

    vector_emplace(vector, 15);
    vector_foreach(vector, e)
        cr_assert_eq(*e, 15);
}

Test(vector_foreach, ten_element_vector)
{
    vector(int) *vector = vector_create(int);
    int j = 0;

    for (int i = 0; i < 10; i++)
        vector_emplace(vector, i);
    vector_foreach(vector, e)
        cr_assert_eq(*e, vector->data[j++]);
}
