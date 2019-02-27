#include <iostream> 
using namespace std;
int min(int x,int y)
{
    if (x<y)
    return x;
    return y;
};
int main()
{
    int n,*start,*end,minS,minE,out=0,array[100],flag=1;
   cin>>n;
   start = new int[n];
   end   = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>*(start+i)>>*(end+i);
    }
    
    for(int i=0;i<n;i++)
    {   minS=*(start+i);
        minE=*(end+i);
        for(int j=i+1;j<n;j++)
        {
            if(*(start+j)<minS)
            {minS=*(start+j);
            minE=*(end+j);
            *(start+j)=*(start+i);
            *(end+j)=*(end+i);}
        
        }
        *(start+i)=minS;
        *(end+i)=minE;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(*(end+i) < *(start+j))
            {array[out]=min (*(end+i),*(end+j));
            out++;
            if (j==n-1)
            {array[out]=*(end+j);out++;}
            break;}
            else
           { flag=j; 
            if (j==n-1)
            {array[out]=min (*(end+i),*(end+j));out++;}  } 
        }

        i=flag;
    }
    if (out==0)
    {out=1;array[0]=*end;}
    cout<<out;
    for(int i=0;i<out;i++)
    {cout<<array[i];}
    delete start;
    delete end;
   return 0;
}
