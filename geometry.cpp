
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
#define MAX         12000000


struct Point {
    double x, y;
};


double calPerPendicularDistance(Point a, Point b, Point c) {
    double area = abs(calAreaOfTriangle(Point a, Point b, Point c));

    Point ab;

    ab.x = b.x - a.x;
    ab.y = b.y - a.y;

    double d = sqrt((ab.x)*(ab.x) + (ab.y)*(ab.y));

    return (area/d);

}



double calShortestDistFromASegment(Point a, Point b, Point c) {
    Point ab, ac, bc;

    ab.x = b.x - a.x;
    ab.y = b.y - a.y;

    ac.x = c.x - a.x;
    ac.y = c.y - a.y;


    bc.x = c.x - b.x;
    bc.y = c.y - b.y;


    int d1 = (ab.x)*(ac.x) + (ab.y)*(ac.y);
    int d2 = (ab.x)*(bc.x) + (ab.y)*(bc.y);

    if (d1 == 0 && d2 == 0) {
        return 0;
    }

    double ans = 0;

    if (d1 < 0) {
        ans = sqrt((ac.x)*(ac.x) + (ac.y)*(ac.y));
    } else if (d2 > 0) {
        ans = sqrt((bc.x)*(bc.x) + (bc.y)*(bc.y));
    } else if ((d1 > 0) && (d2 < 0)) {
        double d3 = sqrt((ab.x)*(ab.x) + (ab.y)*(ab.y));
        ans = (d1/d3);
    }

    return ans;
}



double calAreaOfTriangle(Point a, Point b, Point c) {
    Point ab, ac;

    ab.x = b.x - a.x;
    ab.y = b.y - a.y;

    ac.x = c.x - a.x;
    ac.y = c.y - a.y;

    double area = (ab.x)*(ac.y) - (ac.x)*(ab.y);
    area /= 2;

    return area;
}



double calAreaOfPolygon(vector<Point> &arr) {

    double totalArea = 0;
    int n = arr.size();
    for (int i = 1; i < n-1; ++i) {
        totalArea += calAreaOfTriangle(arr[0], arr[i], arr[i+1]);
    }

    return abs(totalArea);
}


void calCoeff(Point a, Point b, double &A1, double &B1, double &C1) {
    A1 = b.y - a.y;
    B1 = a.x- b.x;
    C1 = A1*(a.x) + B1*(b.y);
}


bool doesLinesIntersect(Point a1, Point b1, Point a2, Point b2) {

    double A1, B1, C1;
    calCoeff(a1, b1, A1, B1, C1);
    // cout << A1 << " " << B1 << " " << C1 << "\n";

    double A2, B2, C2;
    calCoeff(a2, b2, A2, B2, C2);
    // cout << A2 << " " << B2 << " " << C2 << "\n";

    double determinant = A1*B2 - B1*A2;

    bool ans;
    if(determinant == 0) {
        // cout << "Do not intersect\n";
        ans =false;
    } else {
        double x = (C1*B2 - C2*B1) * determinant;
        double y = -1 * (C1*A2 - C2*A1) * determinant;
        ans = true;
        // cout << x << " " << y;
    }
    return ans;
}





int main() {

    string s;

    cin >> s;

    int n = s.length();

    vector<Point> arr;

    double a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        double auxA = 0, auxB = 0;
        if(s[i] == 'N') {
            cin >> auxB;
            auxB = b + auxB;
            auxA = a;
        } else if(s[i] == 'S') {
            cin >> auxB;
            auxB = b - auxB;
            auxA = a;
        } else if(s[i] == 'W') {
            cin >> auxA;
            auxA = a + auxA;
            auxB = b;
        } else if(s[i] == 'E') {
            cin >> auxA;
            auxA = a - auxA;
            auxB = b;
        }
        arr[i].x = auxA;
        arr[i].y = auxB;
        a = auxA;
        b = auxB;
    }

    cout << calAreaOfPolygon(arr) << "\n";

    return 0;
}