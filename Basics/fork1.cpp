#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <bits/stdc++.h>

using namespace std;
int main(){
    pid_t p1, p2, p3;  // pid_t = PID type  (process id)
    cout<<"before forking the program"<<"\n";
    p1 = fork();  // we fork the program with program id = p1 i.e. create a child program p1

    // since the program is been executed till this line of code, therefore in both the process the execution will start from the line below.
    
    if(p1==0){ // when the program is forked, then value of p1 for child is 0
        cout<<"child p1 having id "<<getpid()<<" with parent id "<<getppid()<<"\n";  // getpid() gives the process id for the executing program
        return 0; // this will end the child 1 process here only; so the process p1 terminates;
    }

    p2 = fork();  // we fork the program with program id = p2 i.e. create a child program p2
    if(p2==0){ // when the program is forked, then value of p2 for child is 0
        cout<<"child p2 having id "<<getpid()<<" with parent id "<<getppid()<<"\n";  // getpid() gives the process id for the executing program
        return 0; // this will end the child 2 process here only; so the process p2 terminates;
    }

    p3 = fork();  // we fork the program with program id = p2 i.e. create a child program p2
    if(p3==0){ // when the program is forked, then value of p3 for child is 0
        cout<<"child p3 having id "<<getpid()<<" with parent id "<<getppid()<<"\n";  // getpid() gives the process id for the executing program
        return 0; // this will end the child 3 process here only; so the process p3 terminates;
    }
}