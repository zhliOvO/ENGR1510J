clear,clc
n=input('');
if n==0
    disp('zero')
else
    disp(convert(n))
end
function s=convert(n)% s is a string and the final answer
a1=["", "one", "two", "three", "four","five", "six", "seven","eight", "nine","ten", "eleven", "twelve", "thirteen","fourteen","fifteen","sixteen", "seventeen", "eighteen", "nineteen"];
a2=["ten", "twenty", "thirty", "forty","fifty", "sixty", "seventy", "eighty", "ninety"];
if n<20
    s=a1(n+1);
elseif n<100
    ten=floor(n/10);num=mod(n,10);
    s=a2(ten)+' '+a1(num+1);
elseif n<1000
    if mod(n,100)~=0
        s=convert(floor(n/100))+' hundred and '+convert(mod(n,100));
    else
        s=convert(floor(n/100))+' hundred';w
    end
elseif n<1000000
    s=convert(floor(n/1000))+' thousand ';
    if mod(n,1000)~=0&&floor(mod(n,1000)/10)==0
        s=s+'and '+convert(mod(n,1000));
    else
        s=s+convert(mod(n,1000));
    end
elseif n<1000000000
    s=convert(floor(n/1000000))+' million ';
    if mod(n,1000000)~=0&&floor(mod(n,1000000)/10)==0
        s=s+'and '+convert(mod(n,1000000));
    else
        s=s+convert(mod(n,1000000));
    end
end
end


