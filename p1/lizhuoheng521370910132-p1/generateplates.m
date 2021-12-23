function plate=generateplates
n=1;
al=['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'];
for i=1:6
    s(i)=al(randi(36));
end
solve(s,n);
function  solve(s,n)
  if n==6
    plate=s;return;
  else
    for i=n:6
        t=s(n);s(n)=s(i);s(i)=t;
        solve(s,n+1);
        t=s(n);s(n)=s(i);s(i)=t;
    end
  end
end
end

