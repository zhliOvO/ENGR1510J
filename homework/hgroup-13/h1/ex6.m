clear,clc
x=input('');
if ~isempty(x)
    y=input('','s');
else % in case nothing is inputed
    return
end
switch y % check which way to convert
    case 'stones to pounds'
    answer=14*x;
    case 'pounds to kg'
    answer=x/14*6.35;
    case 'kg to stones'
    answer=x/6.35;
    otherwise
    return
end
disp(answer)