#include <unistd.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <fcntl.h>

using namespace std;

int main(){
    int old_fd, new_fd, assign_fd;
    old_fd = open("test.txt", O_RDWR);
    cout<<"File descriptor is "<<old_fd<<"\n";
    new_fd = dup(old_fd);     // duplicate old_fd (old file descriptor) to new_fd. it will assign the lowest unused file descriptor value
    cout<<"New file descriptor is "<<new_fd<<"\n";
    new_fd = dup2(old_fd, 9);     // ducplicate old_fd to assign_fd the integer value 9 as assigned by us
    cout<<"New file descriptor with self assigned integer value is "<<new_fd;
}