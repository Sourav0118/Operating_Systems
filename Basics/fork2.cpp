#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <bits/stdc++.h>

using namespace std;
int main(){
    pid_t p;  // pid_t = PID type  (process id)
    cout<<"before forking the program"<<"\n";
    p = fork();  // we fork the program with program id = p i.e. create a child program p

    // since the program is been executed till this line of code, therefore in both the process the execution will start from the line below.
    
    if(p==0){ // when the program is forked, then value of p for child is 0
        cout<<"child p1 having id "<<getpid()<<" with parent id "<<getppid()<<"\n";  // getpid() gives the process id for the executing program
        pid_t pp = fork(); // we are in the child program, here we will create a child program pp of child

        if(pp == 0){ // the child of child i.e pp will start executing from here and since pid for child program is 0, the if statement satisfies.
            cout<<"child pp1 having id "<<getpid()<<" with parent id "<<getppid()<<"\n";
        }
        wait(NULL);
    }
    wait(NULL);
}