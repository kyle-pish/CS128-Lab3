//Authors: Kyle Apish, Josh Reed
//Date: 1/20/2022
//This file includes committing more atrocities with pointers, as well as experimentation with references and the heap.

#include <iostream>

//Lab3Part3Helper "1"; this one takes a double and a double pointer, and returns a double pointer on the heap.
double* Lab3Part3Helper(double helper_double_1, double* helper_pointer_1) {

  helper_double_1++;
  *helper_pointer_1 += 1;

  double* heap_pointer_1 = new double;
  *heap_pointer_1 = helper_double_1 * *helper_pointer_1;

  return heap_pointer_1;
}

//Lab3Part3Helper "2"; this one takes a double and a double reference as input, and returns a double pointer on the heap.
double* Lab3Part3Helper(double helper_double_2, double& helper_reference_1) {

  helper_double_2++;
  helper_reference_1 += 1;

  double* heap_pointer_2 = new double;
  *heap_pointer_2 = helper_double_2 * helper_reference_1;

  return heap_pointer_2;
}

//Lab3Part3Helper "3", this one takes a double, a double pointer, and a double reference as input, and returns a double pointer on the heap.
double* Lab3Part3Helper(double plain, double* pointer, double& reference) {

  //Full explanation of what's going on here in Helper 3 Explanation.txt
  //All three variables are being output at every step to show the progression of changes

  *pointer += plain;
  
  std::cout << plain << std::endl;
  std::cout << *pointer << std::endl;
  std::cout << reference << std::endl;

  reference += *pointer;
  
  std::cout << plain << std::endl;
  std::cout << *pointer << std::endl;
  std::cout << reference << std::endl;

  plain += reference;

  std::cout << plain << std::endl;
  std::cout << *pointer << std::endl;
  std::cout << reference << std::endl;

  double* heap_pointer_3 =  new double;
  *heap_pointer_3 = plain * *pointer * reference;

  return heap_pointer_3;
}



//Testing and experimenting more with pointers, references, and the heap, including by calling the three identically named Helper functions.
void Lab3Part3_main() {

  //These are purely for messing about with memory and data storage, but the individuals are meaningless, hence w-z.
  double w = 1;
  double x = 2;
  double y = 3;
  double z = 4; 
  
  //w & x are output first to confirm the result of the helper function is correct
  std::cout << w << std::endl;
  std::cout << x << std::endl;

  double* helper_1_return = Lab3Part3Helper(w, &x);

  std::cout << *helper_1_return;

  std::cout << y << std::endl;
  std::cout << z << std::endl;

  double* helper_2_return = Lab3Part3Helper(y, z);

  std::cout << *helper_2_return << std::endl;

  //This gets a unique name to keep it separate from the others that are only used once or twice.
  double helper_3_input = 2;

  std::cout << helper_3_input << std::endl;

  double* helper_3_return = Lab3Part3Helper(helper_3_input, &helper_3_input, helper_3_input);

  std::cout << *helper_3_return;

  //This deallocates the pointers to the heap we created and saved, and sets the variable values to 0 for safety.
  delete helper_1_return;
  delete helper_2_return;
  delete helper_3_return;

  helper_1_return = 0;
  helper_2_return = 0;
  helper_3_return = 0;
  
}

