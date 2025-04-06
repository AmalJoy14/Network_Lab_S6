#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
bool disconnect = false;
int ack = -1 ,error_ack = 1 , error_frame = 1;
char turn = 's';

struct frame{
    int info;
    int seq;
} p;

void sender(){
    if(turn != 's') return;
    
    if(error_ack != 0 && ack == p.seq){
        printf("SENDER: Received ACK for packet %d\n", ack);
        p.seq++;
        printf("SENDER : Sent packet with seq NO. %d\n" , p.seq);
    }
    else{
        printf("SENDER : Retransmitting packet %d\n" , p.seq);
    }
    
    error_frame = rand() % 4;
    
    if(error_frame == 0){
        printf("Error sending packet ...\n");
    }
    
    turn = 'r';
}

void receiver(){
    if(turn != 'r') return;
    
    if(error_frame != 0){
        printf("RECIEVER ; recieverd packet %d\n" , p.seq);
        
        ack = p.seq;
        
        if(p.seq == 5){
            disconnect = true;
        }
        
    }
    else{
        printf("Duplicate packet\n");
    }
    error_ack = rand() % 4;
    if(error_ack == 0){
        printf("Error sending ack ...\n");
    }
    
    turn = 's';
}
void main(){
    srand(time(NULL));
    while(!disconnect){
        sender();
        sleep(1);
        receiver();
    }
}
