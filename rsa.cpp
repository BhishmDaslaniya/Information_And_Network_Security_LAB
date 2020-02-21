#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll randInRange(ll low, ll high){
    // excluding high and low
    return rand()%(high-(low+1)) + (low+1) ;
}

// ll gcd(ll a, ll b){
//     return b==0 ? a : gcd(b, a%b);
// }

ll powermod(ll a, ll b, ll n){
    ll res = 1;
    for(ll i=0; i<b; i++)
    {
        res = (res*a) % n;
    }
    return res;
}

// C = M^e mod n    [ public key = {e, n} ] 
int encrypt(int M, ll e , ll n) {
    return powermod(M, e, n);
}

// M = C^d mod n  [ private key = {d, n} ]
int decrypt(int C, ll d , ll n){
    return powermod(C, d, n);
}


int main(){
	ll p, q;
	cout<<"Enter two prime number p and q : ";
	cin>>p>>q;
	ll n = p * q;
	ll phi = (p-1) * (q-1);
	ll e,d;
	do{
		e = randInRange(1,phi);
	}while(__gcd(e,phi) != 1);

	for(d = 1 ; d < phi ; d++){
		if((d*e)%phi == 1){
			break;
		}
	}

	// public key = {e, n}
	cout<<"public key = {"<<e<<", "<<n<<"}"<<endl;
	// private key = {d, n}
	cout<<"private key = {"<<d<<", "<<n<<"}"<<endl;

	ll M ,C ,P;
	cout<<"Enter message in decimal (M < " << p*q <<"): ";
	cin>>M;

	C = encrypt(M, e, n);
	cout<<"Encrypted Text : "<<C<<endl;

	P = decrypt(C ,d ,n);
	cout<<"Plain Text [after decrypted] : "<<P<<endl;
	
}