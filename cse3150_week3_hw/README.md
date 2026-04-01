# CSE 3150 Homework 3

## Pointers
I used a lot of pointers to manage the memory and modify data. The names array is an array of pointers that point to C-style arrays. I also passed a pointer in the updateGPA function so the GPA could be updated directly in memory.

## Const 
I used const in the printStudent function to prevent accidentally changing the student's name string. Same thing with the averageGPA function, just ensuring that the GPAs are read-only.

## References
I passed the size variable by reference to the addStudent function to allow it to directly modify the tracking in main. This was to ensure that the count would always increment properly.

## Casting
I used type casting to convert the calculated average GPA into an integer.

## Exceptions
I used exceptions to handle errors. If the user attempts to add a student when size equals capacity, the addStudent function throws an error. Also, if you try to use averageGPA with zero students it will throw an error. There are try/catch blocks in the switch menu.

## Control Flow
A do-while loop keeps the program running until the user chooses the quit option. There is a switch statement to handle menu navigation.
