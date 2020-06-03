function dy = pend(y,u)

m = 0.2;
L = 2;
g = 10;
b = 1;

Sy = sin(y(1));
D = m*L*L;

dy(1,1) = y(2);
dy(2,1) = (1/D)*(-m*g*L*Sy - b*y(1)) +(1/D)*u;
end
