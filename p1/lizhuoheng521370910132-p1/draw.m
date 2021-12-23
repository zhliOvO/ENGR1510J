function draw(n,w)
  axis equal;
  BackColor=[0.83 0.83 0.83];
  set(gca,'color',BackColor);
  plot([w,w],[2*n+w,w],'black');hold on;
  plot([-w,-w],[2*n+w,w],'black');hold on;
  plot([w,w],[-2*n-w,-w],'black');hold on;
  plot([-w,-w],[-2*n-w,-w],'black');hold on;
  plot([2*n+w,w],[w,w],'black');hold on;
  plot([2*n+w,w],[-w,-w],'black');hold on;
  plot([-2*n-w,-w],[w,w],'black');hold on;
  plot([-2*n-w,-w],[-w,-w],'black');hold on;
  plot([-2*n-w,0],[0,0],'y--');hold on;
  plot([2*n+w,0],[0,0],'y--');hold on;
  plot([0,0],[2*n+w,0],'y--');hold on;
  plot([0,0],[-2*n-w,0],'y--');hold on;
end

