#include <stdio.h>
#include <stdlib.h>

struct frame {
    int info;
    int seq;
} p;

int ack, disconnect = 0;
int error_frame = 1, error_ack = 1;
char turn = 's';

void sender() {
    if (turn != 's') return;
    
    printf("SENDER: %s packet with seq NO: %d\n", error_ack ? "Sent" : "Retransmitting", p.seq);
    
    error_frame = rand() % 4;
    if (error_frame == 0) 
        printf("Error while sending packet\n");
    
    turn = 'r';
}

void receiver() {
    if (turn != 'r') return;
    
    if (error_frame) {
        printf("RECEIVER: Received packet with seq %d\n", p.seq);
        ack = p.seq;
        
        if (p.seq == 5)
            disconnect = 1;
        else
            p.seq++;
    } else {
        printf("RECEIVER: Duplicate packet\n");
    }
    
    error_ack = rand() % 4;
    if (error_ack == 0)
        printf("Error while sending ACK\n");
    
    turn = 's';
}

int main() {

    while (!disconnect) {
        sender();
        for (int k = 1; k <= 1000000000; k++); 
        receiver();
    }
    return 0;
}
