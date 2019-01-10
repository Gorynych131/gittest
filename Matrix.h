#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix{
private:
	size_t N, M;
	double *matr;
public:

	Matrix(size_t n, size_t m){
		N = n;
		M = m;
		matr = new double[n*m];
		for(int i=0; i<n*m; i++){
			matr[i] = 0;
		}
	}

	~Matrix(){
		delete[] matr;
	}

	double &operator()(int i, int j){
		return matr[M*i + j];
	}

	void operator=(Matrix &rhs){
		if(N!=rhs.N || M!=rhs.M){
			throw -1;
		}
		else{
			for(int i=0;i<N;i++){
				for(int j=0; j<M;j++){
					matr[i*M + j] = rhs(i, j);
				}
			}
		}
	}

	double det() const{
		if(N!=M){
			throw -1;
		}
		else{
			if(N==2){
				return matr[0]*matr[3] - matr[1]*matr[2];
			}
			else{
				double s = 0;
				Matrix temp(N-1, N-1);
				for(int i=0;i<N;i++){
					for(int j=1; j<N;j++){
						for(int o=0; o<N; o++){
							if(o!=i){
								temp(j-1, o>i? o-1 : o) = matr[j*M + o];
							}
						}
					}
					s+= (i%2==0)? matr[i]*temp.det() : -matr[i]*temp.det();
				}
				return s;
			}
		}
	}

	/*Matrix dot(Matrix &rhs) const{
		if(M!=rhs.N){
			throw -1;
		}
		else{
			Matrix temp (N, rhs.M);
			for(int i=0; i<N;i++){
				for(int j=0; j<rhs.M; j++){
					for(int o=0; o<M; o++){
						temp(i, j)+=matr[i*M + o]*rhs(o, j);
					}
				}
			}
			return temp;
		}
	}*/


};

#endif
#include "stdafx.h"