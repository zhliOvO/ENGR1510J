% algorithm is in the README
clear,clc
format longg
f=input('');
interval=input('');
x1=interval(1);x2=interval(2);
disp(round(bisection(f,x1,x2),3))
function root=bisection(f,x1,x2)
x3=(x1+x2)/2;
if abs(f(x3))<=0.0001
    root=x3;% to check if x3 is the root
    return
end
if f(x1)*f(x3)<0
    root=bisection(f,x1,x3);
elseif f(x2)*f(x3)<0
    root=bisection(f,x2,x3);% determine which two signs are different
end
end

        
        