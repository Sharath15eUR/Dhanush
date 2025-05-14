#include <stdio.h>
#include <string.h>

#define MAX_TASKS 3
#define MAX_DAYS 7
#define MAX_TASK_LENGTH 100

struct Day {
    char dayName[10];
    char tasks[MAX_TASKS][MAX_TASK_LENGTH];
    int taskCount;
};

void inputTasks(struct Day week[]) {
    char day[10];
    int i, j, found;
    
    printf("Enter day name to input tasks (e.g., Monday): ");
    scanf("%s", day);

    found = 0;
    for (i = 0; i < MAX_DAYS; i++) {
        if (strcmp(week[i].dayName, day) == 0) {
            found = 1;
            printf("Enter number of tasks (max 3): ");
            scanf("%d", &week[i].taskCount);
            if (week[i].taskCount > MAX_TASKS) week[i].taskCount = MAX_TASKS;

            for (j = 0; j < week[i].taskCount; j++) {
                printf("Enter task %d: ", j + 1);
                scanf(" %[^\n]", week[i].tasks[j]);
            }
            break;
        }
    }
    if (!found)
        printf("Invalid day name!\n");
}

void displayTasks(struct Day week[]) {
    printf("\nWeekly Tasks:\n");
    for (int i = 0; i < MAX_DAYS; i++) {
        printf("%s:\n", week[i].dayName);
        for (int j = 0; j < week[i].taskCount; j++) {
            printf("  - %s\n", week[i].tasks[j]);
        }
        if (week[i].taskCount == 0)
            printf("  No tasks.\n");
    }
}

int main() {
    struct Day week[MAX_DAYS] = {
        {"Monday", {}, 0},
        {"Tuesday", {}, 0},
        {"Wednesday", {}, 0},
        {"Thursday", {}, 0},
        {"Friday", {}, 0},
        {"Saturday", {}, 0},
        {"Sunday", {}, 0}
    };

    int choice;
    do {
        printf("\n1. Input Tasks\n2. Display Tasks\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: inputTasks(week); break;
            case 2: displayTasks(week); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}

