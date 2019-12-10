#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fonctions.h"
#include "login.h"


int verifier (char username[], char password[])
{
FILE* f;
char User[50];
char Passwd[50];
int r;
f=fopen("Users.txt","r");

if(f!=NULL)
{
while (fscanf(f,"%s %s %d",User,Passwd,&r)!=EOF)
   {
     if(strcmp(username,User)==0 && strcmp(password,Passwd)==0)
      {
       fclose(f);
       return (r);
      }
   }
}

fclose(f);
return -1;
}


