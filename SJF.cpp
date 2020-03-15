

#include<bits/stdc++.h>
using namespace std;

#define IO          ios::sync_with_stdio(0);
#define MOD         1000000007
#define ll          long long
#define nl          cout << "\n";
#define mp          make_pair
#define fi          first
#define se          second
#define dbg         cout << "Debug...\n";
#define prt(a)      cout << a << "\n";
#define vi          vector<int>
#define vb          vector<bool>
#define w_is(a)     cerr << #a << " " << a << "\n";
#define msi         multiset<ll>::iterator
#define fLeft       << setw(20) << left
#define pii         pair<int, int>

#define pi          2*acos(0.0)


int main() {
    
    int n;
    
    cout << "Enter the number of processes\n";
    cin >> n;
    
    int *arrivalTime = new int[n];
    int *burstTime = new int[n];
    
    cout << "Enter the arrival time\n";
    for(int i = 0; i < n; i++) {
        cin >> arrivalTime[i];
    }
    
    cout << "Enter the burst time\n";
    for(int i = 0; i < n; i++) {
        cin >> burstTime[i];
    }
    
    int cT = 0;
    
    int *completionTime = new int [n];
    int *TAT = new int [n];
    int *WT = new int [n];
    float avgWt = 0, avgTat = 0;
    
    
    multiset< pii > remainingJobHolder;
    
    int jobPtr = 0;
    int currentJobBT = 0;
    int currentJobNum = 0;
    int timeCount = 0;
    remainingJobHolder.insert(mp(burstTime[jobPtr], jobPtr));
    
    bool isProcessRunning = false;
    while(jobPtr < n || !remainingJobHolder.empty()) {

        timeCount += 1;
        multiset< pii >::iterator temp = remainingJobHolder.begin();
        pii smallestJobNow = *temp;
        if(temp == remainingJobHolder.end()) {
            if(isProcessRunning) {
                currentJobBT -= 1;
                if(currentJobBT <= 0) {
                    isProcessRunning = false;
                    completionTime[currentJobNum] = timeCount;
                }
                // last job case
                if(jobPtr == n-1) {
                    jobPtr++;
                    // if this is not done then loop will run infinitely
                }       
            }
            /*
                else increment timeCount
                which will be done on line 108
            */
        }
        else {
            if(!isProcessRunning) {
                currentJobBT = smallestJobNow.fi;
                currentJobNum = smallestJobNow.se;
                isProcessRunning = true;
                remainingJobHolder.erase(temp);
                //////
                currentJobBT -= 1;
                if(currentJobBT <= 0) {
                    isProcessRunning = false;
                    completionTime[currentJobNum] = timeCount;
                }
                //////
            }
            else {
                if(currentJobBT > smallestJobNow.fi) {
                    remainingJobHolder.insert(mp(currentJobBT, currentJobNum));
                    currentJobBT = smallestJobNow.fi;
                    currentJobNum = smallestJobNow.se;
                    remainingJobHolder.erase(smallestJobNow);
                }

                currentJobBT -= 1;
                if(currentJobBT <= 0) {
                    isProcessRunning = false;
                    completionTime[currentJobNum] = timeCount;
                }
            }
        }

        currentJobBT -= 1;

        // if jobPtr == n-1 then jobPtr will not be incremented
        // this will lead to infinitel loop
        // this condition is handeled on line 73 
        if((jobPtr != n-1) && arrivalTime[jobPtr+1] == timeCount) {
            remainingJobHolder.insert(mp(burstTime[jobPtr+1], jobPtr+1));
            jobPtr++;
        }

        cout << timeCount << "\n";
        if (timeCount > 30) break;  
    }
    
    cout << "out\n";
    cout << jobPtr << "\n";
    
    for(int i = 0; i < n; i++) {
        TAT[i] = completionTime[i] - arrivalTime[i];
        WT[i] = TAT[i] - burstTime[i];
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
            fLeft << arrivalTime[i]
            fLeft << burstTime[i]
            fLeft << completionTime[i]
            fLeft << TAT[i]
            fLeft << WT[i] << "\n";
    }

    
    cout << "Average waiting time: " << avgWt << "\n";
    cout << "Average Turn around time: " << avgTat << "\n";
    
    
    delete [] arrivalTime;
    delete [] burstTime;
    delete [] completionTime;
    delete [] TAT;
    delete [] WT;

    return 0;

}