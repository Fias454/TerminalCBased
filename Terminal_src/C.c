#include <ncurses.h>
#include <stdlib.h>
FILE *fptr;
void FileManG(){
    noecho();
    while(true){
        int userChoice = getch();
        if(userChoice ==99){
            printw("File creation mode entered\nEnter a file name\n");
            echo();
            char FileName[500];
            getstr(FileName);
            noecho();
            if(FileName !=NULL){
                fptr = fopen(FileName, "w");
                if(fptr != NULL){
                    printw("File created: %s\n", FileName);
                }else{
                    printw("Unable to create file\n");
                }
            }else{
                printw("Unvalid name");
            }
            fclose(fptr);
        }else if(userChoice ==114){
            printw("Read Mode entered\n Enter File name:\n");
            echo();
            char FileName[500];
            getstr(FileName);
            noecho();
            if(FileName !=NULL){
                fptr = fopen(FileName, "r");
                char FileStr[50000];
                while(fgets(FileStr, 50000, fptr)!=NULL){
                    printw("%s", FileStr);
                }
            }else{
                printw("Unable to get file\n");
            }
            fclose(fptr);
        }else if(userChoice ==105){
            printw("Inset mode entered\nEnter file name:\n");
            echo();
            char FileName[500];
            getstr(FileName);
            noecho();
            if(FileName !=NULL){
                fptr = fopen(FileName, "a");
                if(fptr !=NULL){
                    printw("File opened successfully\nInsert data\n");
                    echo();
                    char InsertData[50000];
                    getstr(InsertData);
                    noecho();
                    if(InsertData != NULL){
                        fprintf(fptr, InsertData);
                    }else{
                        printw("No data\n");
                    }
                    fclose(fptr);
                }else{
                    printw("Unable to open file\n");
                }
            }else{
                printw("Unable to get file\n");
            }
            noecho();
        }else if(userChoice ==113){
            printw("Exited file mode\n");
            break;
        }
    }
}
void CalMode(){
    noecho();
    while(true){
        printw("Enter operation\n");
        int Operation = getch();
        echo();
        printw("Enter first number\n");
        char FirstNum[1000];
        getstr(FirstNum);
        int numOne = atoi(FirstNum);
        printw("Enter second number\n");
        char SecondNum[1000];
        getstr(SecondNum);
        noecho();
        int numtwo = atoi(SecondNum);
        if(Operation ==43){
            printw("%d\n",numOne + numtwo);
        }else if(Operation ==45){
            printw("%d\n", numOne - numtwo);
        }else if(Operation ==42){
            printw("%d\n", numOne * numtwo);
        }else if(Operation ==47){
            printw("%d\n", numOne / numtwo);
        }else if(Operation ==113){
            break;
            endwin();
        }

    }
}
int main(){
    initscr();
    scrollok(stdscr, TRUE);
    noecho();
    while(true){
        int UserSel = getch();
        if(UserSel ==102){
            printw("Welcome to file creation\n");
            FileManG();
        }else if(UserSel ==110){
            printw("Calculator mode entered\n");
            CalMode();
        }else if(UserSel ==113){
            break;
        }
    }
    endwin();
}
