//Authors: Kyle Apish, Josh Reed
//Date: 1/20/2022
//This file is messing about with memory addresses and pointers to see the limits and dangers of careless pointer creation and arithmetic.

#include<iostream>

//A series of tests, mostly consisting of creating variables, outputting them and/or their memory addresses, and making changes with pointers. 
void Lab3Part1_main(){
  //These integers are just being used to test and mess around with integer memory; the individual variables are irrelevant, hence a-e naming.
  int a = 5;
  int b = 10;
  int c = 20;
  int d = 40;
  int e = 80;

  std::cout << &a << std::endl; 
  std::cout << &b << std::endl;
  std::cout << &c << std::endl;
  std::cout << &d << std::endl;
  std::cout << &e << std::endl;

  //Memory adresses for variables a, b, c, d, e
  //0x7fffbf2fbdbc, 0x7fffbf2fbdb8, 0x7fffbf2fbdb4, 0x7fffbf2fbdb0, 0x7fffbf2fbdac

  int* ptr_to_a = &a;
  
  *ptr_to_a = -16;
  
  //Outputs the memory address ptr_to_a contains, which is 0x7fffd856cb3c

  std::cout << a << std::endl;
  std::cout << ptr_to_a << std::endl;

  int* new_address = ptr_to_a - 1;
  std::cout << new_address;

  //It goes down by 4 instead of 1 because the type of data stored at ptr_to_a is an integer, which has a size of 4. Therefore subtracting from that address moves us to the "next integer", moving us by 4.

  int* moving_ptr = &a;

  for (int i = 0; i < 5; i++) {
    *moving_ptr = 777;
    moving_ptr -= 1;
  }

  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  std::cout << d << std::endl;
  std::cout << e << std::endl;

  long* long_pointer = (long*)(&e);
  
  std::cout << *long_pointer << std::endl;
  
  *long_pointer = -1000000000000;
  
  std::cout << *long_pointer << std::endl;

  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  std::cout << d << std::endl;
  std::cout << e << std::endl;  

  //Variables a, b, and c are intact, but d and e have been butchered. This is because we tried to save -1000000000000 as a pointer, which overwrote portions of d and e, changing their value when interpreted as ints.

  long_pointer += 1000000;
  //std::cout << *long_pointer;

  //We're not sure why it crashes when we output but not when we store it; it probably crashes when we print it because assigning it is just changing the value stored at the pointer's memory address, but printing it is telling the computer to *actually access* that absurd memory address.

}

