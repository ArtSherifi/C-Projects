#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100

char tasks[MAX_TASKS][MAX_LENGTH];
int taskCount = 0;

void addTask() {
    if (taskCount < MAX_TASKS) {
        printf("Enter a task: ");
        getchar(); // Clear the buffer
        fgets(tasks[taskCount], MAX_LENGTH, stdin);
        tasks[taskCount][strcspn(tasks[taskCount], "\n")] = 0; // Remove newline
        taskCount++;
        printf("Task added!\n");
    } else {
        printf("Task list is full!\n");
    }
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("To-Do List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

void deleteTask() {
    if (taskCount == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    int taskNumber;
    printf("Enter the task number to delete: ");
    scanf("%d", &taskNumber);

    if (taskNumber > 0 && taskNumber <= taskCount) {
        for (int i = taskNumber - 1; i < taskCount - 1; i++) {
            strcpy(tasks[i], tasks[i + 1]);
        }
        taskCount--;
        printf("Task deleted!\n");
    } else {
        printf("Invalid task number!\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Task\n2. View Tasks\n3. Delete Task\n4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
