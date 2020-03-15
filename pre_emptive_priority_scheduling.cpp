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
#define fLeftGc     << setw(7) << left


struct Event {
    int arrivalTime,
        burstTime,
        priority,
        jobNum;

    Event() {
        arrivalTime = 0;
        burstTime = 0;
        priority = 0;
        jobNum = 0;
    }

};


struct compareJobs{

    bool operator()(Event &a, Event &b) {
        return a.priority < b.priority;
    }
    
};



inline bool cmp1(Event a, Event b) {
    if(a.arrivalTime == b.arrivalTime) {
        return a.jobNum < b.jobNum;
    }
    return a.arrivalTime < b.arrivalTime;
}

inline bool cmp2(Event a, Event b) {
    return a.jobNum < b.jobNum;
}


int main() {

    int n;

    cout << "Enter the number of processes\n";

    cin >> n;

    vector<Event> arr(n, Event());

    cout << "Enter the arrival time\n";

    for(int i = 0; i < n; i++) {
        cin >> arr[i].arrivalTime;
    }

    cout << "Enter the burst time\n";

    for(int i = 0; i < n; i++) {
        cin >> arr[i].burstTime;
    }

    cout << "Enter the priorities\n";

    for(int i = 0; i < n; i++) {
        cin >> arr[i].priority;
        arr[i].jobNum = i;
    }

    vi bt(n, 0);

    for(int i = 0; i < n; i++) {
        bt[i] = arr[i].burstTime;
    }

    vi completionTime(n, 0);
    vi turnAroundTime(n, 0);
    vi waitingTime(n, 0);

    double avgTat = 0;
    double avgWt = 0;

    sort(arr.begin(), arr.end(), cmp1);

    vector< pair<int, int> > ganttChart;

    int timeCnt = 0;

    Event currJob;

    int jobPtr = 0;

    bool isProcessRunning = false;

    priority_queue< Event, vector<Event>, compareJobs > jobHolder;

    int lastJobCompletionTime = 0;

    while(jobPtr < n || !jobHolder.empty() || isProcessRunning) {

        while(jobPtr < n && arr[jobPtr].arrivalTime == timeCnt) {
            jobHolder.push(arr[jobPtr]);
            jobPtr += 1;
        }

        if(isProcessRunning) {

            if(!jobHolder.empty()) {
                Event maxPriorityJobInQueue = jobHolder.top();

                if(currJob.priority < maxPriorityJobInQueue.priority) {
                    jobHolder.push(currJob);
                    currJob = maxPriorityJobInQueue;   
                    ganttChart.pb(mp(currJob.jobNum, timeCnt));
                    jobHolder.pop();            
                }
            }

            timeCnt += 1;
            currJob.burstTime -= 1;

            if(currJob.burstTime <= 0) {
                lastJobCompletionTime = timeCnt;
                isProcessRunning = false;

                int currJobNum = currJob.jobNum;

                completionTime[currJobNum] = timeCnt;
                turnAroundTime[currJobNum] = completionTime[currJobNum] - currJob.arrivalTime;
                waitingTime[currJobNum] = turnAroundTime[currJobNum] - bt[currJobNum];

                avgTat += turnAroundTime[currJobNum];
                avgWt += waitingTime[currJobNum];

            }

        } else {

            if(!jobHolder.empty()) {

                if(lastJobCompletionTime != timeCnt) {
                    ganttChart.pb(mp(-1, lastJobCompletionTime));
                }

                currJob = jobHolder.top();
                jobHolder.pop();

                isProcessRunning = true;

                ganttChart.pb(mp(currJob.jobNum, timeCnt));

                timeCnt += 1;
                currJob.burstTime -= 1;

                if(currJob.burstTime <= 0) {

                    lastJobCompletionTime = timeCnt;
                    isProcessRunning = false;

                    int currJobNum = currJob.jobNum;

                    completionTime[currJobNum] = timeCnt;
                    turnAroundTime[currJobNum] = completionTime[currJobNum] - currJob.arrivalTime;
                    waitingTime[currJobNum] = turnAroundTime[currJobNum] - bt[currJobNum];

                    avgTat += turnAroundTime[currJobNum];
                    avgWt += waitingTime[currJobNum];

                }

            } else {

                timeCnt += 1;

            }

        }

    }


    cout << "\n\nGANTT CHART\n\n";

    cout << "   ";

    for(int i = 0; i < ganttChart.size(); i++) {
        if(ganttChart[i].fi == -1) {
            cout fLeftGc << "--";
        } else {
            stringstream ss;
            ss << (ganttChart[i].fi+1);
            string a, b = "P";
            ss >> a;

            a = b + a;

            cout fLeftGc << a;
        }
        
    }

    cout << "\n";

    for(int i = 0; i < ganttChart.size(); i++) {
        cout fLeftGc << ganttChart[i].se;
    }

    cout << lastJobCompletionTime << "\n\n";

    sort(arr.begin(), arr.end(), cmp2);

    cout fLeft << "Process No"
        fLeft << "Arrival Time" 
        fLeft << "Burst Time"
        fLeft << "Priority" 
        fLeft << "Completion Time"
        fLeft << "Turn Around Time" 
        fLeft << "Waiting Time" << "\n";

    for(int i = 0; i < n; i++) {
        int k = arr[i].jobNum;
        cout fLeft << k+1
            fLeft << arr[i].arrivalTime
            fLeft << arr[i].burstTime
            fLeft << arr[i].priority
            fLeft << completionTime[k]
            fLeft << turnAroundTime[k]
            fLeft << waitingTime[k];
            nl;
    }
    nl

    avgWt /= n;
    avgTat /= n;

    cout << "Average turn around time: " << avgTat << "\n";
    cout << "Average waiting time: " << avgWt << "\n";

    return 0;
}