#include <bits/stdc++.h>
using namespace std;
void decompress()
{
    fstream file1 ("compress.txt" , ios :: in | ios :: out);
    fstream file2 ("decompress.txt" , ios :: in | ios :: out | ios :: trunc);

   string line,full_str;
   char ch;

    while(getline(file1,line))
    {
        int cnt,i = 0;
        full_str = (line);
         while(i<full_str.length())
        {
            ch = full_str[i];
            i++;
            cnt = (int)full_str[i];
            cnt = cnt - '0';

            while(cnt)
            {
                file2<<ch;
                cnt--;
            }
            i++;
        }

        file2<<'\n';


    }
}
int main()
{
    fstream input ("input.txt" , ios :: in | ios :: out);
    fstream output ("compress.txt" , ios :: in | ios :: out | ios :: trunc);

   string ln,str;
   char ch;

    while(getline(input,ln))
    {
        int cnt = 0,i = 0;
        str = (ln);
        while(i<str.length())
        {
            ch = str[i];
            while(ch==str[i])
            {
                cnt++;
                i++;
                if(cnt == 9)
                {
                    output<<ch;
                    output<<cnt;
                    cnt = 0;
                }
            }
            if(cnt > 0)
            {
                output<<ch;
                output<<cnt;
            }

            cnt=0;
        }

        output<<'\n';
    }



    output.close();
    decompress();

}
