#include<bits/stdc++.h>
#define single_tab '\t'
#define double_tab "\t\t"
#define tripple_tab "\t\t\t"
using namespace std;
struct Process{
    int id,arrival,burst,ct,tat,wt,iddle;
};

bool cmp(Process &a, Process &b){
    return a.arrival<b.arrival;
}

int main(){
    int n=3;
//    cin >> n;
    vector<Process>ab ={{1,10,5},{2,14,3},{3,20,4}};

    //sorted by arrival time in ascending order
    sort(ab.begin(),ab.end(),cmp);
    ab[0].ct = ab[0].arrival + ab[0].burst;
    ab[0].tat = ab[0].ct - ab[0].arrival;
    ab[0].wt = 0;
    ab[0].iddle = ab[0].arrival;

    //calculation from second to last

    for(int i=1;i<n;i++){

        ab[i].ct = max(ab[i-1].ct,ab[i].arrival) + ab[i].burst;
        ab[i].tat = ab[i].ct - ab[i].arrival;
        ab[i].wt = ab[i].tat - ab[i].burst;
        if(ab[i].arrival > ab[i-1].ct)
        ab[i].iddle = ab[i].arrival - ab[i-1].ct;
        else ab[i].iddle = 0;

    }

    cout<<"Process ID"<< single_tab << "Arrival"<<double_tab << "Burst"<<double_tab << "completion Time"<<double_tab<<"Turnaround Time"<<double_tab<<"Waiting"<<double_tab<<"Iddle"<<endl;
    for(int i=0;i<n;i++){
        cout<<ab[i].id << double_tab<<ab[i].arrival<<double_tab<<ab[i].burst<< double_tab<<ab[i].ct<<tripple_tab<<ab[i].tat<<tripple_tab <<ab[i].wt<<double_tab <<ab[i].iddle<<endl;
    }


    return 0;
}
//ab[i].iddle = (ab[i].arrival>ab[i-1].ct)