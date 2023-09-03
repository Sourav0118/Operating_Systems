#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;


// function for thread 2 where it creates mythread.txt file using ofstream outFile(file_name) function. 
void *thread2_fxn(void *arg){
    cout<<"this is thread 2 and I am creating mythread.txt\n";
    std::ofstream outFile("mythread.txt");
    cout<<"mythread.txt created\n";
    return NULL;
}

/*  
    function for thread 1 where it first opens mythread.txt file using open system call under read and write permission.
    the file discriptor of mythread.txt is stored in f_d
    then using the write system call, text is written in the mythread.txt file using its file discriptor. 
*/ 
void *thread1_fxn(void *arg){
    cout<<"this is thread 1 and I am writing in mythread.txt\n";
    int f_d = open("mythread.txt", O_RDWR);
    write(f_d, "Hello, I am writing in the file created by you.", 47);
    return NULL;
}

/*
    first the threads thread_t1 and thread_t2 is declared.
    then a thread is created using pthread_create where the 
        The first parameter is the buffer which will contain the ID of the new thread, if pthread_create is successful
        The second parameter specifies the attributes of the thread which is generally NULL until wew want to change the default settings
        The third parameter is the name the function which the thread will execute.
        The fourth parameter is the input to the function in the third parameter, which is NULL in our case
    then the process waits for the thread to finish. For this the function pthread_join is used.
    Similar goes for the thread_t1
*/
int main(){
    pthread_t thread_t1, thread_t2;
    pthread_create(&thread_t2, NULL, thread2_fxn, NULL);
    pthread_join(thread_t2, NULL);
    pthread_create(&thread_t1, NULL, thread1_fxn, NULL);
    pthread_join(thread_t1, NULL);
}