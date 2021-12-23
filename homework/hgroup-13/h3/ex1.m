clear,clc
a=[];
d=1;%digits
a(1)=1;
for i=1:64 %calculate 2^64
    k=0;
    for j=1:d
        a(j)=a(j)*2+k; %calculate it in digits
        k=floor(a(j)/10); 
        a(j)=mod(a(j),10); 
    end
    if k>0
        d=d+1;
        a(d)=k; 
    end
end
for i=1:d-1
    fprintf('%d',a(d-i+1)); %the numbers are in an inverted order
end
fprintf('%d',a(1)-1); %the last digit