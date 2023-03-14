//Authors: Kyle Apish, Josh Reed
//Date: 1/20/2022
//This file contains a pass-by-pointer version of a basic arithmetic calculator

/** Starter code for Lab 3, Part 2.

@author: Brian Law
*/

#include <iostream>


// Adds two integers together. This function works purely
// by pointers, rather than using the stack to return a value,
// and the sum is saved into a memory location given by pointer.
//
// When we use parameters like this, I will call this
// "passing-by-pointer," because we are passing the desired
// value into the function using a pointer.

//Takes three int pointers, takes the values stored at the first two, adds them, and places the sum at the third pointer address.
void Lab3Part2PointerAdd(int* int1_p, int* int2_p, int* sum_p) {
  *sum_p = *int1_p + *int2_p;
}

//Takes three int pointers, takes the values stored at the first two, subtracts the second from the first, and places the difference at the third pointer address.
void Lab3Part2PointerSubtract (int* int1_p, int* int2_p, int* difference_p) {
  *difference_p = *int1_p - *int2_p; 
}

//Takes three int pointers, takes the values stored at the first two, multiplies them, and places the product at the third pointer address.
void Lab3Part2PointerMultiply (int* int1_p, int* int2_p, int* product_p) {
  *product_p = *int1_p * *int2_p;
}

//Takes three int pointers, takes the values stored at the first two, divides the first by the second, and places the quotient at the third pointer address.
void Lab3Part2PointerDivide (int* int1_p, int* int2_p, int* quotient_p) {
  *quotient_p = *int1_p / *int2_p;
}

//Notably, instead of using the pow() function, this uses a for loop with the value of the exponent as the condition. Takes three int pointers, takes the values stored at the first two, takes the first to the power of the second, and places the result at the third pointer address.
void Lab3Part2PointerPower (int* int1_p, int* int2_p, int* result_p) {
  int temp_result = 1;
  for (int i = 0; i < *int2_p; i++) {
    temp_result *= *int1_p;
  }

  *result_p = temp_result;
}

//A pass-by-pointer based calculator that uses user console input. No input or output.
void Lab3Part2_main() {
  // All variable declarations at or near top, for clarity and
  // organization.  I am initializing them just for safety.
  // The values have no purpose, since they'll be overwritten.
  int first = 0, second = 0, result = 0;
  char operation = ' ';
  
  // Input/output work.
  std::cout << "Please enter the first number: " << std::endl;
  std::cin >> first;
  std::cout << "Please enter the second number: " << std::endl;
  std::cin >> second;
  std::cout << "Please enter the operation: " << std::endl;
  std::cin >> operation;

  // Determine the given operation and call the appropriate
  // helper function to perform it.
  if (operation == '+') {
    Lab3Part2PointerAdd(&first, &second, &result);
  }
  else if (operation == '-') {
    Lab3Part2PointerSubtract(&first, &second, &result);
  }
  else if (operation == '*') {
    Lab3Part2PointerMultiply(&first, &second, &result);
  }
  else if (operation == '/') {
    Lab3Part2PointerDivide(&first, &second, &result);
  }
  else if (operation == '^') {
    Lab3Part2PointerPower(&first, &second, &result);
  }

  // Output the result.
  std::cout << "The result is " << result << "." << std::endl;
}
