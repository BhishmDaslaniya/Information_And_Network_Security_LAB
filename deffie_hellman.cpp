/*
	Author : Bhishm Daslaniya [17CE023] 
    "Make it work, make it right, make it fast." 
                                                – Kent Beck	
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll powermod(ll a, ll b, ll n){
    ll res = 1;
    for(ll i=0; i<b; i++)
    {
        res = (res*a) % n;
    }
    return res;
}

int main(){
    ll p,g;
    cout<<"Enter P (prime number) : ";
    cin>>p;
    cout<<"Enter G (primitive root of P) : ";
    cin>>g;
    ll a,b;
    cout<<"Enter Alice's private key : ";
    cin>>a;
    cout<<"Enter Bob's private key : ";
    cin>>b;

    ll publicKeyAlice = powermod(g,a,p);
    ll publicKeyBob = powermod(g,b,p);

    // Alice and Bob share their public key publibKeyAlice and publicKeyBob
    // Now from that generate secret key!

    ll Ka = powermod(publicKeyBob,a,p);
    ll Kb = powermod(publicKeyAlice,b,p); 

    cout<<"shared secretkey for Alice : "<<Ka<<endl;
    cout<<"shared secretkey for Bob : "<<Kb<<endl;
}