%ex3 max quantity of items and average age
clear,clc;
%initailize
item(1) = struct('Type','Jumpers','Color','Blue','Quantity',2,'Brought','04/2005');
item(2) = struct('Type','Jumpers','Color','Brwon','Quantity',3,'Brought','02/2013');
item(3) = struct('Type','Jumpers','Color','Green','Quantity',5,'Brought','01/2015');
item(4) = struct('Type','Trousers','Color','Black','Quantity',3,'Brought','06/2012');
item(5) = struct('Type','Trousers','Color','Grey','Quantity',2,'Brought','04/2011');
item(6) = struct('Type','Trousers','Color','White','Quantity',1,'Brought','12/2013');
item(7) = struct('Type','T-shirts','Color','Blue','Quantity',1,'Brought','05/2010');
item(8) = struct('Type','T-shirts','Color','Green','Quantity',2,'Brought','09/2014');
item(9) = struct('Type','T-shirts','Color','Red','Quantity',3,'Brought','01/2012');
item(10) = struct('Type','T-shirts','Color','White','Quantity',2,'Brought','03/2008');
item(11) = struct('Type','T-shirts','Color','Yellow','Quantity',1,'Brought','11/2012');

%the largest quantity
[max,i] = max([item.Quantity]);
disp(convertCharsToStrings(item(i).Type) +" " + convertCharsToStrings(item(i).Color));

%average age
age = 0;
for i = 1:1:11
   s = item(i).Brought;
   age = age + 2021 - str2double(s(4:end)); 
end
ageAverage = round(age/11);
disp(ageAverage);
%try mean


