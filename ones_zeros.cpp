#include<bits/stdc++.h>
using namespace std;

bool isBinary(int n){
  while(n>0)
  {

    int digit=n%10;
    if(digit!=0 && digit != 1)
        return false;
    n/=10;
  }

 return true;

}


int mod(string t,int n)
{
    int r=0;

    for(int i=0;i<t.length();i++)
    {
        r=r*10+ ( t[i]-'0' );
        r%=n;
    }

    return r;
}

string findzeros_ones(int n)
{
    queue<string> q;
    set<int> visit;

    string t="1";

    q.push(t);


    while(!q.empty()){
        t=q.front();
        q.pop();


        int rem=mod(t,n);

        if(rem==0)
            return t;

        else if(visit.find(rem)==visit.end())
        {
            visit.insert(rem);
            q.push(t+"0");
            q.push(t+"1");
        }
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
      if(isBinary(n))
        cout<<n<<endl;
      else
    cout<<findzeros_ones(n)<<endl;
    }

    return 0;
}
