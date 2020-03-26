function days = birthdayFunction(month, day)

months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
days = 0;

for i=1:month - 1
    days = days + months(i);
end

days = days + day;


% output = birthdayFunction(2, 12)
% output would be 43


% Feb 12 > daysSinceJan > 31 + 12
