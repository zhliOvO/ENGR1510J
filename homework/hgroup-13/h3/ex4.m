clear,clc
n=input('');a=zeros(1,11);
fd=fopen('ex4.txt','w');
for i=0:10
    a(1,i+1)=n*i;
    fprintf(fd,'%s\n',[num2str(n) ' x ' num2str(i) ' = ' num2str(a(1,i+1))]);
end
fclose(fd);