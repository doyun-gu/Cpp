/*
MCE - Lecture 7 Example Program 4 - Static Member Functions 

This program is not designed to run on the Nucleo board. It will run on a PC-based C++ compiler.
You may wish to modify this program to run on the Nucleo, using the LCD to output the printf statements.

The code is the same as for lecture 7 Example 3, however with the following additions:

- A static member function has been added to Rectangle which prints the value of the static data member no_rectangles. Examples are provided for the function being called both through the object and through the class.

*/



#include <iostream>

class Rectangle {														//Start of rectangle class

    private:															//This part of the class is private:
        float l, w;														//Data members for length and width


    public:																//This part of the class is public
        static int no_rectangles;										//Static integer to count the number of rectangles created
		Rectangle(float length,float width) : l(length), w(width){no_rectangles++;}		//Constructor 1: Uses two parameters to define a rectangle, increments no_rectangles
        Rectangle(float length) : l(length), w(length) {no_rectangles++;}				//Constructor 2: Uses one parameter to define a square, increments no_rectangles

        float area(void) {												//Member function to calculate shape area

            return l*w;													//Returns length x width

        }

        float getLength(void) const {									//Member function to return length

            return l;													//Returns length
        }

        float getWidth(void) const {									//Member function to return width

            return w;													//Returns width
        }

        void setLength(float length) {									//Member function to update length

            l = length;													//Updates the data member for length with supplied parameter
        }

        void setWidth(float width) {									//Member function to update width

            w = width;													//Updates the data member for width with supplied parameter
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

		static void printNoRectangles(){								//Static member function definition
				//Prints the value of the static data member no_rectangles
            printf("The total number of rectangles is: %u\n", no_rectangles);
        }

};

int Rectangle::no_rectangles = 0;										//Initialises static data member


int main()																//Main function - used to test the class
{

	printf("Hello\n");														//Prints a simple string to show the program is running												

	Rectangle::printNoRectangles();											//Prints the number of rectangles created

	Rectangle rect1(3,4);													//Creates a rectangle object called rect1 with length 3 and width 4
	Rectangle::printNoRectangles();											//Prints the number of rectangles created
	
	Rectangle rect2(5,5);													//Creates a rectangle object called rect2 with length 5 and width 5
	Rectangle rect3(3);														//Creates a rectangle object called rect3 with length and width = 3
	rect1.printNoRectangles();												//Prints the number of rectangles created (called through object)
	
	Rectangle *rect4;														//Creates a pointer to an object of type rectangle
	rect2.printNoRectangles();												//Prints the number of rectangles created. Unchanged as rect4 is a pointer

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

	rect4 = &rect2;															//Assigns the address of rect2 to the pointer rect4


	printf("Is rectangle4 square? %d\n",rect4->isSquare());					//Executes member functions isSquare and area using the.. 
	printf("Area of rectangle 4 is: %f\n",rect4->area());					//..member access operator. The values refer to rect2

	rect2.setLength(5.5);													//Updates the length of rect2 to be 5.5
		
		//Prints updated dimensions of rect2
	printf("Rectangle 2's (length,width) is: (%f,%f) \n",rect2.getLength(),rect2.getWidth());
	printf("Area of rectangle 2 is: %f\n",rect2.area());					//Calculates the updated area of rect2

}
