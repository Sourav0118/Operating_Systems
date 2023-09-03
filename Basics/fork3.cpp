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
    }

    else{ // when the p1 process will end i.e. p1 != 0 then
        wait(NULL); // wait for p1 to end
        p2 = fork(); // create a child process of parent
        if(p2==0) cout<<"child p2 having id "<<getpid()<<" with parent id "<<getppid()<<"\n";
        else{ // when the process p2 will end i.e. p2 != 0
            wait(NULL); // wait for p2 to end
            p3 = fork(); // create a child process of the parent process
            if(p3==0) cout<<"child p3 having id "<<getpid()<<" with parent id "<<getppid()<<"\n";
            else {
                wait(NULL); //wait for p3 to end
                cout<<"childs have finished the process\n";
            }

        }
    }
}