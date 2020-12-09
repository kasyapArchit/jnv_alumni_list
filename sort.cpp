#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,vector<string>> mp;
    
    ifstream in;
    in.open("data.txt");
    stringstream ss;
    ss << in.rdbuf();
    in.close();

    string tmp;
    while(getline(ss, tmp, ')')){
        string name;
        getline(ss, name, '(');
        int year;
        ss >> year;
        mp[year].push_back(name);
        getline(ss,tmp);
    }


    ofstream of;
    of.open("sort.txt");
    for(auto it:mp){
        of << "Year : " << it.first << '\n';
        int cnt = 1;
        for(auto x:it.second){
            of << " " << cnt++ << ')' << x << '\n';
        }
        of << '\n';
    }
    of.close();
    return 0;
}