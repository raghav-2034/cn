#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct {
    int seq_num;
    char data[100];
} Frame;
void swap(Frame* a, Frame* b) {
    Frame temp = *a;
    *a = *b;
    *b = temp;
}
void shuffleFrames(Frame frames[], int frame_count) {
    int i, j;
    srand(time(0));
    for (i = frame_count - 1; i > 0; i--) {
        j = rand() % (i + 1);
        swap(&frames[i], &frames[j]);
    }
}
void sortFrames(Frame frames[], int frame_count) {
    int i, j;
    for (i = 0; i < frame_count - 1; i++) {
        for (j = 0; j < frame_count - i - 1; j++) {
            if (frames[j].seq_num > frames[j + 1].seq_num) {
                swap(&frames[j], &frames[j + 1]);
            }
        }
    }
    }
int main() {
    char message[1000];
    int frame_size, i;
    int message_length, frame_count;
    printf("Enter the statement: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    printf("Enter the frame size: ");
    scanf("%d", &frame_size);
    message_length = strlen(message);
    frame_count = (message_length + frame_size - 1) / frame_size;
    Frame frames[frame_count];
    for (i = 0; i < frame_count; i++) {
        frames[i].seq_num = i + 1;
        strncpy(frames[i].data, message + i * frame_size, frame_size);
        frames[i].data[frame_size] = '\0';
    }                    
    printf("\nAfter assigning the sequence number:\n");
    for (i = 0; i < frame_count; i++) {
        printf("Frame %d: %s\n", frames[i].seq_num, frames[i].data);
    }
    shuffleFrames(frames, frame_count);
    printf("\nAfter shuffling:\n");
    for (i = 0; i < frame_count; i++) {
        printf("Frame %d: %s\n", frames[i].seq_num, frames[i].data);
    }
    sortFrames(frames, frame_count);
    printf("\nOriginal sorting data:\n");
    for (i = 0; i < frame_count; i++) {
        printf("Frame %d: %s\n", frames[i].seq_num, frames[i].data);
    }
    printf("\nShuffled data:\n");
    for (i = 0; i < frame_count; i++) {
        printf("%s", frames[i].data);
    }
    printf("\n");

    return 0;
}