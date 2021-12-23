clear,clc
disp('Welcome to the CrossRoad Game!');
disp('You have four difficulties to choose');
disp('1 for easy (Default), 2 for medium (Default), 3 for hard (Default), 4 for customize (Extra Input)');
mode=input('Please choose :');
if mode==1
    n=8;w=3;p=0;tu=0;g=5;o=0.8;r=5.8; %default
end
if mode==2
    n=14;w=4;p=0.1;tu=0;g=6;o=1;r=7; %default
end
if mode==3
    n=20;w=5;p=0.2;tu=0;g=7;o=1;r=8; %default
end
if mode==4
n=input('Please input the total number of cars n (4~30 recommended):');
w=input('Please input the width of the road w (4~8 recommended):');
p=input('Please input the probability that a car does not stop at the red light p (a decimal from 0 to 1):');
%tu=input('Please input the probability that a car turns left or right:');
tu=0;
g=input('Time for green light g (5~10 recommended):');
o=input('Time for orange light o (1~3 recommended):');
r=input('Time for red light r (6~13 recommended Better if r=g+o):');
end
g=g*10;o=o*10;r=r*10;
axis equal;
draw(n,w); %generate the crossroad
BackColor=[0.83 0.83 0.83]; 
set(gca,'color',BackColor); %change background color to grey
t1=rectangle('Position',[-5*w/4 3*w/4 w/2 w/2],'Curvature',[1,1]);t1.FaceColor='r';
t2=rectangle('Position',[3*w/4 3*w/4 w/2 w/2],'Curvature',[1,1]);t2.FaceColor='g';
t3=rectangle('Position',[3*w/4 -5*w/4 w/2 w/2],'Curvature',[1,1]);t3.FaceColor='r';
t4=rectangle('Position',[-5*w/4 -5*w/4 w/2 w/2],'Curvature',[1,1]);t4.FaceColor='g'; %draw the traffic lights
n1=randi(n-3);n2=randi(n-n1-2);n3=randi(n-n1-n2-1);n4=n-n1-n2-n3; %randomly generate the number of cars on each lane
pn1=zeros(1,n1);pn2=zeros(1,n2);pn3=zeros(1,n3);pn4=zeros(1,n4);
cr1=[];cr2=[];cr3=[];cr4=[];
clr1='r';clr2='g';clr3='g';clr4='r';
%initialize the cars
for i=1:n1
    ww=(randi(20)/100+1)*w;
    car1{i}=rectangle('Position',[-0.7*w n*w+(i-1)*w+(i-1)*w/3 0.4*ww ww],'FaceColor',[1 0.85 0.72],'EdgeColor',[0 0 0]);
end
for i=1:n2
    ww=(randi(20)/100+1)*w;
    car2{i}=rectangle('Position',[-(n)*w-(i)*w-(i-1)*w/3 -0.7*w ww 0.4*ww],'FaceColor',[0.9 0.9 0.98],'EdgeColor',[0 0 0]);
end
for i=1:n3
    ww=(randi(20)/100+1)*w;
    car3{i}=rectangle('Position',[0.3*w -(n)*w-(i)*w-(i-1)*w/3 0.4*ww ww],'FaceColor',[0.5 1 0.83],'EdgeColor',[0 0 0]);
end
for i=1:n4
    ww=(randi(20)/100+1)*w;
    car4{i}=rectangle('Position',[n*w+(i-1)*w+(i-1)*w/3 0.3*w ww 0.4*ww],'FaceColor',[1 0.84 0],'EdgeColor',[0 0 0]);
end
xlim([-2*n-w,2*n+w]);
ylim([-2*n-w,2*n+w]);
t=0;
%the main loop begins
for t=1:n*30
    %time counts
    %the change of traffic lights
    for t=t
      if rem(t,g+o+r)<=g && rem(t,g+o+r)>0
        hold on;
        t1.FaceColor='g';clr1='g';
        t3.FaceColor='g';clr3='g';
        break;
      elseif rem(t,g+o+r)>g && rem(t,g+o+r)<=g+o
        hold on;
        t1.FaceColor='y';clr1='y';
        t3.FaceColor='y';clr3='y';
        break;
      elseif rem(t,g+o+r)<=g+o+r && rem(t,g+o+r)>g+o || rem(t,g+o+r)==0
        hold on;
        t1.FaceColor='r';clr1='r';
        t3.FaceColor='r';clr3='r';
        break;
      end
    end
    for t=t
      if rem(t+r,g+o+r)<=g && rem(t+r,g+o+r)~=0
        hold on;
        t2.FaceColor='g';clr2='g';
        t4.FaceColor='g';clr4='g';
        break;
      elseif rem(t+r,g+o+r)>g && rem(t+r,g+o+r)<=g+o
        hold on;
        t2.FaceColor='y';clr2='y';
        t4.FaceColor='y';clr4='y';
        break
      elseif rem(t+r,g+o+r)<=g+o+r && rem(t+r,g+o+r)>g+o || rem(t+r,g+o+r)==0
        hold on;
        t2.FaceColor='r';clr2='r';
        t4.FaceColor='r';clr4='r';
        break;
      end
    end
    %move the cars
    for t=t
        for i=1:n1
            rd=rand(); 
            if rand()<p && mod(t,20)==0 %mod 20 because it refreshes every 0.1 second
                pn1(i)=1; %decide whether the car jumps the red light
            else
                pn1(i)=0;
            end
            %straight
                if car1{i}.Position(2)>=w+0.5 ||  car1{i}.Position(2)<w
                    car1{i}.Position(2)=car1{i}.Position(2)-0.5;
                elseif (car1{i}.Position(2)>=w &&car1{i}.Position(2)<w+0.5) && ((clr1 =='g') || pn1(i)==1)
                    if pn1(i)==1
                             plt=generateplates(); %using recursion to generate the plates in another function
                             fprintf('Lane 1 Car %d Plate %s jumped the red light\n',i,plt);
                    end
                    car1{i}.Position(2)=car1{i}.Position(2)-0.5;
                else
                    car1{i}.Position(2)=car1{i}.Position(2);
                    break;
                end
        end
       for i=1:n2
            if rand()<p && mod(t,20)==0
                pn2(i)=1; %decide whether the car jumps the red light
            else
                pn2(i)=0;
            end
             %straight
                if car2{i}.Position(1)+w>-w ||  car2{i}.Position(1)+w<=-w-0.5
                    car2{i}.Position(1)=car2{i}.Position(1)+0.5;
                elseif (car2{i}.Position(1)<=-w-w && car2{i}.Position(1)>-0.5-w-w) && ((clr2 =='g') || (pn2(i) == 1))
                    if pn2(i)==1
                             plt=generateplates(); %using recursion to generate the plates in another function
                             fprintf('Lane 2 Car %d Plate %s jumped the red light\n',i,plt);
                    end
                    car2{i}.Position(1)=car2{i}.Position(1)+0.5;
                else
                    car2{i}.Position(1)=car2{i}.Position(1);
                    break;
                end
       end
       for i=1:n3
           if rand()<p && mod(t,20)==0
                pn3(i)=1; %decide whether the car jumps the red light
            else
                pn3(i)=0;
            end
            %straight
                if car3{i}.Position(2)>-w-w || car3{i}.Position(2)<=-w-w-0.5
                    car3{i}.Position(2)=car3{i}.Position(2)+0.5;
                elseif (car3{i}.Position(2)<=-w-w &&car3{i}.Position(2)>-w-w-0.5) && ((clr3 =='g')||(pn3(i) == 1))
                    if pn3(i)==1
                             plt=generateplates(); %using recursion to generate the plates in another function
                             fprintf('Lane 3 Car %d Plate %s jumped the red light\n',i,plt);
                    end
                    car3{i}.Position(2)=car3{i}.Position(2)+0.5;
                else
                    car3{i}.Position(2)=car3{i}.Position(2);
                    break;
                end
       end
       for i=1:n4
            if rand()<p && mod(t,20)==0
                pn4(i)=1; %decide whether the car jumps the red light
            else
                pn4(i)=0;
            end
            %straight
                if car4{i}.Position(1)>=w+0.5 ||  car4{i}.Position(1)<w
                    car4{i}.Position(1)=car4{i}.Position(1)-0.5;
                elseif (car4{i}.Position(1)>=w &&car4{i}.Position(1)<w+0.5) && ((clr4 =='g') || (pn4(i)==1))
                    if pn4(i)==1
                             plt=generateplates(); %using recursion to generate the plates in another function
                             fprintf('Lane 4 Car %d Plate %s jumped the red light\n',i,plt);
                    end
                    car4{i}.Position(1)=car4{i}.Position(1)-0.5;
                else
                    car4{i}.Position(1)=car4{i}.Position(1);
                    break;
                end
       end
        %judge whether there are crashes
        crash=0;
        for i=1:n1
            for j=1:n2
               cr1=[car1{i}.Position(1) car1{i}.Position(2) 0.4*w w];
               cr2=[car2{j}.Position(1) car2{j}.Position(2) w 0.4*w];
               if rectint(cr1,cr2)>0 %judge the crash by calculating the shared area
                   crash=1;crashlane1=1;crashlane2=2;crashcar1=i;crashcar2=j; %record the crash and store the details
                   fprintf('Lane %d Car %d and Lane %d Car %d CRASHED!\n',crashlane1,crashcar1,crashlane2,crashcar2);
                   break;
               end
            end
            if crash==1
                break;
            end
        end
        if crash==0
        for i=1:n1
            for j=1:n4
               cr1=[car1{i}.Position(1) car1{i}.Position(2) 0.4*w w];
               cr4=[car4{j}.Position(1) car4{j}.Position(2) w 0.4*w];
               if rectint(cr1,cr4)>0 %judge the crash by calculating the shared area
                   crash=1;crashlane1=1;crashlane2=4;crashcar1=i;crashcar2=j; %record the crash and store the details
                   fprintf('Lane %d Car %d and Lane %d Car %d CRASHED!\n',crashlane1,crashcar1,crashlane2,crashcar2);
                   break;
               end
            end
            if crash==1
                break;
            end
        end
        end
        if crash==0
        for i=1:n2
            for j=1:n3
               cr3=[car3{j}.Position(1) car3{j}.Position(2) 0.4*w w];
               cr2=[car2{i}.Position(1) car2{i}.Position(2) w 0.4*w];
               if rectint(cr2,cr3)>0 %judge the crash by calculating the shared area
                   crash=1;crashlane1=2;crashlane2=3;crashcar1=i;crashcar2=j; %record the crash and store the details
                   fprintf('Lane %d Car %d and Lane %d Car %d CRASHED!\n',crashlane1,crashcar1,crashlane2,crashcar2);
                   break;
               end
            end
        end
        end
        if crash==0
        for i=1:n3
            for j=1:n4
               cr3=[car3{i}.Position(1) car3{i}.Position(2) 0.4*w w];
               cr4=[car4{j}.Position(1) car4{j}.Position(2) w 0.4*w];
               if rectint(cr3,cr4)>0 %judge the crash by calculating the shared area
                   crash=1;crashlane1=3;crashlane2=4;crashcar1=i;crashcar2=j; %record the crash and store the details
                   fprintf('Lane %d Car %d and Lane %d Car %d CRASHED!\n',crashlane1,crashcar1,crashlane2,crashcar2);
                   break;
               end
            end
            if crash==1
                break;
            end
        end
        end
    end
    xlim([-2*n-w,2*n+w]);
    ylim([-2*n-w,2*n+w]); %Set the background size
    pause(0.1);
end
close all;
