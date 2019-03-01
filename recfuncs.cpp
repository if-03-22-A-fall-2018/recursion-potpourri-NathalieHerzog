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
  int binary = 0;
  int temp;
  int i = 1;

  while (n != 0)
  {
    temp = n % 2;
    n /= 2;
    binary += temp * i;
    i *= 10;
  }

  return binary;
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
  int facto = 1;

  for (int i = 0; i < n - 1; i++)
  {
    facto *= n - i;
  }

  return facto;
}

void test(int *nums, int size, int index, int sum, int *out_arr)
{
  if (index > size)
  {
    out_arr[index] = sum;
    return;
  }

  test(nums, size, index + 1, sum + nums[index], out_arr);
}

void calc_sums(int *nums, int n, int *out_arr, int *out_arr_bin)
{
  test(nums, n - 1, 0, 0, out_arr);
}

CalculationResults perform_calculations(int *nums, int n)
{
  CalculationResults temp;

  return temp;
}
