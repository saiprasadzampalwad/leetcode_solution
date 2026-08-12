double myPow(double x, int n) {
    double ans=1;
    
     if(n>0)
    {
        if (x==1)
    {
        return 1;
    }if (x==-1)
    {
        return -1;
    }
        for(long i=1;i<=n;i++)
        {
            ans=x*ans;
        }
        return ans;
    }
    else{
         if (x==1)
    {
        return 1;
    }
        if (x==-1)
    {
        return 1;
    }
    
        for(long i=n;i<0 ;i++)
        {
            ans=x*ans;

            if(1/ans==0)
            {
                return 0;
            }
        }
        ans=1/ans;
        return ans;
    }
}