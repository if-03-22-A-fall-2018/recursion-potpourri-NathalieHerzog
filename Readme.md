# Recursion training

To freshen up your recursion skills after the holiday break we'll do some finger exercise.
The task of this assignment is to implement a couple of simple functions recursively.

**Be careful, the following methods must be implemented with recursion, 0 points for an iterative solution!**
- The implementation for power used in `calc_array_size` (you mustn't use the math.h function either!)
- The factorial calculation
- The binary representation calculation
- the subset sum calculation

## Calculate the required size of the sums array
The most difficult part of this assignment will be to calculate all possible subset sums.
You'll need to store those in an array while processing.
Yet, you do not know how big the array has to be at compile time.

The solution to this problem is to calculate the size required on the fly based on the input array size and then allocate an array big enough to hold all sums.
The formular for this is luckily very easy: `2^n`

So you only have to implement a recursive function to calculate the number raised to the power of n (because you must not use the function provided in math.h).

## Represent a decimal number in binary
Decimal numbers are boring.
In addition to calculating the subset sums we'll also represent them in their binary format.
To simplify things we won't use actual bits (bit array) but just create an integer which looks like the correct binary representation (even ignoring leading 0s).

For example: the number `9` would become `1001`

## Factorials
We are also going to calculate the factorials for all input numbers (mind: **not** of the resulting sums, you might easily overflow).

Remember, for example 5! = 1 * 2 * 3 * 4 * 5

## Subset sums
Probably the most difficult part is to calculate all possible subset sums of the numbers provided in the input array.

It is easiest to explain by an example:
The set (1,2,3) has the following possible subset sums:
- 0 (nothing summed up)
- 1 (just number `1` summed up)
- 2 (just number `2` summed up)
- 3 (just number `3` summed up)
- 3 (`1`+`2`)
- 4 (`1`+`3`)
- 5 (`2`+`3`)
- 6 (`1`+`2`+`3`)

Surprisingly we expected these `8` results correctly by calculating `2^3` (first task).
Also note that sum values may repeat themselves and that `0` is always part of the result set!
