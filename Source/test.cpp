#include<iostream>
#include<algorithm>
#include<string>

using namespace std;


int main(){

 string str= "om pandey";

string toRemove="pandey";

size_t pos=str.find(toRemove);
cout<<pos<<endl;

if(pos!=string::npos){

    str.erase(pos,toRemove.length());
}

cout<<str;
// for(int x=0;x<n/2;x++)
// {

//     char temp;
//     temp=str[n-x-1];
//     str[n-x-1]=str[x];
//     str[x]=temp;
// }


    return 0;
}