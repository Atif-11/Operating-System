#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Function to calculate average of numbers
void *average(void *arg) {
    int *numbers = (int *)arg;
    printf("Thread %lu handling average of numbers.\n", pthread_self());
    int sum = 0;
    int size = numbers[0];  // Get the number of elements from the first index
    for (int i = 1; i <= size; i++) {
        sum = sum + numbers[i];
    }
    int avg = sum / size;
    printf("The average of your numbers is: %d\n", avg);
    pthread_exit(NULL);
}

// Function to find the maximum value in the array
void *maxValue(void *arg) {
    int *numbers = (int *)arg;
    printf("Thread %lu handling maximum values in numbers.\n", pthread_self());
    int max = numbers[1];
    int size = numbers[0];  // Get the number of elements from the first index
    for (int i = 2; i <= size; i++) {
        if (max < numbers[i]) {
            max = numbers[i];
        }
    }
    printf("The maximum number in your list is %d\n", max);
    pthread_exit(NULL);
}

// Function to find the minimum value in the array
void *minValue(void *arg) {
    int *numbers = (int *)arg;
    printf("Thread %lu handling minimum values in numbers.\n", pthread_self());
    int min = numbers[1];
    int size = numbers[0];  // Get the number of elements from the first index
    for (int i = 2; i <= size; i++) {
        if (min > numbers[i]) {
            min = numbers[i];
        }
    }
    printf("The minimum number in your list is %d\n", min);
    pthread_exit(NULL);
}

int main() {
int n;
printf("Please enter how many numbers you want in your list? ");
scanf("%d", &n);

int numbers[n + 1];
numbers[0] = n;  // Store the number of elements in the first index
for (int i = 1; i <= n; i++) {
printf("Enter number: %d ", i);
scanf("%d", &numbers[i]);
}
pthread_t thread1, thread2, thread3;
    // Create three threads
    if (pthread_create(&thread1, NULL, average, (void *)numbers) != 0 ||
        pthread_create(&thread2, NULL, maxValue, (void *)numbers) != 0 ||
        pthread_create(&thread3, NULL, minValue, (void *)numbers) != 0) {
        fprintf(stderr, "Error creating threads\n");
        return 1;
    }
    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    return 0;
}
