function w=treinamento()
  m=load('treinamento.txt');
  [lin,col]=size(m);
  T=[-ones(lin,1) m(:,1:3)];
  d=m(:,4);

  %taxa de aprendizagem
  n=0.01;

  %contador de epoca
  epoca=0;

  %iniciar  vetor de pesos mais o limiar de ativação
  w=rand(col,1)
  erro=1;
  while erro
    erro=0;
    epoca=epoca+1;
    for k=1:lin
      x=T(k,:)';
      u=w'*x;

      %funcao sinal
      if u>=0
        y=1;
      else y=-1;
      endif
      %ajuste pesos- regra hebb
      if y~= d(k);
        w=w+ n*(d(k)-y)*x;
        erro=1;
      endif

    endfor
  endwhile
epoca
