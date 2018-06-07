#include<bits/stdc++.h>
using namespace std;
long long int t,n,k,m,maxi,ans[100005],f,l;


int main()
{
    ios_base::sync_with_stdio;
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        m=n*(n+1)/2;
        m--;
        if(n==1)
        {
            if(k==0)
                cout<<"1\n";
            else
                cout<<"-1\n";
        }
        else
        {
            if(n%2==1)
            {
                maxi=n*n-1;
                maxi*=3;
                maxi/=4;
            }
            else
            {
                maxi=n*n;
                maxi*=3;
                maxi/=4;
                maxi--;
            }
            if(k<m||k>maxi)
                cout<<"-1\n";
            else
            {
                f=n;
                l=2;
                while(1)
                {
                    if(m+f-l<k)
                    {
                        ans[n-f+l-1]=f;
                        m+=(f-l);
                        f--;
                        l++;
                    }
                    else if(m+f-l==k)
                    {
                        ans[n-f+l-1]=f;
                        break;
                    }
                    else
                    {
                        ans[n-1-(k-m)]=f;
                        break;
                    }
                }
                m=1;
                for(int i=0;i<n;i++)
                {
                    if(ans[i]==0)
                    {
                        ans[i]=m++;
                    }
                }
                for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
        for(int i=0;i<n;i++)
            ans[i]=0;
            }
        }
    }
}
