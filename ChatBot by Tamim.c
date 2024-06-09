#include<stdio.h>
#include<string.h>

int main(){
  char input[100];
  char eitCommand[]="Okay bye";

printf("Hello! I`m a ChatBot. Type'okay bye' to exit.\n");

while(1){
    printf("You: ");
    fgets(input,sizeof(input),stdin);
    input[strcspn(input,"\n")]=0;


    if(strcmp(input,eitCommand)==0){
        printf("Bot: Goodbye! Have a nice day!\n");
        break;
    }else if(strcmp(input,"hello")==0){
        printf("Bot: Hi there!\n");
    }else if(strcmp(input,"how are you?")==0){
        printf("Bot: I`m doing great. How about you?\n");
        }else if(strcmp(input,"what`s your name?")==0){
        printf("Bot: I am just a ChatBot, created by Tamim!!\n");
        }else if(strcmp(input,"CG koto?")==0){
        printf("Bot: Vag ducir vai!!\n");
        }else if(strcmp(input,"tui ducir vai")==0){
        printf("Bot: Bantost!!\n");
        }else if(strcmp(input,"why?")==0){
        printf("Bot: Tok bola lagbe?!!\n");
        }else{
         printf("Bot: I`m sorry, I don`t understand!!\n");
        }
}

 return 0;
}

