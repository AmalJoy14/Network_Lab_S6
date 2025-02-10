#include<stdio.h>

void main() {
    int incoming, outgoing, buck_size, n, store = 0;
    
    printf("Enter bucket size, outgoing rate, and number of inputs: ");
    scanf("%d %d %d", &buck_size, &outgoing, &n);

    for(int i = 0 ; i < n ; i++) {
        printf("Enter the incoming packet size: ");
        scanf("%d", &incoming);
        
        printf("Incoming packet size: %d\n", incoming);

        if (incoming <= (buck_size - store)) {
            store += incoming;
            printf("Bucket buffer size: %d out of %d\n", store, buck_size);
        } else {
            printf("Dropped %d packets\n", incoming - (buck_size - store));
            store = buck_size;
            printf("Bucket buffer size: %d out of %d\n", store, buck_size);
        }

        if (store >= outgoing) {
            store -= outgoing;
        } else {
            store = 0;
        }

        printf("After outgoing, there are %d out of %d packets left in the buffer\n", store, buck_size);

    }
}
