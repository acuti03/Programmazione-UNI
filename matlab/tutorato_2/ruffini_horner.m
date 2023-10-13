function [r,q]=ruffini_horner(p,a)
q(1)=p(1);
n=length(p)-1;
for i=2: n+1
    q(i)=q(i-1)*a+p(i);
end
r=q(n+1);
q=q(1:n);
end