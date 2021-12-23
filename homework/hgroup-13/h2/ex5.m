n=input('');
while 1
    s=num2str(n);
    digits=s-'0'; %take out each digit
    l=length(s); 
    sum=0;
    for i=1:1:l
        sum=sum+power(digits(i),l); %add up
        if sum>n  %prunning (to cost less time)
            break;
        end
    end
    if sum==n %check
        disp(n);break;
    end
    n=n+1;
end
