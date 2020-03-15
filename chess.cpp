#include<bits/stdc++.h>
using namespace std;


int movementX[] = {2, 1, 6, 8, 3, 2, 3, 1, 4, 8, 5, 3, 4, 1, 2, 8, 7, 4, 8};
int movementY[] = {2, 3, 8, 6, 1, 2, 3, 5, 8, 4, 1, 3, 4, 7, 8, 2, 1, 4, 8};


int main() {
    
    int t;
    
    cin >> t;
    
    while(t--) {
        int r, c;
        cin >>  r >> c;
        if(r == 1 && c == 1) {
            cout << 19 << "\n";
            for(int i = 0; i < 19; i++) {
            	cout << movementX[i] << " " << movementY[i] << "\n";
            }
        } else if(r == c) {
            cout << 20 << "\n";
            cout << 1 << " " << 1 << "\n";
            for(int i = 0; i < 19; i++) {
            	cout << movementX[i] << " " << movementY[i] << "\n";
            }
        } else {
            int x = r, y = c;
            int xChangeFactor;
            int yChangeFactor;
            
            if(x == 4 && y < 4) {
                xChangeFactor = -1;
                yChangeFactor = 1;
            } else if((x == 4 && y > 4) && (x > 4 && y == 4)) {
                xChangeFactor = 1;
                yChangeFactor = 1;
            } else if(x < 4 && y == 4) {
                xChangeFactor = 1;
                yChangeFactor = -1;
            } else {
                xChangeFactor = (x < y ? 1 : -1);
                yChangeFactor = (x > y ? 1 : -1);
            }
            
            while(x != y) {
                x += xChangeFactor;
                y += yChangeFactor;
            }
            
            if(x == 1 && y == 1) {
                cout << 20 << "\n";
                cout << 1 << " " << 1 << "\n";
                for(int i = 0; i < 19; i++) {
                	cout << movementX[i] << " " << movementY[i] << "\n";
                }
            } else {
                cout << 21 << "\n";
                cout << x << " " << y << "\n";
                cout << 1 << " " << 1 << "\n";
                for(int i = 0; i < 19; i++) {
                	cout << movementX[i] << " " << movementY[i] << "\n";
                }                
            }
            
        }

    }
        
        
    return 0;
}