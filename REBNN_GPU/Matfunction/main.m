%Initialisation for time period of simulation
time=10;
sample_frequency= 1000;  % in Hz
u1=[1 2 3];
learning_rate=0.01;
%Intialisation ends here

sample_period= 1/sample_frequency;

iteration= time * sample_frequency; 
input_ph=0;
sin_holder=[];
resonator_holder=[];
for i = 1: iteration 
   
   sin_fn=sin(input_ph); 
   
   [rezo_ph,Fn]=rezonator(sin_fn);
   sin_holder=[sin_holder sin_fn];
   resonator_holder=[resonator_holder rezo_ph];
   input_ph=input_ph+sample_period; 
   
   
end