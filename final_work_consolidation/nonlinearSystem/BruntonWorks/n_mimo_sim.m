hold on
 x0=[3; 1]; %initial condition
 dt= 0.001;
 u=[0 ; 0];
tspan=dt:dt:200;

%options=odeset('RelTol',1e-12,'AbsTol',1e-12*ones(1,3));
[t,x]= ode15s(@(t,x)n_mimo(t,x,u),tspan,x0);

plot(x(:,1),x(:,2),'w','LineWidth',1.5);
set(gca,'color','k','xcolor','w','ycolor','w');
set(gcf,'color','k')