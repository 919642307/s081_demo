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
    a[0] = "test";
    a[1] = "1";
    pipe(p);
    if(fork() != 0){
        write(p[1],a[1],1);
        read(p[0],a[1],1);
        printf("%d: received pong\n",getpid());
    }
    else{
        read(p[0],a[1],1);
        printf("%d: received pong\n",getpid());
        write(p[1],a[1],1);
    }
    exit(0);
}