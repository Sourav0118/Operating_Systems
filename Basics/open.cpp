#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main(){
    int file_discp;
    file_discp = open("test.txt", O_RDONLY);  //open the file test.txt in read only mode and store the file discriptor to file_descp
    cout<<"file discriptor of test.txt is : "<<file_discp<<'\n';  //print file discriptor
    char buffer[50];    // define a character array with max size = 50 bytes
    read(file_discp, buffer, 20);  // reading 20 bytes from test.txt (file_discp is the file discriptor for test.txt) to buffer
    write(1, buffer, 20);   // write the text read from test.txt which is stored in buffer on screen
}
