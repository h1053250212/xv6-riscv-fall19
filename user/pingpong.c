#include "kernel/types.h"
#include "user/user.h"
#include "kernel/stat.h"
 
int main(){
    int parent_fd[2];
    int child_fd[2];
    pipe(parent_fd);
    pipe(child_fd);
    if(fork()==0){
        char p[4];
        close(parent_fd[1]);
        read(parent_fd[0],p,4);
        printf("%d: received %s\n",getpid(),p);
        char c[4]="pong";
        close(child_fd[0]);
        write(child_fd[1],c,4);
        close(child_fd[1]);
        close(parent_fd[0]);
    }
    else{
        char p[4]="ping";
        close(parent_fd[0]);
        close(child_fd[1]);
        write(parent_fd[1],p,4);
        char c[4];
        read(child_fd[0],c,4);
        printf("%d: received %s\n",getpid(),c);
        close(parent_fd[1]);
        close(child_fd[0]);
    }
    exit();
}
