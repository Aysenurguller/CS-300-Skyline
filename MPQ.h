#ifndef MPQ_h
#define MPQ_h

#include <iostream>
#include <bits.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>



class MPQ
{
public:
	int size(){return M.size();}
	int GetMax(){return M[0];}
	bool isEmpty(){
		if(size()==0){return true;}
		else{return false;}
	}

	void push(int i){
		M.push_back(i);
		int addedIndex = size()-1;
		percolateUp(addedIndex);
	}

	void remove(int i){
		for (int k= 0 ; k < size(); k++){
			if(M[k] == i ){
				int temp = M[size()-1];
				M[size()-1]= M[k];
				M[k] = temp;
				M.pop_back();
				percolateDown(0);
				break;
			}
		}	
	}

	MPQ();
	~MPQ();

private:
	std::vector<int> M;
	int PARENT(int i){return (i-1)/2;}
	int RIGHT(int i){return 2*i +2;}
	int LEFT(int i){return 2*i+1;}

	void percolateUp(int i){
		if(i && M[PARENT(i)]< M[i]){
			int temp = M[i];
			std::swap(M[i],M[PARENT(i)]);
			percolateUp(PARENT(i));
		}
	}

	void percolateDown(int i){
		int left = LEFT(i);
		int right = RIGHT(i);

		int max= i;
		if(left < size() && M[left]>M[i]){
			max= left;
		}
		if(right < size()&& M[right]>M[max]){
			max = right;
		}
		if (max != i){
			std::swap (M[i],M[max]);
			percolateDown(max);
		}

	}

};














#endif
