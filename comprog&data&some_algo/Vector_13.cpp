#include <iostream>
#include <vector>
using namespace std;
vector<string> split(string line, char delimiter) {
        vector<string> v ;
        for(int i =0 ; i< line.length() ; i++ ){
            string s = "";
            if( line[i] != delimiter ){
                while( line[i] != delimiter && i< line.length() ){
                    s += line[i];
                    i++;
                }
                v.push_back( s ); 
                s="";
            }
        }
        return v ;


}
int main() {
    string line;
    getline(cin, line);
    string delim;
    getline(cin, delim);
    for (string e : split(line, delim[0])) {
    cout << '(' << e << ')';
    }
}
