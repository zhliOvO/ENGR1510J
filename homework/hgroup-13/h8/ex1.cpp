#include "homework.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
void ex1_reverse_array(){
    string str[10000];
    int i=0;
    while (cin>>str[i])
    {
        i++;
    }
    
    for(int j=i;j>=0;j--){
        cout<<str[j]+" ";
    }

}
void ex1_reverse_vector(){
    vector<string> str;
    string temp;
    while (cin >> temp)
    {
        str.push_back(temp);
    }
    while (str.empty()==false)
    {
        cout<<str.back()+" ";
        str.pop_back();
    }
    
}
void ex1_reverse_stack(){
    stack<string> str;
    string temp;
    while(cin>>temp){
        str.push(temp);
    }
    while(str.empty()==false){
        cout<<str.top()+" ";
        str.pop();
    }
}
void ex1_ordered_array(){
    string str[10000];
    int i=0;
    while(cin>>str[i]){
        i++;
    }
    for(int j=0;j<=i;j++){
        cout<<str[j]+" ";
    }
}
void ex1_ordered_vector(){
    vector<string> str;
    string temp;int i=0;
    while(cin>>temp){
        str.push_back(temp);
        i++;
    }
    for(int j=0;j<=i;j++){
        cout<<str[(unsigned long)j]<<" ";
    }
}
void ex1_ordered_queue(){
    queue<string> str;
    string temp;
    while (cin>>temp)
    {
        str.push(temp);
    }
    while (str.empty()==false)
    {
        cout<<str.front()+" ";
        str.pop();
    }
    
}
