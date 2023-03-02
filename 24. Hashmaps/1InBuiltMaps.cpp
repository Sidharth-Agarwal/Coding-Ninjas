#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main()
{
    unordered_map<string,int> ourMap;

    //insert
    pair<string,int> p("abc",1);
    ourMap.insert(p);
    ourMap["def"] = 2;

    // find or access
    cout<<ourMap["abc"]<<endl;
    cout<<ourMap.at("abc")<<endl;

    cout<<"Size : "<<ourMap.size()<<endl;

    //cout<<ourMap.at("ghi")<<endl;
    cout<<ourMap["ghi"]<<endl;

    cout<<"Size : "<<ourMap.size()<<endl;

    // get presence
    if(ourMap.count("ghi") > 0)
    {
        cout<<"It is present"<<endl;
    }

    // erase
    ourMap.erase("ghi");
    cout<<ourMap.size()<<endl;
    if(ourMap.count("ghi") > 0)
    {
        cout<<"It is present";
    }
}