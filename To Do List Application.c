#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TASK 100

typedef struct{
    int id;
    char description[100];
    char due_date[20];

}Task;

Task taskList[MAX_TASKS];
int numTasks=0;

void addTask(){
   Task newTask;
   printf("Enter task description: ");
   scanf("%[^\n]",newTask.description);
   printf("Enter due date(YYYY-MM-DD): ");
   scanf("%s",newTask.due_date);
   newTask.id=numTasks+1;
   taskList[numTasks++]=newTask;
   printf("Task added successfully!\n");
}

void deleteTask(){

   int id;
   printf("Enter task ID to delete: ");
   scanf("%d",&id);
   int found=0;
   for(int i=0;i<numTasks; i++){
    if(taskList[i].id==id){
        found=1;
        for(int j=i; j<numTasks-1;j++){
            taskList[j]=taskList[j+1];
        }
        numTask--;
        printf("Task Deleted Successfully!\n");
        break;
    }

   }
   if(!found){
    printf("Task with ID %d not found!\n",id);
   }
}

void displayTasks(){
    printf("\n-----Tasks-----\n");
    printf("ID   Description   Due Date\n");
    for(int i=0; i<numTasks; i++){
        printf("%-5d%-27s%s\n",taskList[i].id,
    taskList[i].description,taskList[i].due_date);
    }
}

int main(){
   int choice;
   do{
    printf("\n===To-Do List App===\n");
    printf("1.Add Task\n");
   printf("2.Delete Tasks\n");
   printf("3.Display Task\n");
   printf("4.exit\n");
   printf("Enter your choice: ");
   scanf("%d",&choice);

     switch(choice){
   case 1:
    addtask();
    break;
    case 2:
    deletetask();
    break;
    case 3:
    displaytask();
    break;
    case 4:
    printf("Exiting....!\n");
    break;
    default:
        printf("Invalide id!!\n");
        }
    }while (choice !=0);
return 0;
}








