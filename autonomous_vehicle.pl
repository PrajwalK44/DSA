% Facts about road conditions
road_condition(clear).
road_condition(wet).
road_condition(icy).

% Facts about sensor data
sensor_data(obstacle_nearby, yes).
sensor_data(obstacle_nearby, no).
sensor_data(vehicle_speed(30), yes). % Speed is 30 km/h
sensor_data(vehicle_speed(60), no). % Speed is 60 km/h

% Facts about vehicle state
vehicle_state(stopped).
vehicle_state(moving).

% Facts about traffic signals
traffic_signal(green).
traffic_signal(yellow).
traffic_signal(red).

% Facts about pedestrian presence
pedestrian_presence(yes).
pedestrian_presence(no).


% Rule for stopping the vehicle if an obstacle is detected nearby
should_stop :-
    sensor_data(obstacle_nearby, yes),
    vehicle_state(moving).

% Rule for slowing down the vehicle if the road is wet or icy
should_slow_down :-
    road_condition(wet),
    sensor_data(vehicle_speed(60), no).

should_slow_down :-
    road_condition(icy),
    sensor_data(vehicle_speed(60), no).

% Rule for reacting to traffic lights
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

% Rule to avoid pedestrians
avoid_pedestrian :-
    pedestrian_presence(yes),
    sensor_data(obstacle_nearby, yes),
    should_stop.
