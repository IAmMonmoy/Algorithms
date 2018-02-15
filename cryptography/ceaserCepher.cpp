#include <bits/stdc++.h>
using namespace std;

string encrypt(int key, string plainText)
{
    int len = plainText.length();

    for(int i = 0; i < len; i++)
    {
        if(plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            plainText[i] += key;
            if(plainText[i] > 'z')
            {
                plainText[i] -= 'z';
                plainText[i] += 'a'-1;
            }
        }
        else if(plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            plainText[i] += key;
            if(plainText[i] > 'Z')
            {
                plainText[i] -= 'Z';
                plainText[i] += 'A'-1;
            }
        }
    }

    return plainText;
}

string decrypt(int key, string plainText)
{
    int len = plainText.length();

    for(int i = 0; i < len; i++)
    {
        if(plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            plainText[i] -= key;
            if(plainText[i] < 'a')
            {
                plainText[i] = 'a'-plainText[i];
                plainText[i] = 'z'-plainText[i]+1;
            }
        }
        else if(plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            plainText[i] -= key;
            if(plainText[i] < 'A')
            {
                plainText[i] = 'A'-plainText[i];
                plainText[i] = 'Z'-plainText[i]+1;
            }
        }
    }

    return plainText;
}

int main()
{
    int key;
    string plainText;

    printf("Enter Plaintext\n");
    getline(cin,plainText);

    printf("Enter Key Value\n");
    cin>>key;

    string encrypted = encrypt(key,plainText);
    printf("Encrypted Message\n");
    cout<<encrypted<<endl;

    printf("Decrypted Message\n");
    cout<<decrypt(key,encrypted);
    return 0;
}
