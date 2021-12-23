clear,clc
%Problem 1
x=[3;2;6;8];y=[4;1;3;5];
disp(x);disp(y);
%Problem 2
y(5,1)=sum(x);
disp(x);disp(y);
x=[3;2;6;8];y=[4;1;3;5];
%Problem 3
a=x.^y;
x=[3;2;6;8];y=[4;1;3;5];
disp(a);disp(y);
%Problem 4
b=y./x;
x=[3;2;6;8];y=[4;1;3;5];
disp(b);disp(x);
%Problem 5
x=[3;2;6;8];y=[4;1;3;5];
z=x.*y;
disp(x);disp(y);disp(z)
%Problem 6
z=x.*y;
w=sum(z);
x=[3;2;6;8];y=[4;1;3;5];
disp(z);disp(w);
%Problem 7
x=[3;2;6;8];y=[4;1;3;5];
z=x.*y;
w=sum(z);
disp(x);disp(y);disp(w);disp(x'*y-w);
% x'*y means multiplying each element in x by the corresponding element in
% y and add them up ,while w also means that, so the result is 0. 