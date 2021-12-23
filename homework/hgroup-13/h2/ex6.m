date=input('');
convert(date)
function convert(date)
d=date(1);
if date(2)==1||date(2)==2
    m=10+date(2);
    date(3)=date(3)-1;
else
    m=date(2)-2;
end
y=mod(date(3),100);
c=floor(date(3)/100);
day=1+mod(d+floor((13*m-1)/5)+y+floor(y/4)+floor(c/4)-2*c,7);
switch day
    case 1 ;disp('Sunday')
    case 2 ;disp('Monday')
    case 3 ;disp('Tuesday')
    case 4 ;disp('Wednesday')
    case 5 ;disp('Thursday')
    case 6 ;disp('Friday')
    case 7 ;disp('Saturday')
end
end