fuzzyFIS = mamfis( ...
    'Name', 'Uses Binary MF', ...
    'NumInputs', 1, 'NumInputMFs', 3, ...
    'NumOutputs', 1, 'NumOutputMFs', 3, ...
    'AddRule', 'none' ...
    );


fuzzyFIS.Inputs(1).Name = "Preference of the Respondents";
fuzzyFIS.Inputs(1).Range = [0, 100];

labels = ["Hard Usability", "Moderate Usability", "Easy Usability"];
params = [0 0 28.33 33.33; 28.33 33.55 61.67 66.67; 51.75 66.67 100 100];
rsponse = [62.50, 56.25, 75, 56.25, 100];
disp(size(params, 1));

for i = 1:size(params, 1)
    % (cat 1)
    fuzzyFIS.Inputs(1).MembershipFunctions(i).Name = labels(i);
    fuzzyFIS.Inputs(1).MembershipFunctions(i).Type = 'trapmf';
    fuzzyFIS.Inputs(1).MembershipFunctions(i).Parameters = params(i,:);
end

% Plot Input MFs
figure('Name', 'User Usability - Preference', 'NumberTitle','off');
plotmf(fuzzyFIS, 'input', 1, 1000);
hold on
plot(rsponse, 0, 'black*');
hold off
set(findall(gca, 'Type', 'Line'), 'LineWidth', 3);