#include <iostream>
#include <vector>
#include <string>
/*
 * Date: 23 Nov, 2020
 * Author: Uddeep Karki
 * Project: Crossword
 *
 * This is a program to simulate a checkers board. The program will diplay a board with pieces of the
 * opposing teams on it. It will ask for input for posn of piece, and the destination. This program will
 * loop until a win condition has been satisfied.
 *
 * 23 Nov:
 * Some things to implement
 * 1.Void method to display the board, and the pieces.
 * 2. Check if piece is present from initial input
 * 3. Check if destination is empty
 * 4. Loop the whole thing... or something similar
 */

using namespace std;
void displayErrMsg() {
    cout << "Please press enter to continue!" <<endl;
    cin.clear(); //clears error flag on cin
    cin.ignore(1000,'\n'); //ignores 1000 characters until \n character
    string temp;
    getline(cin , temp);
}
void display(vector<vector <int>> b) {

    cout<<endl;
    cout << " _________________________________" << endl;
    for(int i=0; i<8 ; i++) {

        cout<<" | ";
        for(int j = 0; j< 8; j++) {
            char c;
            switch(b[i][j]) {
                case -1:
                    c = 'w';
                    break;
                case -2:
                    c = 'W';
                    break;
                case 1:
                    c = 'b';
                    break;
                case 2:
                    c='B';
                    break;
                default:
                    c=' ';
                    break;
            }
            cout << c << " | " ;
        }
        cout<<"\n" << 8-i << "|";
        for(int j = 0 ; j < 8 ; j++) {
            cout<<"___|";
        }
        cout<<endl;
    }
    cout<<" ";
    for ( int j = 0 ; j<8 ;j++){
        char column = 'a' +j;
        cout << "  " << column << " " ;
    }
    cout <<endl;
}
vector<vector <int>> createBoard (){
    /*vector<vector <int>> t = {  //This was an easy way
            {  0, -1,  0, -1,  0, -1,  0, -1},
            { -1,  0, -1,  0, -1,  0, -1,  0},
            {  0, -1,  0, -1,  0, -1,  0, -1},
            {  0,  0,  0,  0,  0,  0,  0,  0},
            {  0,  0,  0,  0,  0,  0,  0,  0},
            {  1,  0,  1,  0,  1,  0,  1,  0},
            {  0,  1,  0,  1,  0,  1,  0,  1},
            {  1,  0,  1,  0,  1,  0,  1,  0}

    };
    */
    vector<vector<int>> t;
    for( int i = 0 ; i <8 ; i++) {
        vector <int> v;
        for( int j = 0 ; j < 8 ; j++) {
            if( i < 3) {
                v.push_back((-1)*((i+j)%2));
            }
            else if(i> 4) {
                v.push_back((i+j)%2);
            }
            else
                v.push_back(0);

        }
        t.push_back(v);
    }
    return t;
}
bool checkWin (vector <vector<int>> v) { //note simplify it to just check for one color ?
    int w, b;
    for(auto i: v ) {
        for ( auto j : i) {
            if (j<0)
                w++;
            if (j>0)
                b++;
        }
    }

    return (w==0 || b ==0);
}
bool checkValidSource ( int n, vector <vector<int>> v , int r , int c) {
    // check valid input within range
    if(!((r>=0 && r<8) && (c>=0 && c<8))) {
        cout << "The source position values are not in the range. Column are a-h, row are 0-7" <<endl;
        return false;
    }
    if(v[r][c]==0) { //check empty
        cout <<"The source position is empty."<<endl;
        return false;
    }
    //Check right piece
    if((n%2 == 0 && v[r][c] >0) || (n%2==1 && v[r][c] <0) )
        return true;
    else {
        cout << "Piece is wrong color" <<endl;
        return false;
    }

}
bool checkValidDestination( vector<vector<int>> v, int rS , int cS, int rD , int cD) {
    //Check if in range
    if(!((rD>=0 && rD<8) && (cD>=0 && cD< 8))) {
        //cout << "The source position values are not in the range. Column are a-h, row are 0-7" <<endl;
        return false;
    }
    //Check empty
    if(v[rD][cD] != 0) {
        //cout << "Destination is not empty." <<endl;
        return false;
    }
    int rM = rD - rS;
    int cM = cD - cS;
    //Now how do we check for the moves. depends on n, and 1, 1.
    switch(v[rS][cS] ) { // Can i replace this expression with an auto source = &v[rS][cS] ??
        case 1:
            if ( (rM==-1 && abs(cM)==1 )||
            ((rM==-2 && abs(cM)==2) && v[rS+(rM/2)][cS+(cM/2)] < 0) ) {
                return true;
            }
            break;
        case 2:
            if( (abs(rM)==1 && abs(cM)==1) ||
                    ((abs(rM)==2&& abs(cM)==2) && v[rS+(rM/2)][cS+(cM/2)] < 0 )) {
                return true;
            }
            break;
        case -1:
            if ( (rM==1 && abs(cM)==1 )||
                 ((rM==2 && abs(cM)==2) && (v[rS+(rM/2)][cS+(cM/2)] > 0)) ) {
                //cout << "Invalid Move. case -1" << endl;
                return true;
            }
            break;
        case -2:
            if( (abs(rM)==1 && abs(cM)==1) ||
                ((abs(rM)==2&& abs(cM)==2) && v[rS+(rM/2)][cS+(cM/2)] > 0 )) {
                //cout << "Invalid Move. case -2 ... " <<endl;
                return true;
            }
            break;
        default:
            cout << " How the fuck did you break it ? " << endl;
            return false;
    }
    return false;
}
void move ( int n, vector<vector<int>> &v, int rS , int cS, int rD , int cD) {
    //using bool to find jump and re do it ?

    int rM = rD - rS;
    int cM = cD - cS;
    //Now how do we check for the moves. depends on n, and 1, 1.
    switch(v[rS][cS] ) { // Can i replace this expression with an auto source = &v[rS][cS] ??
        case 1:
            if(((rM)==-1) && (abs(cM)==1)) { //because it can only move one way
                v[rS][cS] = 0;
                v[rD][cD] = 1;
            }
            if(((rM)==-2) && (abs(cM)==2)) { //because it can only move one way
                    v[rS][cS] = 0;
                    v[rS+(rM/2)][cS+(cM/2)] = 0;
                    v[rD][cD] = 1;

            }
            if(rD == 0)
                v[rD][cD] = 2;
            break;
        case 2:
            if((abs(rM)==1) && (abs(cM)==1)) { //because it can only move one way
                v[rS][cS] = 0;
                v[rD][cD] = 2;
            }
            if((abs(rM)==2) && (abs(cM)==2)) { //because it can only move one way
                //middle piece already checked...
                    v[rS][cS] = 0;
                    v[rS + (rM / 2)][cS + (cM / 2)] = 0;
                    v[rD][cD] = 2;


            }
            break;
        case -1:
            if(((rM)== 1) && (abs(cM)==1)) { //because it can only move one way
                v[rS][cS] = 0;
                v[rD][cD] = -1;
            }
            if(((rM)== 2) && (abs(cM)==2)) {
                    v[rS][cS] = 0;
                    v[rS+(rM/2)][cS+(cM/2)] = 0;
                    v[rD][cD] = -1;

            }
            if(rD == 7)
                v[rD][cD] = -2;
            break;
        case -2:
            if((abs(rM)==1) && (abs(cM)==1)) { //because it can only move one way
                v[rS][cS] = 0;
                v[rD][cD] = 2;
            }
            if((abs(rM)==2) && (abs(cM)==2)) {
                v[rS][cS] = 0;
                v[rS + (rM / 2)][cS + (cM / 2)] = 0;
                v[rD][cD] = 2;

            }
            break;
        default:
            cout << " How the fuck did you break it ? " << endl;
    }
}
bool checkMoves( vector <vector<int>> v , int r , int c) {
    vector <vector<int>> possibleMoves = {
            {1 , 1},{-1 , -1} , {-1, 1} ,{1, -1} ,
            {2, 2}, {-2, -2}, {-2 , 2} , {2, -2}
    };
    for( auto i: possibleMoves ) {
        if(checkValidDestination(v , r , c , r+ i[0] , c+i[1])) {
            return true;
        }
    }
    return false;
}
bool checkMovesAvailable(vector <vector<int>> v , int t) { // t if for whose turn. if 0
    for(int i = 0 ; i < 8 ; ++i) {
            for(int j = 0; j<8 ; ++j) {
                if(v[i][j] > 0 && t==0) {
                    if(checkMoves( v , i , j)) {
                        return true;
                    }
                }
                if(v[i][j] < 0 && t==1) {
                    if(checkMoves(v , i, j)) {
                        return true;
                    }
                }
            }
    }
    return false;
}

bool checkJumpsAvailable( vector<vector<int>> v , int r , int c) {
    vector <vector<int>> possibleJumps = {
            {2, 2}, {-2, -2}, {-2 , 2} , {2, -2}
    };

    for(auto i: possibleJumps) {
        if(checkValidDestination( v , r , c , r+i[0] , c+i[1])) {
            return true;
        }
    }
    return false;
}
bool checkAllJumps ( int t , vector <vector<int>> v , vector <vector<int>> &jSources ) {
    int jumpsAvailable = 0;
    for ( int i = 0 ; i <8 ; ++i) {
        for ( int j = 0 ; j < 8 ; ++j) {
            vector <int> temp;
            if( t == 0 ) {
                if ( v[i][j] >0) {
                    if(checkJumpsAvailable( v , i , j)) {
                        jumpsAvailable++;
                        temp.push_back(i);
                        temp.push_back(j);
                        jSources.push_back(temp);
                    }
                }
            }
            else {
                if ( v[i][j] < 0) {
                    if(checkJumpsAvailable( v , i , j)) {
                        jumpsAvailable++;
                        temp.push_back(i);
                        temp.push_back(j);
                        jSources.push_back(temp);
                    }
                }
            }
        }
    }
    return jumpsAvailable>0;
}
bool checkValidJumpSource (vector <vector<int>> v , int r , int c) {
    for(auto a: v) {
        if(r == a[0] && c == a[1]) {
            return true;
        }
    }
    return false;
}
int main() {
    // Create a 2 dimensional array to represent the pieces on the board.
    vector<vector<int>> m = createBoard();
    int n = 0; //turn timer . also black moves first
    while (checkWin(m) || checkMovesAvailable(m , (n%2))) {
        display(m);
        cout << endl;
        //Prompt move
        if(n%2 == 0)
            cout<< "B move"<<endl;
        else
            cout <<"W move"<<endl;

        int rowS, rowD  ;
        char columnS, columnD ;

        vector <vector<int>> jS;

        cout << "Enter position of piece : " << endl;
        //check validity of source position, if empty or right piece.
        //

        // jump available ?

        if (!((cin >> columnS>> rowS ) && checkValidSource(n , m , 8-rowS, columnS-'a'))) { //Checking input and source position
                cout << "Please enter the right source position." <<endl;
                displayErrMsg();
                continue;
        }

        if (checkAllJumps ( (n%2) , m , jS)) {

            // Take input and match against the jumpavailable. vector jS
            if( checkValidJumpSource(jS , 8-rowS , columnS-'a') ) {
                while(checkJumpsAvailable(m , 8-rowS , columnS - 'a')) {
                    display(m);
                    cout << "Jumping is mandatory. \n" <<
                            "Enter destination for the piece at " << columnS <<" " << rowS <<":" <<endl;
                    if((cin >> columnD >> rowD) && checkValidDestination( m , 8-rowS, columnS-'a' , 8-rowD, columnD-'a')
                    && (abs(rowD-rowS) == 2 && abs(columnD-columnS) == 2)) {
                        move(n ,m , 8-rowS , columnS-'a' , 8-rowD, columnD-'a');
                        // check if jump ? simple is rowS - rowD :)
                        rowS = rowD;
                        columnS = columnD;

                    }
                    else {
                        cout << "Please enter the right destination position." <<endl;
                        displayErrMsg();
                        continue;
                    }
                }
                n++;
                continue;
            }
            else {
                cout << "Jumps available for pieces the following pieces." << endl;
                //Display the mandatory source
                for ( auto x : jS) {
                    cout << char('a' + x[1]) << 8 - x[0] << '\t' << endl;
                }
                cout << "Jumping is mandatory. Please pick from one of the above positions." <<endl;
                displayErrMsg();
                continue;
            }
        }

        //Prompt for destination moves
        cout << "Enter destination position :" <<endl;

        if((cin >> columnD >> rowD) && checkValidDestination( m , 8-rowS, columnS-'a' , 8-rowD, columnD-'a')) {
            move(n ,m , 8-rowS , columnS-'a' , 8-rowD, columnD-'a');
            // check if jump ? simple is rowS - rowD :)
        }
        else {
            cout << "Please enter the right destination position." <<endl;
            displayErrMsg();
            continue;
        }
        n++;
    }
    if ( n%2 == 0) {
        cout << "W wins!" << endl;
    }
    else {
        cout << "B wins!" << endl;
    }
    return 0;
}
