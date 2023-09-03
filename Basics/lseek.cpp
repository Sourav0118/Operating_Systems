#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int f_d;
    char buffer[20];
    
    f_d = open("test.txt",O_RDWR);  //open the file test.txt in read and write mode and store the file discriptor to f_d
    read(f_d, buffer, 10);   // reading 10 bytes from test.txt (f_d is the file discriptor for test.txt) to buffer
    write(1, "without lseek (SEEK_CUR) - ", 27);   // write system call
    write(1, buffer, 10);   // write the text read from test.txt which is stored in buffer on screen
    write(1, "\n", 1);   // write system call
    lseek(f_d, 5, SEEK_CUR);     //skips 5 characters from the current position i.e the position after writing 10 bytes.
    read(f_d, buffer, 10);   // reading 10 bytes from test.txt (f_d is the file discriptor for test.txt) to buffer. The current position is at 16th position, {10: after writing, 5: skipping from current}
    write(1, "after skipping 5 characters from current - ", 43);  // write system call
    write(1, buffer, 10);   // write the text read from test.txt which is stored in buffer on screen 
    
    write(1, "\n", 1);

    f_d = open("test.txt", O_RDWR);
    read(f_d, buffer, 10);
    write(1, "without lseek (SEEK_SET) - ", 27);
    write(1, buffer, 10);
    write(1, "\n", 1);
    lseek(f_d, 5, SEEK_SET);     //skips 5 characters from the starting position
    read(f_d, buffer, 10);
    write(1, "after skipping 5 characters from starting - ", 44);  // the current position is at 6th position, {10: after writing, 5: skipping from current}
    write(1, buffer, 10);
}
