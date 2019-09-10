#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	char st[50];   //assuming the maximum size of the plain text to not exceed 50
	printf("Enter the Plain text : ");
	scanf("%s[^ ]",st);
	
	int l=strlen(st); //length of the plain text
	//modifying the plain text and creating digraph

	char modst[50];
	int i,k=0;
	for(i=0;i<(l-1);i++)
	{
		if(st[i]==st[i+1])
		{
			modst[k++]=st[i];
			modst[k++]='x';
		}
		else
		{
			modst[k++]=st[i];
		}
	}
	modst[k]=st[i];        // adds the last character of the string to the modified text
	printf("%s\n",modst);  //prints the modified string
    
    //if the modified string is not even
    
    if(strlen(modst)%2!=0)
        modst[k+1]='x';

    char key[26];
    printf("Enter the key : ");
    scanf("%s[^ ]",key);
    
    //immitatintg hash key feature by creating an array of alphabets
    
    int arr[26]={0};

	char c='a';  // this is for iterating through the characters
	char keymat[5][5];
	int j,m=0; // m is traversing through the string
	for(i=0;i<5;i++){
		for(j=0;j<5;){
			if(m!=strlen(key)){

				while(arr[(int)key[m]-97]!=0)
					m++;
				arr[(int)key[m]-97]=1;
				keymat[i][j++]=key[m++];
			}
			else{
					while(arr[(int)c-97]!=0){
						c=(char)((int)c+1);
					}
					arr[(int)c-97]=1;
					keymat[i][j++]=c;
					c=(char)((int)c+1);
			}
		}
	}
	printf("\n");
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%c",keymat[i][j]);
		}
		printf("\n");
	}

    return 0;
}
