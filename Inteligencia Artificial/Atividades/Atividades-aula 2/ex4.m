b1= 0.5;
b2=1.0;
b3=5.0;
b4=20;
x = (-6:0.01:6);

y1= 1./(1+(exp(-b1*x)));

subplot(2,2,1)
plot(x,y1)
title('beta=0.5')

y2= 1./(1+(exp(-b2*x)));

subplot(2,2,2)
plot(x,y2)
title('beta=1.0')

y3= 1./(1+(exp(-b3*x)));

subplot(2,2,3)
plot(x,y3)
title('beta=5.0')

y4= 1./(1+(exp(-b4*x)));

subplot(2,2,4)
plot(x,y4)
title('beta=20')



