#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string,int>mapping;
    
    pair<string,int>p = make_pair("priyanshu", 22);
    pair<string,int>q("nothing", 21);
    
    pair<string,int>r;
    
    q.first = "Arun";
    q.second = 26;
    
    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);
    
    mapping["patel"] = 22;
    
    cout<< "size of map: " << mapping.size() << endl;
    
    cout << mapping.at("priyanshu")<<endl;
    cout << mapping["priyanshu"] << endl;
    
    cout << mapping.count("priyanshu") << endl;
    
    if(mapping.find("patel") != mapping.end()){
        cout << "found" << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
    
    cout << "Size of map: " << mapping.size() << endl;
    cout << mapping["kumar"] << endl;
    cout << "Size of map: " << mapping.size() << endl;
    
    return 0;
}