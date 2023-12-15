function y = teste (w)
  V=load('teste.txt');
  [lin,col]=size(V);
  V=[-ones(lin,1) V];

  for k=1:lin
    x=V(k,:)';
    u=w'*x;
    if u>=0
      y(k)=1;
    else
      y(k)=-1;
    end
  end
end
