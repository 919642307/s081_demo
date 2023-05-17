//
// Created by 91964 on 2023/5/16.
//

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, char *argv[]){
    int num = atoi(argv[1]);

    write(1,argv[1],strlen(argv[1]));
    exit(0);

}
