typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plp;
typedef pair<pll,ll> ppl;
typedef vector<pll> vpll;
typedef vector<vll>vvll;
typedef complex<long double> point;
typedef pair<point, point> line;
typedef pair<double , point> circle;
typedef priority_queue<ll,vector<ll>,greater<ll>> pq;

const double EPS = 1e-9;
const int INF = 1000000000;
const int MAX = 50001;
const int oo= 0x3f3f3f3f;
const double infd = 1.0/0.0;

#define pia 3.14159265358979323846264338327950
#define Pip acos(-1.0)
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define fdp(x) cout<<std::fixed <<std::setprecision(2)<<(x);
#define i64 long long
#define sz(x) ((ll)(x).size())
#define F first
#define S second
#define pb(f) push_back(f)
#define pob(f) pop_back(f)
#define mkp(a,b) make_pair(a,b)
#define X real()
#define Y imag()
#define polar(r,t) ((r)* exp(point(0,(t))))
#define length(a) hypot( (a).X , (a).Y )
#define angle(a) atan2( (a).Y , (a).X )
#define vec(a,b) ( (b) - (a) )
#define dot(a,b) (conj(a)*(b)).X
#define cross(a,b) (conj(a)*(b)).Y
#define lengthsqr(a) dot(a,a)
#define reflect(V,M) (conj((V)/(M)) * (M))
#define normalize(a)   ((a)/length(a))
#define ccw(a,b,c)   cross(vec(a,b) , vec(a,c)) > -eps
#define cosRule(a,b,c) (acos(((a)*(a)+(b)*(b)-(c)*(c))/(2*(a)*(b))))
#define cosDot(a,b) (acos(dot(a,b)/length(a)/length(b)))
#define rotate(v,t) ((v)*exp(point(0,t)))
#define rotateabout(v,t,a) (rotate(vec(a,v),t)+(a))
#define lb(v,val) lower_bound(v.begin(),v.end(),val)-v.begin()
#define ub(v,val) upper_bound(v.begin(),v.end(),val)-v.begin()
#define un(x) x.erase(unique(x.begin(),x.end()), x.end())
#define forf(i,a,b) for(ll i=a;i<=b;i++)
#define forr(i,b,a) for(ll i=b;i>=a;i--)
#define sorti(v) sort(v.begin(),v.end())
#define sortd(v) sort(v.begin(),v.end(),greater<int>())
#define lcm(a, b) ((a)*((b)/__gcd(a,b)))
#define fill(a,d) memset(a,d,sizeof(a))

//int dx[] = {+0,+1,+0,-1};
//int dy[] = {+1,+0,-1,+0};
//int dx[] = {-1,-1,-1,+0,+0,+1,+1,+1};
//int dy[] = {-1,+0,+1,-1,+1,-1,+0,+1};
//int dx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knight's Move
//int dy[]={-1,  1, -2,  2, -2,  2, -1,  1};  // Knight's Move
//ll powr(ll a,ll b){ll x=1,y=a;while(b>0){if(b%2==1)x=(x*y)%mod;y=(y*y)%mod;b=b/2;}return x;}
//ll fpow(ll n, ll k, ll p = mod) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
//ll inv(ll a, ll p = mod) {return fpow(a, p - 2, p);}

template <typename T> void scan(T &x) {T c = getchar_unlocked(); while(((c < 48) || (c > 57)) && (c!='-')) c = getchar_unlocked();
bool neg = false; if(c == '-') neg = true; x = 0; for(;c < 48 || c > 57;c=getchar_unlocked());for(;c > 47 && c < 58;c=getchar_unlocked()) x = (x*10) + (c - 48); if(neg) x = -x;}
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
 



int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
     
     int t;
     cin>>t;
     while(t--)
     {
         int n;
         cin>>n;
         ll v[n];
         ll p=1;
         for(int i=0;i<n;i++)
         {
             cin>>v[i];
             p=(p*v[i])%mod;
         }
         ll g=v[0];
         for(int i=1;i<n;i++)
         {
             g=__gcd(g,v[i])%mod;
         }
         ll ans=1;
         for(int i=1;i<=g;i++)ans=(ans*p)%mod;
         cout<<ans<<"\n";
     }
    
    return 0;
}


/*  
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
*/