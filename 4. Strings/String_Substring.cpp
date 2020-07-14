#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string str = "abc";
    vector <string> st;
    for(int i=0;i<str.length();i++)
    {
        for(int j =1;j<=str.length();j++)
            st.push_back(str.substr(i,j));
    }
    st.erase( unique( st.begin(), st.end() ), st.end() ); // set only unique elements in vector
    sort(st.begin(),st.end());
    for(auto x : st)
        cout<<x<<endl;
}