function [reconstructed_signal,Fn]   = rezonator(signalz)

persistent numberofrezonator;
persistent g c bfr_rezo_sm aft_delay dft_out;
persistent out signal_dif;
persistent n;
persistent memory_alloc_flag;


%assign the number of rezonator here. For configuring it for higher order
%rezonator  we need to change (1) 'numberofrezonaotor' variable
if isempty(numberofrezonator)
        numberofrezonator = 128;   %here 16 parallel rezonators
end
N=128;
%Initialisation of memory allocations/variables ====> 
if isempty(memory_alloc_flag)
        memory_alloc_flag = 0; 
end
if isempty(g)
       g=zeros(numberofrezonator,numberofrezonator,'like',0i); 
end
if isempty(c)
       c=zeros(numberofrezonator,numberofrezonator,'like',0i); 
end
if memory_alloc_flag==0
 for i=0:numberofrezonator-1
  for j= 0:numberofrezonator-1
   g(i+1,j+1)=1/numberofrezonator*(exp(-1i*2*pi*i*j/numberofrezonator));
   c(i+1,j+1)=(exp(1i*2*pi*i*j/numberofrezonator));
  end 
 end
 memory_alloc_flag=1;
end

g=gpuArray(g) ;
c=gpuArray(c);


%Initialisation of variables  =====> 
if isempty(n)
        n = 0;   
end 
if isempty(out)
  out=0+0i;
end
if isempty(signal_dif)
  signal_dif=0+0i;
end
if isempty(bfr_rezo_sm)
  bfr_rezo_sm=repmat(0+0i,numberofrezonator,1);
end
if isempty(aft_delay)
  aft_delay=repmat(0+0i,numberofrezonator,1);
end
if isempty(dft_out)
  dft_out=repmat(0+0i,numberofrezonator,1);
end

%creating cycle of rotation for selection of correct column of g & c.
cycle=mod(n,numberofrezonator);

%resonator core -----------------------------> 
dft_out=c(:,cycle+1).*aft_delay;
out= sum(dft_out,1);
signal_dif=signalz-out;
bfr_rezo_sm=g(:,cycle+1).*signal_dif;

%counting the counter
n=n+1;

% output assignment ------------------>
reconstructed_signal=real(out);
dft=aft_delay; 
%N=size(dft,1);
a=1:1:N/2-1;
b=N/2+1:1:N-1;
dft_trans=transpose(dft);
Fn=transpose([real(dft_trans(1)) 2*(real(dft_trans(2:N/2)).*cos(2*pi*a*n/N)-imag(dft_trans(2:N/2)).*sin(2*pi*a*n/N)) -1^n*real(dft_trans(N/2+1)) -2*(imag(dft_trans(N/2+2:N)).*cos(2*pi*b*n/N)+real(dft_trans(N/2+2:N)).*sin(2*pi*b*n/N))]);
%--------output assignment over----------<

%final updation of buffer ------>>>>>>>>>>>>
aft_delay= aft_delay+bfr_rezo_sm; 
end