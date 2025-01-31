/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:05:05 by mberila           #+#    #+#             */
/*   Updated: 2025/01/31 16:59:29 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	test_is_valid_number(void)
{
    printf("\nTesting is_valid_number:\n");
    printf("\"123\":        %d (expected: 1)\n", is_valid_number("123"));
    printf("\"-123\":       %d (expected: 1)\n", is_valid_number("-123"));
    printf("\"+123\":       %d (expected: 0)\n", is_valid_number("+123"));
    printf("\"12a3\":       %d (expected: 0)\n", is_valid_number("12a3"));
    printf("\"-\":          %d (expected: 0)\n", is_valid_number("-"));
    printf("\"\":           %d (expected: 0)\n", is_valid_number(""));
    printf("NULL:           %d (expected: 0)\n", is_valid_number(NULL));
}

void	test_has_duplicates(void)
{
    int	test1[] = {1, 2, 3, 4, 5};
    int	test2[] = {1, 2, 2, 4, 5};
    int	test3[] = {1, 1};
    int	test4[] = {42};

    printf("\nTesting has_duplicates:\n");
    printf("Test1 {1,2,3,4,5}:     %d (expected: 0)\n", 
        has_duplicates(test1, 5));
    printf("Test2 {1,2,2,4,5}:     %d (expected: 1)\n", 
        has_duplicates(test2, 5));
    printf("Test3 {1,1}:           %d (expected: 1)\n", 
        has_duplicates(test3, 2));
    printf("Test4 {42}:            %d (expected: 0)\n", 
        has_duplicates(test4, 1));
    printf("NULL:                   %d (expected: 0)\n", 
        has_duplicates(NULL, 0));
}

void	test_is_within_int_limits(void)
{
    printf("\nTesting is_within_int_limits:\n");
    printf("\"2147483647\":  %d (expected: 1)\n", 
    is_within_int_limits("2147483647"));
    printf("\"-2147483648\": %d (expected: 1)\n", 
    is_within_int_limits("-2147483648"));
    printf("\"2147483648\":  %d (expected: 0)\n", 
    is_within_int_limits("2147483648"));
    printf("\"-2147483649\": %d (expected: 0)\n", 
    is_within_int_limits("-2147483649"));
    printf("\"0\":           %d (expected: 1)\n", 
    is_within_int_limits("0"));
    printf("\"-0\":          %d (expected: 1)\n", 
    is_within_int_limits("-0"));
    printf("NULL:           %d (expected: 0)\n", 
    is_within_int_limits(NULL));
}

int	main(void)
{
    test_is_valid_number();
    test_is_within_int_limits();
	test_has_duplicates();
    return (0);
}