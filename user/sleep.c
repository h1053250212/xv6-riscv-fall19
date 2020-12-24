#include "kernel/types.h"
#include "user/user.h"
#include "kernel/stat.h"

int main(int argc,char* argv[]){
    if(argc<2){
        printf("must 1 argument for sleep\n");
        exit();
    }

    int num=atoi(argv[1]);
    printf("sleep %d ticks\n",num);
    sleep(num);
    exit();
}