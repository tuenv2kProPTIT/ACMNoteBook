#include <bits/stdc++.h>
#define N 100005

using namespace std;

struct Data{
	int beauty,price;
};

struct Data2{
	int id1,id2;
};

int n,X,Y,beauty,price,resx=1,resy=1,Maxx=0,Maxy=0,MAX=0,idmax1,idmax2;
char c;
Data datax[N],datay[N];
Data2 dataxx[N],datayy[N];

bool cmp(Data a,Data b){
	return a.price<b.price;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n>>X>>Y;
	for(int i=0;i<n;++i){
		cin>>beauty>>price>>c;
		if(c=='C'){
			datax[resx].beauty=beauty;
			datax[resx++].price=price;
		}
		else{
			datay[resy].beauty=beauty;
			datay[resy++].price=price;
		}
	}
	sort(datax+1,datax+resx,cmp);
	sort(datay+1,datay+resy,cmp);
	for(int i=1;i<resx;++i){
		if(X>=datax[i].price){
			Maxx=max(Maxx,datax[i].beauty);
		}
		else break;
	}
	for(int i=1;i<resy;++i){
		if(Y>=datay[i].price){
			Maxy=max(Maxy,datay[i].beauty);
		}
		else break;
	}
	if(Maxx&&Maxy) MAX=Maxx+Maxy;
	idmax1=1;
	idmax2=0;
	dataxx[1].id1=idmax1;
	dataxx[1].id2=idmax2;
	for(int i=2;i<resx;++i){
		if(datax[i].beauty>datax[idmax1].beauty){
			swap(idmax1,idmax2);
			idmax1=i;
		}
		else{
			if(datax[i].beauty>datax[idmax2].beauty){
				idmax2=i;
			}
		}
		dataxx[i].id1=idmax1;
		dataxx[i].id2=idmax2;
	}
	int i=1,j=resx-1;
	Maxx=0;
	while(1){
		while(datax[i].price+datax[j].price>X&&j>0){
			--j;
		}
		if(i<j){
			if(i!=dataxx[j].id1){
				Maxx=max(Maxx,datax[dataxx[j].id1].beauty+datax[i].beauty);
			}
			else{
				Maxx=max(Maxx,datax[dataxx[j].id2].beauty+datax[i].beauty);
			}
		}
		else break;
		++i;
	}
	MAX=max(MAX,Maxx);
	idmax1=1;
	idmax2=0;
	datayy[1].id1=idmax1;
	datayy[1].id2=idmax2;
	for(int i=2;i<resy;++i){
		if(datay[i].beauty>datay[idmax1].beauty){
			swap(idmax1,idmax2);
			idmax1=i;
		}
		else{
			if(datay[i].beauty>datay[idmax2].beauty){
				idmax2=i;
			}
		}
		datayy[i].id1=idmax1;
		datayy[i].id2=idmax2;
	}
	i=1;j=resy-1;
	Maxy=0;
	while(1){
		while(datay[i].price+datay[j].price>Y&&j>0){
			--j;
		}
		if(i<j){
			if(i!=datayy[j].id1){
				Maxy=max(Maxy,datay[datayy[j].id1].beauty+datay[i].beauty);
			}
			else{
				Maxy=max(Maxy,datay[datayy[j].id2].beauty+datay[i].beauty);
			}
		}
		else break;
		++i;
	}
	MAX=max(MAX,Maxy);
	cout<<MAX;
}
