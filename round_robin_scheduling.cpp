
#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<sstream>
using namespace std;

#define nl          cout << "\n";
#define pb          push_back
#define mp          make_pair
#define fi          first
#define se          second
#define vi          vector<int>
#define fLeft       << setw(20) << left



struct Event {
    int arrivalTime, burstTime, jobNum;
};


inline bool cmp(Event A, Event B) {
    return A.arrivalTime < B.arrivalTime;
}

inline bool cmp1(Event A, Event B) {
    return A.jobNum < B.jobNum;
}


int main() {

    int n;
    int tc;

    cout << "Enter the number of processes and time quantum\n";

    cin >> n >> tc;

    vector<Event> arr(n, Event());

    cout << "Enter the arrival time\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i].arrivalTime;
    }

    cout << "Enter the burst time\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i].burstTime;
        arr[i].jobNum = i;
    }

    vi BT(n, 0);

    for(int i = 0; i < n; i++) {
        BT[i] = arr[i].burstTime;
    }

    sort(arr.begin(), arr.end(), cmp);


    vi CT(n, 0);
    vi TAT(n, 0);
    vi WT(n, 0);


    vector< pair<int, int> > ganttChart;


    int timeCount = 0;
    queue< Event > q;

    int jobPtr = 0;

    double avgWt = 0, avgTat = 0;


    int lastCompletedQuantum = 0;

    while(!q.empty() || jobPtr < n) {

        while(jobPtr < n && arr[jobPtr].arrivalTime == timeCount) {
            q.push(arr[jobPtr]);
            jobPtr += 1;
        }

        if(!q.empty()) {

            if(lastCompletedQuantum != timeCount) {
                ganttChart.pb(mp(-1, lastCompletedQuantum));
            }

            Event currJob = q.front();
            q.pop();

            ganttChart.pb(mp(currJob.jobNum, timeCount));

            for(int i = 0;(i < tc) && (currJob.burstTime > 0); i++) {
                currJob.burstTime -= 1;
                timeCount += 1;

                while(jobPtr < n && arr[jobPtr].arrivalTime == timeCount) {
                    q.push(arr[jobPtr]);
                    jobPtr += 1;
                }

            }

            lastCompletedQuantum = timeCount;

            if(currJob.burstTime <= 0) {

                int k = currJob.jobNum;
                CT[k] = timeCount;
                TAT[k] = CT[k] - currJob.arrivalTime;
                WT[k] = TAT[k] - BT[k];

                avgTat += TAT[k];
                avgWt += WT[k];

            } else {
                q.push(currJob);
            }

        } else {
            timeCount += 1;
        }

    }

    cout << "\n\nGANTT CHART\n\n";

    cout << "\t";

    for(int i = 0; i < ganttChart.size(); i++) {
        if(ganttChart[i].fi == -1) {
            cout fLeft << "--";
        } else {
            stringstream ss;
            ss << (ganttChart[i].fi+1);
            string a, b = "P";
            ss >> a;

            a = b + a;

            cout fLeft << a;
        }
        
    }

    cout << "\n";

    for(int i = 0; i < ganttChart.size(); i++) {
        cout fLeft << ganttChart[i].se;
    }

    cout << CT[(--ganttChart.end())->fi] << "\n\n";

    sort(arr.begin(), arr.end(), cmp1);

    cout fLeft << "Process No"
        fLeft << "Arrival Time" 
        fLeft << "Burst Time"
        fLeft << "Completion Time"
        fLeft << "Turn Around Time" 
        fLeft << "Waiting Time" << "\n";

    for(int i = 0; i < n; i++) {
        int k = arr[i].jobNum;
        cout fLeft << k+1
            fLeft << arr[i].arrivalTime
            fLeft << arr[i].burstTime
            fLeft << CT[k]
            fLeft << TAT[k]
            fLeft << WT[k];
            nl;
    }
    nl

    avgWt /= n;
    avgTat /= n;

    cout << "Average turn around time: " << avgTat << "\n";
    cout << "Average waiting time: " << avgWt << "\n";

    return 0;
}