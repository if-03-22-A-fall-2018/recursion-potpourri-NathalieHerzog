#include "recfuncs.h"

int calc_array_size(int i)
{
  if(i > 0)
  {
    return 2*calc_array_size(i-1);
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

int* create_array(int size)
{
  return 0;
}

int calc_factorial(int i)
{
  return 1;
}

void calc_sums(int* nums, int i, int* out_arr, int* out_arr_bin)
{

}

CalculationResults perform_calculations(int* nums, int i)
{
  CalculationResults temp;

  return temp;
}
