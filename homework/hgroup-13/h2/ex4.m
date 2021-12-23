clear,clc
format longg
f=input('');
interval=input('');
precision=input('');
i=2;x=[];
root=solve1(f,interval,precision,i);
%root=solve2(f,interval,precision,i,x);
disp(root)
function root=solve1(f,interval,precision,i) %This is the iterative solution
x(1)=interval(1);x(2)=interval(2);
while i>=2
    if i==2
        if abs(f(x(1)))<1*10^(-precision-1)
            root=round(x(1),precision);
            break
        elseif abs(f(x(2)))<1*10^(-precision-1)
            root=round(x(2),precision);
            break
        end
    end   % to know whether x1,x2 is the root
    i=i+1;
    x(i)=(x(i-2)*f(x(i-1))-x(i-1)*f(x(i-2)))/(f(x(i-1))-f(x(i-2)));
    if abs(f(x(i)))<1*10^(-precision-1)
        break
    end
end
root=round(x(i),precision);
end

function root=solve2(f,interval,precision,i,x) %This is the  recursive solution
if i==2
    x(1)=interval(1);x(2)=interval(2);
    if abs(f(x(1)))<1*10^(-precision-1)
        root=round(x(1),precision);
        return
    elseif abs(f(x(2)))<1*10^(-precision-1)
        root=round(x(2),precision);
        return
    end    % to know whether x1,x2 is the root
end
if abs(f(x(i)))<10^(-precision-1)
    root=round(x(i),precision);
else
    i=i+1;
    x(i)=(x(i-2)*f(x(i-1))-x(i-1)*f(x(i-2)))/(f(x(i-1))-f(x(i-2)));
    root=solve2(f,interval,precision,i,x);
end
end
