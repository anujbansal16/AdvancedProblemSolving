#include<bits/stdc++.h>
using namespace std;
typedef long  l;
int x[3][3];
int fu(int a,int b,int c,int d,int e,int f,int g,int h,int i){
/*    cout<<a<<" "<<b<<" "<<c<<"\n";
    cout<<d<<" "<<e<<" "<<f<<"\n";
    cout<<g<<" "<<h<<" "<<i<<"\n\n";*/
    return (abs(x[0][0]-a)+abs(x[0][1]-b)+abs(x[0][2]-c)+abs(x[1][0]-d)+abs(x[1][1]-e)+abs(x[1][2]-f)+abs(x[2][0]-g)+abs(x[2][1]-h)+abs(x[2][2]-i));
}
int main() {
    ios::sync_with_stdio(false);
    int k=0,count=0,mn=10000;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin>>x[i][j];
    for (int a = 1; a <=9; a++){
        for (int b = 1; b <=9; b++){
            if(b==a) continue;
            for (int c = 1; c <=9; c++){
                if(c==a||c==b)continue;
                for (int d = 1; d <=9; d++){
                    if(d==a||d==b||d==c)continue;
                    for (int e = 1; e <=9; e++){
                        if(e==a||e==b||e==c||e==d)continue;
                        for (int f = 1; f <=9; f++){
                            if(f==a||f==b||f==c||f==d||f==e)continue;
                            for (int g = 1; g <=9; g++){
                                if(g==a||g==b||g==c||g==d||g==e||g==f)continue;
                                for (int h = 1; h <=9; h++){
                                    if(h==a||h==b||h==c||h==d||h==e||h==f||h==g)continue;
                                    for (int i = 1; i <=9; i++){
                                        if(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h)continue;
                                           if(a+b+c==15){
                                                if(d+e+f==15){
                                                    if(g+h+i==15){
                                                        if(a+d+g==15){
                                                            if(b+e+h==15){
                                                                if(c+f+i==15){
                                                                    if(a+e+i==15){
                                                                        if(c+e+g==15){
                                                                            mn=min(mn,fu(a,b,c,d,e,f,g,h,i));
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                           }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout<<mn;
    return 0;
}


