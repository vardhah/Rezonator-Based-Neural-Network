function [output_difference_vector,output_fft] = difBuffer(dif_ip,rbnn_output)                      

 sz=32;                       % size of the dft 
 
 persistent a;
 persistent b;
 if isempty(b)
  b= zeros(1,sz);
 end
 if isempty(a)
  a= zeros(1,sz);
 end
 
 
  a= circshift(a,1);
  a(1)=dif_ip;
  b= circshift(b,1);
  b(1)=rbnn_output;

 output_difference_vector=a; 
 output_fft=1/sz*fft(b); 
end
