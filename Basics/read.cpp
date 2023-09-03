#include <unistd.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    char buffer[20]; // define a character array with max size = 20 bytes
    write(0, "input : ", 8);  // write system call
    read(0, buffer, 20);      // reading 20 bytes from keyboard (0 is the file discriptor) to buffer
    write(0, buffer, 20);     // write the input read on screen
}
