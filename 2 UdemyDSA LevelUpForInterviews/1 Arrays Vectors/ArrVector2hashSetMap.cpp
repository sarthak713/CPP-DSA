#include<iostream>
#include<map>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/* 
Unordered Maps & Unordered Sets

- Map = O(log n)
    - implemented using BST
    - stores elements in sorted way
- Unordered Map = O(1)
    - implemented using Hashing with Separate Chaining
    - stores elements in unsorted way

*/

int main(){

    unordered_map<string,int>menu;
    menu["maggi"]=15;
    menu["drink"]=20;
    menu["drink"]=(1.1)*menu["drink"];
    menu["dosa"]=100;
    menu["pizza"]=120;
    menu["roll"]=200;
    string item="dosa";
    menu.erase("dosa");
    if(menu.count(item)==0){
        cout<<"Item not available"<<endl;
    }else{
        cout<<"Item available, cost = "<<menu[item]<<endl;
    }
    cout<<menu["drink"]<<endl;
    for(pair<string,int> item:menu){
        cout<<item.first<<" - "<<item.second<<endl;
    }

    
          
    
    return 0;
}