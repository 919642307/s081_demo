//
// Created by 91964 on 2023/5/17.
//

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int p[2];
    char *a[2];
    a[0] = "ping";
    a[1] = "pong";
    char text[10];
    pipe(p);
    if(fork() != 0){
        write(p[1],a[0],10);
        wait(0);
        read(p[0],text,10);
        printf("%d: received %s\n",getpid(),text);
    }
    else{
        read(p[0],text,10);
        printf("%d: received %s\n",getpid(),text);
        write(p[1],a[1],10);
        exit(0);
    }
    exit(0);
}