x= linspace (0,5*pi/2,500)

y1= sin(x);

subplot(2,2,1)
plot(x,y1)
ylabel('sen(x)')

y2= cos(x);
y3= 2 *sin(x).*cos(x);
y4= sin(x)/exp(x);

