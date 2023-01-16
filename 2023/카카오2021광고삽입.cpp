#include <string>
#include <vector>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;


string decode(int num) {
    string ans;
    int st = num;
    int tmp;
    if (st / 3600) {
        tmp = st / 3600;
        if (tmp / 10 != 0) { //2자리수
            ans += (char)(tmp / 10) + 48;

        }
        else {
            ans += (char)48;
        }
        ans += (char)tmp % 10 + 48;
        // cout<<"chk1: "<<tmp/10<<" "<<tmp%10<<endl;

        st %= 3600;
    }

    else
        ans += "00";

    ans += ":";

    if (st / 60) {
        tmp = st / 60;
        if (tmp / 10 != 0) { //2자리수
            ans += (char)(tmp / 10) + 48;

        }
        else {
            ans += (char)48;
        }
        ans += (char)tmp % 10 + 48;
        // cout<<"chk2: "<<tmp/10<<" "<<tmp%10<<endl;
        st %= 60;
    }
    else
        ans += "00";

    ans += ":";

    if (st == 0) ans += "00";
    else {
        if (st / 10 != 0) {
            ans += (char)(st / 10) + 48;
        }
        else {
            ans += (char)48;
        }
        ans += (char)st % 10 + 48;
    }
    //  cout<<"chk3: "<<st/10<<" "<<st%10<<endl;
    return ans;
}

int parser_single(string str) {
    int tmp;
    int time = 0;
    int arr[3] = { 3600,60,1 };
    int t = 0;
    for (int i = 0; i < 8; i += 3) {
        string ss;
        tmp = 0;
        // tmp+= ( stoi(str[i])*10 +stoi(str[i+1]) );
        ss += str[i];
        ss += str[i + 1];
        time += stoi(ss) * arr[t++];
    }
    return time;
}

pair<int, int> parser(string str) {
    int tmp;
    int st = 0, ed = 0;
    int arr[3] = { 3600,60,1 };
    int t = 0;
    for (int i = 0; i < 8; i += 3) {
        string ss;
        tmp = 0;
        // tmp+= ( stoi(str[i])*10 +stoi(str[i+1]) );
        ss += str[i];
        ss += str[i + 1];
        st += stoi(ss) * arr[t++];
    }
    t = 0;
    for (int i = 9; i < 17; i += 3) {
        string sss;
        tmp = 0;
        sss += str[i];
        sss += str[i + 1];
        ed += stoi(sss) * arr[t++];
    }
    pair<int, int> time = { st,ed };
    return time;

}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    vector<int> st;
    vector<int> ed;
    vector<pair<int, int> > tl;
    pair<int, int> tmp;

    int adv = parser_single(adv_time);
    int play = parser_single(play_time);
    if (adv >= play) return "00:00:00";
    for (int i = 0; i < logs.size(); i++) {
        tmp = parser(logs[i]);
        st.push_back(tmp.first);
        ed.push_back(tmp.second);
        tl.push_back(tmp);
    }
    sort(tl.begin(), tl.end());
    sort(st.begin(), st.end());
    sort(ed.begin(), ed.end());

    vector<int> last_st = st;
    vector<int> last_ed = ed;
    int aaa = 0;
    int sit = 0, eit = 0, l_sit = 0, l_eit = 0;
    bool chk1 = false, chk2 = false;

    int max = -987654321;
    int max_point = 0;
    int sum = 0;
    int concurent_dif = 0; //0~ 0+adv_time에게 상대적으로 
    l_sit = lower_bound(last_st.begin(), last_st.end(), adv) - last_st.begin();
    l_eit = lower_bound(last_ed.begin(), last_ed.end(), adv) - last_ed.begin();
    // cout<<"l: "<<l_sit<<" "<<l_eit<<endl;
     //cout<<"ll: "<<decode(last_st[l_sit])<<" "<<decode(last_ed[l_eit])<<endl;
     //cout<<"adv_time: "<<adv<< "play: "<<play<<endl;
    concurent_dif = l_sit - l_eit;
    //for(int i=0;i<st.size();i++)
      //  cout<<decode(st[i])<< " "<<decode(ed[i])<<endl;
    for (int i = 0; i <= play; i++) {

        int adv_st = i, adv_ed = i + adv;
        // if(adv_ed>=play) adv_ed=play;


        bool tt = false;
        while (eit < ed.size() && ed[eit] < adv_st - 1) eit++;
        while (sit < st.size() && st[sit] < adv_st - 1) sit++;

        while (l_eit < last_ed.size() && last_ed[l_eit] < adv_ed) l_eit++;
        while (l_sit < last_st.size() && last_st[l_sit] < adv_ed - 1) l_sit++;

        if (adv_st == st[sit] + 1) {

            concurent_dif--;
            tt = true;

        }
        if (adv_st == ed[eit] + 1) {
            concurent_dif++;
            //tt=true;
        }

        if (adv_ed == last_st[l_sit] + 1) {
            concurent_dif++;

            // tt=true;
        }
        if (adv_ed == last_ed[l_eit]) {
            concurent_dif--;
            //  tt=true;
        }
        // if(tt) cout<<decode(adv_st)<<"~"<<decode(adv_ed)<<": "<<concurent_dif<<endl;



        sum += concurent_dif;
        if (max < sum) {
            max_point = i;
            max = sum;
            // cout<<concurent_dif;
        }




    }
    answer = decode(max_point);

    //cout<<decode(max_point);

    /*
    int max=-1,max_time=0;

    for(int i=0;i<=play-adv;i++){
        int sum=0;
        for(int j=i;j<i+adv;j++){
            sum+=arr[j];
        }
        if(max<sum){
            max=sum;
            max_time=i;
        }
    }
    cout<<decode(max_time);


    for(auto it:tl){
        int st=it.first;
        int ed=st+adv;
        int valid_it=tl.begin-lower_bound(tl.begin(),tl.end(),st);

    }
    */




    //for(int i=0;i<st.size();i++)
      //  cout<<"st: "<<st[i]<<" ed "<<ed[i]<<endl;


    /*
    pair<int,int> test=parser("99:59:59-10:00:00");
    cout<<test.first<<" "<<test.second<<endl;
    answer = decode(test.first)+ "-"+decode(test.second);
    */

    return answer;
}