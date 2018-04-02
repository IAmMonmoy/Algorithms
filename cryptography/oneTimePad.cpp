#include <bits/stdc++.h>
using namespace std;
map<char,int>Big;
map<char,int>small;


string encrypt(string plainText)
{
    ifstream file,file1;
    file.open("input.txt");
    file1.open("input1.txt");
    //fstream output ("compress.txt" , ios :: in | ios :: out | ios :: trunc);
    string result = "";
    for(int i = 0; i < plainText.length(); i++)
    {
        char word;

        if(isupper(plainText[i]))
        {
            file.get(word);
            int temp = (Big[plainText[i]] + Big[word])%26;
            char c = temp+64;
            result += c;
        }

        else if(islower(plainText[i]))
        {
            file1.get(word);
            int temp = (small[plainText[i]] + small[word])%26;
            char c = temp+96;
            result += c;
        }
        else{
            result+=plainText[i];
        }

    }

    char word;
    ofstream tmp;
    tmp.open("temp.txt");
    while(file.get(word))
    {
        tmp.put(word);
    }
    file.close();
    remove("input.txt");
    tmp.close();
    rename("temp.txt", "input.txt");


    ofstream tmp1;
    tmp1.open("temp.txt");
    while(file1.get(word))
    {
        tmp1.put(word);
    }
    file1.close();
    remove("input1.txt");
    tmp1.close();
    rename("temp.txt", "input1.txt");


    return result;
}

string decrypt(string decrypted)
{
    ifstream file,file1;
    file.open("output.txt");
    file1.open("output1.txt");
    //fstream output ("compress.txt" , ios :: in | ios :: out | ios :: trunc);
    string result = "";
    for(int i = 0; i < decrypted.length(); i++)
    {
        char word;

        if(isupper(decrypted[i]))
        {
            file.get(word);
            int temp = decrypted[i]-64 + 26 - Big[word];
            if(temp>26)
                temp = temp-26;
            char c = temp+64;
            result += c;


        }

        else if(islower(decrypted[i]))
        {
            file1.get(word);
            int temp = decrypted[i]-96 + 26 - small[word];
            if(temp>26)
                temp = temp-26;
            char c = temp+96;
            result += c;
        }
        else{
            result+=decrypted[i];
        }

    }


    char word;
    ofstream tmp;
    tmp.open("temp.txt");
    while(file.get(word))
    {
        tmp.put(word);
    }
    file.close();
    remove("output.txt");
    tmp.close();
    rename("temp.txt", "output.txt");


    ofstream tmp1;
    tmp1.open("temp.txt");
    while(file1.get(word))
    {
        tmp1.put(word);
    }
    file1.close();
    remove("output1.txt");
    tmp1.close();
    rename("temp.txt", "output1.txt");

    return result;
}

void mp()
{
    int i = 1;
    for(char c = 'A'; c <= 'Z' ; c++,i++)
        Big[c] = i;

    i = 1;
    for(char c = 'a'; c <= 'z' ; c++,i++)
        small[c] = i;
}

int main()
{
    mp();
    string plainText;


    printf("Enter Plaintext\n");
    getline(cin,plainText);

    string encrypted = encrypt(plainText);
    cout<<encrypted<<" Encrypted"<<endl;
    cout<<decrypt(encrypted)<< " Decrypted"<<endl;

    return 0;
}
