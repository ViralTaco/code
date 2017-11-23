//
//  main.c
//  med.c
//
//  Created by Anthony Capobianco on 05/11/2017.
//  Copyright © 2017 Anthony Capobianco. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

size_t strftime(char *, size_t, const char *, const struct tm *);



typedef struct drugUsed{
    int dose[6];
    char doseUsed[4]
         ,drugUsed[3];
    char * drugName[3];
    
}drug;

int logger(void) {
    //fucking time function
    time_t rawtime;
    struct tm *info;
    char buffer[80];
    
    time( &rawtime );
    
    info = localtime( &rawtime );
    
    strftime(buffer,80,"%x - %I:%M%p", info);
    
    drug med = {
        .dose = {5, 10, 15, 20, 72, 225}
        ,.doseUsed = {'A','B','C','D'}
        ,.drugUsed = {'A','B','C'}
        ,.drugName = {"Concerta", "Effexor", "Rilatin"}
    };
    
    int v = 0;
    char drugChoice
        ,doseChoice = '\0';
    !drugChoice?drugChoice='\0':drugChoice;
    while (drugChoice == '\0') {
        printf("Please select the drug used from the list:\n");
        for (int i = 0; i < 3; i++){
            printf("[%c]%s\n", med.drugUsed[i], med.drugName[i]);
        }
        
        scanf("%c", &drugChoice);
    }
    
    //put input to uppercase
    drugChoice = toupper(drugChoice);
    
    //find the position of the input in the array
    do{
        (drugChoice == med.drugUsed[v]) ? v : v++;
    }while(drugChoice != med.drugUsed[v] && v <= 2);
        

    //if the user used a char not found in the table start again
    if((drugChoice != med.drugUsed[v] && v >= 2) && drugChoice != '\0'){
        printf("%c isn't part of the list\n", drugChoice);
        logger();
    }
    
    //print the possible doses
    int x = 0;
    v == 0 ? x = 4 : x;
    v == 1 ? x = 5 : x;
    
    //ask for dose
    while (doseChoice == '\0' && x < 3) {
        printf("Please select the dose used from the list:\n");
        for (int i = 0; i < 4; i++){
            printf("[%c]%i mg\n", med.doseUsed[i], med.dose[i]);
        }
        
        scanf(" %c", &doseChoice);
    }
    //put input to uppercase
    doseChoice = toupper(doseChoice);
    if (x == 0 ) {
        while(doseChoice != med.doseUsed[x] && x < 3){
            (doseChoice == med.doseUsed[x]) ? x : x++;
        }
    }
    
    
    //if the user used a char not found in the table start again
    if((doseChoice != med.doseUsed[x] && v >= 4) && doseChoice != '\0'){
        printf("%c isn't part of the list\n", doseChoice);
        logger;
    }
    
    //FOR DEBUG
    //printf("%s %i mg\n",med.drugName[v], med.dose[x]);
    
    FILE *fp;
    
    fp = fopen("/Users/Muddy/Desktop/drugLog/log.txt", "a+");
    fprintf(fp,"\n[%s] %s %i mg\n", buffer, med.drugName[v], med.dose[x]);
    //fputs("This is testing for fputs...\n", fp);
    fclose(fp);
    
    return 0;
    
}
