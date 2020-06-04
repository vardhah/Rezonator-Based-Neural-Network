function [nn_op]  = NN(u1,df,F,u2,learning_rate,training)
coder.extrinsic('gpuArray')
persistent w1 w2 w3;
persistent vy;
persistent g1 g2 g3;
persistent itr;
persistent J;
persistent del_w1 del_w2 del_w3;
persistent mult1 mult2 mult3;
persistent memory_alloc_flag;

persistent n;
persistent z1 z2 z3 an3;
%%
%%%%%%----------------------------------------------------------------------------%%%%%
%Hyper-parameter & other tunable part of code

M=32;   %declare batch size of training (It will also be equal to number of input in our case as we are using DFT)
E=1;    % size of external associative input

%layer declaration
layer_1=32;
layer_2=64;
layer_3=128;       % Output layer must match with number of rezonators declared in rezonator function

%learning rate. Currently reading from input pin 
alpha = learning_rate;

%others
input_layer =M+E;       %layer_0
output_layer=layer_3;

a=isempty(memory_alloc_flag);
if a==1
  memory_alloc_flag = 0;
end

% weight Intialisation 
if training==1 && function [nn_op]  = NN(u1,df,F,u2,learning_rate,training)
coder.extrinsic('gpuArray')
persistent w1 w2 w3;
persistent vy;
persistent g1 g2 g3;
persistent itr;
persistent J;
persistent del_w1 del_w2 del_w3;
persistent mult1 mult2 mult3;
persistent memory_alloc_flag;

persistent n;
persistent z1 z2 z3 an3;
%%
%%%%%%----------------------------------------------------------------------------%%%%%
%Hyper-parameter & other tunable part of code

M=32;   %declare batch size of training (It will also be equal to number of input in our case as we are using DFT)
E=1;    % size of external associative input

%layer declaration
layer_1=32;
layer_2=64;
layer_3=128;       % Output layer must match with number of rezonators declared in rezonator function

%learning rate. Currently reading from input pin 
alpha = learning_rate;

%others
input_layer =M+E;       %layer_0
output_layer=layer_3;

a=isempty(memory_alloc_flag);
if a==1
  memory_alloc_flag = 0;
end

% weight Intialisation 
if training==1
  if isempty(w1)  
    w1=randn(input_layer,layer_1)*0.1;
  end
  if isempty(w2)
       w2=randn(layer_1,layer_2)*0.1;
  end
  if isempty(w3)
       w3=randn(layer_2,layer_3)*0.1;
  end

elseif training==0 
     load('weights.mat');
end    
%%%%%---------------------------------------------------------------------------------%%%%%

%%

%synchronising clock
if isempty(n)
        n = 0; end
n=n+1;

%%
%Allocation of variables that will be used during runtime( one time execution code) 
if isempty(z1)
       z1= zeros(layer_1,1);
end
if isempty(z2)
       z2= zeros(layer_2,1);
end
if isempty(z3)
       z3= zeros(layer_3,1);
end
if isempty(an3)
       an3= zeros(layer_3,1);
end

if isempty(memory_alloc_flag)
        memory_alloc_flag = 0; 
end
if isempty(mult1)
       mult1=zeros(layer_1,layer_1*input_layer); 
end
if isempty(mult2)
       mult2=zeros(layer_2,layer_1*layer_2); 
end
if isempty(mult3)
       mult3=zeros(layer_3,layer_2*layer_3); 
end
if isempty(vy)
       vy=zeros(input_layer,M); 
end

if memory_alloc_flag==0
 %write memory allocation for looped code here.It runs once and store it in memory.  
 mult1=[];
 mult2=[];
 mult3=[];
  for iteration =1:layer_1
   mult1=[mult1;[zeros(1,(iteration-1)*input_layer) ones(1,input_layer) zeros(1,(layer_1-iteration)*input_layer)]];
  end
  for iterate=1:layer_2
   mult2=[mult2;[zeros(1,(iterate-1)*layer_1) ones(1,layer_1) zeros(1,(layer_2-iterate)*layer_1)]];
  end
  for iterate=1:layer_3
   mult3=[mult3;[zeros(1,(iterate-1)*layer_2) ones(1,layer_2) zeros(1,(layer_3-iterate)*layer_2)]];
  end
 %{
 for k= 1:input_layer
    for j = 1:M 
        if k<=(M/2)+1 && k>=1
            vy(k,j)=(1/M)*cos(pi*(M-j)*(k-1)/(M/2));
        elseif k<=M && k>=(M/2)+1
            vy(k,j)=-(1/M)*sin(pi*(M-j)*(k-1)/(M/2));
        elseif k>M
            vy(k,j)=0;     
        end
    end
 end
  %}
 memory_alloc_flag=1; 
end

%%
%============All other Initiaisation =========================>

%Initialisation of delta of weight storage
if isempty(del_w1)
    del_w1=zeros(1,input_layer*layer_1);
end
if isempty(del_w2)
    del_w2=zeros(1,layer_2*layer_1);
end
if isempty(del_w3)
    del_w3=zeros(1,layer_2*layer_3);
end

%Intialising iteration number & cost value. 
if isempty(itr)
    itr=0;
end
if isempty(J)
    J=0;
end


%gradient initialisation(in matrix form)
if isempty(g1)
    g1= zeros(M,input_layer*layer_1);   
end
if isempty(g2)
    g2= zeros(M,layer_1*layer_2);   
end
if isempty(g3)
    g3= zeros(M,layer_3*layer_2);   
end

%%
%Input vector creation code block
x_in = [real(u1(1:(size(u1,2)/2)+1)) imag(u1(1:(size(u1,2)/2)-1))];
v=transpose([x_in transpose(u2)]);

%v=transpose([u1' transpose(u2)]);
%%
%RBNN core vectorised algorithm implementation 

%--------------->forward propogation ------------>
if sum(1*(max(z3-5,0)>0),'all')==0
 z1=w1'*v ;
%a1=(1./(1+exp(-z1)));
%an1=(a1-0.5);
a1=max(z1,0)+0.1*min(0,z1);
z2=w2'*a1 ;
%z2=w2'*an1 ;
%a2=(1./(1+exp(-z2)));
%an2=(a2-0.5);
a2=max(z2,0)+0.1*min(0,z2);
%z3=w3'*an2 ;
z3=w3'*a2 ;
a3=(1./(1+exp(-z3)));
an3=(a3-0.5);

%-------------> Backward Propogation -------->

%calculation of Nv:
da3_z3=a3.*(1-a3)*10;
dn_a2=w3'.*repmat(da3_z3,1,layer_2);
%da2_z2=a2.*(1-a2);
da2_z2=(1*(a2>=0) + 0.1*((a2>=0)==0));
dn_z2= dn_a2.* repmat(transpose(da2_z2),output_layer,1);
dn_a1=dn_z2*w2';
%da1_z1=a1.*(1-a1); 
da1_z1=(1*(a1>=0) + 0.1*((a1>=0)==0));
dn_z1=dn_a1.*repmat(transpose(da1_z1),output_layer,1);
dn_v=dn_z1*w1';   %"This is Nv" 

%calculation of aD, A & B 
aD=transpose(F)*dn_v*vy;
A=[aD;eye(M-1) zeros(M-1,1)];
B=[transpose(F) ; zeros(M-1,size(F,1))]; 

%calculation of Nw(diff of N(v,w) wrt each weights)
dIn_3= da3_z3*transpose(a2);
dn_w3=repmat(dIn_3,1,layer_3).* mult3;

dIn_2= da2_z2*transpose(a1);
da2_w2=repmat(dIn_2,1,layer_2).* mult2;
dn_w2=dn_a2*da2_w2;

dIn_1= da1_z1*transpose(v);
da1_w1= repmat(dIn_1,1,layer_1).*mult1;
dn_w1=dn_a1*da1_w1;

%gradient updation
g3=A*g3+B*dn_w3;
g2=A*g2+B*dn_w2;
g1=A*g1+B*dn_w1;

%Training & updation only once in a batch(batch size=M,n=Overall counter) 
if mod(n,M)==0 && training==1 && sum(1*(max(z3-5,0)>0),'all')==0
    fprintf('Training')
    del_w1 =alpha*df*1*g1/M ;
    del_w2 =alpha*df*1*g2/M ;
    del_w3 =alpha*df*1*g3/M ;
    del_w_reshaped1= reshape(del_w1,[input_layer,layer_1]);
    del_w_reshaped2= reshape(del_w2,[layer_1,layer_2]);
    del_w_reshaped3= reshape(del_w3,[layer_2,layer_3]);
    w1=w1+ del_w_reshaped1;
    w2=w2+ del_w_reshaped2;
    w3=w3+ del_w_reshaped3; 
    itr=itr+1;
    J= sum(df.^2,'all')/(2*M);
end
end
%For logging & visulisation purpose


%NN output assignment
nn_op=an3;

if mod(n,100)==0 && training==1
    save('weights.mat','w1','w2','w3');
end
end




  if isempty(w1)  
    w1=randn(input_layer,layer_1)*0.1;
  end
  if isempty(w2)
       w2=randn(layer_1,layer_2)*0.1;
  end
  if isempty(w3)
       w3=randn(layer_2,layer_3)*0.1;
  end

elseif training==0 
     load('weights.mat');
end    
%%%%%---------------------------------------------------------------------------------%%%%%

%%

%synchronising clock
if isempty(n)
        n = 0; end
n=n+1;

%%
%Allocation of variables that will be used during runtime( one time execution code) 
if isempty(z1)
       z1= zeros(layer_1,1);
end
if isempty(z2)
       z2= zeros(layer_2,1);
end
if isempty(z3)
       z3= zeros(layer_3,1);
end
if isempty(an3)
       an3= zeros(layer_3,1);
end

if isempty(memory_alloc_flag)
        memory_alloc_flag = 0; 
end
if isempty(mult1)
       mult1=zeros(layer_1,layer_1*input_layer); 
end
if isempty(mult2)
       mult2=zeros(layer_2,layer_1*layer_2); 
end
if isempty(mult3)
       mult3=zeros(layer_3,layer_2*layer_3); 
end
if isempty(vy)
       vy=zeros(input_layer,M); 
end

if memory_alloc_flag==0
 %write memory allocation for looped code here.It runs once and store it in memory.  
 mult1=[];
 mult2=[];
 mult3=[];
  for iteration =1:layer_1
   mult1=[mult1;[zeros(1,(iteration-1)*input_layer) ones(1,input_layer) zeros(1,(layer_1-iteration)*input_layer)]];
  end
  for iterate=1:layer_2
   mult2=[mult2;[zeros(1,(iterate-1)*layer_1) ones(1,layer_1) zeros(1,(layer_2-iterate)*layer_1)]];
  end
  for iterate=1:layer_3
   mult3=[mult3;[zeros(1,(iterate-1)*layer_2) ones(1,layer_2) zeros(1,(layer_3-iterate)*layer_2)]];
  end
 %{
 for k= 1:input_layer
    for j = 1:M 
        if k<=(M/2)+1 && k>=1
            vy(k,j)=(1/M)*cos(pi*(M-j)*(k-1)/(M/2));
        elseif k<=M && k>=(M/2)+1
            vy(k,j)=-(1/M)*sin(pi*(M-j)*(k-1)/(M/2));
        elseif k>M
            vy(k,j)=0;     
        end
    end
 end
  %}
 memory_alloc_flag=1; 
end

%%
%============All other Initiaisation =========================>

%Initialisation of delta of weight storage
if isempty(del_w1)
    del_w1=zeros(1,input_layer*layer_1);
end
if isempty(del_w2)
    del_w2=zeros(1,layer_2*layer_1);
end
if isempty(del_w3)
    del_w3=zeros(1,layer_2*layer_3);
end

%Intialising iteration number & cost value. 
if isempty(itr)
    itr=0;
end
if isempty(J)
    J=0;
end


%gradient initialisation(in matrix form)
if isempty(g1)
    g1= zeros(M,input_layer*layer_1);   
end
if isempty(g2)
    g2= zeros(M,layer_1*layer_2);   
end
if isempty(g3)
    g3= zeros(M,layer_3*layer_2);   
end

%%
%Input vector creation code block
x_in = [real(u1(1:(size(u1,2)/2)+1)) imag(u1(1:(size(u1,2)/2)-1))];
v=transpose([x_in transpose(u2)]);

%v=transpose([u1' transpose(u2)]);
%%
%RBNN core vectorised algorithm implementation 

%--------------->forward propogation ------------>
if sum(1*(max(z3-5,0)>0),'all')==0
 z1=w1'*v ;
%a1=(1./(1+exp(-z1)));
%an1=(a1-0.5);
a1=max(z1,0)+0.1*min(0,z1);
z2=w2'*a1 ;
%z2=w2'*an1 ;
%a2=(1./(1+exp(-z2)));
%an2=(a2-0.5);
a2=max(z2,0)+0.1*min(0,z2);
%z3=w3'*an2 ;
z3=w3'*a2 ;
a3=(1./(1+exp(-z3)));
an3=(a3-0.5);

%-------------> Backward Propogation -------->

%calculation of Nv:
da3_z3=a3.*(1-a3)*10;
dn_a2=w3'.*repmat(da3_z3,1,layer_2);
%da2_z2=a2.*(1-a2);
da2_z2=(1*(a2>=0) + 0.1*((a2>=0)==0));
dn_z2= dn_a2.* repmat(transpose(da2_z2),output_layer,1);
dn_a1=dn_z2*w2';
%da1_z1=a1.*(1-a1); 
da1_z1=(1*(a1>=0) + 0.1*((a1>=0)==0));
dn_z1=dn_a1.*repmat(transpose(da1_z1),output_layer,1);
dn_v=dn_z1*w1';   %"This is Nv" 

%calculation of aD, A & B 
aD=transpose(F)*dn_v*vy;
A=[aD;eye(M-1) zeros(M-1,1)];
B=[transpose(F) ; zeros(M-1,size(F,1))]; 

%calculation of Nw(diff of N(v,w) wrt each weights)
dIn_3= da3_z3*transpose(a2);
dn_w3=repmat(dIn_3,1,layer_3).* mult3;

dIn_2= da2_z2*transpose(a1);
da2_w2=repmat(dIn_2,1,layer_2).* mult2;
dn_w2=dn_a2*da2_w2;

dIn_1= da1_z1*transpose(v);
da1_w1= repmat(dIn_1,1,layer_1).*mult1;
dn_w1=dn_a1*da1_w1;

%gradient updation
g3=A*g3+B*dn_w3;
g2=A*g2+B*dn_w2;
g1=A*g1+B*dn_w1;

%Training & updation only once in a batch(batch size=M,n=Overall counter) 
if mod(n,M)==0 && training==1 && sum(1*(max(z3-5,0)>0),'all')==0
    fprintf('Training')
    del_w1 =alpha*df*1*g1/M ;
    del_w2 =alpha*df*1*g2/M ;
    del_w3 =alpha*df*1*g3/M ;
    del_w_reshaped1= reshape(del_w1,[input_layer,layer_1]);
    del_w_reshaped2= reshape(del_w2,[layer_1,layer_2]);
    del_w_reshaped3= reshape(del_w3,[layer_2,layer_3]);
    w1=w1+ del_w_reshaped1;
    w2=w2+ del_w_reshaped2;
    w3=w3+ del_w_reshaped3; 
    itr=itr+1;
    J= sum(df.^2,'all')/(2*M);
end
end
%For logging & visulisation purpose


%NN output assignment
nn_op=an3;

if mod(n,100)==0 && training==1
    save('weights.mat','w1','w2','w3');
end
end



