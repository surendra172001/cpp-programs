

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

#define pi          2*acos(0.0)


struct date {
    int day;
    int month;
    int year;
    
    bool operator == (const date d) {
        bool cmp1 = (this->year == d.year);
        bool cmp2 = (this->month == d.month);
        bool cmp3 = (this->day == d.day);
        return (cmp1 && cmp2 && cmp3);
    }
    
    friend istream & operator >> (istream &in,  date &d);
    friend ostream & operator << (ostream &out,  date &d);
};


istream & operator >> (istream &in,  date &d) { 
    in >> d.day >> d.month >> d.year;
    return in; 
}


ostream & operator << (ostream &out,  date &d) { 
    out << d.day << " " << d.month << " " << d.year;
    return out; 
}

bool isLeapYear(ll year) {
    bool ans = false;
    if(year%400 == 0) {
        ans = true;
    }
    else if(year%100 == 0) {
        ans = false;
    }
    else if(year%4 == 0) {
        ans = true;
    }
    return ans;
}


ll calLeapYrsCount(ll startYear, ll endYear) {

    ll leapYrsCnt = 0;
    
    for(int i = startYear; i <= endYear; i++) {
        leapYrsCnt += isLeapYear(i);
    }
    
    return leapYrsCnt;
}



void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void correctDate(date &d1, date &d2) {
    if(d1.year == d2.year) {
        if(d1.month == d2.month) {
            if(d1.day > d2.day) {
                swap(d1.day, d2.day);
            }
        }
        else if(d1.month > d2.month) {
            swap(d1.month, d2.month);
            swap(d1.day, d2.day);
        }
    }
    else if(d1.year > d2.year) {
        swap(d1.year, d2.year);
        swap(d1.month, d2.month);
        swap(d1.day, d2.day);
    }
}


int noOfDaysInAMonth(int monthNum, bool isLeapYear) {
    int dayCnt = 0;
    switch(monthNum) {
        case 2:
            dayCnt = 28;
            dayCnt = (isLeapYear ? dayCnt+1 : dayCnt);
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dayCnt = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            dayCnt = 30;
            break;
        default:
            break;    
    }
    
    return dayCnt;
}

ll noOfDaysBetWnTwoDates(date d1, date d2) {
    if(d1 == d2) return 0;
    correctDate(d1, d2);
    ll noOfYears;
    ll noOfLeapYears;
    if(d1.year+1 == d2.year || d1.year == d2.year) {
        noOfYears = 0;
        noOfLeapYears = 0;
    }
    else {
        noOfYears = (d2.year-1) - d1.year;
        noOfLeapYears = calLeapYrsCount(d1.year+1, d2.year-1);
    }
    
    ll noOfDays = noOfYears*365 + noOfLeapYears;

    int dayCntOfd1 = 0;

    bool isStartLeapYr = isLeapYear(d1.year);
    dayCntOfd1 = noOfDaysInAMonth(d1.month, isStartLeapYr) - d1.day;

    int extraDays = 0;

    for(int i = d1.month+1; i <= 12; i++) {
        int temp = noOfDaysInAMonth(i, isStartLeapYr);
        dayCntOfd1 += temp;
        if(d1.year == d2.year && i >= d2.month) {
            extraDays += temp;
        }
    }
    
    // cout << dayCntOfd1 << "\n";

    int dayCntOfd2 = 0;
    bool isEndLeapYr = isLeapYear(d2.year);

    for(int i = 1; i < d2.month; i++) {
        int temp = noOfDaysInAMonth(i, isEndLeapYr);
        dayCntOfd2 += temp;
        if(d1.year == d2.year && i <= d2.month) {
            extraDays += temp;
        }
    }

    dayCntOfd2 += d2.day;

    noOfDays += dayCntOfd1 + dayCntOfd2 - extraDays;
    

    return noOfDays;
}



int main() {
    int t;

    cin >> t;
    
    date d1, d2;

    while(t--) {
        cin >> d1 >> d2;
        cout << noOfDaysBetWnTwoDates(d1, d2) << "\n";
    }
    return 0;
}


