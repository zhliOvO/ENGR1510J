clear,clc
distance=input('');
r=rem(distance,400);% r means remainder
lap=(distance-r)./400;
left=400-r;% left means how long to go to complete a lap
if r==0
    disp(lap)
else
    disp(lap);disp(left);
end