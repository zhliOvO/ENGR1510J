x=input('');
n=floor(x/4)+1; %since p=4n+1 this can decrease the time cost
while 1
    p=4*n+1;
    ifsquare=0; %judge if p^2=a^2+b^2 is possible
    for i=1:1:floor(sqrt(p))
        if floor(sqrt(p-i*i))^2==p-i*i 
            ifsquare=1;a=i;b=floor(sqrt(p-i*i));break; %break can cut the abundant part
        end
    end
    if ifsquare==1 && isprime(p)
       formatSpec = '%d = %d^2 + %d^2'; %outputformat
       fprintf(formatSpec,p,a,b);
       break;
    end
    n=n+1;
end