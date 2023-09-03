#include <stdio.h>
#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main(){
    pid_t p;
    p = fork();
    if(p==0){ // when the program is forked, then value of p for child is 0
        sleep(5);   // child program will not execute of 5 seconds and in the mean time parent program terminates. 
                    // Now the child program will have no parent as the exectution of parent program is over.
        cout<<"program is child having id "<<getpid()<<"\n";  // getpid() gives the process id for the executing program
        cout<<"program's parent id is "<<getppid()<<"\n";  // getppid() gives the process id for the parent program
        return 0;
    }
    else{ // when the program is forked, the value of p for the parent program is a non-zero value
        cout<<"program is parent with child having id "<<p<<"\n";
        cout<<"I am parent having id "<<getpid()<<"\n";
    }
}