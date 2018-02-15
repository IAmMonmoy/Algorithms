#include <bits/stdc++.h>
using namespace std;
string encrypt(int key, string plainText)
{
    int ara[1000];
    memset(ara,1,sizeof(ara));
    int len = plainText.length();
    string finalText = "";
    for(int i = 0; i < key && key < len; i++)
    {
        for(int j = i; j < len; j+=key)
        {
            ara[j] = 0;
            finalText+=plainText[j];
        }
    }

    return finalText;
}

string decrypt(int key, string Encrypted)
{
    int len = Encrypted.length();
    string decryted = "";

    int finalKey = ceil((double)len/(double)key);

     int ara[1000];
     memset(ara,1,sizeof(ara));
     for(int i = 0; i < finalKey && finalKey < len; i++)
     {
        for(int j = i; j < len; j+=finalKey)
        {
            ara[j] = 0;
            decryted+=Encrypted[j];
        }

     }

    return decryted;
}

int main()
{
    int key;
    string plainText;

    printf("Enter Plaintext\n");
    getline(cin,plainText);

    printf("Enter How Many Column\n");
    cin>>key;

    string encrypted = encrypt(key,plainText);
    printf("Encrypted Message\n");
    cout<<encrypted<<endl;

    printf("Decrypted Message\n");
    cout<<decrypt(key,encrypted);
    return 0;
}
