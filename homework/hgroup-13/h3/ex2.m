clear,clc
axis equal;hold on
rectangle('position',[0 0 4 5]);
rectangle('position',[0.5 3 1 1]);
rectangle('position',[2.5 0 1 2]);
rectangle('position',[2.7 0.9 0.2 0.2],'curvature',[1 1]);
rectangle('position',[6 0.5 4 1]);
rectangle('position',[6.25 0 0.5 0.5],'curvature',[1 1]);
rectangle('position',[7 0 0.5 0.5],'curvature',[1 1]);
rectangle('position',[8.5 0 0.5 0.5],'curvature',[1 1]);
rectangle('position',[9.25 0 0.5 0.5],'curvature',[1 1]);
plot([-0.5 4.5],[5 5],'k');
plot([-0.5 2],[5 7],'k');plot([2 4.5],[7 5],'k');
plot([0.5 1.5] ,[3.5 3.5],'k');plot([1 1],[3 4],'k');
plot([6.5 7],[1.5 2.5],'k');plot([7 9],[2.5 2.5],'k');plot([9 9.5],[2.5 1.5],'k')
