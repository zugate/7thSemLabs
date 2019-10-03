#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<cctype>
#define plainTextFile "plaintext.txt"
#define cipherTextFile "cipher.txt"
using namespace std;
void generateRandomKey(char key[26]){
 //generating random permutation Key from the set {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z}
    srand(time(NULL));
    for(int i=0;i<26;i++){
        int random_index;
        while(key[random_index=rand()%26]);//loop to ignore duplicate random index generation
        key[random_index]='a'+i;
    }
    //displaying key
    cout<<"Your key is: ";
    for(int i=0;i<26;i++)
        cout<<key[i]<<" ";
}

void printFrequencyTable(int frequencyUpper[26],int frequencyLower[26],int length,char key[26]){
    cout<<"\nchar\tcipher\tFreq\t%(frequency/length_of_text)\n";
    for(int i=0;i<26;i++)
            cout<<char('a'+i)<<"\t"<<key[i]<<"\t"<<frequencyLower[i]<<"\t"<<float(frequencyLower[i])/length*100<<endl;
    for(int i=0;i<26;i++)
            cout<<char('A'+i)<<"\t"<< char(toupper(key[i]))<<"\t"<<frequencyUpper[i]<<"\t"<<float(frequencyUpper[i])/length*100<<endl;
}
void decrypt(string cipher,char key[26]){
    ifstream inFile;
    inFile.open(cipherTextFile);
    getline(inFile,cipher);
    inFile.close();
    cout<<"\n\nDecrypted text:\n";
    for(int i=0;cipher[i]!='\0';i++){
        if(isspace(cipher[i])){
            cout<<' ';
        }
        for(int j=0;j<26;j++){
            if(isupper(cipher[i])&& tolower(cipher[i])==key[j]){
                    cout<<char('A'+j);
                    break;
            }else if(cipher[i]==key[j]){
                    cout<<char('a'+j);
                    break;
            }
        }
    }
    cout<<"\n";
}
int readPlainTextFile(string &text){
    ifstream inFile; //to read the plain-text from the plaintext.txt file
    inFile.open(plainTextFile);
    getline(inFile,text);
    inFile.close();
    if(text==""){
        cout<<"\n\nEmpty File!\nPlease enter some text to the plain-text file\n";
        ofstream outFile;
        outFile.open(plainTextFile);
        getline(cin,text);
        outFile<<text;
        outFile.close();
    }
    return text.size();
}
void encrypt(string text,char key[26],int frequencyUpper[26],int frequencyLower[26]){
    ofstream outFile; //to write the converted cipher text to cipher.txt file
    outFile.open(cipherTextFile);
    for(int i=0;text[i]!='\0';i++){
        if(isspace(text[i])){
            outFile<<' ';
        }else if(isupper(text[i])){
            outFile<<char(toupper(key[text[i]-'A']));
            frequencyUpper[text[i]-'A']++;
        }else{
        outFile<<key[text[i]-'a'];
        frequencyLower[text[i]-'a']++;
        }
    }
    outFile.close();
}
int main(){
    string text,cipher;
    int length=0;
    char key[26]={'\0'};
    int frequencyUpperCase[26]={0};
    int frequencyLowerCase[26]={0};
    generateRandomKey(key); //generates a key table
    length=readPlainTextFile(text); //reads plain text from a file and returns the length of the text
    encrypt(text,key,frequencyUpperCase,frequencyLowerCase); //encrypts the text into cipher text and stores it in file
    printFrequencyTable(frequencyUpperCase,frequencyLowerCase,length,key); //prints the table with character ,frequency in plain text and relative frequency with total length of the text
    decrypt(cipher,key);//decryption
    return 0;
}