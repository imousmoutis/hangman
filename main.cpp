#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define FILENAME "default.txt"
 
void dictionary();
void play(int x, char **wordar);
char swap(char a, char b);
void document(char fname[]);
 
main(int argc, char *argv[]){
         
    int option1, option2;
    char c, filename[100];
 
    printf("Welcome.\n");
    printf("0. Close the program.\n");
    printf("1. Let's play hangman\n");
    printf("Your option: ");
    scanf ("%d", &option1);
    scanf ("%c", &c);
    printf("\n");
    
    if (option1==1){
              
        printf("Do you wish to play using a file or by typing in words?\n");
        printf("0. Type in my dictionary.\n");
        printf("1. Import a file.\n");
        printf("Your option: ");
        scanf("%d", &option2);
        scanf("%c", &c);
        printf("\n");
        
        if(option2==0)
            dictionary();
        else if (option2==1){
            if (argc > 1){
                     
                printf("A file has already been imported.\n");
                strcpy(filename, argv[1]);
            }
            else{
                 
                printf("The user hasn't imported a file, so the program is using the default.\n");
                strcpy(filename, FILENAME);
            }
            
            printf("Filename: %s\n", filename);
            document(filename);
        }
    }else if (option1==0){
          
           printf("I hope you had fun :)\n");
    } 
}
 
void dictionary(){
     
    char c, ch, *word, **wordar; 
    int i,j, k, counter, length, x;
    
    i=0;
    wordar=(char **)malloc(sizeof(char*)); 
    
    do{
        word=(char *)malloc(50*sizeof(char)); 
        
        printf("\n");
        printf("Type in a word: ");
        gets(word);
        length=strlen(word);
        
        word=(char*)realloc(word,(length+1)*sizeof(char));
        wordar[i]=(char*)malloc((length+1)*sizeof(char));
        strcpy(wordar[i],word); 
        
        printf("\n");
        printf("Do you want to add another word?\n");
        printf("0. Add another word.\n");
        printf("1. Play.\n");
        printf("Your option: ");
        scanf ("%d",&k);
        scanf ("%c",&c);
        
        if (k==1){
            
            printf("\n");
            printf("The words you entered are:\n");
            for(j=0; j<=i; j++)
                     printf("%s\n",wordar[j]);
            play(i,wordar);
        }else if (k==0){
            
            i++;
            wordar=(char**)realloc(wordar,i);
        }
    }while (k==0);
}
 
 
void document(char fname[]){
     
    int sn, i=0, length, j, c;
    char *word, **wordar;
    FILE *fp;
 
    fp=fopen(fname,"r");
    if (fp == NULL)
        printf("The file you imported cannot be located.\n");
        
    wordar=(char **)malloc(sizeof(char*)); 
    word=(char *)malloc(50*sizeof(char));
    fscanf(fp,"%s", word);
    length=strlen(word);
    word=(char*)realloc(word,(length+1)*sizeof(char));
    wordar[i]=(char*)malloc((length+1)*sizeof(char));
    strcpy(wordar[i],word);
     
    while ((c = fgetc(fp)) != EOF) {
          
        i++;
        wordar=(char**)realloc(wordar,i);
        word=(char *)malloc(50*sizeof(char));
        fscanf(fp, "%s", word);
        length=strlen(word);
        word=(char*)realloc(word,(length+1)*sizeof(char));
        wordar[i]=(char*)malloc((length+1)*sizeof(char));
        strcpy(wordar[i],word);
    }
    printf("\n");
    printf("The imported words are: \n");
    for (j=0; j<i; j++)
    {
        printf("%s\n", wordar[j]);
 
    }
    play(i,wordar);
    fclose(fp);
 
 
}
 
void play(int x, char **wordar)
{
    
    int pl,k,l,i,j=0,length,suxn[25],tempint;
    int arthes,p,*thes,lathicounter,validwordcount,validcount=0;
    char **wordn,AB[25],c,m,tempchar;
 
    printf("\n");
    printf("Let's play XD\n");
    printf("Enter the length of the word: ");
    scanf("%d", &pl);
    printf("\n");
    wordn=(char **)malloc(pl*sizeof(char*));
 
    for (i=0;i<=x;i++){
        length=strlen(wordar[i]);
        if (length==pl)
        {
            wordn[j]=(char*)malloc((pl+1)*sizeof(char));
            strcpy(wordn[j],wordar[i]);
            j++;
            wordn=(char**)realloc(wordn,j);
        }
    }
 
    AB[0]='a';
    suxn[0]=0;
    for (i=1;i<=25;i++){
        AB[i]=AB[i-1]+1;
        suxn[i]=0;
    }
    
    for (i=0; i<26; i++){
        for (k=0;k<j;k++){
             for (l=0;l<=pl;l++){
                 if (wordn[k][l]==AB[i])
                    suxn[i]++;
             }
         }
    }
    for (i=0; i<26; i++){
         for (k=0;k<26;k++){
             if (suxn[i]>suxn[k]){
                tempint=suxn[i];
                suxn[i]=suxn[k];
                suxn[k]=tempint;
                tempchar=AB[i];
                AB[i]=AB[k];
                AB[k]=tempchar;
             }
         }
    }
    lathicounter=0;
    printf ("Enter 'y' for yes and 'n' for no.\n");
    i=0;
 
    do{
         
         printf ("There is a '%c' in the word: ",AB[i]);
         c=getchar();
         m=getchar();
         printf("\n");
         
         if ((m=='y')||(c=='y')){   
                                    
            printf ("In how many positions: ");
            scanf ("%d",&arthes);
            printf("\n");
            printf ("Enter the exact positions.\n");
            thes=(int *)malloc(arthes*sizeof(int));
            
            for (l=0;l<arthes;l++){
                scanf ("%d",&thes[l]);
            }
            for (k=0;k<j;k++){
                if (wordn[k]!=NULL){
                 
                 validwordcount=0;
                 for (l=0;l<arthes;l++){
                    
                    if (wordn[k][thes[l]-1]==AB[i]){
                       
                       validwordcount++;
                    }   
                    else if (wordn[k][thes[l]]!=AB[i]){
                        
                        wordn[k]=NULL;
                    }       
                    if (validwordcount==arthes){                
                                                    
                       validcount++;
                       p=k;   
                    }             
                 }
                }
            }     
         }
         else if ((m=='n')||(c=='n')){
          for (k=0;k<j;k++){
                if (wordn[k]!=NULL){
                                    
                 validwordcount=0;
                 for (l=0;l<pl;l++){
                    if (wordn[k][l]==AB[i]){
                                            
                       wordn[k]=NULL;
                       break;
                    }   
                    else if (wordn[k][l]!=AB[i]){
                        
                        validwordcount++;
                    }       
                    if (validwordcount==pl){                              
                       
                       validcount++;
                       p=k;   
                    }             
                 } 
                }
            } 
         }
         else
             printf ("Wrong data.\n");
             
         if (validcount>1){    
              validcount=0;
              lathicounter++;
         }
         else if (validcount==1){  
            printf ("The word is %s.\n",wordn[p]);
            lathicounter=7;
         }
         else{
             
             lathicounter++;
         }        
         i++;
     }while (lathicounter<6);
     
     if (lathicounter==6)
        printf("GAME OVER\n");
}
