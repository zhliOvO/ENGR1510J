clear,clc
while true
    year=input('input a year(Please input nmbers):');
    if year>0 && mod(year,1)==0 %to ensure it is a digit
        break
    end
end
% The loop is to prompt the user for a correct input
if mod(year,4)==0
    if mod(year,100)~=0
        disp('It is a leap year');
    else
        if mod(year,400)==0
            disp('It is a leap year');
        else
            disp('It is a regular year')
        end
    end
else
    disp('It is a regular year')
end



