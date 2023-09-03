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


/*  
    function for thread 1 where it calculate the sum of elements of an array
    it takes pointer to array's first element as (int *)arg in variable arr
    then it sums up all the elements of array.
    then it allocates a integer space x in the heap using new and stores sum to it. 
    if we directly pass the address of sum, then it will not give the correct output because as the thread is finished, the local vaiables will also vanish and hence the value stored in it will not be the same.
    therefore we need to create a integer space in the heap so that value stored there is retained when thread is finsihed.
    using pthread_exit(x) we exit the thread by returning void* x to the main function. 
*/ 
void* thread1_fxn(void *arg){
    int sum = 0;
    int *arr = (int *) arg ;
    for(int i=0; i<10; i++) sum += arr[i];
    void* x = new int(sum);
    pthread_exit(x);
}

/*
    first the thread thread_t1 is declared.
    then a thread is created using pthread_create where the 
        The first parameter is the buffer which will contain the ID of the new thread, if pthread_create is successful
        The second parameter specifies the attributes of the thread which is generally NULL until wew want to change the default settings
        The third parameter is the name the function which the thread will execute.
        The fourth parameter is the input to the function in the third parameter, which is pointer to the first element of the array in our case
    then the process waits for the thread to finish and we pass the void* ans as a parameter to it which will store the return value of the thread
    then we convert void* to int* and print the value stored at that address.
*/
int main(){
    pthread_t thread_t1;
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    pthread_create(&thread_t1, NULL, thread1_fxn, &arr);
    void* ans;
    pthread_join(thread_t1, &ans);
    cout<<"sum of all integers is "<< *((int* )ans);
}