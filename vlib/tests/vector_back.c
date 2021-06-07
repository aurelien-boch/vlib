/*
** EPITECH PROJECT, 2021
** vlib
** File description:
** vector_back macro unit tests
*/

#include <criterion/criterion.h>
#include <vlib.h>

Test(vector_back, empty_vector)
{
    vector(int) *vector = vector_create(int);

    cr_assert_null(vector_back(vector));
}

Test(vector_back, one_element_vector)
{
    vector(int) *vector = vector_create(int);

    vector_emplace(vector, 15);
    cr_assert_eq(*vector_back(vector), 15);
}

Test(vector_back, ten_element_vector)
{
    vector(int) *vector = vector_create(int);

    for (int i = 0; i < 10; i++)
        vector_emplace(vector, i);
    cr_assert_eq(*vector_back(vector), 0);
}
