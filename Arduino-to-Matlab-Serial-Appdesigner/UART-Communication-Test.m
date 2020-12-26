% Create serial object.
s=serial("COM5");

% Set values.
% Values below are the default values, normally you just need
% to change the baudrate.
 s.BaudRate = 9600;
 
% Open the serial object.
fopen(s);

disp("Serial connection opened.");

% Infinite loop to read incoming data.
% Input y to stop the loop.
% Press enter to continue receiving data.
try
    while s.status=="open"
        data=fgets(s); % Gets data sent by the serial every certain time.
        data=data(1:end-2); % Remove /r/n sent from Arduino using Serial.println.
        
        disp("Received: ");
        disp(data);
         
        command = input("Close the serial? ", "s");
        
        if command == "y"
            fclose(s);
        end
    end
catch ME
    disp(ME.message);
end

clear;
clc;

disp("Serial connection closed.");