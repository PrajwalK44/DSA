% --- Facts ---
soil_dry.
temperature(high).
raining(false).
pest_detected.

% --- Rules ---

% Rule: Start irrigation if soil is dry and not raining
start_irrigation :-
    soil_dry,
    raining(false).

% Rule: Stop irrigation if raining
stop_irrigation :-
    raining(true).

% Rule: Apply pesticide if pest detected
apply_pesticide :-
    pest_detected.

% Rule: Warn if temperature is too high
warn_high_temperature :-
    temperature(high).

