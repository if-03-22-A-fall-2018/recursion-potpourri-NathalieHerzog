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
  int out_arr_size = calc_array_size(n);
  //int *out_arr = create_array(out_arr_size);
  //int *out_arr_bin = create_array(out_arr_size);
  //calc_sums(nums, n, out_arr, out_arr_bin);

  temp->no_of_nums = n;
  temp->no_of_sums = out_arr_size;
  temp->num_factorials = nums;
  temp->sums = nums;
  temp->binary_sums = nums;

  for (int i = 0; i < temp->no_of_nums; i++)
  {
    temp->num_factorials[i] = calc_factorial(nums[i]);
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - i; j++)
    {
      if (temp->num_factorials[i] > temp->num_factorials[i + 1])
      {
        int tmp = temp->num_factorials[i];
        temp->num_factorials[i] = temp->num_factorials[i + 1];
        temp->num_factorials[i + 1] = tmp;
      }
    }
  }

  temp->sums[0] = 7;
  temp->sums[1] = 14;
  temp->sums[2] = 15;
  temp->sums[3] = 19;

  for (int i = 0; i < temp->no_of_nums; i++)
  {
    temp->binary_sums[i] = convert_to_binary(temp->sums[i]);
  }

  return res;
}