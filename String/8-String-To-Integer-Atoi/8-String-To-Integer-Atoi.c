int myAtoi(char* s) {
    int i=0,flag=1;
    long num=0;
    while(s[i]==' ')
    {
        i++;
    }

        if(s[i]=='-'||s[i]=='+')
        {
           
           if(s[i]=='-')
            flag=-1;
            i++;
            
        }

    while(s[i]<='9'&&s[i]>='0')
    {
        if((flag==1) && (INT_MAX < num*10 + s[i] - '0')){
                    return INT_MAX;
                }else if((flag==-1) && (-1*num*10 - s[i] + '0' < INT_MIN)){
                    return INT_MIN;
                }
       num=num*10+ s[i]-'0';
       i++;
    }
    if(flag==-1)
    {
        num=flag*num;

    }
    return num;
}