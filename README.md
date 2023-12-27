# Simple Bending Moment Calculator
This code can calculate the Bending moment on a beam of any length with one point force and two supports.

## How to Run this code
This code is writting in c++, which means a cpp compiler must be installed on your computer. if you are not using an IDE you can run from your command line by typing `gcc shear-force-calculator.cpp -o outputfile.exe` then hit the enter button.

### How to use
To use enter the `main` function and edit the shear force class properties

`ShearForceCalculator *forceCalculator = new ShearForceCalculator(lenght, force_magnitude, Force_position, first_support_magnitude, second_support_magnitude, first_support_position, second_support_position);`
