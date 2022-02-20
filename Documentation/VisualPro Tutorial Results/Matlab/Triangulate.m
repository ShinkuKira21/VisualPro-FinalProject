fuzzyFIS = mamfis( ...
    'Name', 'Uses Binary MF', ...
    'NumInputs', 1, 'NumInputMFs', 3, ...
    'NumOutputs', 1, 'NumOutputMFs', 3, ...
    'AddRule', 'none' ...
    );


fuzzyFIS.Inputs(1).Name = "Security";
fuzzyFIS.Inputs(1).Range = [0, 50];

labels = ['A', 'B', 'C'];
params = [0 0 10 15; 10 15 25 30; 25 50 50 50];

disp(size(params, 1));

for i = 1:size(params, 1)
    % (cat 1)
    fuzzyFIS.Inputs(1).MembershipFunctions(i).Name = labels(i);
    fuzzyFIS.Inputs(1).MembershipFunctions(i).Type = 'trapmf';
    fuzzyFIS.Inputs(1).MembershipFunctions(i).Parameters = params(i,:);
end

% Plot Input MFs
plotmf(fuzzyFIS, 'input', 1, 1000);
set(findall(gca, 'Type', 'Line'), 'LineWidth', 3);