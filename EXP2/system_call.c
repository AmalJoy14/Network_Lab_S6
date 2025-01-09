#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"./sample", NULL};
    execv(args[0], args);
}

// csea2@sjcet-WIV59355-0116:~/AmalJoy$ gcc sample.c -o sample
// csea2@sjcet-WIV59355-0116:~/AmalJoy$ gcc system_call.c
// csea2@sjcet-WIV59355-0116:~/AmalJoy$ ./a.out
// Running sample.c using systemcall.c
