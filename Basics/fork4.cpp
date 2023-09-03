#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <bits/stdc++.h>

using namespace std;
int main(){
    pid_t p;  // pid_t = PID type  (process id)
    cout<<"Process ID of Parent (P): "<<getpid()<<"\n";  // we are in the parent process since we haven't forked the process

    p = fork(); // create a child process using fork()
    if(p==0){
        cout<<"Process ID of child (P1): "<<getpid()<<"\n";  // we are in the child process and we print the child id
        cout<<"Parent ID of Child P1: "<<getppid()<<"\n";  // printing the childs parent id
        cout<<"ID of P's Child (P1): "<<getpid()<<"\n";  // printing the parent's child id 
    }
    wait(NULL); // waiting for the child process to get terminate
}