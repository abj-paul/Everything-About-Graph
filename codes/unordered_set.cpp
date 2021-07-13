#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<string> strset;
    strset.insert("code");
    strset.insert("in");
    strset.insert("c++");
    strset.insert("is");
    strset.insert("fast");
    
    string key = "slow";
    if(strset.find(key)==strset.end()) printf("%s is not in the set.\n",key.c_str());
    else printf("Found!\n");

    unordered_set<string>::iterator itr;
    for(itr = strset.begin(); itr!=strset.end(); itr++) printf("%s\n",(*itr).c_str());
return 0;
}
