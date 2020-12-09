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
    while(!ss.eof()){
        char ch;
        ss >> ch;
        while(!isalpha(ch)) ss >> ch;

        string name, year, tmp;
        name += ch;
        getline(ss, tmp, '(');
        name += tmp;
        ss >> ch;
        while(!isdigit(ch)){
            name += '(';
            name += ch;
            getline(ss, tmp, '(');
            name += tmp;
            ss >> ch;
        }
        
        while(isdigit(ch)){
            year += ch;
            ss >> ch;
        }
        mp[stoi(year)].push_back(name);
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