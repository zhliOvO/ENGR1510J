s=input('Please input a set of letters and numbers(No space):','s');  % a set of letters and numbers
n=1;l=length(s);
solve(s,n,l);
function  solve(s,n,l)
if n==l
    disp(s);
else
    for i=n:l
        t=s(n);s(n)=s(i);s(i)=t;
        solve(s,n+1,l);
        t=s(n);s(n)=s(i);s(i)=t;
    end
end
end
