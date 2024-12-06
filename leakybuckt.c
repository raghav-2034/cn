#include <stdio.h>
int main() {
    int n,i, bucketSize, outputRate;
    int currentSize = 0, time = 0;
    printf("Enter the number of packets: ");
    scanf("%d", &n);
    int arrivalTime[n], packetSize[n];
        printf("Enter the packets in the order of arrival time\n");
    for ( i = 0; i < n; i++) {
        printf("Enter time and size: ");
        scanf("%d %d", &arrivalTime[i], &packetSize[i]);
    }
    printf("Enter bucket size: ");
    scanf("%d", &bucketSize);
    printf("Enter the output rate: ");
    scanf("%d", &outputRate);
    for ( i = 0; i < n; i++) {
        while (time < arrivalTime[i]) {
            printf("At time %d\n", time);
            if (currentSize > 0) {
                int transmitted = (currentSize < outputRate) ? currentSize : outputRate;
                printf("%d bytes transmitted\n", transmitted);
                currentSize -= transmitted;
            } else {
                printf("No packets to transmit\n");
            }
            printf("Packets in the bucket: %d bytes\n", currentSize);
            time++;
        }
        printf("At time %d\n", arrivalTime[i]);
        if (currentSize + packetSize[i] <= bucketSize) {
            printf("%d bytes packet is inserted\n", packetSize[i]);
            currentSize += packetSize[i];
        } else {
            printf("%d bytes packet is discarded (bucket overflow)\n", packetSize[i]);
        }
        printf("%d bytes transmitted\n", (currentSize < outputRate) ? currentSize : outputRate);
        currentSize -= (currentSize < outputRate) ? currentSize : outputRate;
        printf("Packets in the bucket: %d bytes\n", currentSize);
        time = arrivalTime[i] + 1;
    }
    while (currentSize > 0) {
        printf("At time %d\n", time);
        int transmitted = (currentSize < outputRate) ? currentSize : outputRate;
        printf("%d bytes transmitted\n", transmitted);
        currentSize -= transmitted;
        printf("Packets in the bucket: %d bytes\n", currentSize);
        time++;
    }

    return 0;
}



/*
Enter the number of packets: 3
Enter the packets in the order of arrival time
Enter time and size: 1 7
Enter time and size: 2 9
Enter time and size: 5 2
Enter bucket size: 10
Enter the output rate: 3
At time 0
No packets to transmit
Packets in the bucket: 0 bytes
At time 1
7 bytes packet is inserted
3 bytes transmitted
Packets in the bucket: 4 bytes
At time 2
9 bytes packet is discarded (bucket overflow)
3 bytes transmitted
Packets in the bucket: 1 bytes
At time 3
1 bytes transmitted
Packets in the bucket: 0 bytes
At time 4
No packets to transmit
Packets in the bucket: 0 bytes
At time 5
2 bytes packet is inserted
2 bytes transmitted
Packets in the bucket: 0 bytes

*/