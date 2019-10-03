#include<bits/stdc++.h>
using namespace std;
struct position
{
	int row;
	int col;
};

int main(void){
	char st[50];   //assuming the maximum size of the plain text to not exceed 50
	cout<<"Enter the Plain text : ";
	cin>>st;
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
	modst[k++]=st[i];        // adds the last character of the string to the modified text
    //if the modified string is not even
    	//add another x as filler at last
    if(strlen(modst)%2!=0)
        modst[k++]='x';
    modst[k]='\0';//terminating the string
    cout<<modst;  //prints the modified string

    char key[26];
    cout<<endl<<"Enter the key : ";
    cin>>key;
    
    //immitatintg hash key feature by creating an array of alphabets
    
    int arr[26]={0};

	char c='a';  // this is for iterating through the characters
	char keymat[5][5];
	int j,m=0; // m is traversing through the string
	for(i=0;i<5;i++){
		for(j=0;j<5;){
			if(m!=strlen(key)){

				while(arr[(int)key[m]-97]!=0){
					m++;
				}
				if(key[m]=='i'||key[m]=='j'){
							arr[(int)'i'-97]=1;
							arr[(int)'j'-97]=1;
						}
					arr[(int)key[m]-97]=1;
				keymat[i][j++]=key[m++];
			}
			else{
					while(arr[(int)c-97]!=0){
						c=(char)((int)c+1);
					}
					if(c=='i'||c=='j'){
							arr[(int)'i'-97]=1;
							arr[(int)'j'-97]=1;
						}
					arr[(int)c-97]=1;
					keymat[i][j++]=c;
					c=(char)((int)c+1);
			}
		}
	}
	cout<<endl;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			cout<<keymat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//Encrpting 
	// firstly hash mapping the array again that are present in the modified text

	int arrMod[26]={0};
	int l2=strlen(modst);
	for(i=0;i<l2;i++)
		{ 
			if(arrMod[(int)modst[i]-97]==0)
				arrMod[(int)modst[i]-97]=1;
		}
	//structure array for storing positions

	struct position p[l2];

	 //will iterate through the position p
	
	//tracking position of every character and storing in p
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++){
			if(arrMod[(int)(keymat[i][j])-97]==1)
			{
				p[(int)(keymat[i][j])-97].row=i;
				p[(int)(keymat[i][j])-97].col=j;
			}
		}
	}

	for(i=0;i<l2;i++){
				cout<<p[(int)(modst[i])-97].row;
				cout<<p[(int)(modst[i])-97].col<<endl;
			}
	char EncMod[l2];

	// now going through the p and replacing the characters using condition 
		//listed in breaking down playfair

	/*********What the motherfucking bastard code is this***********/
	// cout<<p[(int)modst[0]-97].row;
	cout<<p[(int)(modst[0])-97].col<<endl;

	for(i=0;i<l2-1;i+=2){
		if(p[(int)modst[i]-97].row==p[(int)modst[i+1]-97].row){    //if the letter pair is in the same row
			
			EncMod[i]=keymat[p[(int)modst[i]-97].row][((int)p[(int)modst[i]-97].col+1)%5];
			EncMod[i+1]=keymat[p[(int)modst[i+1]-97].row][(p[(int)modst[i+1]-97].col+1)%5];
		}
		else if(p[(int)modst[i]-97].col==p[(int)modst[i+1]-97].col){    //if the letter pair is in the same column
			EncMod[i]=keymat[(p[(int)modst[i]-97].row+1)%5][p[(int)modst[i]-97].col];
			EncMod[i+1]=keymat[(p[(int)modst[i+1]-97].row+1)%5][p[(int)modst[i+1]-97].col];
		}
		else {                         //if the letter p[air is neither in the same row or column
			EncMod[i]=keymat[p[(int)modst[i]-97].row][p[(int)modst[i+1]-97].col];
			EncMod[i+1]=keymat[p[(int)modst[i+1]-97].row][p[(int)modst[i]-97].col];
		}
	}
	EncMod[i]='\0';
	cout<<EncMod<<endl;  
	cout<<strlen(EncMod);

	//going throught the last and final step of decription

	int arrMod2[26]={0};
	int l3=strlen(EncMod);
	for(i=0;i<l3;i++)
		{ 
			if(arrMod2[(int)EncMod[i]-97]==0)
				arrMod2[(int)EncMod[i]-97]=1;
		}
	//structure array for storing positions

	struct position p2[l2];

	 //will iterate through the position p2
	
	//tracking position of every character and storing in p2
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++){
			if(arrMod2[(int)(keymat[i][j])-97]==1)
			{
				p2[(int)(keymat[i][j])-97].row=i;
				p2[(int)(keymat[i][j])-97].col=j;
			}
		}
	}

	char DecMod[l2];

	for(i=0;i<l2-1;i+=2){
		if(p2[(int)EncMod[i]-97].row==p2[(int)EncMod[i+1]-97].row)  //if in the same row
		{    

			DecMod[i]=keymat[p2[(int)EncMod[i]-97].row][((int)p2[(int)EncMod[i]-97].col+4)%5];
			DecMod[i+1]=keymat[p2[(int)EncMod[i+1]-97].row][(p2[(int)EncMod[i+1]-97].col+4)%5];
		}
		else if(p2[(int)EncMod[i]-97].col==p2[(int)EncMod[i+1]-97].col)
		{

			DecMod[i]=keymat[(p2[(int)EncMod[i]-97].row+4)%5][p2[(int)EncMod[i]-97].col];
			DecMod[i+1]=keymat[(p2[(int)EncMod[i+1]-97].row+4)%5][p2[(int)EncMod[i+1]-97].col];
		}
		else //neither in same row nor in same column
		{

			DecMod[i]=keymat[p2[(int)EncMod[i]-97].row][p2[(int)EncMod[i+1]-97].col];

			DecMod[i+1]=keymat[p2[(int)EncMod[i+1]-97].row][p2[(int)EncMod[i]-97].col];
		}
	}
	DecMod[i]='\0';
	cout<<endl<<DecMod<<endl;

    return 0;
}
