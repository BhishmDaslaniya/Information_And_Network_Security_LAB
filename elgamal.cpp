#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long ll;
string msg;
ull p;

ull randInRange(ull low, ull high){
    // excluding high and low
    return rand()%(high-(low+1)) + (low+1) ;
}

ull powermod(ull a, ull b, ull n){
    ull res = 1;
    for(ll i=0; i<b; i++)
    {
        res = (res*a) % n;
    }
    return res;
}

ull get_key(ull q){
    ull key = randInRange(pow(10,5),q);
    while( __gcd(q,key) != 1 ){
        key =  randInRange(pow(10,5),q);
    }
    return key;
}

vector<ull> encrypt(ull q,ull h, ull g){
    vector<ull> en_msg;
    ull k = get_key(q);
    ull s = powermod(h,k,q);
    p = powermod(g,k,q);

    for(ll i = 0 ; i < msg.length() ; i++){
        en_msg.push_back(msg[i]);
    }

    cout<<"g^k  = "<<p<<endl;
    cout<<"g^ak = "<<s<<endl;

    for(ll i = 0 ; i < en_msg.size() ; i++){
        en_msg[i] = s * int(en_msg[i]);
    }

    return en_msg;
}

vector<char> decrypt(vector<ull> en_msg , ull key , ull q){
    vector<char> dec_msg;
    ull h = powermod(p,key,q);
    for(ll i = 0 ; i < en_msg.size() ;i++){
        dec_msg.push_back(char(int(en_msg[i] / h)));
    }
    return dec_msg;
}

int main(){
    
    cout<<"Enter message : ";
    cin>>msg;
    ull q = randInRange(pow(10,5),pow(10,15));
    ull g = randInRange(2,q); 
    ull key =  get_key(q);
    ull h = powermod(g,key,q);
    cout<<"g = "<<g<<endl;
    cout<<"g^a = "<<h<<endl;

    vector<ull> en_msg = encrypt(q,h,g);
    vector<char> dec_msg = decrypt(en_msg, key, q);

    string dmsg = "";
    for(ll i = 0 ; i < dec_msg.size() ; i++){
        dmsg+=dec_msg[i];
    }

    cout<<"Decrypted Message : "<<dmsg<<endl;
}