/*
EEEN20011 - Lecture 19 Example Program 1 - Buffers

This program is not designed to run on the Nucleo board. It will run on a PC-based C++ compiler.
You may wish to modify this program to run on the Nucleo, using the LCD to output the printf statements.

The code implements a simple 8-byte FIFO buffer as a C++ class. Member functions are provided for inserting values (put) and removing values (get). Additional member functions are able to check if the buffer is full (isFull), if it is empty (isEmpty), to return the number of items stored in the buffer (getCount) and also to display the capacity of the buffer (getSize).

The main() function contains some code which shows how to interact with the class. It may be modified to create
different instances of the object, and to explore the class in more detail. 

The capacity of the buffer is printed to the terminal, and four values are added. The capacity is again printed before a further four values are added. The capacity is printed once again, showing that the buffer is now full. The contents of the buffer are then printed in order, showing the numbers 1-8. The buffer is now empty.

The code is then repeated. However, this time a further three values are added to the buffer (9, 10 and 11). This exceeds the capacity of the buffer, and consequently overwrites some of the buffer values. When the values are emptied from the buffer it is possible to see that the numbers 1, 2 and 3 have been overwritten by 9, 10 and 11.

A second buffer is created, which shows the effect where data is added and removed without filling the buffer.


*/


#include<iostream>

class Buffer {
public:
    Buffer() {
        int buf[8] = {}; 
        in = 0; 
        out = 0;
        count = 0;
        size = 8;
    }
    
    void put (int i) {
        buf[in] = i;
        if (count<8) {++count;}

        if(in == 7) {in=0;}
        else {++in;}
    }
    
    int get() {
        int x;
        x = buf[out];
        buf[out]=0;
        --count;
        if(out == 7) {out=0;}
        else {++out;}
        return (x);
    }
    
    bool isFull() const {return (count >= size);}
    bool isEmpty() const {return (count == 0);}
    int getCount() const {return count;}
    int getSize() const {return size;}

private:
    int buf[8];
    int size, count, in, out;
};

int main()
{

    Buffer buffer;

    printf("Buffer full? : %u : %u|%u \n", buffer.isFull(), buffer.getCount(), buffer.getSize());
    buffer.put(1);
    buffer.put(2);
    buffer.put(3);
    buffer.put(4);
    printf("Buffer full? : %u : %u|%u \n", buffer.isFull(), buffer.getCount(), buffer.getSize());
    buffer.put(5);
    buffer.put(6);
    buffer.put(7);
    buffer.put(8);
    printf("Buffer full? : %u : %u|%u \n", buffer.isFull(), buffer.getCount(), buffer.getSize());

    while (!buffer.isEmpty())
    {
        printf("Buffer output: %u\n", buffer.get());
    }

    printf("Buffer full? : %u : %u|%u \n", buffer.isFull(), buffer.getCount(), buffer.getSize());
    buffer.put(1);
    buffer.put(2);
    buffer.put(3);
    buffer.put(4);
    printf("Buffer full? : %u : %u|%u \n", buffer.isFull(), buffer.getCount(), buffer.getSize());
    buffer.put(5);
    buffer.put(6);
    buffer.put(7);
    buffer.put(8);
    buffer.put(9);
    buffer.put(10);
    buffer.put(11);
    printf("Buffer full? : %u : %u|%u \n", buffer.isFull(), buffer.getCount(), buffer.getSize());

    while (!buffer.isEmpty())
    {
        printf("Buffer output: %u\n", buffer.get());
    }

    Buffer buffer2;

    printf("Buffer full? : %u : %u|%u \n", buffer2.isFull(), buffer2.getCount(), buffer2.getSize());
    buffer2.put(1);
    buffer2.put(2);
    buffer2.put(3);
    buffer2.put(4);
    buffer2.put(5);
    buffer2.put(6);
    printf("Buffer full? : %u : %u|%u \n", buffer2.isFull(), buffer2.getCount(), buffer2.getSize());
    while (!buffer2.isEmpty())
    {
        printf("Buffer output: %u\n", buffer2.get());
    }

    printf("Buffer full? : %u : %u|%u \n", buffer2.isFull(), buffer2.getCount(), buffer2.getSize());
    buffer2.put(10);
    buffer2.put(20);
    buffer2.put(30);
    printf("Buffer full? : %u : %u|%u \n", buffer2.isFull(), buffer2.getCount(), buffer2.getSize());
    while (!buffer2.isEmpty())
    {
        printf("Buffer output: %u\n", buffer2.get());
    }
}
