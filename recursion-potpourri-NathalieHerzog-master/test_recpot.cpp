#include <stdlib.h>
#include <math.h>
#include "test_recpot.h"
#include "shortcut.h"
#include "recfuncs.h"

bool array_contains(int arr[], int arr_size, int number);

TEST(calc_sum_array_sizes)
{
    for (int i = 0; i < 20; i++){
        ASSERT_EQUALS((int) pow(2,i), calc_array_size(i));
    }
}

TEST(conv_to_binary)
{
    ASSERT_EQUALS(111, convert_to_binary(7));
    ASSERT_EQUALS(1111, convert_to_binary(15));
    ASSERT_EQUALS(1001, convert_to_binary(9));
    ASSERT_EQUALS(100, convert_to_binary(4));
    ASSERT_EQUALS(1010, convert_to_binary(10));
}

TEST(create_dyn_array)
{
    int size = 18;
    int* arr = create_array(size);

    for (int i = 0; i < size; i++){
        ASSERT_EQUALS(-1, arr[i]);
    }
}

TEST(factorial_calculation)
{
    int nums[] = {0, 1, 3, 4, 6, 7, 9};
    int facs[] = {1, 1, 6, 24, 720, 5040, 362880};

    for (uint i = 0; i < sizeof(nums)/sizeof(nums[0]); i++){
        ASSERT_EQUALS(facs[i], calc_factorial(nums[i]));
    }
}

TEST(calc_single_sum)
{
    int nums[] = {3};
    int out_arr_size = calc_array_size(1);
    int* out_arr = create_array(out_arr_size);
    int* out_arr_bin = create_array(out_arr_size);

    calc_sums(nums, 1, out_arr, out_arr_bin);

    ASSERT_EQUALS(3, out_arr[0]);
    ASSERT_EQUALS(11, out_arr_bin[0]);
}

TEST(calc_sum_two_values)
{
    int nums[] = {3, 5};
    int out_arr_size = calc_array_size(2);
    int* out_arr = create_array(out_arr_size);
    int* out_arr_bin = create_array(out_arr_size);

    calc_sums(nums, 2, out_arr, out_arr_bin);

    ASSERT_TRUE(array_contains(out_arr, out_arr_size, 0), "Value of 0 should be present");
    ASSERT_TRUE(array_contains(out_arr, out_arr_size, 3), "Value of 3 should be present");
    ASSERT_TRUE(array_contains(out_arr, out_arr_size, 5), "Value of 5 should be present");
    ASSERT_TRUE(array_contains(out_arr, out_arr_size, 8), "Value of 8 should be present");

    ASSERT_TRUE(array_contains(out_arr_bin, out_arr_size, 0), "Bin value of 0 should be present");
    ASSERT_TRUE(array_contains(out_arr_bin, out_arr_size, 11), "Bin value of 11 should be present");
    ASSERT_TRUE(array_contains(out_arr_bin, out_arr_size, 101), "Bin value of 101 should be present");
    ASSERT_TRUE(array_contains(out_arr_bin, out_arr_size, 1000), "Bin value of 1000 should be present");
}

TEST(calc_sum_three_values)
{
    int nums[] = {3, 5, 2};
    int out_arr_size = calc_array_size(3);
    int* out_arr = create_array(out_arr_size);
    int* out_arr_bin = create_array(out_arr_size);

    calc_sums(nums, 3, out_arr, out_arr_bin);

    ASSERT_TRUE(array_contains(out_arr, out_arr_size, 0), "Value of 0 should be present");
    ASSERT_TRUE(array_contains(out_arr, out_arr_size, 3), "Value of 3 should be present");
    ASSERT_TRUE(array_contains(out_arr, out_arr_size, 5), "Value of 5 should be present");
    ASSERT_TRUE(array_contains(out_arr, out_arr_size, 8), "Value of 8 should be present");
    ASSERT_TRUE(array_contains(out_arr, out_arr_size, 2), "Value of 2 should be present");
    ASSERT_TRUE(array_contains(out_arr, out_arr_size, 7), "Value of 7 should be present");
    ASSERT_TRUE(array_contains(out_arr, out_arr_size, 10), "Value of 10 should be present");

    ASSERT_TRUE(array_contains(out_arr_bin, out_arr_size, 0), "Bin value of 0 should be present");
    ASSERT_TRUE(array_contains(out_arr_bin, out_arr_size, 11), "Bin value of 11 should be present");
    ASSERT_TRUE(array_contains(out_arr_bin, out_arr_size, 101), "Bin value of 101 should be present");
    ASSERT_TRUE(array_contains(out_arr_bin, out_arr_size, 1000), "Bin value of 1000 should be present");
    ASSERT_TRUE(array_contains(out_arr_bin, out_arr_size, 10), "Bin value of 10 should be present");
    ASSERT_TRUE(array_contains(out_arr_bin, out_arr_size, 111), "Bin value of 111 should be present");
    ASSERT_TRUE(array_contains(out_arr_bin, out_arr_size, 1010), "Bin value of 1010 should be present");
}

TEST(putting_it_all_together)
{
    int nums[] = {4, 1, 6, 8};

    struct CalculationResults res = perform_calculations(nums, 4);

    ASSERT_EQUALS(16, res.no_of_sums);
    ASSERT_EQUALS(4, res.no_of_nums);

    ASSERT_TRUE(array_contains(res.num_factorials, res.no_of_nums, 1), "Factorial 1 (1!) expected");
    ASSERT_TRUE(array_contains(res.num_factorials, res.no_of_nums, 24), "Factorial 24 (4!) expected");
    ASSERT_TRUE(array_contains(res.num_factorials, res.no_of_nums, 720), "Factorial 720 (6!) expected");
    ASSERT_TRUE(array_contains(res.num_factorials, res.no_of_nums, 40320), "Factorial 40320 (8!) expected");

    ASSERT_TRUE(array_contains(res.sums, res.no_of_sums, 7), "Value of 7 expected");
    ASSERT_TRUE(array_contains(res.sums, res.no_of_sums, 14), "Value of 14 expected");
    ASSERT_TRUE(array_contains(res.sums, res.no_of_sums, 15), "Value of 15 expected");
    ASSERT_TRUE(array_contains(res.sums, res.no_of_sums, 19), "Value of 19 expected");

    ASSERT_TRUE(array_contains(res.binary_sums, res.no_of_sums, 111), "Bin value of 111 expected");
    ASSERT_TRUE(array_contains(res.binary_sums, res.no_of_sums, 1110), "Bin value of 1110 expected");
    ASSERT_TRUE(array_contains(res.binary_sums, res.no_of_sums, 1111), "Bin value of 1111 expected");
    ASSERT_TRUE(array_contains(res.binary_sums, res.no_of_sums, 10011), "Bin value of 10011 expected");
}

bool array_contains(int arr[], int arr_size, int number){
    for (int i = 0; i< arr_size; i++){
        if (arr[i] == number){
            return true;
        }
    }
    return false;
}
