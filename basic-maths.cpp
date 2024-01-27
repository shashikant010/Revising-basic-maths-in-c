#include <bits/stdc++.h>
using namespace std;

int countdig(int n){
    int count=0;
    while(n>0){
        int r=n%10;
        n=n/10;
        count++;
    }
    return count;
}

int reversenum(int n){
    int rNum=0;
    while(n>0){
        int r=n%10;
        rNum*=10;
        rNum+=r;
        n/=10;
    }
    return rNum;
}

string checkpalindrone(int n){
    if(n==reversenum(n)){
        return "is";
    }
    else{
        return "is not";
    }
}

string checkArmstrong(int n){
    int power=countdig(n);
    int nCopy =n;
    int pSum=0;//power sum
    while(nCopy>0){
        int r=nCopy%10;
        pSum+=pow(r,power);
        nCopy/=10;
    }
    if(pSum==n){
        return "is";
    }
    else{
        return "is not";
    }
}

vector<int> printalldivisor(int n){
    vector<int> ls;
    for(int i=1;i*i<n;i++){
        
        if(n%i==0){
            if(n/i!=i){
            ls.push_back(i);
            ls.push_back(n/i);
            }
            else{
            ls.push_back(i);

            }
        }
        
    }
    sort(ls.begin(),ls.end());
   return ls;
}

string checkprime(int n){
    vector<int> ls=printalldivisor(n);
    if(ls.size()<=2){
        return "is";
    }
    else return "is not";
}

//basic method to find hcf
int findhcf(int a ,int b){
    for(int i=min(a,b);i>0;i--){
        if(a%i==0 && b%i==0){
            return i;
        }
    }
}

int findhcfbyeu(int a,int b){
    while(a>0 && b>0){
        if(a>b){
            a=a%b;
        }
        else b=b%a;
    }
    if(a==0){
        return b;
    }
    else return a;
}

int main(){
    int n;
    cout<<"enter a number ";
    cin>>n;
    cout<<"number of digit in number is "<<countdig(n)<<endl;
    cout<<"Reverse of number is "<<reversenum(n)<<endl;
    cout<<"The number "<<checkpalindrone(n)<<" a palindrone"<<endl;
    cout<<"The number "<<checkArmstrong(n)<<" a armstrong"<<endl;
    cout<<"the divisor of "<<n<<" is follows: ";
    vector<int> ab = printalldivisor(n);
    for(auto it:ab){
        cout<<it<<" ";
        }
    cout<<endl;
    cout<<"The number "<<checkprime(n)<<" a prime number"<<endl;
    int a,b;
    cout<<"enter two number to find hcf ";
    cin>>a>>b;
    cout<<"the hcf of "<<a<<","<<b<<" is "<<findhcf(a,b)<<endl;
    cout<<"the hcf of "<<a<<","<<b<<" by euclidean algorithm is "<<findhcfbyeu(a,b)<<endl;
return 0;
}