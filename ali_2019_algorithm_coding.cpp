/*
 * main.cpp
 *
 *  Created on: 2018年3月5日
 *      Author: customer
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;
double digui(int n, int m){
    if(n==1)
        return m;
    if(n==2){
        if (m<2)
            return 0.0;
        return (double)m*(m-1);
     }
    if(m==2)
    	  return 2.0;
    return m*pow(double(m-1), double(n-1))-digui(n-1, m);
}
int main(){
    int N, M;
    cin >> N >> M;
    int ans = 0;
    ans=(int)digui(N,M);
    printf("%d", ans);
    return 0;
}
