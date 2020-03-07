a = input('Input Value for a ');
b = input('\nInput Value for b ');
c = 0;

disp(a)
disp(b)

for i=0:10
    c = a + b;
    a = b;
    b = c;
    disp(c)
end

disp('Complete.')





