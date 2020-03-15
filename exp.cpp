#include<bits/stdc++.h>
using namespace std;





void printArr(int **mat, int n,int k) {
    for(int i = 0; i< k; i++) {
        for(int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    
}



int main() {
    
    int t;
    
    cin >> t;
    
    while(t--) {
        
        int n,k;
        
        cin >> n >> k;
        
        int arr[k][n];
        
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }

        int mat[n+1][n+1];
        memset(mat,0,(n+1)*(n+1)*sizeof(int));
        
        vector< set<int> > v(n+1, set<int>());
        
        
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                v[arr[i][j]].insert(n-j-1);
            }
        }
        
        map<int, vector<int>, greater<int> > m;
        
        for(int i = 1; i <= n; i++) {
            set<int>::iterator it = v[i].end();
            it--;
            m[*it].push_back(i);
        }
        
        queue<int> q;
        map<int, vector<int> >::iterator it1 = m.begin();
        map<int, vector<int> >::iterator it2 = m.begin();
        it2++;
        int indegree=0;
        indegree+=(it1->second.size());
        // cout<<it1->second.size()<<endl;
        // cout<<it1->first<<endl;
        
        for(; it2!= m.end(); it2++,it1++) {
            vector<int> &vec1=(it1->second);
            vector<int> &vec2=(it2->second);
            vector<int>::iterator vit1=vec1.begin();
            vector<int>::iterator vit2=vec2.begin();
            // cout<<(*vit1)<<" "<<(*vit2)<<"\n";
            
            while( (vit1 != vec1.end()) && (vit2 != vec2.end())){
                // cout<<count<<" ";
                mat[*vit1][*vit2]=1;
                vit1++;
                vit2++;
            }
            
            for(;vit1!=vec1.end();vit1++){
                q.push(*vit1);
            }
            indegree+=((vec2.end()-vit2));
           
            for(;vit2!=vec2.end()&&(!q.empty()) ;vit2++){
                int x=q.front();
                mat[x][*vit2]=1;
                q.pop();
                
                
            }
            
            
            
            
            
        }
        
        vector<int>::iterator it4=it1->second.begin();
      
        
        while( (!q.empty())  ) {
            if(it4==it1->second.end()){
                
                it4=it1->second.begin();
                
            }else{
                it4++;
            }
            int x=q.front();
            q.pop();
            mat[x][*it4]=1;
        }
        
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         cout<<mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        cout<<indegree<<"\n";
        
        
        for(int i=1;i<=n;i++){
            bool flag=true;
            for(int j=1;j<=n;j++){
                // cout<<mat[i][j]<<" ";
                if(mat[i][j]==1){
                    cout<<j<<" ";
                    flag=false;
                    break;
                    
                    
                }
            }
            if(flag){
                cout<<0<<" ";
            }
        }
        cout<<"\n";
        
        
        
    }
    
    
    
    
    return 0;
}


