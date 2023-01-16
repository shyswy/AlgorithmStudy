#include <string>
#include <vector>
#include<map>
#include<iostream>
using namespace std;

map<string, bool> ma;
bool solution(vector<string> phone_book) {
    bool answer = true;
    for (int i = 0; i < phone_book.size(); i++) ma[phone_book[i]] = true;

    for (int i = 0; i < phone_book.size(); i++) {
        string str = "";
        //해당 번호가 다른 번호를 접두어로 가지는지 check. 동일한 번호는x이기에 size-1까지만.
        for (int len = 0; len < phone_book[i].size() - 1; len++) {
            str += phone_book[i][len];
            if (ma[str]) answer = false;   //ma[str] 에서 key값 str이 존재하지 않으면, 0( value 디폴트) 값을 삽입.
        }
    }
    return answer;
}


//map.count(key) ==0 >> key가 존재 x

//string의 sort>> 사전순.     abc   abcdgwegwr    abd,..... ( 길이 관계없이..
//>>    "123" ,"123545635","124",......   따라서 인접한거끼리만 확인하면됨.
//["88","12",,"1235","567","123"]
// 이걸 사전순으로하면
// "12", "123","1235","567","88"  
/*
 sort(phoneBook.begin(), phoneBook.end());

    for ( int i = 0 ; i < phoneBook.size() - 1 ; i++ )
    {
        if ( phoneBook[i] == phoneBook[i+1].substr(0, phoneBook[i].size()) )
        {
            answer = false;
            break;
        }
    }


*/