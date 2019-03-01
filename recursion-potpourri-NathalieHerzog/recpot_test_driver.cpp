#include "test_recpot.h"

int main(int argc, char *argv[])
{
    ADD_TEST(calc_sum_array_sizes);
    ADD_TEST(conv_to_binary);
    ADD_TEST(create_dyn_array);
    ADD_TEST(factorial_calculation);
    ADD_TEST(calc_single_sum);
    ADD_TEST(calc_sum_two_values);
    ADD_TEST(calc_sum_three_values);
    ADD_TEST(putting_it_all_together);

    run_tests();
    return 0;
}