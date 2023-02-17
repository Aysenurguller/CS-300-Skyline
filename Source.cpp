#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "MPQ.h"

using namespace std;

struct building{
	int x;
	int h;
	string loc;
};

bool sortHeight(const building & a, const  building & b)
{

	if(a.x == b.x){

		if(a.loc==b.loc){

			if(a.loc=="l")
				return(a.h > b.h);
			else
				return (a.h < b.h);
		}
		else
			return (a.loc == "l");
	}
	else{
		return (a.x<b.x);
	}

}

vector<building> combinevectors(vector<building> &vec1,vector<building> &vec2,int total){
	vector<building>temp=vec1;
	for (int i=0;i<total;i++)
		temp.push_back(vec2[i]);
	int t=(total*2)-1;
	std::sort(temp.begin(),temp.end(),sortHeight);

	return temp;
}

int main(){
	ifstream input;
	vector<building> leftX;
	vector<building> rightX;
	MPQ mpq;

	input.open("input1.txt");
	int numBuilding, xleft, xright, height,i=0;
	input >> numBuilding;

	while (input >> xleft >> height >> xright){
		building temp1={xleft,height,"l"};
		building temp2={xright,height,"r"};
		leftX.push_back(temp1);
		rightX.push_back(temp2);
		i++;
		if(i==numBuilding)
			break;
	}

	vector<building> buildings=combinevectors(leftX,rightX,numBuilding);

	mpq.push(0);

	for(auto i : buildings){

		if(i.x!=0 && i.x == buildings[0].x){
			cout<<"0 0"<<endl;
		}

		if(i.loc=="l"){
			int a=mpq.GetMax();
			mpq.push(i.h);
			if(a<i.h)
				cout<<i.x<< " "<<i.h<<endl;
		}
		else {
			int b=mpq.GetMax();
			mpq.remove(i.h);
			int c=mpq.GetMax();
			if(b>c)
				cout<<i.x<< " "<<c<<endl;
		}
	}
	return 0;
}