#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int ry=3,rx=2,ly=3,lx=0;
    for(auto n : numbers){
        if(n==0||n%3==2){
            int ny=n/3, nx=1;
            if(n==0)ny=3;
            int dr=abs(ny-ry)+abs(nx-rx), dl=abs(ny-ly)+abs(nx-lx);
            if(dr>dl){answer+="L";ly=ny;lx=nx;}
            else if(dr<dl){answer+="R";ry=ny;rx=nx;}
            else{
                if(hand=="right"){answer+="R";ry=ny;rx=nx;}
                else{answer+="L";ly=ny;lx=nx;}
            }
        }
        else if(n%3==1){answer+="L"; ly=n/3;lx=0;}
        else{answer+="R";ry=n/3-1;rx=2;}
    }
    return answer;
}
