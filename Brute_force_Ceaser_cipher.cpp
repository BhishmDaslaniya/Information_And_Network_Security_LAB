#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

string Encrypt(string text, ll key){
    string cipher = "";
    for(ll i = 0 ; i < text.length();i++){
        if(isupper(text[i])){
            cipher += (text[i] + key - 65)%26 + 65;
        }else if(islower(text[i])){
            cipher += (text[i] + key - 97)%26 + 97;
        }else{
            cipher += text[i];
        }
    }
    return cipher;
}


void Decrypt(string cipher){
    string text;
    for(ll i=0 ;i < 26 ; i++){
        text = "";
        for(int j=0;j<cipher.length();j++){
            if(isupper(cipher[j])){
                if((cipher[j] - i - 65)<0)
                    text += 91 +  (cipher[j] - i - 65);
                else
                    text += (cipher[j] - i - 65)%26 + 65;
                }
            else if(islower(cipher[j])){
                if((cipher[j] - i - 97) < 0)
                    text += 123 + (cipher[j] - i - 97);
                else
                    text += (cipher[j] - i - 97)%26 + 97;
                }
            else
                text += cipher[j];
            }
        cout << "[+] Key #" << i << " : " << text << endl;
        }
}

int main(){
    string s;
    cout<<"Enter String : ";
    // cin>>s;
    getline(cin,s);
    ll key;
    cout<<"Enter key for encryption: ";
    cin>>key;
    string cipher = Encrypt(s,key);
    cout<<"Cipher text : " + cipher <<endl;
    Decrypt(cipher);
    return 0;
}
