#include<bits/stdc++.h>
using namespace std;

unordered_map<char, int> mp{
    {'^', 3},
    {'/', 2},
    {'*', 2},
    {'+', 1},    
    {'-', 1},
    {'(', 0},
};

string prefix(string s){
    string ans = "";
    int n = s.length();
    stack<char> st;
    for(int i=n-1; i>=0; i--){
        if(s[i] >= 'a' && s[i] <= 'z'){
            ans += s[i];
        }
        else if(s[i] == '('){
            while(st.top() != ')'){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else if(st.empty() || s[i] == ')' || (mp[s[i]] >= mp[st.top()])){
            st.push(s[i]);
        }
        else{
            while(!st.empty() && (mp[s[i]] < mp[st.top()])){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s = "a+b*(c^d-e)^(f+g*h)-i";
    cout<<prefix(s)<<endl;
    return 0;
}