#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

namespace ASD{
    template<typename T>
class Array{
private:
    T* arr;
    int N;
public:
    Array() {
        N = 1;
        arr = new T[N];
        for (int i = 0; i < N; i++)
            arr[i] = 0;
    }
    Array(int n){
        N = n;
        arr = new T[N];
        setrand();
    }

    ~Array(){ delete[]arr;}
    int getsize() { return N;}

    void setrand(){
        srand(time(0));
        for (int i = 0; i < N; i++)
            arr[i] = rand() % 100;
    }


    void sort(){
        int temp; 
        for (int i = 0; i < N; i++)
        {
            temp = arr[i]; 
            for (int j = i; j < N; j++)
                if (temp > arr[j])
                {
                    temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
        }
    }
    int Max(){
        sort();
        return arr[N - 1];
    }
    int Min(){
        sort();
        return arr[0];
    }

    T& operator [](int i) { return arr[i]; }
};
}