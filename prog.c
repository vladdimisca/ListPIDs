#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = 12415;//you have to choose an existent pid before running the program
    bool type = 1;//you can also take type = 0 and see the short description
                //for each process in the tree

    syscall(331, pid, type);

    return 0;
}