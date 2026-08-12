int reverse(int x){
    int n,num=0;
while(x!=0)
{
    n=x%10;
    if(num>INT_MAX/10||num<INT_MIN/10)
    { 
        return 0;
    }
    x=x/10;
    num=num*10+n;
}
return num;

}