//creating a key matrix
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

int main(void){
	char key[10];
	printf("Enter the string : " );
	gets(key);

	// printf("%d\n",strlen(key) );
	//imitating hash key

	int arr[26]={0};
	char c='a';  // this is for iterating through the characters
	char keymat[5][5];
	int i,j,m=0; // m is traversing through the string
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