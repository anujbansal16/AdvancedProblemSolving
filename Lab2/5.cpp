#include<bits/stdc++.h>
using namespace std;
typedef long long l;
//function to get the sum of intersting number for 1 to r;
l counting(l inum[],l r){
			l nn,temp=0,sum=0;
			for(l j=0;(j<2046)&&(r!=0);){
				if(inum[j]>=r){
					if((j-1)==-1){
						nn=r;
						r=0;
					}
					else{
						nn=(r-inum[j-1]);
						r=inum[j-1];	
					}
					sum+=nn*inum[j];
					j--;
				}	
				else
					j++;
			}
			return sum;
}
int main() {
	l a,b,two=2,ten=10,count=0,m,t,sum1,sum2;
	l inum[2046];//array of size 2046 containing all the interesting numbers from 1-7^9	
	inum[0]=4;
	inum[1]=7;
	//preprocessing to inizialize inum
	for(l i=2;count<9;i+=two){
		l m=i;
		for(l j=i;j<i+two;j++){
			m--;
			inum[j]=4*ten+inum[m];
			inum[j+two]=7*ten+inum[m];
		}		
		ten*=10;	
		two=two*2;
		count++;
	}
	sort(inum,inum+2046);
	//after sort we have 4,7,44,47,74,77,444....
	cin>>t;	
	while(t--){
		cin>>a>>b;
		sum1=counting(inum,b);
		sum2=counting(inum,a-1);
		sum1=sum1-sum2;
		cout<<sum1<<"\n";
	}
    return 0;
}

