class Solution {
public:

 

    double myPow(double x, int n) {
        long long new_n =n;
        if(n<0)
           new_n= new_n*=-1;
    double ans=1.0 ;
    while(new_n!=0){
        if(new_n%2)
         { ans*=x;new_n--;   }
        else{
        x*=x ;
        new_n/=2 ;
           }
    }
     if(n<0)
        return 1/ans ;
return ans ;      



    }

};