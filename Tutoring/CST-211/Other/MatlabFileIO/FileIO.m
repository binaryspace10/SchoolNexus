%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%   Matlab File IO Program
%
%   - Ryan (binaryspace) K 
%
%   3/6/2020
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%mP = input('File Path of Matrix: ')
%vP = input('File Path of Vector: ')

matrix = csvread('C:\Users\binar\Documents\GitHub\SchoolNexus\Tutoring\CST-211\Other\MatlabFileIO\Matrix.csv', 1, 0);  % file, row, column
vector = csvread('C:\Users\binar\Documents\GitHub\SchoolNexus\Tutoring\CST-211\Other\MatlabFileIO\Vector.csv', 1, 0);  % file, row, column

disp(matrix)
disp(vector)

out = matrix * vector;

disp(out)

writematrix(out, 'Output.csv');

disp('Complete.')
