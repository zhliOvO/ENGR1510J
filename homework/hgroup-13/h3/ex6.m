clear,clc
n=input('');
a=1;
f=fopen('ex6.txt','w'); %create a file
for i=1:2*n-3
      fprintf(f,' '); %set the space 
end
fprintf(f,'1\n');
for i=1:2*n-5
      fprintf(f,' '); %set the space 
end
fprintf(f,'1 1\n');
for i=2:n
  a=[a,0]+[0,a]; %calculate the numbers
  a(i)=1;
  if i~=2
      for j=1:2*(n-i)
         fprintf(f,' '); %set the space
      end
      fprintf(f,'%d ',a);fprintf(f,'\n');
  end
end
fclose(f); %close the file