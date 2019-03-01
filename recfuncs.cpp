#include "recfuncs.h"

int calc_array_size(int i)
{
  if (i > 0)
  {
    return 2 * calc_array_size(i - 1);
  }

  return 1;
}

int convert_to_binary(int n)
{
  if(n == 0)
  {
    return 0;
  }

  return n % 2 + 10 * convert_to_binary(n / 2);
}

int *create_array(int size)
{
  int finalSize = calc_array_size(size);
  int *array = new int[finalSize];

  for (int i = 0; i < finalSize; i++)
  {
    array[i] = -1;
  }

  return array;
}

int calc_factorial(int n)
{
  if (n < 2)
  {
    return 1;
  }

  return n * calc_factorial(n - 1);
}

int test(int *nums, int size, int index, int arrIndex, int sum, int *out_arr, int *out_arr_bin)
{
  if (index > size)
  {
    out_arr[arrIndex] = sum;
    out_arr_bin[arrIndex] = convert_to_binary(out_arr[arrIndex]);
    return ++arrIndex;
  }

  int newIndex = test(nums, size, index + 1, arrIndex, sum+nums[index], out_arr, out_arr_bin);
  test(nums, size, index + 1, newIndex, sum, out_arr, out_arr_bin);
}

void calc_sums(int *nums, int n, int *out_arr, int *out_arr_bin)
{
  test(nums, n - 1, 0, 0, 0, out_arr, out_arr_bin);
}

CalculationResults perform_calculations(int *nums, int n)
{
  CalculationResults temp;

  temp.no_of_nums = n;
  temp.no_of_sums = n + n;

  temp.num_factorials[n] = calc_factorial(nums[n]);

  return temp;
}
