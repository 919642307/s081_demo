//
// Created by 91964 on 2023/5/18.
//
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#define length 36
char num[length];

void prime(int prime_read, int prime_write)
{
    char target[length];
    read(prime_read, target, length);
    int val = 0;
    for(int i = 0; i < length; i++) {
        if(target[i] != '0')
        {
            val = i;
            break;
        }
    }

    if(val == 0) {
        exit(0);
    }
    printf("prime %d\n",val);
    for(int i = 2; i < length; i++) {
        if(i >= val && i % val == 0)
        {
            target[i] = '0';
        }

    }
    int temp = fork();
    if(temp > 0 ) {
        write(prime_write, target, length);
        wait(0);
    }
    else{
        prime(prime_read,prime_write);
    }
}
int main(int argc, char *argv[]){
    int fd[2];
    pipe(fd);
    num[0] = '0';
    num[1] = '0';
    for(int i = 2; i < length; i++) {
        num[i] = '1';
    }
    int temp = fork();
    if(temp > 0 )//father
    {
        close(fd[0]);
        write(fd[1], num, length);
        int status;
        wait(&status);
        exit(0);

    }
    if(temp == 0)
    {
        prime(fd[0], fd[1]);
        wait(0);
    }
    exit(0);
}