/*
 * 
 * 
 * Copyright 2021 Tanishk <tanishktonk>
 * ........ ;)
 * 
 * 1. Output observed:
 * 
 * 		Average time for Naive Algorithm = 0.0172630000
 *
 *		Average time for Karatsuba algorithm = 0.1366010000
 *
 * 2. Time complexity:
 * 		
 * 		Naive Algorithm = O(n^2)
 * 		Karatsuba Algorithm = O(n^1.58)
 * 
 * 3. Inspite of having a better complexity than Naive algorithm.
 * 	  Karatsuba algorithm has much worse running time than the naive one.
 * 	
 */

#include <bits/stdc++.h>
#define ll long long int
#define fr(i,n) for(i=0;i<n;i++)
#define rng(i,a,b) for(i=a;i<b;i++)
#define T long long int T;cin>>T;while(T--)
#define ain(a,n) for(int zzz=0;zzz<n;zzz++){cin>>a[zzz];}
#define aout(a,n) for(int zzz=0;zzz<n;zzz++){cout<<a[zzz]<<" ";}cout<<"\n";
#define All(v) v.begin(),v.end()
#define dbg(v) cerr<<">-- "<<#v<<" = "<<v<<"\n";
#define PB push_back
#define MP make_pair
#define N "\n"
const int inf = ((int)1e9+3);
const int M97 = ((int)1e9+7);
using namespace std;

typedef vector<int> Vi;
typedef pair<int,int> Pii;

vector<int> add(vector<int> &a, vector<int> &b)
{
	int i, n = a.size(), m = b.size();
	vector<int> sum(max(m,n));
	
	for(i = 0; i < n; i++)
		sum[i] = a[i];
	for(i = 0; i < m ;i++)
		sum[i] += b[i];
	
	return sum;
}

vector<int> sub(vector<int> &a, vector<int> &b)
{
	int i, n = a.size(), m = b.size();
	vector<int> diff(max(m,n));
	
	for(i = 0; i < n; i++)
		diff[i] = a[i];
	for(i = 0; i < m ;i++)
		diff[i] -= b[i];
	
	return diff;
}

vector<int> polynomial_multiply(vector<int> &a, vector<int> &b)
{
	int i,j;
	int n = a.size();
	int m = b.size();
	vector<int> product(m+n-1);
	
	for(i = 0; i < n; i++)
		for(j = 0; j < m;j++)
			product[i+j] += (a[i]*b[j]);
	
	return product;
}

void treat(vector<int> &a, vector<int> &b)
{
	int i, n = a.size(), m = b.size();
	i = pow(2,ceil(log2(max(m,n))));
	while((int)a.size() < i) a.push_back(0);
	while((int)b.size() < i) b.push_back(0);
}

vector<int> polynomial_karatsuba(vector<int> &a, vector<int> &b)
{
	vector<int> ans;
	int i, n = a.size(), m = b.size();
	if(n == 1 && m == 1)
	{
		ans.push_back(a[0]*b[0]);
		return ans;
	}
	
	vector<int> a0,a1,b0,b1;
	for(i = 0; i < m/2; i++)
	{
		a0.push_back(a[i]);
		b0.push_back(b[i]);
		a1.push_back(a[i+m/2]);
		b1.push_back(b[i+m/2]);
	}
	
	auto a1b1 = polynomial_karatsuba(a1,b1);
	auto a0b0 = polynomial_karatsuba(a0,b0);
	auto a1_plus_a0 = add(a1,a0);
	auto b1_plus_b0 = add(b1,b0);
	auto a1b1_plus_a0b0 = add(a1b1,a0b0);
	auto a1_plus_a0_into_b1_plus_b0 = polynomial_karatsuba(a1_plus_a0,b1_plus_b0);
	auto mid_term = sub(a1_plus_a0_into_b1_plus_b0, a1b1_plus_a0b0);
	
	reverse(All(mid_term));
	reverse(All(a1b1));
	
	for(i = 0; i < n/2; i++)
		mid_term.push_back(0);
	for(i = 0; i < n; i++)
		a1b1.push_back(0);
	
	reverse(All(mid_term));
	reverse(All(a1b1));
	
	ans = add(a0b0, mid_term);
	ans = add(ans, a1b1);
	return ans;
}

ll i,j,k;

void solve()
{
	int t;
    t = 1;                           
    
    cout << setprecision(10) << fixed;
    int n = 1e3;
    cin >> n;
    srand(time(0));
    vector<int> a,b;
    int x,y;
	for(i = 0; i < n; i++)
	{
		x = rand()%100;
		y = rand()%100;
		
		if(rand()%5 == 0) x *= -1;
		if(rand()%5 == 0) x *= -1;
		
		a.push_back(x);
		b.push_back(y);
		
		//~cin >> a[i] >> b[i];
	}
    
    double total = 0;
    fr(i,t)
    {   
        clock_t start, end; 
        start = clock();
        
        //~cout << "Answer from Naive Algorithm = " ;
        auto product = polynomial_multiply(a,b);
        //~aout(product,(int)product.size())
        
        end = clock(); 
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
        total += time_taken;
    }
    
    double times = t;
    
    cout<< "Average time for Naive Algorithm = " << (double)(total / times) << N << N;

	total = 0;
	fr(i,t)
	{
		clock_t start, end; 
        start = clock();
        
        //~cout << "Answer from Karatsuba Algorithm = " ;
        treat(a,b);
        auto product = polynomial_karatsuba(a,b);
        while(product.back() == 0) product.pop_back();
        //~aout(product,(int)product.size())
        
        end = clock(); 
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
        total += time_taken;
	}
	
	times = t;
	
	cout<< "Average time for Karatsuba algorithm = " << (double)(total / times) << N << N;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	solve();
    
    return 0;
}
