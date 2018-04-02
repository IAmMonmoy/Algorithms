#include<bits/stdc++.h>
using namespace std;

string encrypt(string plain_text,int width)
{
    char C[500];
    int i,j=0;
    int col=-1;
    int length = plain_text.length();

    while(j<length)
    {
        for(i=++col; i<length; i=i+width)
        {
            C[j++]= plain_text[i];
        }
    }
    C[length] = '\0';
    return C;
}
string decrypt(string cipher_text,int width)
{
    char P[500];
    int i,j=0;
    int col=-1;
    int length = cipher_text.length();

    while(j<length)
    {
        for(i=++col; i<length; i=i+width)
        {
            P[i]= cipher_text[j++];
        }
    }
    P[length] = '\0';
    return P;
}
int main()
{
    string plain_text, cipher_text,decrypted_text,cipher_text1,decrypted_text1;
    int width;
    cout<<"Enter Plain Text: ";
    getline(cin,plain_text);  //******************* For Space Including as Input
    cout<<"Enter Width: ";
    cin>>width;

    cipher_text = encrypt(plain_text,width);
    cipher_text1 = encrypt(cipher_text,width);
    cout<<"\nEncrypted Cipher Text: " + cipher_text1 ;
    decrypted_text = decrypt(cipher_text1,width);
    decrypted_text1 = decrypt(decrypted_text,width);
    cout<<"\nDecrypted Plain Text : " + decrypted_text1 ;

    cout<<endl;


    return 0;
}
