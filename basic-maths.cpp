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

void printalldivisor(int n){
    cout<<"the divisor of "<<n<<" is follows: ";
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
    for(auto it:ls){
        cout<<it<<" ";
    }
}

int main(){
    int n;
    cout<<"enter a number ";
    cin>>n;
    cout<<"number of digit in number is "<<countdig(n)<<endl;
    cout<<"Reverse of number is "<<reversenum(n)<<endl;
    cout<<"The number "<<checkpalindrone(n)<<" a palindrone"<<endl;
    cout<<"The number "<<checkArmstrong(n)<<" a armstrong"<<endl;
    printalldivisor(n);
return 0;
}