/*
	Author : Bhishm Daslaniya [17CE023] 
    "Make it work, make it right, make it fast." 
                                                – Kent Beck	
*/
#include<bits/stdc++.h>
using namespace std;

char mat[5][5];

typedef struct{
    int row;
    int col;
}position;


void MatrixGenerator(string key){
    //uniq = 0 -> letter is not present in matrix!
    //uniq = 1 -> letter is present in matrix!
    int uniq[26] = {0};
    int x = 0;
    int y = 0;
    
    //fill matrix with key characters!
    for(int i = 0 ; i < key.length();i++){
        if(key[i]== 'j'){
            key[i] = 'i';
        }
        if(uniq[key[i]-'a'] == 0){
            mat[x][y++] = key[i];
            uniq[key[i]-'a'] = 1;
        }
        if(y==5){
            x++;
            y = 0;
        }
    }

    // Add remaining characters in matrix!!!
    for(char c = 'a' ; c <= 'z' ; c++){
        if(c == 'j'){  
            continue;
        }
        if(uniq[c -'a'] == 0){
            mat[x][y++] = c;
            uniq[c -'a'] = 1;
        }
        if(y==5){
            x++;
            y = 0;
        }
    }
}

string formatMsg(string msg){
    for(int i=0; i < msg.length(); i++){
        if(msg[i] == 'j'){
            msg[i] = 'i';
        }
    }

    // pairing two characters! balloon -> ba lx lo on
    for(int i=1; i<msg.length(); i+=2){
        if(msg[i-1] == msg[i]){
            msg.insert(i, "x");
        }
    }

    if(msg.length()%2 !=0){
        msg += 'x';
    }

    return msg;
}

//Returns the position of the character!
position getPosition(char c){
    position p;
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(c == mat[i][j]){
                p = {i ,j};
            }
        }
    }
    return p;
}

string Encrypt(string message){
    string ctext = "";
    for(int i=0; i<message.length(); i+=2){
        // i is incremented by 2 inorder to check for pair values
		position p1 = getPosition(message[i]);
		position p2 = getPosition(message[i+1]);
        int x1 = p1.row; 
        int y1 = p1.col;
        int x2 = p2.row; 
        int y2 = p2.col;
        
        // same row
        if( x1 == x2 ) {
            ctext +=  mat[x1][(y1+1)%5];
            ctext +=  mat[x2][(y2+1)%5];
        }else if( y1 == y2 ){   // same column
            ctext += mat[ (x1+1)%5 ][ y1 ];
            ctext += mat[ (x2+1)%5 ][ y2 ];
        }else{
            ctext += mat[ x1 ][ y2 ];
            ctext += mat[ x2 ][ y1 ];
        }
    }
    return ctext;
}

string Decrypt(string message)
{
    string ptext = "";
    for(int i=0; i<message.length(); i+=2){
        // i is incremented by 2 inorder to check for pair values
        position p1 = getPosition(message[i]);
		position p2 = getPosition(message[i+1]);

        int x1 = p1.row;
        int y1 = p1.col;
        int x2 = p2.row; 
        int y2 = p2.col;
        
        // same row
        if( x1 == x2 ){
            ptext += mat[x1][ --y1<0 ? 4: y1 ];
            ptext += mat[x2][ --y2<0 ? 4: y2 ];
        }else if( y1 == y2 ){    // same column
            ptext += mat[ --x1<0 ? 4: x1 ][y1];
            ptext += mat[ --x2<0 ? 4: x2 ][y2];
        }else{
            ptext += mat[ x1 ][ y2 ];
            ptext += mat[ x2 ][ y1 ];
        }
    }
    return ptext;
}

int main(){ 
    string msg;
    cout<<"Enter message : ";
    // cin>>msg;
    getline(cin,msg);
    string key;
    cout<<"Enter Key : ";
    cin>>key;
    MatrixGenerator(key);
    cout<<": Matrix : \n";
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    } 
    cout<<"Original msg  : "<<msg<<endl;
    string formattedMsg = formatMsg(msg);
    cout<<"Formatted msg  : "<<formattedMsg<<endl;
    string cipher = Encrypt(formattedMsg);
    cout<<"Encrypted msg  : "<<cipher<<endl;
    string decrypted = Decrypt(cipher);
    cout<<"Decrypted msg  : "<<decrypted<<endl;
}