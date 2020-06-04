%% Initialisation for simulation
tic;
time=10;
sample_frequency= 1000;  % in 1/Hz

%inputs to Nueral network
u2=1;
learning_rate=0.01;
training=1;
%inital state of system 
y0=[0;0];                % inital position(theta,theta_dot)
%input signal 
input_freq= 1 ;           % in rad/sec
amplitude=3.8  ;          % amplitude of sine wave

%intialising buffer
dif_ip=0;
rbnn_output=0;
%Intialisation ends here

%% Dynamics System simulation 
tspan=0:(1/sample_frequency):(time*input_freq); 
ft=tspan;
f= 3.8*sin(tspan);
[t,y]=ode45(@(t,y)pend_test(t,y,ft,f),tspan,y0);
sample_period=1/sample_frequency;
theta=y(:,1);
theta_dot=y(:,2);

%%
iteration= time * sample_frequency; 
input_ph=0;
sin_holder=[];
resonator_holder=[];
y_rbnn=[];

for i = 1: iteration 
    
    sin_fn=3.8*sin(input_ph);
    [rezo_ph,Fn]=rezonator(sin_fn);
    [output_difference_vector,output_fft]= difBuffer(dif_ip,rbnn_output);
    u1=output_fft ; df= output_difference_vector;
    nn_op= NN(u1,df,Fn,u2,learning_rate,training);
    freq_char=nn_op; dft= Fn;
    yn=transpose(freq_char)*dft;
   
  
   
   
   
   sin_holder=[sin_holder sin_fn];
   resonator_holder=[resonator_holder rezo_ph];
   y_rbnn=[y_rbnn yn];
   
   
   
   input_ph=input_ph+sample_period; 
   %Update buffer code(to write)
   dif_ip=theta(i+1)-yn;
   rbnn_output=yn;
     
end

figure;plot(sin_holder);hold on; plot(resonator_holder) ;
figure; plot(theta);hold on; plot(y_rbnn) ;
toc;