#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdbool.h>

int N;

// Signal handler
void sigint_handler(int sig) {
    printf("\nSIGINT received. Termination prevented. Use kill -9 to force quit.\n");
}

// Prime check helper
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0) return false;
    return true;
}

// Thread A: Sum of first N primes
void* threadA_func(void* arg) {
    clock_t start = clock();
    int count = 0, num = 2, sum = 0;

    while (count < N) {
        if (isPrime(num)) {
            sum += num;
            count++;
        }
        num++;
    }

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n[Thread A] Sum of first %d primes = %d\n", N, sum);
    printf("[Thread A] Time taken: %.2f seconds\n", time_taken);

    pthread_exit(NULL);
}

// Thread B: Print every 2 seconds
void* threadB_func(void* arg) {
    time_t start = time(NULL);
    while (time(NULL) - start < 100) {
        printf("[Thread 1] Thread 1 running...\n");
        sleep(2);
    }
    pthread_exit(NULL);
}

// Thread C: Print every 3 seconds
void* threadC_func(void* arg) {
    time_t start = time(NULL);
    while (time(NULL) - start < 100) {
        printf("[Thread 2] Thread 2 running...\n");
        sleep(3);
    }
    pthread_exit(NULL);
}

int main() {
    signal(SIGINT, sigint_handler);

    pthread_t threadA, threadB, threadC;

    printf("Enter N (number of prime numbers to sum): ");
    scanf("%d", &N);

    printf("Starting threads...\n");

    pthread_create(&threadA, NULL, threadA_func, NULL);
    pthread_create(&threadB, NULL, threadB_func, NULL);
    pthread_create(&threadC, NULL, threadC_func, NULL);

    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    printf("All threads finished execution.\n");
    return 0;
}

