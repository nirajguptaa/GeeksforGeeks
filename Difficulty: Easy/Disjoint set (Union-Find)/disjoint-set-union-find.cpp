/*Complete the functions below*/
int find(int par[], int x) {
    // add code here
    if(x==par[x]){
        return x;
    }else{
        return par[x]=find(par,par[x]);
    }
}

void unionSet(int par[], int x, int z) {
    // add code here.
    x=find(par,x);
    z=find(par,z);
    if(x!=z){
        par[x]=z;
    }
}