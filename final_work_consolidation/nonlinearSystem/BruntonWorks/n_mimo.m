function dx= n_mimo(t,x,u)
 
 dx=[
     x(1)/(1+x(2)^2)+u(1);
     x(1)*x(2)/(1+x(2)^2)+u(2);
     ];
 