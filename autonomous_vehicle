% --- Facts ---
obstacle_in_path.
traffic_signal(red).
speed(high).
pedestrian_crossing_detected.

% --- Rules ---

% Rule: Stop if obstacle is in path
stop_vehicle :-
    obstacle_in_path.

% Rule: Stop at red traffic signal
stop_vehicle :-
    traffic_signal(red).

% Rule: Slow down if pedestrian crossing is detected
slow_down :-
    pedestrian_crossing_detected.

% Rule: Warn if speed is too high
warn_speed :-
    speed(high).
