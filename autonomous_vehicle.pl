% --- Facts ---
road_condition(clear).
road_condition(wet).

sensor_data(obstacle_nearby, yes).
sensor_data(obstacle_nearby, no).

% Replace old speed facts with one numeric fact:
current_speed(30).    % vehicle is traveling at 30 km/h

vehicle_state(stopped).
vehicle_state(moving).

traffic_signal(green).
traffic_signal(yellow).
traffic_signal(red).

pedestrian_presence(yes).
pedestrian_presence(no).


% --- Rules ---

% Stop if an obstacle is detected and you're moving
should_stop :-
    sensor_data(obstacle_nearby, yes),
    vehicle_state(moving).

% Slow down if the road is wet and speed exceeds 50 km/h
should_slow_down :-
    road_condition(wet),
    current_speed(S),
    S > 50.

% React to traffic lights
react_to_traffic_signal :-
    traffic_signal(red),
    vehicle_state(moving),
    should_stop.
react_to_traffic_signal :-
    traffic_signal(yellow),
    vehicle_state(moving),
    should_slow_down.
react_to_traffic_signal :-
    traffic_signal(green),
    vehicle_state(moving).

% Avoid pedestrians by stopping if someone is detected in your path
avoid_pedestrian :-
    pedestrian_presence(yes),
    sensor_data(obstacle_nearby, yes),
    should_stop.
