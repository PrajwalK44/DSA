% Static facts
road_condition(clear).
road_condition(wet).
road_condition(icy).

traffic_light(red).
traffic_light(yellow).
traffic_light(green).

obstacle(none).
obstacle(pedestrian).
obstacle(vehicle).
obstacle(animal).

% Rules for speed decision
recommended_speed(clear, green, none, 60).
recommended_speed(clear, yellow, none, 40).
recommended_speed(clear, red, none, 0).

recommended_speed(wet, green, none, 40).
recommended_speed(wet, yellow, none, 30).
recommended_speed(wet, red, none, 0).

recommended_speed(icy, _, _, 10).

% Rules when obstacle is present
adjust_speed_for_obstacle(pedestrian, 0).
adjust_speed_for_obstacle(vehicle, 10).
adjust_speed_for_obstacle(animal, 5).
adjust_speed_for_obstacle(none, Speed, Speed).

% Main decision rule
decide_speed(RoadCondition, TrafficLight, Obstacle, FinalSpeed) :-
    recommended_speed(RoadCondition, TrafficLight, none, BaseSpeed),
    (Obstacle = none ->
        FinalSpeed = BaseSpeed ;
        adjust_speed_for_obstacle(Obstacle, AdjustedSpeed),
        FinalSpeed is min(BaseSpeed, AdjustedSpeed)).

% Entry point for user query
% Example usage: ?- vehicle_decision(clear, green, none, Speed).
vehicle_decision(Road, Light, Obstacle, Speed) :-
    decide_speed(Road, Light, Obstacle, Speed),
    format('Recommended speed: ~w km/h~n', [Speed]).
