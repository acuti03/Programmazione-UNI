% Simone Acuti
% Programma che effettua la conversione conversione da base 10 a base b

function [] = conversioneBase()


num = input("Inserisci il numero da convertire: ");
base = input("Inserisci la base: ");

while base <= 1
    base = input("Inserisci la base: ");
end

int = fix(num);
frac = mod(abs(num),1);

outInt = 0;
if int ~= 0
    outInt = conversionInt(int, base);
end

outFrac = 0;
if frac > 0
    outFrac = conversionFrac(frac, base);
end

display(outInt);
display(outFrac);
end


function [out] = conversionInt(n, base)
i = 1;
tmp = n;
nElements = 0;
isNegative = 0;

% Elements to allocate in the array
while tmp ~= 0
    tmp = tmp / base;
    tmp = fix(tmp);
    nElements = nElements + 1;
end

out = string(zeros(1, nElements + 1));

% Check the sign of the number
if n < 0
    n = abs(n);
    isNegative = 1;
end

% Generations of the new number with the other base
while n ~= 0
    reminder = num2str(n - (fix(n / base) * base));
    
    out(nElements - (i - 2)) = reminder;
    n = fix(n / base);
    i = i + 1;
end

out(1) = '+';
if isNegative == 1
    out(1) = '-';
end
end

function [out] = conversionFrac(frac, base)

i = 1;

out = string(zeros(1, 10));

while i <= 10 && frac ~= 0
    int = fix(frac * base);
    frac = (frac * base - int);

    out(i) = num2str(int);
    i = i + 1;
end

end