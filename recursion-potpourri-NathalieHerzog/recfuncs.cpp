#include "recfuncs.h"
#include <stdlib.h>

int calc_array_size(int n)
{
  if (n > 0)
  {
    return 2 * calc_array_size(n - 1);
  }

  return 1;
}

int convert_to_binary(int n)
{
  if (n == 0)
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
    return arrIndex + 1;
  }

  int newIndex = test(nums, size, index + 1, arrIndex, sum + nums[index], out_arr, out_arr_bin);
  test(nums, size, index + 1, newIndex, sum, out_arr, out_arr_bin);
}

void calc_sums(int *nums, int n, int *out_arr, int *out_arr_bin)
{
  test(nums, n - 1, 0, 0, 0, out_arr, out_arr_bin);
}

CalculationResults perform_calculations(int *nums, int n)
{
  struct CalculationResults *temp = (struct CalculationResults *)malloc(sizeof(struct CalculationResults));
  struct CalculationResults res;
  res.no_of_nums = n;
  res.no_of_sums = calc_array_size(n);
  res.num_factorials = create_array(n);

  for (int i = 0; i < n; i++)
  {
    res.num_factorials[i] = calc_factorial(nums[i]);
  }

  res.sums = create_array(res.no_of_sums);
  res.binary_sums = create_array(res.no_of_sums);
  calc_sums(nums, n, res.sums, res.binary_sums);
  return res;
}