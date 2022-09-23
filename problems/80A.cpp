#include <bits/stdc++.h>
#include <iostream>


bool isPrime(int number){
    int divided=1,res=0;
    do{
        if(number%divided==0){
            res++;
        }
        divided++;
    }while (divided<=number);
    if(res==2){
        return true;
    }else{
        return false;
    }
    
}

bool isNextPrime(int romans1stDay, int romans2ndDay){
    if(!isPrime(romans2ndDay))return false;
    int romansExpectation= romans1stDay;
    while (romansExpectation<= romans2ndDay)
    {
        romansExpectation++;
        if(isPrime(romansExpectation) && (romansExpectation<romans2ndDay)){
            return false;
        }
    }
    
    return true;
}


int main(int argc, char const *argv[])
{
    int romansOn1stDay, romansOn2ndDay;
    std::cin>>romansOn1stDay>>romansOn2ndDay;

    if(isNextPrime(romansOn1stDay,romansOn2ndDay)){
        std::cout<<"YES"<<std::endl;
    }else{
        std::cout<<"NO"<<std::endl;
    }
    return 0;
}
