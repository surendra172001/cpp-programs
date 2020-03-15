

// #include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<iomanip>
#include<sstream>

using namespace std;

#define nl          cout << "\n";
#define mp          make_pair
#define fi          first
#define se          second
#define vi          vector<int>
#define fLeft       << setw(20) << left
#define pii         pair<int, int>
#define pb          push_back

struct event {
    int arrivalTime;
    int burstTime;
    event() {
        arrivalTime = 0;
        burstTime = 0;
    }
};



inline bool cmp(event A, event B) {
    return A.arrivalTime < B.arrivalTime;
}



int main() {
    
    int n;
    
    cout << "Enter the number of processes\n";
    cin >> n;
    
    if(n == 0) return 0;
    
    event temp;
    vector<event> job(n, temp);
    
    cout << "Enter the arrival time\n";
    for(int i = 0; i < n; i++) {
        cin >> job[i].arrivalTime;
    }
    
    cout << "Enter the burst time\n";
    for(int i = 0; i < n; i++) {
        cin >> job[i].burstTime;
    }
    
    sort(job.begin(), job.end(), cmp);
    
    vi completionTime(n, 0);
    vi WT(n, 0);
    vi TAT(n, 0);
    float avgWt = 0, avgTat = 0;
    
    
    multiset< pii > remainingJobHolder;
    
    int jobPtr = 0;
    int currentJobBT = 0;
    int currentJobNum = 0;
    int timeCount = 0;
    timeCount = job[0].arrivalTime;
    remainingJobHolder.insert(mp(job[jobPtr].burstTime, jobPtr));
    while(jobPtr < n-1 && job[jobPtr+1].arrivalTime == timeCount) {
        remainingJobHolder.insert(mp(job[jobPtr+1].burstTime, jobPtr+1));
        jobPtr += 1;
    }

    bool isProcessRunning = false;

    vector< pii > ganttChart;

    int lastJobCompletionTime = 0;


    while(jobPtr < n || !remainingJobHolder.empty()) {
        timeCount += 1;
        multiset< pii >::iterator temp = remainingJobHolder.begin();
        pii smallestJobNow = *temp;

        if(isProcessRunning) {
            if(remainingJobHolder.end() != temp) {
                if(smallestJobNow.fi < currentJobBT) {
                    remainingJobHolder.insert(mp(currentJobBT, currentJobNum));
                    currentJobBT = smallestJobNow.fi;
                    currentJobNum = smallestJobNow.se;
                    ganttChart.pb(mp(currentJobNum, timeCount-1));
                    remainingJobHolder.erase(temp);
                }
            } 
            currentJobBT -= 1;
            if(currentJobBT <= 0) {
                lastJobCompletionTime = timeCount;
                completionTime[currentJobNum] = timeCount;
                isProcessRunning = false;
                if (jobPtr == n-1 && remainingJobHolder.empty()) {
                    jobPtr += 1;
                }
            }
        } else {
            if(remainingJobHolder.end() != temp) {

                if(timeCount - lastJobCompletionTime - 1 > 0) {
                    ganttChart.pb(mp(-1, lastJobCompletionTime));
                }

                currentJobBT = smallestJobNow.fi;
                currentJobNum = smallestJobNow.se;
                ganttChart.pb(mp(currentJobNum, timeCount-1));
                remainingJobHolder.erase(temp);
                isProcessRunning = true;
                currentJobBT -= 1;
                if(currentJobBT <= 0) {
                    lastJobCompletionTime = timeCount;
                    completionTime[currentJobNum] = timeCount;
                    isProcessRunning = false;
                }
            }
        }

        while(jobPtr < n-1 && job[jobPtr+1].arrivalTime == timeCount) {
            remainingJobHolder.insert(mp(job[jobPtr+1].burstTime, jobPtr+1));
            jobPtr += 1;
        }
        
    }

    cout << "\n\nGANTT CHART\n\n";
    for(int i = 0; i < ganttChart.size(); i++) {
        if(ganttChart[i].fi == -1) {
            cout fLeft << "--" fLeft << ganttChart[i].se << "\n";
        } else {
            stringstream ss;
            ss << (ganttChart[i].fi+1);
            string a, b = "P";
            ss >> a;

            a = b + a;

            cout fLeft << a fLeft << ganttChart[i].se << "\n";
        }
        
    }

    cout << "\n\n";
    
    for(int i = 0; i < n; i++) {
        TAT[i] = completionTime[i] - job[i].arrivalTime;
        WT[i] = TAT[i] - job[i].burstTime;
        avgTat += TAT[i];
        avgWt += WT[i];
    }
    
    avgWt /= n;
    avgTat /= n;

    cout fLeft << "Process No"
        fLeft << "Arrival Time" 
        fLeft << "Burst Time"
        fLeft << "Completion Time"
        fLeft << "Turn Around Time" 
        fLeft << "Waiting Time" << "\n";
    for(int i = 0; i < n; i++) {
        cout fLeft << i+1
            fLeft << job[i].arrivalTime
            fLeft << job[i].burstTime
            fLeft << completionTime[i]
            fLeft << TAT[i]
            fLeft << WT[i] << "\n";
    }

    
    cout << "Average waiting time: " << avgWt << "\n";
    cout << "Average Turn around time: " << avgTat << "\n";
    
    return 0;
}