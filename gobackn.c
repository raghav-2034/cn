#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void transmission(int *i, int N, int tf, int *tt) {
    while (*i <= tf) {
        int z = 0;
        for (int k = *i; k < *i + N && k <= tf; k++) {
            printf("Sending Frame %d...\n", k);
            (*tt)++;
        }
        for (int k = *i; k < *i + N && k <= tf; k++) {
            int ack;
            printf("Did you receive Frame %d? (1 for Yes, 0 for No): ", k);
            scanf("%d", &ack);

            if (ack == 1) {
                printf("Acknowledgment for Frame %d received...\n", k);
                z++;  // Move the window forward if acknowledged
            } else {
                printf("Timeout!! Frame Number: %d Not Received\n", k);
                printf("Retransmitting Window...\n");
                break;  // Retransmit the whole window if any frame failed
            }
        }
        printf("\n");
        *i = *i + z;  // Increment i based on successful frames acknowledged
    }
}
int main() {
    int tf, N, tt = 0;
    printf("Enter the Total number of frames: ");
    scanf("%d", &tf);
    printf("Enter the Window Size: ");
    scanf("%d", &N);
    int i = 1;
    transmission(&i, N, tf, &tt);
    printf("Total number of frames which were sent and resent are: %d\n", tt);
    return 0;
}