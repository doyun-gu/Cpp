/*
MCE - Lecture 6 Example Program 1

This program is not designed to run on the Nucleo board. It will run on a PC-based C++ compiler.
You may wish to modify this program to run on the Nucleo, using the LCD to output the printf statements.

The code shows anexample of how to construct a class in C++, using the idea of a Rectangle, which is 
described in terms of a length and width. These two parameters are initialised with the object via the constructor.
The arguments for length and width are passed during the creation of the object. 
An overloaded constructor allows for the user to pass a single argument, in which case it is assumed that the 
parameter will be applied to both length and width, and hence defining a square.

Member functions are provided for calculating the area of the rectangle, checking if the rectangle is a square, and 
transposing the shape, by swapping the length and width.

Selector functions getLength and getWidth are provided to allow for polling of the stored length and width.

The main() function contains some code which shows how to interact with the class. It may be modified to create
different instances of the object, and to explore the class in more detail.

*/


#include <iostream>

class Rectangle {														//Start of rectangle class

    private:															//This part of the class is private:
        float l, w;														//Data members for length and width


    public:																//This part of the class is public
        Rectangle(float length,float width) : l(length), w(width){}		//Constructor 1: Uses two parameters to define a rectangle 
        Rectangle(float length) : l(length), w(length) {}				//Constructor 2: Uses one parameter to define a square

        float area(void) {												//Member function to calculate shape area

            return l*w;													//Returns length x width

        }

        float getLength(void) {											//Member function to return length

            return l;													//Returns length
        }

        float getWidth(void) {											//Member function to return width

            return w;													//Returns width
        }

        bool isSquare(void) {											//Member function to check if rectangle describes a square

            if(l==w) {													//Returns 'true' or 'false' depending if length == width
                return true;
            }
            else {
                return false;
            }
        }

        void transpose(void){											//Member function to transpose the rectangle dimensions
            float temp_length;											//Declare a temporary value to store one of the parameters

            temp_length = l;											//Copy the length to the temporary variable
            l=w;														//Set length to be equal to width (overwrites the stored length)
            w = temp_length;											//Sets the width to the temporarily stored value for length
        }

};



int main()																//Main function - used to test the class
{

	printf("Hello\n");														//Prints a simple string to show the program is running												

	Rectangle rect1(3,4);													//Creates a rectangle object called rect1 with length 3 and width 4
	Rectangle rect2(5,5);													//Creates a rectangle object called rect2 with length 5 and width 5
	Rectangle rect3(3);														//Creates a rectangle object called rect3 with length and width = 3
	
	printf("Rectangle 1's (length,width) is: (%f,%f) \n",rect1.getLength(),rect1.getWidth());	//Prints dimensions of rect1
	printf("Rectangle 2's (length,width) is: (%f,%f) \n",rect2.getLength(),rect2.getWidth());	//Prints dimensions of rect2
	printf("Rectangle 3's (length,width) is: (%f,%f) \n",rect3.getLength(),rect3.getWidth());	//Prints dimensions of rect3



	printf("Area of rectangle 1 is: %f\n",rect1.area());					//Prints the area of rect1
	printf("Area of rectangle 2 is: %f\n",rect2.area());					//Prints the area of rect2
	printf("Area of rectangle 3 is: %f\n",rect3.area());					//Prints the area of rect3


	printf("Is rectangle1 square? %d\n",rect1.isSquare());					//Checks if rect1 is square (length = width)
	printf("Is rectangle2 square? %d\n",rect2.isSquare());					//Checks if rect2 is square (length = width)
	printf("Is rectangle3 square? %d\n",rect3.isSquare());					//Checks if rect3 is square (length = width)


	printf("\nTransposing Rectangle 1...\n");								
	rect1.transpose();														//Transposes rect1

	printf("Rectangle 1's (length,width) is: (%f,%f) \n",rect1.getLength()),rect1.getWidth();	//Prints new dimensions of rect1

}
