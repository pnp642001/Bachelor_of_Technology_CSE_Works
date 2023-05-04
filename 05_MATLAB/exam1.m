clear all
close all
clc
a=15.62;
b=-7.08;
c=62.5;
d=0.5*((a*b)-c);
ans_a=a+((a*b)/c)*(((a+d)^2)/sqrt(abs(a*b)));
ans_b=(d*exp(d/2))+((((a*d)+(b*c))/((20/a)+(30/b)))/(a+b+c+d));
ans_c=(443*c)/(2*(a^3))+(exp(-a*b)/(a+b));
disp('a : ');
disp(ans_a);
disp('b : ');
disp(ans_b);
disp('c : ');
disp(ans_c);