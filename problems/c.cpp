#include <bits/stdc++.h>

using namespace std;

bool arr[1000002];

vector <int> primos;

void generacriba(int lim){
    for(int i=2;i<=sqrt(lim);i++){
        if(!arr[i]){

            for(int j=i;j<=(lim/i);j++){
                arr[i*j]=1;
            }
        }
    }
    for(int i=2;i<=lim;i++){
        if(!arr[i])primos.push_back(i);
    }

}

int busca(int k, bool tipo){ //tipo=1 mayor, tipo=0 ->menor
    int ini=0,fin=primos.size()-1;
    int mid;
    if(k>=primos[fin])return fin;

    while(ini<fin){
        mid=(fin+ini)/2;

        if(primos[mid]<k){
            ini=mid+1;
        }else {
            fin=mid;
        }
    }

    if(tipo){
        return ini;
    }else {

        if(primos[ini]==k)
            return ini;
        else
            return ini-1;
    }

}
int main()
{
    vector <pair<int, int>> casos;
    int t,x,y,mayor=0,m,q, a,b;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>x>>y;
        mayor=max(mayor,y);
        casos.push_back(pair<int,int>(x,y));
    }
    generacriba(mayor);

    for(int i=0;i<casos.size();i++){
        //cout<<casos[i].first<<" "<<casos[i].second<<endl;
        //for(int h=1;h<=casos[i].second;h++)cout<<arr[h]<<" "<<h<<endl;

        if(casos[i].first==casos[i].second && casos[i].first==1){
            cout<<0<<endl;
        }else{
            if(casos[i].first==casos[i].second && arr[casos[i].first]==true){
                cout<<0<<endl;
            }
            else{
                a=busca(casos[i].first,1);
                b=busca(casos[i].second,0);
                cout<<b-a+1<<endl;
            }
        }


    }
    //cin>>m>>q;
    //cout<<busca(m,q);

    return 0;
}