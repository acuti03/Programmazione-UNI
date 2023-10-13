close all
clear all
clc

p=[3 -9 0 11 -pi 0 -2]';
x0=input('inserire il punto: x0=');
[r,q]=ruffini_horner(p,x0);
[r2,q2]=ruffini_horner(q,x0);
[r3,q3]=ruffini_horner(q2,x0);
fprintf('\n Valore del polinomio in x0=%g',r);
fprintf('\n Valore della derivata prima in x0=%g',r2);
fprintf('\n Valoere della derivata seconda in x0=%g',2*r3);