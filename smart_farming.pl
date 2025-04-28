% Static facts
soil_type(clay).
soil_type(sand).
soil_type(loam).

soil_quality(clay, good).
soil_quality(sand, moderate).
soil_quality(loam, excellent).

% Rules for planting decision based on soil quality
% excellent → ideal
% good      → suitable with minor amendments
% moderate  → requires significant amendments

recommended_soil(excellent, 'Ideal for planting').
recommended_soil(good,     'Suitable but consider soil improvement').
recommended_soil(moderate, 'Not recommended without soil amendments').

% Main decision rule
decide_planting(SoilType, Advice) :-
    soil_type(SoilType),
    soil_quality(SoilType, Quality),
    recommended_soil(Quality, Advice).

% Entry point for user query
% Example usage: ?- soil_decision(loam, Advice).
soil_decision(SoilType, Advice) :-
    decide_planting(SoilType, Advice),
    format('Planting advice for ~w soil: ~w.~n', [SoilType, Advice]).
