///God is Almighty
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    int i,j,l1,l2;
    while(getline(cin,s1),getline(cin,s2)){
    l1=s1.size();
    l2=s2.size();
    char sign[l1+1][l2+1];
    int LCS[l1+1][l2+1];
    for(i=0;i<=l1; i++)
    {
        LCS[i][0]=0;
    }
    for(i=0;i<=l2; i++)
    {
        LCS[0][i]=0;
    }
    for(i=1; i<=l1; i++)
    {
        for(j=1; j<=l2; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                LCS[i][j] = LCS[i-1][j-1]+1;
                sign[i][j]= 'd';
            }
            else
            {
                if(LCS[i-1][j]>=LCS[i][j-1])
                {
                    LCS[i][j]=LCS[i-1][j];
                    sign[i][j]= 't';
                }
                else
                {
                    LCS[i][j]=LCS[i][j-1];
                    sign[i][j]= 'l';
                }
            }
        }
    }
    //cout<<sign[l1][l2]<<endl;
    int x=l1,y=l2;
    char ch;
    ch=sign[l1][l2];
    //cout<<sign[4][6];
   stack<char>Stack;
   int ct=0;

      while(1)
       {

          if(ch=='t')
          { //cout<<ch;
              x--;
          }
          if(ch=='d') {
              //cout<<x<<"-->"<<y;
              //cout<<s1[x-1];
                Stack.push(s1[x-1]);
                x--;y--;
            }
        if(ch=='l') {y--;}
        ch=sign[x][y];
        if(x==0 || y==0) break;
      }
      //getchar();
      cout<<"Longest Common Subsequence: ";
      while(!Stack.empty())
      {
          cout<<Stack.top(); //ct++;
          Stack.pop();
      }
      cout<<endl;
      cout<<"Length of LCS: "<<LCS[l1][l2]<<endl;

      //cout<<ct<<endl;
      //Stack.clear();
    }
    return 0;
}
