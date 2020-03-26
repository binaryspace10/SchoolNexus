% CST-211 Assignment
%

clear

% Reading .csv data
data = table2struct(readtable('C:\Users\binar\Documents\GitHub\SchoolNexus\Tutoring\CST-211\Other\MatlabStructuringData\EmployeeData.csv'));  % read in data and convert to struct

% Creating new structure, copying data as needed
records=struct('firstname',{data.firstname},'lastname',{data.lastname},'birthday', [],'salary', {data.salary} )

% Span the input structure to update the records structure with the calulated birthday data
for i=1:length(data)
    records(i).birthday=birthdayFunction(data(i).month,data(i).day);    
end

user_input = input('Please input first name of employee: ','s');

found = false;
td = clock;
today = birthdayFunction(td(2), td(3));
for i=1:length(records)
    if length(records(i).firstname) == length(user_input) & lower(records(i).firstname) == lower(user_input)
        found=true;
        disp(['Number of days until your Birthday: ', num2str(records(i).birthday-today)])
    end
end

if found == false
    disp(['There is no employee with the name: ', user_input])
end