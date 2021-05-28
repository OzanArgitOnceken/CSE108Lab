#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char enc(char []);
int main()
{
    char user[100];
    printf("Enter a dna Sequence:");
    scanf("%s",user);
    enc(user);
    
    
    
}
char enc(char user[])
{
    int i=0,j=0;
    char encrypt[100];
    char tempch=user[0];
    int cou=0;
        char tempo[10];
    while (user[i]!='\0')
    {
        strcpy(tempo,&user[i]);
        if(tempch==user[i])
        {
            cou++;
        }
        else
        {
            encrypt[j]=tempch;
            j++;
            encrypt[j]=48+cou;
            cou=1;
            j++;
        }
        tempch=user[i];
        i++;
    }
    i=0;
    while (tempo[i]!='\0')//my code did not read last letter so i did that
    {
        i++;
    }
    encrypt[j]=tempo[0];
    j++;
    encrypt[j]=i+48+1;
    j++;
    encrypt[j]='\0';
    printf("\nResult of encoding:%s\n",encrypt);
    

}

